#include <iostream>
#include <string>
#include <list>

class PrivateDriverData {
	public:
		std::string PythonExecutable = "lolpython";
		std::string exec(std::string command) {
            char buffer[128];
            std::string result = "";
            // Open pipe to file
            FILE* pipe = popen(command.c_str(), "r");
            if (!pipe) {
                return "popen failed!";
            }
            while (!feof(pipe)) {
                if (fgets(buffer, 128, pipe) != NULL)
                    result += buffer;
            }
            pclose(pipe);
            return result;
        }
};


int IntScraperDriver() {
	return 0;
}

std::string ScraperDriver() {
	/* Collective Driver Data Instance */
	PrivateDriverData LocalPDD;
	
	std::string ScraperExecuteData = LocalPDD.PythonExecutable + " ScraperModule.py";
	
	return LocalPDD.exec(ScraperExecuteData);
}

class CollectiveDriverData {
	public:
		std::string ScraperDriverReturnType = "string";
};
