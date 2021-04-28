#pragma once
#include <iostream>
#include <cstdarg>
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>

using namespace std;

string exec(string command) {
    char buffer[128];
    string result = "";
    // Open pipe to file
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    _pclose(pipe);
    return result;
}


std::string PythonExecutableName = "python";
std::string FullExecuteCommand = PythonExecutableName + " MainScraperModule.py";
std::string DefaultDriverInput[2] = { "cd PythonModules",FullExecuteCommand };
std::list<std::string> DDI(&DefaultDriverInput[0], &DefaultDriverInput[2]);

std::string PythonScrapeDriver()
{
    std::string DriverResults;
    exec(DefaultDriverInput[0]);
    exec(DefaultDriverInput[1]);
    return "0";
}