modded class MissionServer extends MissionBase
{
    ref ServerLogsSettings m_ActiveConfig;
    DeutscheBohrmaschineLogs DBMLogger;
    void MissionServer()
	{
		 if(GetGame().IsServer())
		 {
			m_ServerLogsConfig = null;
			GetServerLogsConfig();
		 }
	}
    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
        
        super.InvokeOnConnect( player, identity );
        if(!player)
            return;
        m_ActiveConfig = ServerLogsSettings.Load();
		if(m_ActiveConfig.LogActionInvokeOnConnect != 1)
			return;
        DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
        vector playerPos;
        playerPos = player.GetPosition();
        DBMLogger.LogJson(identity.GetName(), identity.GetPlainId(), playerPos, "logged in", playerPos);
	}

    override void InvokeOnDisconnect( PlayerBase player )
	{
		super.InvokeOnDisconnect( player );
        if(!player)
            return;
        if(m_ActiveConfig.LogActionInvokeOnDisconnect != 1)
			return;
        PlayerIdentity playerId;
		playerId = PlayerIdentity.Cast(player.GetIdentity());
        DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
        DBMLogger.LogJson(playerId.GetName(), playerId.GetPlainId(), player.GetPosition(), "logged out", player.GetPosition());
	}
};
modded class MissionGameplay
{
    void MissionGameplay()
    {
        if (GetGame().IsServer()) 
        {
            m_ServerLogsConfig = null;
            GetServerLogsConfig();
        }	
    }
};
