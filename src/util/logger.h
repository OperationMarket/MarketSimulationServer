#pragma once
#include <string>
#include <fstream>
#include <time.h>

enum Level {
    INFO,
    DEBUG,
    WARN,
    ERROR
};

class Logger {
public:
    static bool log(std::string str, Level level);

private:
    static std::string toString(Level level);
};