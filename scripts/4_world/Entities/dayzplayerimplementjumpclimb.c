/*modded class DayZPlayerImplementJumpClimb
{
	DeutscheBohrmaschineLogs DBMLogger;
	private bool Climb(SHumanCommandClimbResult pClimbRes)
	{
		DBMLogger = DeutscheBohrmaschineLogs.Cast(GetPlugin(DeutscheBohrmaschineLogs));
        PlayerIdentity playerId;
		vector playerpos;
        playerpos   = m_Player.GetPosition();
		playerId    = PlayerIdentity.Cast(m_Player.GetIdentity());
		int climbType = GetClimbType(pClimbRes.m_fClimbHeight);
		string climb_Typ = "";	
		if( climbType != -1 )
		{
			m_Player.StartCommand_Climb(pClimbRes, climbType);
			m_Player.StopHandEvent();
			switch(climbType)
			{
				case 0:
					climb_Typ = "vaulted";
					break;
				case 1:
					climb_Typ = "vaulted";
					break;
				case 2: 
					climb_Typ = "climbed";
					break;
				default:
					climb_Typ = "Unkown climb Typ";
					break;
			}
			if(GetGame().IsServer())
			{
				DBMLogger.Log("Spieler: " + playerId.GetName() + "[Steam64ID:" + playerId.GetPlainId() + "] " + "Playerpos X:" + playerpos[0] + " Y:" + playerpos[1] + " Z:" + playerpos[2] + climb_Typ);
			}
		}
		
		return climbType != -1;
	}
}
*/

