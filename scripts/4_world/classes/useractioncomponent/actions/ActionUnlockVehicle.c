modded class ActionUnlockVehicle
{
    DeutscheBohrmaschineLogs DBMLogger;
    ref ServerLogsSettings m_ActiveConfig;
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        if(GetGame().IsServer())
        {
            m_ActiveConfig = ServerLogsSettings.Load();
            if(m_ActiveConfig.LogActionUnlockVehicleTRADER != 1)
                return;
            
            DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
            super.OnFinishProgressServer(action_data);

            PlayerIdentity playerID = action_data.m_Player.GetIdentity();
            CarScript vehicle = CarScript.Cast(action_data.m_Target.GetParent());
            vector playerpos;
            DBMLogger.LogJson(playerID.GetName(), playerID.GetPlainId(), playerpos, "unlocked", vehicle.GetPosition());
        }
    }
}