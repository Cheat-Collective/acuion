#include "aimbottab.h"

#include "../../SDK/definitions.h"
#include "../../settings.h"
#include "../../Utils/xorstring.h"
#include "../../ImGUI/imgui_internal.h"
#include "../atgui.h"

#pragma GCC diagnostic ignored "-Wformat-security"

static ItemDefinitionIndex currentWeapon = ItemDefinitionIndex::INVALID;
static bool enabled = false;
static bool silent = false;
static bool friendly = false;
static bool closestHitbox = false;
static HitboxFlags desiredHitboxes = HitboxFlags::HEAD;
static bool engageLock = false;
static bool engageLockTR = false; // Target Reacquisition
static int engageLockTTR = 700; // Time to Target Reacquisition ( in ms )
static Bone bone = CONST_BONE_HEAD;
static ButtonCode_t aimkey = ButtonCode_t::MOUSE_MIDDLE;
static bool aimkeyOnly = false;
static bool smoothEnabled = false;
static float smoothValue = 0.5f;
static SmoothType smoothType = SmoothType::SLOW_END;
static bool smoothSaltEnabled = false;
static float smoothSaltMultiplier = 0.0f;
static bool errorMarginEnabled = false;
static float errorMarginValue = 0.0f;
static bool autoAimEnabled = false;
static float autoAimValue = 180.0f;
static bool aimStepEnabled = false;
static float aimStepMin = 25.0f;
static float aimStepMax = 35.0f;
static bool rcsEnabled = false;
static bool rcsAlwaysOn = false;
static float rcsAmountX = 2.0f;
static float rcsAmountY = 2.0f;
static bool autoPistolEnabled = false;
static bool autoShootEnabled = false;
static bool autoScopeEnabled = false;
static bool noShootEnabled = false;
static bool ignoreJumpEnabled = false;
static bool ignoreEnemyJumpEnabled = false;
static bool smokeCheck = false;
static bool flashCheck = false;
static bool spreadLimitEnabled = false;
static float spreadLimit = 0.1f;
static bool hitChanceEnabled = false;
static float hitChance = 80.f;
static bool autoWallEnabled = false;
static float autoWallValue = 10.0f;
static bool autoAimRealDistance = false;
static bool autoSlow = false;
static bool predEnabled = false;
static bool scopeControlEnabled = false;

