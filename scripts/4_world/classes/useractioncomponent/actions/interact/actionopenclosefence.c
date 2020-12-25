modded class ActionCloseFence: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionOpenCloseFence != 1)
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
			string DP_Name = target_object.GetDisplayName();
			if(DP_Name == "#STR_CFGVEHICLES_CONSTRUCTION_PART_GATE")
			{
				//Replace shit from BI to Human Readable text :D
				DP_Name.Replace("#STR_CFGVEHICLES_CONSTRUCTION_PART_GATE","Vanilla Gate");
			}
			DBMLogger.LogJson(playerId.GetName(), playerId.GetPlainId(), playerpos, "closed " + DP_Name, objpos);
		}
	}
};
modded class ActionOpenFence: ActionInteractBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionOpenCloseFence != 1)
				return;
			
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerId;
			vector playerpos;
			vector objpos;
			objpos = action_data.m_Target.GetObject().GetPosition();
			playerId    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();
			Object target_object = action_data.m_Target.GetObject();
			string DP_Name = target_object.GetDisplayName();
			if(DP_Name == "#STR_CFGVEHICLES_CONSTRUCTION_PART_GATE")
			{
				//Replace shit from BI to Human Readable text :D
				DP_Name.Replace("#STR_CFGVEHICLES_CONSTRUCTION_PART_GATE","Vanilla Gate");
			}
			DBMLogger.LogJson(playerId.GetName(), playerId.GetPlainId(), playerpos, "opened " + DP_Name, objpos);
		}
	}
};