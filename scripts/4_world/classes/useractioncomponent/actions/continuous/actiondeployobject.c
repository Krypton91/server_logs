modded class ActionDeployObject: ActionContinuousBase
{
	DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		if(GetGame().IsServer())
		{
			m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionDeployObject != 1)
				return;


			EntityAI entity_for_placing = action_data.m_MainItem;
			vector position = action_data.m_Player.GetLocalProjectionPosition();
			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			PlayerBase builder = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity builderid;
			vector builderpos;
			builderid  = PlayerIdentity.Cast(builder.GetIdentity());
			builderpos = builder.GetPosition();
			//string log = string.Format("\"%1\":\"%2\",\"%3\":\"%4\",\"%5\":\"%6\",\"%7\":\"%8\",", "name", builderid.GetName(), "steam64id", builderid.GetPlainId(), "x", builderpos[0], "y", builderpos[1]);
			//string log1 = string.Format("\"%1\":\"%2\",\"%3\":\"%4\",\"%5\":\"%6\",\"%7\":\"%8\",",	"z", builderpos[2], "reason", "placed " + entity_for_placing.GetDisplayName(), "x", position[0], "y", position[1]);
			//string log2 = string.Format("\"%1\":\"%2\"}", "z", position[2]);
			DBMLogger.LogJson(builderid.GetName(), builderid.GetPlainId(), builderpos, "placed " + entity_for_placing.GetDisplayName(), position);
			//DBMLogger.Log("{ name:" + builderid.GetName() + ", " + "(steam64id=" + builderid.GetPlainId() + ")" + "pos=<" + builderpos[0] + ", " + builderpos[1] + ", " + builderpos[2] + "> Placed a Object: " + entity_for_placing.GetDisplayName() + "(OBJ Location: <" + position[0] + ", " + position[1] + ", " + position[2] + ">");
		}
	}
};