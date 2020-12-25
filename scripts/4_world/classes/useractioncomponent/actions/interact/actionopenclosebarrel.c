modded class ActionOpenBarrel: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionDeployObject != 1)
				return;
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerId;
			vector playerpos;
			vector objpos;
			objpos = action_data.m_Target.GetObject().GetPosition();
			Object target_object = action_data.m_Target.GetObject();
			playerId    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			DBMLogger.LogJson(playerId.GetName(), playerId.GetPlainId(), playerpos, "opened " + target_object.GetDisplayName(), objpos);
		}
	}
};
modded class ActionOpenBarrelHoles: ActionInteractBase
{
	ref ServerLogsSettings m_ActiveConfig;
	DeutscheBohrmaschineLogs DBMLogger;
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionOpenCloseFireBarrel != 1)
				return;
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerId;
			vector playerpos;
			vector objpos;
			objpos = action_data.m_Target.GetObject().GetPosition();
			Object target_object = action_data.m_Target.GetObject();
			playerId    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			DBMLogger.LogJson(playerId.GetName(), playerId.GetPlainId(), playerpos, "opened " + target_object.GetDisplayName(), objpos);
		}
	}
};