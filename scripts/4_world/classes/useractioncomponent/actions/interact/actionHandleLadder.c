
modded class ActionEnterLadder: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnStartServer( ActionData action_data )
	{
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionHandleLadder != 1)
				return;
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerid;
			vector playerpos;
			playerid    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			DBMLogger.LogJson(playerid.GetName(), playerid.GetPlainId(), playerpos, "Interacted with Ladder", playerpos);
		}
	}
};