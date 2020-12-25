modded class ActionDismantlePart : ActionContinuousBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnFinishProgressServer( ActionData action_data )
	{	
		super.OnFinishProgressServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionDismantlePart != 1)
				return;

			
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase Dismantler = PlayerBase.Cast(action_data.m_Player);
			ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
			ConstructionPart construction_part = construction_action_data.GetTargetPart();
			PlayerIdentity dismantlerid;
			vector dismantlerpos;
			vector objpos;
			objpos = action_data.m_Target.GetObject().GetPosition();

			dismantlerid    = PlayerIdentity.Cast(Dismantler.GetIdentity());
			dismantlerpos   = Dismantler.GetPosition();
			DBMLogger.LogJson(dismantlerid.GetName(), dismantlerid.GetPlainId(), dismantlerpos, "dismantled " + construction_part.GetPartName(), objpos);
		}
	}
	override string GetAdminLogMessage(ActionData action_data)
	{
		DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
		PlayerBase Dismantler = PlayerBase.Cast(action_data.m_Player);
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		PlayerIdentity dismantlerid;
		vector dismantlerpos;
		vector objpos;
		objpos = action_data.m_Target.GetObject().GetPosition();

		dismantlerid    = PlayerIdentity.Cast(Dismantler.GetIdentity());
		dismantlerpos   = Dismantler.GetPosition();
		DBMLogger.LogJson(dismantlerid.GetName(), dismantlerid.GetPlainId(), dismantlerpos, "dismantled " + construction_part.GetPartName(), objpos);
		return " dismantled " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
};