modded class PluginManager
{
	//=================================
	// Init
	//=================================
	override void Init()
	{	
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		if (GetGame().IsServer())
		{
			RegisterPlugin( "DeutscheBohrmaschineLogs",						false, 	true );
		}
		super.Init();
	}
};