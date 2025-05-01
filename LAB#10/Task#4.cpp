#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void logSystemStartup()
{
    ofstream logFile("system_log.txt", ios::app);

    if (!logFile.is_open())
    {
        cerr << "errror" << endl;
        return;
    }

    time_t now = time(nullptr);//copied from github 
    tm *localTime = localtime(&now);//copied from github 
    char timeStr[20];//copied from github 
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localTime); //copied from github 
    logFile << "system started; " << timeStr << endl;
    logFile.close();
}

int main()
{
    logSystemStartup();
    return 0;
}