static const string Config_Directory = "$profile:ServerLogs\\";
static const string Config_Directory_json = "$profile:ServerLogs\\ServerLogsSettings.json";
class ServerLogsSettings
{
    int isLoggingActive;
    int DebugEnabled;
    int LogActionInvokeOnConnect;
    int LogActionInvokeOnDisconnect;
    int LogActionDeployObject;
    int LogActionDismantlePart;
    int LogActionCloseBarrel;
    int LogActionGetOutOfTransport;
    int LogActionGetInTransport;
    int LogActionHandleLadder;
    int LogActionOpenCloseBarrel;
    int LogActionOpenCloseFireBarrel;
    int LogActionOpenCloseFence;
    int LogActionPackTent;
	int LogActionToogleTentOpenClose;
    int LogActionLogIn;
    int LogActionLockVehicleTRADER;
    int LogActionUnlockVehicleTRADER;
    int LogActionUnlockVehicleInsideTRADER;
    int LogActionTradeTRADER;
    string ModVersion;

    void ServerLogsSettings()
    {
        
    }
    void LoadServerLogsDefaultSettings()
    {
        isLoggingActive = 1;
        DebugEnabled = 0;
        LogActionInvokeOnConnect = 1;
        LogActionInvokeOnDisconnect = 1;
        LogActionDeployObject = 1;
        LogActionDismantlePart = 1;
        LogActionCloseBarrel = 1;
        LogActionGetOutOfTransport = 1;
        LogActionGetInTransport = 1;
        LogActionHandleLadder = 1;
        LogActionOpenCloseBarrel = 1;
        LogActionOpenCloseFireBarrel = 1;
        LogActionOpenCloseFence = 1;
        LogActionPackTent = 1;
        LogActionToogleTentOpenClose = 1;
        LogActionLogIn = 1;
        LogActionLockVehicleTRADER = 1;
        LogActionUnlockVehicleTRADER = 1;
        LogActionUnlockVehicleInsideTRADER = 1;
        LogActionTradeTRADER = 1;
        ModVersion = "2.0";
        CheckConfig();
    }

    void CheckConfig()
	{
		if ( !FileExist( Config_Directory ) )
		{
			MakeDirectory( Config_Directory );
		}

		JsonFileLoader<ServerLogsSettings>.JsonSaveFile( Config_Directory_json, this );
	}
    static ref ServerLogsSettings Load()
	{
		ref ServerLogsSettings settings = new ServerLogsSettings();

		if ( FileExist( Config_Directory_json ) )
		{
			JsonFileLoader<ServerLogsSettings>.JsonLoadFile( Config_Directory_json, settings );

		} 
		else 
		{
			settings.LoadServerLogsDefaultSettings();
		}

		return settings;
	}
};
class ServerLogsBase
{
    DeutscheBohrmaschineLogs DBMLogger;
    ref ServerLogsSettings m_ActiveRandomChestConfig;
    const string actuellVersion = "2.0";

    void ServerLogsBase()
	{
		m_ActiveRandomChestConfig = ServerLogsSettings.Load();
        DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
        if(m_ActiveRandomChestConfig.ModVersion != actuellVersion)
        {
            DeleteFile(Config_Directory_json);
            DBMLogger.WriteFirstLine("[INTERNAL LOGGER ERROR]-> Please restart your Server! Your Config is outdatet! New Version (" + actuellVersion + ") Config will replace automatik after the restart");
        }
	}
};
static ref ServerLogsBase m_ServerLogsConfig;
static ref ServerLogsBase GetServerLogsConfig()
{
    if ( !m_ServerLogsConfig )
    {
         m_ServerLogsConfig = new ref ServerLogsBase();
    }
    
    return m_ServerLogsConfig;
};