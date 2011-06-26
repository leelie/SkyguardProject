//************************************
// File:	Log.h
// Path:	/src/shared/
// Author:  Patryk Mirecki
// Description:  Basic interface for creating logs
// Complementation: 80%
// To-Do:	[Thread Support]
//************************************
#ifndef LOG_H
#define LOG_H
#include "defines.h"
#include "Common.h"
#include <fstream>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

enum LogLevels{
	BASIC_LOG_LEVEL = 0,
	DEBUG_LOG_LEVEL = 1,
	BOTH_LOG_LEVELS = 2
};

enum LogFiles{
	BASIC_FILE,
	DEBUG_FILE,
	ALL_FILES
};

class CLog
{
private: 
	void OpenLogFile(LogFiles rLogFile);
	void CloseLogFiles();
	string LogTime();
	LogLevels mLogLevel;
	ofstream mBasicLogFile;
	ofstream mDebugLogFile;
public:
	CLog();
	CLog(LogLevels rLogLevel);
	~CLog(void);
	void Log(char *rMsg);
	void BasicLog(char* rMsg);
	void DebugLog(char* rMsg);
};

extern CLog Log;

#define BASIC_LOG(...) Log.BasicLog(__VA_ARGS__);
#define DEBUG_LOG(...) Log.DebugLog(__VA_ARGS__);     

#endif