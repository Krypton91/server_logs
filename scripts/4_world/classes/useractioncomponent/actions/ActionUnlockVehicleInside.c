modded class ActionUnlockVehicleInside
{
    DeutscheBohrmaschineLogs DBMLogger;
    ref ServerLogsSettings m_ActiveConfig;
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        if(GetGame().IsServer())
        {
            m_ActiveConfig = ServerLogsSettings.Load();
            if(m_ActiveConfig.LogActionUnlockVehicleInsideTRADER != 1)
                return;
            DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
            super.OnFinishProgressServer(action_data);
            PlayerBase player = PlayerBase.Cast(action_data.m_Player);
            PlayerIdentity playerID = action_data.m_Player.GetIdentity();
            CarScript vehicle = CarScript.Cast(action_data.m_Target.GetParent());
            DBMLogger.LogJson(playerID.GetName(), playerID.GetPlainId(), player.GetPosition(), "unlocked " + vehicle.GetDisplayName(), vehicle.GetPosition());
        }
    }
}