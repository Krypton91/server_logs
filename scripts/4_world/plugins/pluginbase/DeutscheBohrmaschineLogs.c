class DeutscheBohrmaschineLogs extends PluginBase
{
    ref ServerLogsSettings m_ActiveConfig;
    protected const string  m_LogPath = "$profile:/ServerLogs/Logs/";
    string m_currentLogFileName = "";
    bool isDBMDEBUGActive = true;
    FileHandle  m_FileHandler;
    FileHandle  m_FileHandler1;
    
    //TimeStamps
    int year, month, day, hour, minute, second;
	string sYear, sMonth, sDay, sHour, sMinute, sSecond, currentTime;

    void DeutscheBohrmaschineLogs()
    {
        m_ActiveConfig = ServerLogsSettings.Load();
        DBMDEBUG("DeutscheBohrmaschineLogs Started");
        if(m_ActiveConfig.isLoggingActive != 1)
            return;
        
        CheckLogPath();

        if(m_currentLogFileName == "")
        {
            m_currentLogFileName = "ServerLog" + GetTimeForLog() + ".log";
            if(FileExist(m_LogPath + m_currentLogFileName))
            {
                DeleteFile(m_LogPath + m_currentLogFileName);
            }
            //Create File......
            CreateLogFile();
        }
        
    }
    void CreateLogFile()
    {
        if(GetGame().IsServer())
        {
            m_FileHandler = OpenFile(m_LogPath + m_currentLogFileName, FileMode.WRITE);
            DBMDEBUG(m_LogPath + m_currentLogFileName);
            if(m_FileHandler != 0)
            {
                WriteFirstLine("Server Log File created");
                WriteFirstLine(m_ActiveConfig.ModVersion);
            }
            DBMDEBUG("DeutscheBohrmaschineLogs: Unable to Create Log File!");
        }
    }
    void ~DeutscheBohrmaschineLogs()
    {
        CloseFile(m_FileHandler);
    }
    void CheckLogPath()
    {
        DBMDEBUG("DeutscheBohrmaschineLogs Checking Log path...");
        if(!FileExist(m_LogPath))
        {
            DBMDEBUG("DeutscheBohrmaschineLogs Path dont exist Creating....");
            MakeDirectory(m_LogPath);
        }
        DBMDEBUG("DeutscheBohrmaschineLogs Path exist skipping....");
    }
    void DBMDEBUG(string Messsage)
    {
        if(m_ActiveConfig.DebugEnabled == 1)
            Print(Messsage);
    }
    string GetTimeForLog()
    {
            // Setting Time Variables for new file name
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			
			// Setting String for Time Variables for new file name
			sYear = year.ToString();
			
			sMonth = month.ToString();
			if (sMonth.Length() == 1)
			{
				sMonth = "0" + sMonth;
			}
			
			sDay = day.ToString();
			if (sDay.Length() == 1)
			{
				sDay = "0" + sDay;
			}
			
			sHour = hour.ToString();
			if (sHour.Length() == 1)
			{
				sHour = "0" + sHour;
			}
			
			sMinute = minute.ToString();
			if (sMinute.Length() == 1)
			{
				sMinute = "0" + sMinute;
			}
			
			sSecond = second.ToString();
			if (sSecond.Length() == 1)
			{
				sSecond = "0" + sSecond;
			}
			currentTime = "_" + sYear + "-" + sMonth + "-" + sDay + "_" + sHour + "-" + sMinute + "-" + sSecond;
            return currentTime;

    }
    string GetUnixTimeStamp()
    {

        string currentUnixTime = string.Format("{\"%1\":\"%2\",", "time", GetTimeForLogMessage());
        return currentUnixTime;
    }
    string GetTimeForLogMessage()
    {
         // Setting Time Variables for new file name
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			
			// Setting String for Time Variables for new file name
			sYear = year.ToString();
			
			sMonth = month.ToString();
			if (sMonth.Length() == 1)
			{
				sMonth = "0" + sMonth;
			}
			
			sDay = day.ToString();
			if (sDay.Length() == 1)
			{
				sDay = "0" + sDay;
			}
			
			sHour = hour.ToString();
			if (sHour.Length() == 1)
			{
				sHour = "0" + sHour;
			}
			
			sMinute = minute.ToString();
			if (sMinute.Length() == 1)
			{
				sMinute = "0" + sMinute;
			}
			
			sSecond = second.ToString();
			if (sSecond.Length() == 1)
			{
				sSecond = "0" + sSecond;
			}
			currentTime = sYear + ":" + sMonth + ":" + sDay + ":" + sHour + ":" + sMinute + ":" + sSecond;
            return currentTime;
    }
    void LogJson(string playername, string steamid, vector playerpos, string reason, vector objectpos)
    {
        string log =  string.Format("\"%1\":\"%2\",\"%3\":\"%4\",\"%5\":\"%6\",\"%7\":\"%8\",", "name", playername, "steam64id", steamid, "player_x", playerpos[0], "player_y", playerpos[1]);
		string log1 = string.Format("\"%1\":\"%2\",\"%3\":\"%4\",\"%5\":\"%6\",\"%7\":\"%8\",",	"player_z", playerpos[2], "reason", reason, "object_x", objectpos[0], "object_y", objectpos[1]);
		string log2 = string.Format("\"%1\":\"%2\"}", "object_z", objectpos[2]);
        WriteToFile(log + log1 + log2);
    }
    void Log(string text)
    {
        WriteToFile(text);
    }
    void WriteFirstLine(string text)
    {
        FPrintln(m_FileHandler, GetTimeForLogMessage() + " | " + text);
    }
    void WriteToFile(string text)
    {
        if(m_ActiveConfig.isLoggingActive != 1)
            return;
        if(text == "")
            return;
        FPrintln(m_FileHandler, GetUnixTimeStamp() + text);
    }
};