void UI::ReloadWeaponSettings()
{
	ItemDefinitionIndex index = ItemDefinitionIndex::INVALID;
	if (Settings::Aimbot::weapons.find(currentWeapon) != Settings::Aimbot::weapons.end())
		index = currentWeapon;

	enabled = Settings::Aimbot::weapons.at(index).enabled;
	silent = Settings::Aimbot::weapons.at(index).silent;
	friendly = Settings::Aimbot::weapons.at(index).friendly;
	closestHitbox = Settings::Aimbot::weapons.at(index).closestHitbox;
	engageLock = Settings::Aimbot::weapons.at(index).engageLock;
	engageLockTR = Settings::Aimbot::weapons.at(index).engageLockTR;
	engageLockTTR = Settings::Aimbot::weapons.at(index).engageLockTTR;
	bone = Settings::Aimbot::weapons.at(index).bone;
	aimkey = Settings::Aimbot::weapons.at(index).aimkey;
	aimkeyOnly = Settings::Aimbot::weapons.at(index).aimkeyOnly;
	smoothEnabled = Settings::Aimbot::weapons.at(index).smoothEnabled;
	smoothValue = Settings::Aimbot::weapons.at(index).smoothAmount;
	smoothType = Settings::Aimbot::weapons.at(index).smoothType;
	smoothSaltEnabled = Settings::Aimbot::weapons.at(index).smoothSaltEnabled;
	smoothSaltMultiplier = Settings::Aimbot::weapons.at(index).smoothSaltMultiplier;
	errorMarginEnabled = Settings::Aimbot::weapons.at(index).errorMarginEnabled;
	errorMarginValue = Settings::Aimbot::weapons.at(index).errorMarginValue;
	autoAimEnabled = Settings::Aimbot::weapons.at(index).autoAimEnabled;
	autoAimValue = Settings::Aimbot::weapons.at(index).autoAimFov;
	aimStepEnabled = Settings::Aimbot::weapons.at(index).aimStepEnabled;
	aimStepMin = Settings::Aimbot::weapons.at(index).aimStepMin;
	aimStepMax = Settings::Aimbot::weapons.at(index).aimStepMax;
	rcsEnabled = Settings::Aimbot::weapons.at(index).rcsEnabled;
	rcsAlwaysOn = Settings::Aimbot::weapons.at(index).rcsAlwaysOn;
	rcsAmountX = Settings::Aimbot::weapons.at(index).rcsAmountX;
	rcsAmountY = Settings::Aimbot::weapons.at(index).rcsAmountY;
	autoPistolEnabled = Settings::Aimbot::weapons.at(index).autoPistolEnabled;
	autoShootEnabled = Settings::Aimbot::weapons.at(index).autoShootEnabled;
	autoScopeEnabled = Settings::Aimbot::weapons.at(index).autoScopeEnabled;
	noShootEnabled = Settings::Aimbot::weapons.at(index).noShootEnabled;
	ignoreJumpEnabled = Settings::Aimbot::weapons.at(index).ignoreJumpEnabled;
	ignoreEnemyJumpEnabled = Settings::Aimbot::weapons.at(index).ignoreEnemyJumpEnabled;
	smokeCheck = Settings::Aimbot::weapons.at(index).smokeCheck;
	flashCheck = Settings::Aimbot::weapons.at(index).flashCheck;
	spreadLimitEnabled = Settings::Aimbot::weapons.at(index).spreadLimitEnabled;
	spreadLimit = Settings::Aimbot::weapons.at(index).spreadLimit;
	hitChanceEnabled = Settings::Aimbot::weapons.at(index).hitChanceEnabled;
	hitChance = Settings::Aimbot::weapons.at(index).hitChance;
	autoWallEnabled = Settings::Aimbot::weapons.at(index).autoWallEnabled;
	autoWallValue = Settings::Aimbot::weapons.at(index).autoWallValue;
	autoAimRealDistance = Settings::Aimbot::weapons.at(index).autoAimRealDistance;
	autoSlow = Settings::Aimbot::weapons.at(index).autoSlow;
	predEnabled = Settings::Aimbot::weapons.at(index).predEnabled;
	scopeControlEnabled = Settings::Aimbot::weapons.at(index).scopeControlEnabled;
	desiredHitboxes = Settings::Aimbot::weapons.at(index).desiredHitboxes;
}

void UI::UpdateWeaponSettings()
{
	if (Settings::Aimbot::weapons.find(currentWeapon) == Settings::Aimbot::weapons.end())
		Settings::Aimbot::weapons[currentWeapon] = AimbotWeapon_t();

	AimbotWeapon_t settings = {
			.enabled = enabled,
			.silent = silent,
			.friendly = friendly,
			.closestHitbox = closestHitbox,
			.engageLock = engageLock,
			.engageLockTR = engageLockTR,
			.aimkeyOnly = aimkeyOnly,
			.smoothEnabled = smoothEnabled,
			.smoothSaltEnabled = smoothSaltEnabled,
			.errorMarginEnabled = errorMarginEnabled,
			.autoAimEnabled = autoAimEnabled,
			.aimStepEnabled = aimStepEnabled,
			.rcsEnabled = rcsEnabled,
			.rcsAlwaysOn = rcsAlwaysOn,
			.spreadLimitEnabled = spreadLimitEnabled,
			.hitChanceEnabled = hitChanceEnabled,
			.autoPistolEnabled = autoPistolEnabled,
			.autoShootEnabled = autoShootEnabled,
			.autoScopeEnabled = autoScopeEnabled,
			.noShootEnabled = noShootEnabled,
			.ignoreJumpEnabled = ignoreJumpEnabled,
			.ignoreEnemyJumpEnabled = ignoreEnemyJumpEnabled,
			.smokeCheck = smokeCheck,
			.flashCheck = flashCheck,
			.autoWallEnabled = autoWallEnabled,
			.autoAimRealDistance = autoAimRealDistance,
			.autoSlow = autoSlow,
			.predEnabled = predEnabled,
			.scopeControlEnabled = scopeControlEnabled,

			.engageLockTTR = engageLockTTR,
			.bone = bone,
			.smoothType = smoothType,
			.aimkey = aimkey,
			.smoothAmount = smoothValue,
			.smoothSaltMultiplier = smoothSaltMultiplier,
			.errorMarginValue = errorMarginValue,
			.autoAimFov = autoAimValue,
			.aimStepMin = aimStepMin,
			.aimStepMax = aimStepMax,
			.rcsAmountX = rcsAmountX,
			.rcsAmountY = rcsAmountY,
			.autoWallValue = autoWallValue,
			.spreadLimit = spreadLimit,
			.hitChance = hitChance,
	};

	settings.desiredHitboxes = desiredHitboxes;

	Settings::Aimbot::weapons.at(currentWeapon) = settings;

	if (Settings::Aimbot::weapons.at(currentWeapon) == Settings::Aimbot::weapons.at(ItemDefinitionIndex::INVALID) &&
		currentWeapon != ItemDefinitionIndex::INVALID)
	{
		Settings::Aimbot::weapons.erase(currentWeapon);
		UI::ReloadWeaponSettings();
	}
}

