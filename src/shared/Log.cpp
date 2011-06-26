//************************************
// File:	Log.cpp
// Path:	/src/shared/
// Author:  Patryk Mirecki
// Description:  Basic interface for creating logs
// Complementation: 80%
// To-Do:	[Thread Support]
//************************************
#include "Log.h"

CLog::CLog(void)
{

}

CLog::CLog( LogLevels rLogLevel )
{
	mLogLevel=rLogLevel;
	remove(BASIC_LOG_PATH);
	remove(DEBUG_LOG_PATH);
	BasicLog("Project: The Game.");
	BasicLog("Log type: Basic Log.");
	BasicLog("Started.");
	DebugLog("Project: The Game.");
	DebugLog("Log type: Debug Log.");
	DebugLog("Started.");
}

CLog::~CLog(void)
{
}

void CLog::OpenLogFile( LogFiles rLogFile )
{
	switch(rLogFile){
	case BASIC_FILE: mBasicLogFile.open(BASIC_LOG_PATH,fstream::app); break;
	case DEBUG_FILE: mDebugLogFile.open(DEBUG_LOG_PATH,fstream::app); break;
	case ALL_FILES:  
		mBasicLogFile.open(BASIC_LOG_PATH,fstream::app);
		mDebugLogFile.open(DEBUG_LOG_PATH,fstream::app);
		break;
	}
}

void CLog::CloseLogFiles()
{
	if(mBasicLogFile.is_open()) mBasicLogFile.close();
	if(mDebugLogFile.is_open()) mDebugLogFile.close();
}

string CLog::LogTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	time ( &rawtime );
	timeinfo = localtime(&rawtime);
	strftime (buffer,80,"%d-%m-%Y %X : ",timeinfo);
	return buffer;
}

void CLog::BasicLog( char* rMsg )
{
	if(mLogLevel==BASIC_LOG_LEVEL || mLogLevel==BOTH_LOG_LEVELS){
		OpenLogFile(BASIC_FILE);
		mBasicLogFile<<LogTime()<<' '<<rMsg<<ENDLINE;
		CloseLogFiles();

	}
}

void CLog::Log( char *rMsg )
{
	switch(mLogLevel){
	case BASIC_LOG_LEVEL: BasicLog(rMsg); break;
	case DEBUG_LOG_LEVEL: DebugLog(rMsg); break;

	}
}

void CLog::DebugLog( char* rMsg )
{
	if(mLogLevel==DEBUG_LOG_LEVEL || mLogLevel==BOTH_LOG_LEVELS){
		OpenLogFile(DEBUG_FILE);
		mDebugLogFile<<LogTime()<<' '<<rMsg<<ENDLINE;
		cout<<LogTime()<<' '<<rMsg<<ENDLINE;
		CloseLogFiles();
	}
}

CLog Log(LOG_LEVEL); //Global single log file object