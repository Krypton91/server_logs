class CfgPatches
{
	class server_logs 
	{
		units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
			"DZ_Data",
			"Trader"
        };
	};
};

class CfgMods
{
	class server_logs
	{
		dir = "server_logs";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "serverlogs";
		credits = "DeutscheBohrmaschine.de";
		author = "Krypton91,Tkone2806";
		authorID = "0"; 
		version = "1.0";
		extra = 0;
		type = "mod";
		
		dependencies[] = {"Game", "World","Mission"};
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"server_logs/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"server_logs/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"server_logs/scripts/5_Mission"};
			};
		};
	};
};