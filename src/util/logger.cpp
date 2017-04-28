#include "logger.h"

bool Logger::log(std::string str, Level level) {
    std::fstream logfile ("MarketSimulationServer.log", std::fstream::out);
    std::string levelName = toString(level);

    if (logfile.is_open()) {
        time_t currentTime = time(NULL);
        struct tm *tm = localtime(&currentTime);
        str = "[" + levelName + "] " + "[" + std::to_string(tm->tm_hour) + ":" + std::to_string(tm->tm_min) + ":" + std::to_string(tm->tm_sec) + "] " + str + "\n";
        logfile << str;
        return true;
    } else {
        return false;
    }
}

std::string Logger::toString(Level level) {
    std::string levelName;

    switch(level) {
        case ERROR:
            levelName = "ERROR";
        case WARN:
            levelName = "WARN";
        case DEBUG:
            levelName = "DEBUG";
        case INFO:
            levelName = "INFO";
    }

    return levelName;
}
