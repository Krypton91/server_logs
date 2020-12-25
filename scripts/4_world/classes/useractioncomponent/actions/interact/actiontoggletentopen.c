modded class ActionToggleTentOpen: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionToogleTentOpenClose != 1)
				return;
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			Object targetObject = action_data.m_Target.GetObject();

			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerid;
			vector playerpos;
			playerid    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			DBMLogger.LogJson(playerid.GetName(), playerid.GetPlainId(), playerpos, "opened/closed " + targetObject.GetDisplayName(), targetObject.GetPosition());
		}
	}
};