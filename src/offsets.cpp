#include "offsets.h"
#include "Utils/netvarmanager.h"
#include "Utils/xorstring.h"

COffsets offsets;

void Offsets::GetNetVarOffsets()
{
	std::vector<RecvTable *> tables = NetVarManager::GetTables();

	offsets.DT_BasePlayer.m_Local = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_Local"));
	offsets.DT_BasePlayer.m_aimPunchAngle = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_aimPunchAngle"));
	offsets.DT_BasePlayer.m_viewPunchAngle = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_viewPunchAngle"));
	offsets.DT_BasePlayer.m_vecViewOffset = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_vecViewOffset[0]"));
	offsets.DT_BasePlayer.m_nTickBase = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_nTickBase"));
	offsets.DT_BasePlayer.m_vecVelocity = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_vecVelocity[0]"));
	offsets.DT_BasePlayer.m_iHealth = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_iHealth"));
	offsets.DT_BasePlayer.m_lifeState = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_lifeState"));
	offsets.DT_BasePlayer.m_fFlags = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_fFlags"));
	offsets.DT_BasePlayer.m_iObserverMode = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_iObserverMode"));
	offsets.DT_BasePlayer.m_hObserverTarget = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_hObserverTarget"));
	offsets.DT_BasePlayer.m_hViewModel = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_hViewModel[0]"));
	offsets.DT_BasePlayer.m_szLastPlaceName = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("m_szLastPlaceName"));
	offsets.DT_BasePlayer.deadflag = NetVarManager::GetOffset(tables, XORSTR("DT_BasePlayer"), XORSTR("deadflag"));

	offsets.DT_BaseEntity.m_flAnimTime = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_flAnimTime"));
	offsets.DT_BaseEntity.m_flSimulationTime = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_flSimulationTime"));
	offsets.DT_BaseEntity.m_vecOrigin = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_vecOrigin"));
	offsets.DT_BaseEntity.m_nRenderMode = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_nRenderMode"));
	offsets.DT_BaseEntity.m_iTeamNum = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_iTeamNum"));
	offsets.DT_BaseEntity.m_MoveType = offsets.DT_BaseEntity.m_nRenderMode + 1;
	offsets.DT_BaseEntity.m_Collision = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_Collision"));
	offsets.DT_BaseEntity.m_bSpotted = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_bSpotted"));
	offsets.DT_BaseEntity.m_bSpottedByMask = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_bSpottedByMask"));
	offsets.DT_BaseEntity.m_RefEHandle = NetVarManager::GetOffset(tables, XORSTR("DT_BaseEntity"), XORSTR("m_RefEHandle"));

	offsets.DT_BaseCombatCharacter.m_hActiveWeapon = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatCharacter"), XORSTR("m_hActiveWeapon"));
	offsets.DT_BaseCombatCharacter.m_hMyWeapons = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatCharacter"), XORSTR("m_hMyWeapons")) / 2;
	offsets.DT_BaseCombatCharacter.m_hMyWearables = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatCharacter"), XORSTR("m_hMyWearables"));

	offsets.DT_PlayerResource.m_iPing = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iPing"));
	offsets.DT_PlayerResource.m_iKills = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iKills"));
	offsets.DT_PlayerResource.m_iAssists = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iAssists"));
	offsets.DT_PlayerResource.m_iDeaths = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iDeaths"));
	offsets.DT_PlayerResource.m_bConnected = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_bConnected"));
	offsets.DT_PlayerResource.m_iTeam = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iTeam"));
	offsets.DT_PlayerResource.m_iPendingTeam = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iPendingTeam"));
	offsets.DT_PlayerResource.m_bAlive = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_bAlive"));
	offsets.DT_PlayerResource.m_iHealth = NetVarManager::GetOffset(tables, XORSTR("DT_PlayerResource"), XORSTR("m_iHealth"));

	offsets.DT_CSPlayerResource.m_iPlayerC4 = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iPlayerC4"));
	offsets.DT_CSPlayerResource.m_iPlayerVIP = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iPlayerVIP"));
	offsets.DT_CSPlayerResource.m_bHostageAlive = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bHostageAlive"));
	offsets.DT_CSPlayerResource.m_isHostageFollowingSomeone = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_isHostageFollowingSomeone"));
	offsets.DT_CSPlayerResource.m_iHostageEntityIDs = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iHostageEntityIDs"));
	offsets.DT_CSPlayerResource.m_bombsiteCenterB = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bombsiteCenterB"));
	offsets.DT_CSPlayerResource.m_hostageRescueX = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_hostageRescueX"));
	offsets.DT_CSPlayerResource.m_hostageRescueY = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_hostageRescueY"));
	offsets.DT_CSPlayerResource.m_hostageRescueZ = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_hostageRescueZ"));
	offsets.DT_CSPlayerResource.m_iMVPs = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iMVPs"));
	offsets.DT_CSPlayerResource.m_iArmor = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iArmor"));
	offsets.DT_CSPlayerResource.m_bHasHelmet = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bHasHelmet"));
	offsets.DT_CSPlayerResource.m_bHasDefuser = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bHasDefuser"));
	offsets.DT_CSPlayerResource.m_iScore = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iScore"));
	offsets.DT_CSPlayerResource.m_iCompetitiveRanking = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iCompetitiveRanking"));
	offsets.DT_CSPlayerResource.m_iCompetitiveWins = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iCompetitiveWins"));
	offsets.DT_CSPlayerResource.m_iCompTeammateColor = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iCompTeammateColor"));
	offsets.DT_CSPlayerResource.m_bControllingBot = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bControllingBot"));
	offsets.DT_CSPlayerResource.m_iControlledPlayer = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iControlledPlayer"));
	offsets.DT_CSPlayerResource.m_iControlledByPlayer = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iControlledByPlayer"));
	offsets.DT_CSPlayerResource.m_iBotDifficulty = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iBotDifficulty"));
	offsets.DT_CSPlayerResource.m_szClan = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_szClan"));
	offsets.DT_CSPlayerResource.m_iTotalCashSpent = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iTotalCashSpent"));
	offsets.DT_CSPlayerResource.m_iCashSpentThisRound = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_iCashSpentThisRound"));
	offsets.DT_CSPlayerResource.m_nEndMatchNextMapVotes = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nEndMatchNextMapVotes"));
	offsets.DT_CSPlayerResource.m_bEndMatchNextMapAllVoted = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_bEndMatchNextMapAllVoted"));
	offsets.DT_CSPlayerResource.m_nActiveCoinRank = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nActiveCoinRank"));
	offsets.DT_CSPlayerResource.m_nMusicID = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nMusicID"));
	offsets.DT_CSPlayerResource.m_nPersonaDataPublicLevel = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nPersonaDataPublicLevel"));
	offsets.DT_CSPlayerResource.m_nPersonaDataPublicCommendsLeader = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nPersonaDataPublicCommendsLeader"));
	offsets.DT_CSPlayerResource.m_nPersonaDataPublicCommendsTeacher = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nPersonaDataPublicCommendsTeacher"));
	offsets.DT_CSPlayerResource.m_nPersonaDataPublicCommendsFriendly = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayerResource"), XORSTR("m_nPersonaDataPublicCommendsFriendly"));

	offsets.DT_PlantedC4.m_bBombTicking = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_bBombTicking"));
	offsets.DT_PlantedC4.m_flC4Blow = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_flC4Blow"));
	offsets.DT_PlantedC4.m_bBombDefused = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_bBombDefused"));
	offsets.DT_PlantedC4.m_hBombDefuser = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_hBombDefuser"));
	offsets.DT_PlantedC4.m_flDefuseCountDown = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_flDefuseCountDown"));
	offsets.DT_PlantedC4.m_flDefuseLength = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_flDefuseLength"));
	offsets.DT_PlantedC4.m_nBombSite = NetVarManager::GetOffset(tables, XORSTR("DT_PlantedC4"), XORSTR("m_nBombSite"));

	offsets.DT_CSPlayer.m_iShotsFired = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_iShotsFired"));
	offsets.DT_CSPlayer.m_angEyeAngles[0] = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_angEyeAngles[0]"));
	offsets.DT_CSPlayer.m_angEyeAngles[1] = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_angEyeAngles[1]"));
	offsets.DT_CSPlayer.m_iAccount = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_iAccount"));
	offsets.DT_CSPlayer.m_totalHitsOnServer = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_totalHitsOnServer"));
	offsets.DT_CSPlayer.m_ArmorValue = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_ArmorValue"));
	offsets.DT_CSPlayer.m_bIsDefusing = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bIsDefusing"));
	offsets.DT_CSPlayer.m_bIsGrabbingHostage = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bIsGrabbingHostage"));
	offsets.DT_CSPlayer.m_bIsScoped = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bIsScoped"));
	offsets.DT_CSPlayer.m_bGunGameImmunity = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bGunGameImmunity"));
	offsets.DT_CSPlayer.m_bIsRescuing = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bIsRescuing"));
	offsets.DT_CSPlayer.m_bHasHelmet = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bHasHelmet"));
	offsets.DT_CSPlayer.m_bHasDefuser = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_bHasDefuser"));
	offsets.DT_CSPlayer.m_flFlashDuration = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_flFlashDuration"));
	offsets.DT_CSPlayer.m_flFlashMaxAlpha = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_flFlashMaxAlpha"));
	offsets.DT_CSPlayer.m_flLowerBodyYawTarget = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_flLowerBodyYawTarget"));
	offsets.DT_CSPlayer.m_nSurvivalTeam = NetVarManager::GetOffset(tables, XORSTR("DT_CSPlayer"), XORSTR("m_nSurvivalTeam"));

	offsets.DT_BaseAttributableItem.m_iItemDefinitionIndex = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_iItemDefinitionIndex"));
	offsets.DT_BaseAttributableItem.m_iItemIDHigh = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_iItemIDHigh"));
	offsets.DT_BaseAttributableItem.m_iAccountID = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_iAccountID"));
	offsets.DT_BaseAttributableItem.m_iEntityQuality = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_iEntityQuality"));
	offsets.DT_BaseAttributableItem.m_szCustomName = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_szCustomName"));
	offsets.DT_BaseAttributableItem.m_nFallbackPaintKit = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_nFallbackPaintKit"));
	offsets.DT_BaseAttributableItem.m_nFallbackSeed = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_nFallbackSeed"));
	offsets.DT_BaseAttributableItem.m_flFallbackWear = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_flFallbackWear"));
	offsets.DT_BaseAttributableItem.m_nFallbackStatTrak = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_nFallbackStatTrak"));
	offsets.DT_BaseAttributableItem.m_bInitialized = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAttributableItem"), XORSTR("m_bInitialized"));

	offsets.DT_BaseViewModel.m_nModelIndex = NetVarManager::GetOffset(tables, XORSTR("DT_BaseViewModel"), XORSTR("m_nModelIndex"));
	offsets.DT_BaseViewModel.m_hWeapon = NetVarManager::GetOffset(tables, XORSTR("DT_BaseViewModel"), XORSTR("m_hWeapon"));
	offsets.DT_BaseViewModel.m_hOwner = NetVarManager::GetOffset(tables, XORSTR("DT_BaseViewModel"), XORSTR("m_hOwner"));

	offsets.DT_WeaponCSBase.m_bReloadVisuallyComplete = NetVarManager::GetOffset(tables, XORSTR("DT_WeaponCSBase"), XORSTR("m_bReloadVisuallyComplete"));
	offsets.DT_WeaponCSBase.m_fAccuracyPenalty = NetVarManager::GetOffset(tables, XORSTR("DT_WeaponCSBase"), XORSTR("m_fAccuracyPenalty"));
    offsets.DT_WeaponCSBase.m_flPostponeFireReadyTime = NetVarManager::GetOffset(tables, XORSTR("DT_WeaponCSBase"), XORSTR("m_flPostponeFireReadyTime"));

	offsets.DT_WeaponC4.m_bStartedArming = NetVarManager::GetOffset(tables, XORSTR("DT_WeaponC4"), XORSTR("m_bStartedArming"));

	offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatWeapon"), XORSTR("m_flNextPrimaryAttack"));
	offsets.DT_BaseCombatWeapon.m_hOwner = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatWeapon"), XORSTR("m_hOwner"));
	offsets.DT_BaseCombatWeapon.m_iClip1 = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCombatWeapon"), XORSTR("m_iClip1"));
	offsets.DT_BaseCombatWeapon.m_bInReload = offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack + 113;

	offsets.DT_BaseCSGrenade.m_bRedraw = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_bRedraw"));
	offsets.DT_BaseCSGrenade.m_bIsHeldByPlayer = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_bIsHeldByPlayer"));
	offsets.DT_BaseCSGrenade.m_bPinPulled = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_bPinPulled"));
	offsets.DT_BaseCSGrenade.m_fThrowTime = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_fThrowTime"));
	offsets.DT_BaseCSGrenade.m_bLoopingSoundPlaying = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_bLoopingSoundPlaying"));
	offsets.DT_BaseCSGrenade.m_flThrowStrength = NetVarManager::GetOffset(tables, XORSTR("DT_BaseCSGrenade"), XORSTR("m_flThrowStrength"));

	offsets.DT_DynamicProp.m_bShouldGlow = NetVarManager::GetOffset(tables, XORSTR("DT_DynamicProp"), XORSTR("m_bShouldGlow"));

	offsets.DT_CSGameRulesProxy.m_bBombPlanted = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bBombPlanted"));
	offsets.DT_CSGameRulesProxy.m_bIsValveDS = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bIsValveDS"));

	offsets.DT_CSGameRulesProxy.m_bFreezePeriod = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bFreezePeriod"));
	offsets.DT_CSGameRulesProxy.m_bMatchWaitingForResume = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bMatchWaitingForResume"));
	offsets.DT_CSGameRulesProxy.m_bWarmupPeriod = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bWarmupPeriod"));
	offsets.DT_CSGameRulesProxy.m_fWarmupPeriodEnd = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_fWarmupPeriodEnd"));
	offsets.DT_CSGameRulesProxy.m_fWarmupPeriodStart = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_fWarmupPeriodStart"));
	offsets.DT_CSGameRulesProxy.m_bTerroristTimeOutActive = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bTerroristTimeOutActive"));
	offsets.DT_CSGameRulesProxy.m_bCTTimeOutActive = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bCTTimeOutActive"));
	offsets.DT_CSGameRulesProxy.m_flTerroristTimeOutRemaining = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flTerroristTimeOutRemaining"));
	offsets.DT_CSGameRulesProxy.m_flCTTimeOutRemaining = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flCTTimeOutRemaining"));
	offsets.DT_CSGameRulesProxy.m_nTerroristTimeOuts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nTerroristTimeOuts"));
	offsets.DT_CSGameRulesProxy.m_nCTTimeOuts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nCTTimeOuts"));
	offsets.DT_CSGameRulesProxy.m_iRoundTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iRoundTime"));
	offsets.DT_CSGameRulesProxy.m_gamePhase = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_gamePhase"));
	offsets.DT_CSGameRulesProxy.m_totalRoundsPlayed = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_totalRoundsPlayed"));
	offsets.DT_CSGameRulesProxy.m_nOvertimePlaying = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nOvertimePlaying"));
	offsets.DT_CSGameRulesProxy.m_timeUntilNextPhaseStarts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_timeUntilNextPhaseStarts"));
	offsets.DT_CSGameRulesProxy.m_flCMMItemDropRevealStartTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flCMMItemDropRevealStartTime"));
	offsets.DT_CSGameRulesProxy.m_flCMMItemDropRevealEndTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flCMMItemDropRevealEndTime"));
	offsets.DT_CSGameRulesProxy.m_fRoundStartTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_fRoundStartTime"));
	offsets.DT_CSGameRulesProxy.m_bGameRestart = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bGameRestart"));
	offsets.DT_CSGameRulesProxy.m_flRestartRoundTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flRestartRoundTime"));
	offsets.DT_CSGameRulesProxy.m_flGameStartTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flGameStartTime"));
	offsets.DT_CSGameRulesProxy.m_iHostagesRemaining = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iHostagesRemaining"));
	offsets.DT_CSGameRulesProxy.m_bAnyHostageReached = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bAnyHostageReached"));
	offsets.DT_CSGameRulesProxy.m_bMapHasBombTarget = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bMapHasBombTarget"));
	offsets.DT_CSGameRulesProxy.m_bMapHasRescueZone = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bMapHasRescueZone"));
	offsets.DT_CSGameRulesProxy.m_bMapHasBuyZone = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bMapHasBuyZone"));
	offsets.DT_CSGameRulesProxy.m_bIsQueuedMatchmaking = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bIsQueuedMatchmaking"));
	offsets.DT_CSGameRulesProxy.m_bIsValveDS = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bIsValveDS"));
	offsets.DT_CSGameRulesProxy.m_bIsQuestEligible = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bIsQuestEligible"));
	offsets.DT_CSGameRulesProxy.m_bLogoMap = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bLogoMap"));
	offsets.DT_CSGameRulesProxy.m_iNumGunGameProgressiveWeaponsCT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iNumGunGameProgressiveWeaponsCT"));
	offsets.DT_CSGameRulesProxy.m_iNumGunGameProgressiveWeaponsT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iNumGunGameProgressiveWeaponsT"));
	offsets.DT_CSGameRulesProxy.m_iSpectatorSlotCount = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iSpectatorSlotCount"));
	offsets.DT_CSGameRulesProxy.m_bBombDropped = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bBombDropped"));
	offsets.DT_CSGameRulesProxy.m_bBombPlanted = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bBombPlanted"));
	offsets.DT_CSGameRulesProxy.m_iRoundWinStatus = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iRoundWinStatus"));
	offsets.DT_CSGameRulesProxy.m_eRoundWinReason = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_eRoundWinReason"));
	offsets.DT_CSGameRulesProxy.m_flDMBonusStartTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flDMBonusStartTime"));
	offsets.DT_CSGameRulesProxy.m_flDMBonusTimeLength = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flDMBonusTimeLength"));
	offsets.DT_CSGameRulesProxy.m_unDMBonusWeaponLoadoutSlot = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_unDMBonusWeaponLoadoutSlot"));
	offsets.DT_CSGameRulesProxy.m_bDMBonusActive = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bDMBonusActive"));
	offsets.DT_CSGameRulesProxy.m_bTCantBuy = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bTCantBuy"));
	offsets.DT_CSGameRulesProxy.m_bCTCantBuy = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bCTCantBuy"));
	offsets.DT_CSGameRulesProxy.m_flGuardianBuyUntilTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flGuardianBuyUntilTime"));
	offsets.DT_CSGameRulesProxy.m_iMatchStats_RoundResults = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iMatchStats_RoundResults"));
	offsets.DT_CSGameRulesProxy.m_iMatchStats_PlayersAlive_T = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iMatchStats_PlayersAlive_T"));
	offsets.DT_CSGameRulesProxy.m_iMatchStats_PlayersAlive_CT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iMatchStats_PlayersAlive_CT"));
	offsets.DT_CSGameRulesProxy.m_GGProgressiveWeaponOrderC = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_GGProgressiveWeaponOrderC"));
	offsets.DT_CSGameRulesProxy.m_GGProgressiveWeaponOrderT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_GGProgressiveWeaponOrderT"));
	offsets.DT_CSGameRulesProxy.m_GGProgressiveWeaponKillUpgradeOrderCT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_GGProgressiveWeaponKillUpgradeOrderCT"));
	offsets.DT_CSGameRulesProxy.m_GGProgressiveWeaponKillUpgradeOrderT = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_GGProgressiveWeaponKillUpgradeOrderT"));
	offsets.DT_CSGameRulesProxy.m_MatchDevice = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_MatchDevice"));
	offsets.DT_CSGameRulesProxy.m_bHasMatchStarted = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bHasMatchStarted"));
	offsets.DT_CSGameRulesProxy.m_TeamRespawnWaveTimes = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_TeamRespawnWaveTimes"));
	offsets.DT_CSGameRulesProxy.m_flNextRespawnWave = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_flNextRespawnWave"));
	offsets.DT_CSGameRulesProxy.m_nNextMapInMapgroup = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nNextMapInMapgroup"));
	offsets.DT_CSGameRulesProxy.m_nEndMatchMapGroupVoteOptions = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nEndMatchMapGroupVoteOptions"));
	offsets.DT_CSGameRulesProxy.m_bIsDroppingItems = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_bIsDroppingItems"));
	offsets.DT_CSGameRulesProxy.m_iActiveAssassinationTargetMissionID = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_iActiveAssassinationTargetMissionID"));
	offsets.DT_CSGameRulesProxy.m_fMatchStartTime = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_fMatchStartTime"));
	offsets.DT_CSGameRulesProxy.m_szTournamentEventName = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_szTournamentEventName"));
	offsets.DT_CSGameRulesProxy.m_szTournamentEventStage = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_szTournamentEventStage"));
	offsets.DT_CSGameRulesProxy.m_szTournamentPredictionsTxt = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_szTournamentPredictionsTxt"));
	offsets.DT_CSGameRulesProxy.m_nTournamentPredictionsPct = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nTournamentPredictionsPct"));
	offsets.DT_CSGameRulesProxy.m_szMatchStatTxt = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_szMatchStatTxt"));
	offsets.DT_CSGameRulesProxy.m_nGuardianModeWaveNumber = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nGuardianModeWaveNumber"));
	offsets.DT_CSGameRulesProxy.m_nGuardianModeSpecialKillsRemaining = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nGuardianModeSpecialKillsRemaining"));
	offsets.DT_CSGameRulesProxy.m_nGuardianModeSpecialWeaponNeeded = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nGuardianModeSpecialWeaponNeeded"));
	offsets.DT_CSGameRulesProxy.m_nHalloweenMaskListSeed = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_nHalloweenMaskListSeed"));
	offsets.DT_CSGameRulesProxy.m_numGlobalGiftsGiven = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_numGlobalGiftsGiven"));
	offsets.DT_CSGameRulesProxy.m_numGlobalGifters = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_numGlobalGifters"));
	offsets.DT_CSGameRulesProxy.m_numGlobalGiftsPeriodSeconds = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_numGlobalGiftsPeriodSeconds"));
	offsets.DT_CSGameRulesProxy.m_arrFeaturedGiftersAccounts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_arrFeaturedGiftersAccounts"));
	offsets.DT_CSGameRulesProxy.m_arrFeaturedGiftersGifts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_arrFeaturedGiftersGifts"));
	offsets.DT_CSGameRulesProxy.m_arrProhibitedItemIndices = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_arrProhibitedItemIndices"));
	offsets.DT_CSGameRulesProxy.m_numBestOfMaps = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_numBestOfMaps"));
	offsets.DT_CSGameRulesProxy.m_arrTournamentActiveCasterAccounts = NetVarManager::GetOffset(tables, XORSTR("DT_CSGameRulesProxy"), XORSTR("m_arrTournamentActiveCasterAccounts"));

	offsets.DT_BRC4Target.m_bBrokenOpen = NetVarManager::GetOffset(tables, XORSTR("DT_BRC4Target"), XORSTR("m_bBrokenOpen"));
	offsets.DT_BRC4Target.m_flRadius = NetVarManager::GetOffset(tables, XORSTR("DT_BRC4Target"), XORSTR("m_flRadius"));

	offsets.DT_Dronegun.m_vecAttentionTarget = NetVarManager::GetOffset(tables, XORSTR("DT_Dronegun"), XORSTR("m_vecAttentionTarget"));
	offsets.DT_Dronegun.m_vecTargetOffset = NetVarManager::GetOffset(tables, XORSTR("DT_Dronegun"), XORSTR("m_vecTargetOffset"));
	offsets.DT_Dronegun.m_iHealth = NetVarManager::GetOffset(tables, XORSTR("DT_Dronegun"), XORSTR("m_iHealth"));
	offsets.DT_Dronegun.m_bHasTarget = NetVarManager::GetOffset(tables, XORSTR("DT_Dronegun"), XORSTR("m_bHasTarget"));

	offsets.DT_PhysPropLootCrate.m_bRenderInPSPM = NetVarManager::GetOffset(tables, XORSTR("DT_PhysPropLootCrate"), XORSTR("m_bRenderInPSPM"));
	offsets.DT_PhysPropLootCrate.m_bRenderInTablet = NetVarManager::GetOffset(tables, XORSTR("DT_PhysPropLootCrate"), XORSTR("m_bRenderInTablet"));
	offsets.DT_PhysPropLootCrate.m_iHealth = NetVarManager::GetOffset(tables, XORSTR("DT_PhysPropLootCrate"), XORSTR("m_iHealth"));
	offsets.DT_PhysPropLootCrate.m_iMaxHealth = NetVarManager::GetOffset(tables, XORSTR("DT_PhysPropLootCrate"), XORSTR("m_iMaxHealth"));
	offsets.DT_BaseAnimating.m_nSequence = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nSequence"));
	offsets.DT_BaseAnimating.m_bClientSideAnimation = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_bClientSideAnimation"));
	offsets.DT_BaseAnimating.m_nSkin = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nSkin"));
	offsets.DT_BaseAnimating.m_nBody = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nBody"));
	offsets.DT_BaseAnimating.m_flPoseParameter = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_flPoseParameter"));
	offsets.DT_BaseAnimating.m_nForceBone = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nForceBone"));
	offsets.DT_BaseAnimating.m_nHitboxSet = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nHitboxSet"));
	offsets.DT_BaseAnimating.m_nMuzzleFlashParity = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_nMuzzleFlashParity"));
	offsets.DT_BaseAnimating.m_hLightingOrigin = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_hLightingOrigin"));
	offsets.DT_BaseAnimating.m_bClientSideFrameReset = NetVarManager::GetOffset(tables, XORSTR("DT_BaseAnimating"), XORSTR("m_bClientSideFrameReset"));
}