void Aimbot::RenderTab()
{
	const char* targets[] = { "PELVIS", "", "", "HIP", "LOWER SPINE", "MIDDLE SPINE", "UPPER SPINE", "NECK", "HEAD" };
	const char* smoothTypes[] = { "Slow Near End", "Constant Speed", "Fast Near End" };
	static char filterWeapons[32];

	if (ImGui::Checkbox(XORSTR("Enabled"), &enabled))
		UI::UpdateWeaponSettings();
	ImGui::Separator();

	ImGui::Columns(3, nullptr, true);
	{
		ImGui::SetColumnOffset(1, 200);
		ImGui::PushItemWidth(-1);
		ImGui::InputText(XORSTR("##FILTERWEAPONS"), filterWeapons, IM_ARRAYSIZE(filterWeapons));
		ImGui::PopItemWidth();
		ImGui::ListBoxHeader(XORSTR("##GUNS"), ImVec2(-1, -1));
		for (auto it : ItemDefinitionIndexMap)
		{
			bool isDefault = (int) it.first < 0;
			if (!isDefault && !Util::Contains(Util::ToLower(std::string(filterWeapons)), Util::ToLower(Util::Items::GetItemDisplayName(it.first).c_str())))
				continue;

			if (Util::Items::IsKnife(it.first) || Util::Items::IsGlove(it.first) || Util::Items::IsUtility(it.first))
				continue;

			const bool item_selected = ((int) it.first == (int) currentWeapon);
			ImGui::PushID((int) it.first);
			std::string formattedName;
			char changeIndicator = ' ';
			bool isChanged = Settings::Aimbot::weapons.find(it.first) != Settings::Aimbot::weapons.end();
			if (!isDefault && isChanged)
				changeIndicator = '*';
			formattedName = changeIndicator + (isDefault ? Util::Items::GetItemDisplayName(it.first).c_str() : Util::Items::GetItemDisplayName(it.first));
			if (ImGui::Selectable(formattedName.c_str(), item_selected))
			{
				currentWeapon = it.first;
				UI::ReloadWeaponSettings();
			}
			ImGui::PopID();
		}
		ImGui::ListBoxFooter();
	}
	ImGui::NextColumn();
	{
		ImGui::SetColumnOffset(2, ImGui::GetWindowWidth() / 2 + 75);
		ImGui::BeginChild(XORSTR("COL1"), ImVec2(0, 0), true);
		{
			ImGui::Text(XORSTR("Target"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, false);
			{
				if (ImGui::Checkbox(XORSTR("FriendlyFire"), &friendly))
					UI::UpdateWeaponSettings();
			}
			ImGui::NextColumn();
			{
				ImGui::PushItemWidth(-1);
				ImGui::Text(XORSTR("Aimbot Target"));
							if(!closestHitbox)
				{
					if (ImGui::Combo(XORSTR("##AIMTARGET"), (int*)&bone, targets, IM_ARRAYSIZE(targets)))
						UI::UpdateWeaponSettings();
				}
				if( closestHitbox )
				{
					if(ImGui::Button(XORSTR("Hitboxes"), ImVec2(-1, 0)))
						ImGui::OpenPopup(XORSTR("optionHitboxes"));
					if(ImGui::BeginPopup(XORSTR("optionHitboxes"), ImGuiWindowFlags_AlwaysAutoResize) )
					{
						if(ImGui::CheckboxFlags(XORSTR("Head"), (unsigned int *)&desiredHitboxes, HitboxFlags::HEAD))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Neck"), (unsigned int *)&desiredHitboxes, HitboxFlags::NECK))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Chest"), (unsigned int *)&desiredHitboxes, HitboxFlags::CHEST))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Stomach"), (unsigned int *)&desiredHitboxes, HitboxFlags::STOMACH))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Pelvis"), (unsigned int *)&desiredHitboxes, HitboxFlags::PELVIS))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Arms"), (unsigned int *)&desiredHitboxes, HitboxFlags::ARMS))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Hands"), (unsigned int *)&desiredHitboxes, HitboxFlags::HANDS))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Legs"), (unsigned int *)&desiredHitboxes, HitboxFlags::LEGS))
							UI::UpdateWeaponSettings();
						if(ImGui::CheckboxFlags(XORSTR("Feet"), (unsigned int *)&desiredHitboxes, HitboxFlags::FEET))
							UI::UpdateWeaponSettings();

						ImGui::EndPopup();
					}
				}
				if(ImGui::Checkbox(XORSTR("Closest Hitbox"), &closestHitbox))
					UI::UpdateWeaponSettings();

				if(ImGui::Checkbox(XORSTR("EngageLock"), &engageLock))
					UI::UpdateWeaponSettings();
				if(engageLock)
				{
					if(ImGui::Checkbox(XORSTR("Target Reacquisition"), &engageLockTR))
						UI::UpdateWeaponSettings();
					if( engageLockTR )
					{
						if(ImGui::SliderInt(XORSTR("##TTR"), &engageLockTTR, 0, 1000))
							UI::UpdateWeaponSettings();
					}
				}
				ImGui::PopItemWidth();
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("Accuracy"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{
				if (ImGui::Checkbox(XORSTR("Auto Aim"), &autoAimEnabled))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Recoil Control"), &rcsEnabled))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Distance-Based FOV"), &autoAimRealDistance))
					UI::UpdateWeaponSettings();
			}
			ImGui::NextColumn();
			{
				ImGui::PushItemWidth(-1);
				if (ImGui::SliderFloat(XORSTR("##AA"), &autoAimValue, 0, 180))
					UI::UpdateWeaponSettings();
				ImGui::PopItemWidth();
				if (ImGui::Button(XORSTR("RCS Settings"), ImVec2(-1, 0)))
					ImGui::OpenPopup(XORSTR("optionRCSAmount"));
				ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Always);
				if (ImGui::BeginPopup(XORSTR("optionRCSAmount")))
				{
					ImGui::PushItemWidth(-1);
					if (ImGui::Checkbox(XORSTR("RCS Always on"), &rcsAlwaysOn))
						UI::UpdateWeaponSettings();
					if (ImGui::SliderFloat(XORSTR("##RCSX"), &rcsAmountX, 0, 2, XORSTR("Pitch: %0.3f")))
						UI::UpdateWeaponSettings();
					if (ImGui::SliderFloat(XORSTR("##RCSY"), &rcsAmountY, 0, 2, XORSTR("Yaw: %0.3f")))
						UI::UpdateWeaponSettings();
					ImGui::PopItemWidth();

					ImGui::EndPopup();
				}
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("Humanizing"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{
				if (ImGui::Checkbox(XORSTR("Smoothing"), &smoothEnabled))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Smooth Salting"), &smoothSaltEnabled))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Error Margin"), &errorMarginEnabled))
					UI::UpdateWeaponSettings();
				ImGui::PushItemWidth(-1);
				if (ImGui::Combo(XORSTR("##SMOOTHTYPE"), (int*)& smoothType, smoothTypes, IM_ARRAYSIZE(smoothTypes)))
					UI::UpdateWeaponSettings();
				ImGui::PopItemWidth();
			}
			ImGui::NextColumn();
			{
				ImGui::PushItemWidth(-1);
				if (ImGui::SliderFloat(XORSTR("##SMOOTH"), &smoothValue, 0, 1))
					UI::UpdateWeaponSettings();
				if (ImGui::SliderFloat(XORSTR("##SALT"), &smoothSaltMultiplier, 0, smoothValue))
					UI::UpdateWeaponSettings();
				if (ImGui::SliderFloat(XORSTR("##ERROR"), &errorMarginValue, 0, 2))
					UI::UpdateWeaponSettings();
				ImGui::PopItemWidth();
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("Autoshoot"));
			ImGui::Separator();
			if (ImGui::Checkbox(XORSTR("Auto Shoot"), &autoShootEnabled))
				UI::UpdateWeaponSettings();
			ImGui::Checkbox(XORSTR("Velocity Check"), &Settings::Aimbot::AutoShoot::velocityCheck);
			if( ImGui::Checkbox(XORSTR("Spread Limit"), &spreadLimitEnabled) )
				UI::UpdateWeaponSettings();
			if( ImGui::SliderFloat(XORSTR("##SPREADLIMIT"), &spreadLimit, 0, 0.1) )
				UI::UpdateWeaponSettings();
			if( ImGui::Checkbox(XORSTR("Hit Chance"), &hitChanceEnabled) )
				UI::UpdateWeaponSettings();
			if( ImGui::SliderFloat(XORSTR("##hitChance"), &hitChance, 0, 100) )
				UI::UpdateWeaponSettings();
			ImGui::EndChild();
		}
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild(XORSTR("COL2"), ImVec2(0, 0), true);
		{
			ImGui::Text(XORSTR("Aimkey Only"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{
				if (ImGui::Checkbox(XORSTR("Enabled"), &aimkeyOnly))
					UI::UpdateWeaponSettings();
			}
			ImGui::NextColumn();
			{
				UI::KeyBindButton(&aimkey);
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("Casual / DM Only"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{
				if (ImGui::Checkbox(XORSTR("Aim Step"), &aimStepEnabled))
					UI::UpdateWeaponSettings();
			}
			ImGui::NextColumn();
			{
				ImGui::PushItemWidth(-1);
				ImGui::Text(XORSTR("Min"));
				if (ImGui::SliderFloat(XORSTR("##STEPMIN"), &aimStepMin, 5, 35))
					UI::UpdateWeaponSettings();
				ImGui::Text(XORSTR("Max"));
				if (ImGui::SliderFloat(XORSTR("##STEPMAX"), &aimStepMax, (aimStepMin) + 1.0f, 35))
					UI::UpdateWeaponSettings();
				ImGui::PopItemWidth();
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("Other"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{

				switch (currentWeapon)
				{
					case ItemDefinitionIndex::INVALID:
					case ItemDefinitionIndex::WEAPON_DEAGLE:
					case ItemDefinitionIndex::WEAPON_ELITE:
					case ItemDefinitionIndex::WEAPON_FIVESEVEN:
					case ItemDefinitionIndex::WEAPON_GLOCK:
					case ItemDefinitionIndex::WEAPON_TEC9:
					case ItemDefinitionIndex::WEAPON_HKP2000:
					case ItemDefinitionIndex::WEAPON_USP_SILENCER:
					case ItemDefinitionIndex::WEAPON_P250:
					case ItemDefinitionIndex::WEAPON_CZ75A:
					case ItemDefinitionIndex::WEAPON_REVOLVER:
						if (ImGui::Checkbox(XORSTR("Auto Pistol"), &autoPistolEnabled))
							UI::UpdateWeaponSettings();
						break;
					default:
						break;
				}

				if (ImGui::Checkbox(XORSTR("Silent Aim"), &silent))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Smoke Check"), &smokeCheck))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Prediction"), &predEnabled))
					UI::UpdateWeaponSettings();
			}
			ImGui::NextColumn();
			{
				if (ImGui::Checkbox(XORSTR("No Shoot"), &noShootEnabled))
					UI::UpdateWeaponSettings();

				switch (currentWeapon)
				{
					case ItemDefinitionIndex::WEAPON_DEAGLE:
					case ItemDefinitionIndex::WEAPON_ELITE:
					case ItemDefinitionIndex::WEAPON_FIVESEVEN:
					case ItemDefinitionIndex::WEAPON_GLOCK:
					case ItemDefinitionIndex::WEAPON_TEC9:
					case ItemDefinitionIndex::WEAPON_HKP2000:
					case ItemDefinitionIndex::WEAPON_USP_SILENCER:
					case ItemDefinitionIndex::WEAPON_P250:
					case ItemDefinitionIndex::WEAPON_CZ75A:
					case ItemDefinitionIndex::WEAPON_REVOLVER:
						break;
					default:
						if (ImGui::Checkbox(XORSTR("Auto Scope"), &autoScopeEnabled))
							UI::UpdateWeaponSettings();
						if (ImGui::Checkbox(XORSTR("Scope Control"), &scopeControlEnabled))
							UI::UpdateWeaponSettings();
				}

				if (ImGui::Checkbox(XORSTR("Flash Check"), &flashCheck))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Ignore Jump (Self)"), &ignoreJumpEnabled))
					UI::UpdateWeaponSettings();
				if (ImGui::Checkbox(XORSTR("Ignore Jump (Enemies)"), &ignoreEnemyJumpEnabled))
					UI::UpdateWeaponSettings();
			}


			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("AutoSlow"));
			ImGui::Separator();
			if (ImGui::Checkbox(XORSTR("Enabled##AUTOSLOW"), &autoSlow))
				UI::UpdateWeaponSettings();

			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::Text(XORSTR("AutoWall"));
			ImGui::Separator();
			ImGui::Columns(2, nullptr, true);
			{
				if (ImGui::Checkbox(XORSTR("Enabled##AUTOWALL"), &autoWallEnabled))
					UI::UpdateWeaponSettings();
							if(ImGui::Button(XORSTR("Autowall Hitboxes"), ImVec2(-1, 0)))
					ImGui::OpenPopup(XORSTR("optionHitboxes"));
				if(ImGui::BeginPopup(XORSTR("optionHitboxes"), ImGuiWindowFlags_AlwaysAutoResize) )
				{
					if(ImGui::CheckboxFlags(XORSTR("Head"), (unsigned int *)&desiredHitboxes, HitboxFlags::HEAD))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Neck"), (unsigned int *)&desiredHitboxes, HitboxFlags::NECK))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Chest"), (unsigned int *)&desiredHitboxes, HitboxFlags::CHEST))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Stomach"), (unsigned int *)&desiredHitboxes, HitboxFlags::STOMACH))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Pelvis"), (unsigned int *)&desiredHitboxes, HitboxFlags::PELVIS))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Arms"), (unsigned int *)&desiredHitboxes, HitboxFlags::ARMS))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Hands"), (unsigned int *)&desiredHitboxes, HitboxFlags::HANDS))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Legs"), (unsigned int *)&desiredHitboxes, HitboxFlags::LEGS))
						UI::UpdateWeaponSettings();
					if(ImGui::CheckboxFlags(XORSTR("Feet"), (unsigned int *)&desiredHitboxes, HitboxFlags::FEET))
						UI::UpdateWeaponSettings();
					ImGui::EndPopup();
				}
			}
			ImGui::NextColumn();
			{
				ImGui::PushItemWidth(-1);
				if (ImGui::SliderFloat(XORSTR("##AUTOWALLDMG"), &autoWallValue, 0, 100, XORSTR("Min Damage: %f")))
					UI::UpdateWeaponSettings();
				ImGui::PopItemWidth();
			}


			ImGui::Columns(1);
			ImGui::Separator();
			if (currentWeapon > ItemDefinitionIndex::INVALID && Settings::Aimbot::weapons.find(currentWeapon) != Settings::Aimbot::weapons.end())
			{
				if (ImGui::Button(XORSTR("Clear Weapon Settings"), ImVec2(-1, 0)))
				{
					Settings::Aimbot::weapons.erase(currentWeapon);
					UI::ReloadWeaponSettings();
				}
			}
			ImGui::EndChild();
		}
	}
}
