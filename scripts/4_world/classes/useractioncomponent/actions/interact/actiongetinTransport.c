modded class ActionGetInTransport: ActionBase
{
    DeutscheBohrmaschineLogs DBMLogger;
	ref ServerLogsSettings m_ActiveConfig;

    override void OnEndServer( ActionData action_data )
    {
        super.OnEndServer(action_data);

        if(GetGame().IsServer())
        {
           m_ActiveConfig = ServerLogsSettings.Load();
			if(m_ActiveConfig.LogActionGetOutOfTransport != 1)
				return;
			PlayerBase player = PlayerBase.Cast(action_data.m_Player);
			PlayerIdentity playerid;
			vector playerpos;
			playerid    = PlayerIdentity.Cast(player.GetIdentity());
			playerpos   = player.GetPosition();

			DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
			DBMLogger.LogJson(playerid.GetName(), playerid.GetPlainId(), playerpos, "Got into a vehicle", playerpos);
        }
    }
};