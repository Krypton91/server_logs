modded class ActionPackTent: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionPackTent != 1)
				return;
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			Object targetObject = action_data.m_Target.GetObject();
			vector target_object_pos = targetObject.GetPosition();
		
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerid;
			vector playerpos;
			playerid    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			DBMLogger.LogJson(playerid.GetName(), playerid.GetPlainId(), playerpos, "packed " + targetObject.GetDisplayName(), target_object_pos);
		}
	}
};