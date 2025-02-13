#include "chams.h"

#include "lagcomp.h"

#include "../Utils/xorstring.h"
#include "../Utils/entity.h"
#include "../settings.h"
#include "../interfaces.h"
#include "../Hooks/hooks.h"

IMaterial* materialChams;
IMaterial* materialChamsIgnorez;
IMaterial* materialChamsFlat;
IMaterial* materialChamsFlatIgnorez;
IMaterial* materialChamsArms;
IMaterial* materialChamsWeapons;

typedef void (*DrawModelExecuteFn) (void*, void*, void*, const ModelRenderInfo_t&, matrix3x4_t*);

static void DrawPlayer(void* thisptr, void* context, void *state, const ModelRenderInfo_t &pInfo, matrix3x4_t* pCustomBoneToWorld)
{
	if (!Settings::ESP::Chams::enabled)
		return;

	C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());
	if (!localplayer)
		return;

	C_BasePlayer* entity = (C_BasePlayer*) entityList->GetClientEntity(pInfo.entity_index);
	if (!entity
		|| entity->GetDormant()
		|| !entity->GetAlive())
		return;

	if (entity == localplayer && !Settings::ESP::Filters::localplayer)
		return;

	if (!Entity::IsTeamMate(entity, localplayer) && !Settings::ESP::Filters::enemies)
		return;

	if (entity != localplayer && Entity::IsTeamMate(entity,localplayer) && !Settings::ESP::Filters::allies)
		return;

	IMaterial* visible_material = nullptr;
	IMaterial* hidden_material = nullptr;

	switch (Settings::ESP::Chams::type)
	{
		case ChamsType::CHAMS:
		case ChamsType::CHAMS_XQZ:
			visible_material = materialChams;
			hidden_material = materialChamsIgnorez;
			break;
		case ChamsType::CHAMS_FLAT:
		case ChamsType::CHAMS_FLAT_XQZ:
			visible_material = materialChamsFlat;
			hidden_material = materialChamsFlatIgnorez;
			break;
	}

	visible_material->AlphaModulate(1.0f);
	hidden_material->AlphaModulate(1.0f);

	if (entity == localplayer)
	{
		Color visColor = Color::FromImColor(Settings::ESP::Chams::localplayerColor.Color(entity));
		Color color = visColor;
		color *= 0.45f;

		visible_material->ColorModulate(visColor);
		hidden_material->ColorModulate(color);

		visible_material->AlphaModulate(Settings::ESP::Chams::localplayerColor.Color(entity).Value.w);
		hidden_material->AlphaModulate(Settings::ESP::Chams::localplayerColor.Color(entity).Value.w);
	}
	else if (Entity::IsTeamMate(entity, localplayer))
	{
		Color visColor = Color::FromImColor(Settings::ESP::Chams::allyVisibleColor.Color(entity));
		Color color = Color::FromImColor(Settings::ESP::Chams::allyColor.Color(entity));

		visible_material->ColorModulate(visColor);
		hidden_material->ColorModulate(color);
		
		visible_material->AlphaModulate(Settings::ESP::Chams::allyVisibleColor.Color(entity).Value.w);
		hidden_material->AlphaModulate(Settings::ESP::Chams::allyColor.Color(entity).Value.w);
	}
	else if (!Entity::IsTeamMate(entity, localplayer))
	{
		Color visColor = Color::FromImColor(Settings::ESP::Chams::enemyVisibleColor.Color(entity));
		Color color = Color::FromImColor(Settings::ESP::Chams::enemyColor.Color(entity));

		visible_material->ColorModulate(visColor);
		hidden_material->ColorModulate(color);
		
		visible_material->AlphaModulate(Settings::ESP::Chams::enemyVisibleColor.Color(entity).Value.w);
		hidden_material->AlphaModulate(Settings::ESP::Chams::enemyColor.Color(entity).Value.w);
	}
	else
	{
		return;
	}

	if (entity->GetImmune())
	{
		visible_material->AlphaModulate(0.5f);
		hidden_material->AlphaModulate(0.5f);
	}

	if (!Settings::ESP::Filters::legit && (Settings::ESP::Chams::type == ChamsType::CHAMS_XQZ || Settings::ESP::Chams::type == ChamsType::CHAMS_FLAT_XQZ))
	{
		modelRender->ForcedMaterialOverride(hidden_material);
		modelRenderVMT->GetOriginalMethod<DrawModelExecuteFn>(21)(thisptr, context, state, pInfo, pCustomBoneToWorld);
	}

	modelRender->ForcedMaterialOverride(visible_material);
	// No need to call DME again, it already gets called in DrawModelExecute.cpp
}

