modded class DayZPlayerImplement
{
    DeutscheBohrmaschineLogs DBMLogger;
    ref ServerLogsSettings m_ActiveConfig;
    override void traderServerLog(string message)
	{
        //super.traderServerLog(string message);
        DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
        m_ActiveConfig = ServerLogsSettings.Load();
        if(m_ActiveConfig.LogActionTradeTRADER != 1)
            return;
		super.traderServerLog(message);
        vector playerpos;
        DBMLogger.LogJson(GetIdentity().GetName(), GetIdentity().GetPlainId(), playerpos, message, playerpos);
	}
};