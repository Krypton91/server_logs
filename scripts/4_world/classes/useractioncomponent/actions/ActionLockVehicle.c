modded class ActionLockVehicle
{
    DeutscheBohrmaschineLogs DBMLogger;
    ref ServerLogsSettings m_ActiveConfig;
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        if(GetGame().IsServer())
        {
            m_ActiveConfig = ServerLogsSettings.Load();
            if(m_ActiveConfig.LogActionLockVehicleTRADER != 1)
                return;
            DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
            vector playerpos;
            PlayerIdentity playerID = action_data.m_Player.GetIdentity();
            CarScript vehicle = CarScript.Cast(action_data.m_Target.GetParent());
            DBMLogger.LogJson(playerID.GetName(), playerID.GetPlainId(), playerpos, "locked " + vehicle.GetDisplayName(), vehicle.GetPosition());
        }
    }
}