static void DrawRecord(void* thisptr, void* context, void *state, const ModelRenderInfo_t &pInfo, matrix3x4_t* pCustomBoneToWorld)
{
	if (!Settings::LagComp::enabled || !Settings::ESP::Chams::backtrackEnabled)
        return;

    C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());
	if (!localplayer)
		return;
	
	C_BasePlayer* entity = (C_BasePlayer*) entityList->GetClientEntity(pInfo.entity_index);
	if (!entity
	    || !entity->GetAlive())
		return;
		
	if (LagComp::ticks.empty())
		return;
	
	auto &tick = LagComp::ticks.back();
	for (auto &record : tick.records)
	{
		if (!record.boneMatrix || entity != record.entity)
			continue;
		
		IMaterial* visible_material = nullptr;
		IMaterial* hidden_material = nullptr;
		
		switch (Settings::ESP::Chams::backtrackType)
		{
			case ChamsType::CHAMS:
			case ChamsType::CHAMS_XQZ:
				visible_material = materialChams;
				hidden_material = materialChamsIgnorez;
				break;
			case ChamsType::CHAMS_FLAT:
			case ChamsType::CHAMS_FLAT_XQZ:
				visible_material = materialChamsFlat;
				hidden_material = materialChamsFlatIgnorez;
				break;
		}
		
		Color visColor = Color::FromImColor(Settings::ESP::Chams::backtrackVisibleColor.Color(entity));
		Color color = Color::FromImColor(Settings::ESP::Chams::backtrackColor.Color(entity));
		
		visible_material->ColorModulate(visColor);
		hidden_material->ColorModulate(color);
		
		visible_material->AlphaModulate(Settings::ESP::Chams::backtrackVisibleColor.Color(entity).Value.w);
		hidden_material->AlphaModulate(Settings::ESP::Chams::backtrackColor.Color(entity).Value.w);
		
		if (!Settings::ESP::Filters::legit && (Settings::ESP::Chams::backtrackType == ChamsType::CHAMS_XQZ || Settings::ESP::Chams::backtrackType == ChamsType::CHAMS_FLAT_XQZ))
		{
			modelRender->ForcedMaterialOverride(hidden_material);
			modelRenderVMT->GetOriginalMethod<DrawModelExecuteFn>(21)(thisptr, context, state, pInfo, (matrix3x4_t*)record.boneMatrix);
		}
		
		// pInfo.origin = record.origin;
		modelRender->ForcedMaterialOverride(visible_material);
		modelRenderVMT->GetOriginalMethod<DrawModelExecuteFn>(21)(thisptr, context, state, pInfo, (matrix3x4_t*)record.boneMatrix);
	}
}

static void DrawWeapon(const ModelRenderInfo_t& pInfo)
{
	if (!Settings::ESP::Chams::Weapon::enabled)
		return;

	std::string modelName = modelInfo->GetModelName(pInfo.pModel);
	IMaterial* mat = materialChamsWeapons;

	if (!Settings::ESP::Chams::Weapon::enabled)
		mat = material->FindMaterial(modelName.c_str(), TEXTURE_GROUP_MODEL);

	mat->ColorModulate(Settings::ESP::Chams::Weapon::color.Color());
	mat->AlphaModulate(Settings::ESP::Chams::Weapon::color.Color().Value.w);

	mat->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, Settings::ESP::Chams::Weapon::type == WeaponType::WIREFRAME);
	mat->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, Settings::ESP::Chams::Weapon::type == WeaponType::NONE);
	modelRender->ForcedMaterialOverride(mat);
}

static void DrawArms(const ModelRenderInfo_t& pInfo)
{
	if (!Settings::ESP::Chams::Arms::enabled)
		return;

	std::string modelName = modelInfo->GetModelName(pInfo.pModel);
	IMaterial* mat = materialChamsArms;

	if (!Settings::ESP::Chams::Arms::enabled)
		mat = material->FindMaterial(modelName.c_str(), TEXTURE_GROUP_MODEL);

	mat->ColorModulate(Settings::ESP::Chams::Arms::color.Color());
	mat->AlphaModulate(Settings::ESP::Chams::Arms::color.Color().Value.w);

	mat->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, Settings::ESP::Chams::Arms::type == ArmsType::WIREFRAME);
	mat->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, Settings::ESP::Chams::Arms::type == ArmsType::NONE);
	modelRender->ForcedMaterialOverride(mat);
}

void Chams::DrawModelExecute(void* thisptr, void* context, void *state, const ModelRenderInfo_t &pInfo, matrix3x4_t* pCustomBoneToWorld)
{
	if (!engine->IsInGame())
		return;

	if (!Settings::ESP::enabled)
		return;

	if (!pInfo.pModel)
		return;

	static bool materialsCreated = false;
	if (!materialsCreated)
	{
		materialChams = Util::CreateMaterial(XORSTR("VertexLitGeneric"), XORSTR("VGUI/white_additive"), false, true, true, true, true);
		materialChamsIgnorez = Util::CreateMaterial(XORSTR("VertexLitGeneric"), XORSTR("VGUI/white_additive"), true, true, true, true, true);
		materialChamsFlat = Util::CreateMaterial(XORSTR("UnlitGeneric"), XORSTR("VGUI/white_additive"), false, true, true, true, true);
		materialChamsFlatIgnorez = Util::CreateMaterial(XORSTR("UnlitGeneric"), XORSTR("VGUI/white_additive"), true, true, true, true, true);
		materialChamsArms = Util::CreateMaterial(XORSTR("VertexLitGeneric"), XORSTR("VGUI/white_additive"), false, true, true, true, true);
		materialChamsWeapons = Util::CreateMaterial(XORSTR("VertexLitGeneric"), XORSTR("VGUI/white_additive"), false, true, true, true, true);
		materialsCreated = true;
	}

	const char *modelName = modelInfo->GetModelName(pInfo.pModel);

	if (strstr(modelName, XORSTR("models/player")))
	{
		DrawRecord(thisptr, context, state, pInfo, pCustomBoneToWorld);
		DrawPlayer(thisptr, context, state, pInfo, pCustomBoneToWorld);
	}
	else if (strstr(modelName, XORSTR("arms")))
	{
		DrawArms(pInfo);
	}
	else if (strstr(modelName, XORSTR("weapon")))
	{
		DrawWeapon(pInfo);
	}
}
