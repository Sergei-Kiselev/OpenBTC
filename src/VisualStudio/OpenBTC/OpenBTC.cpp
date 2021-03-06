#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include "rawinput.h"
#include "ScrapeCaller.h"
#include "sha256.h"
#include "format.h"
#include "moduledriver.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* Codes:
0: Exited Normally , 1: TypeError
 */

using namespace std;

int main(int argc, char** argv) {
	/* string input = "grape"; */
	/* string output1 = sha256(input); */
	cout << "Bitcoin Miner C++ Version 1\n";
	cout << "\n\n";

	int PythonExecWarn = 1;
	if (PythonExecWarn == 1) {
		cout << "WARNING: Default Python Executable Set To " << PythonExecutableName << ".\n";
		cout << "Please Ensure that this is the correct Executable Name\n";
		cout << "To change, set moduledriver.h/LocalPDD.PythonExecutable to your executable.\n";
		cout << "Do the same with ScrapeCaller.h/PythonExecutableName\n";
		cout << "To Disable this warning, build with int PythonExecWarn as 0.\n\n\n";
	}

	RawInput RWI;
	cout << "Merkle Root: ";
	cin >> RWI.MerkleRootHash;

	STHDriverInit();

	CollectiveDriverData CollectiveDriverDataInstance;

	if (CollectiveDriverDataInstance.ScraperDriverReturnType == "string") {
		std::string ScraperDriverReturns;
		ScraperDriverReturns = ScraperDriver();
		cout << "Displaying finished logs from Scraper Using ScraperDriver\n";
		cout << ScraperDriverReturns;
	}
	else if (CollectiveDriverDataInstance.ScraperDriverReturnType == "int") {
		int ScraperDriverReturns;
		ScraperDriverReturns = IntScraperDriver();
		cout << "Displaying finished logs from Scraper Using INTScraperDriver\n";
		cout << ScraperDriverReturns;
	}
	else {
		cout << "Local Type Error from class main.cpp : CollectiveDriverDataInstance.ScraperDriverReturnType -> (CollectiveDriverData.ScraperReturnType) was not a valid or compatible type of {string,int}.\n";
		cout << "Exiting With Code '1' (TypeError)\n";
		int ErrorCode = 1;
		_Exit(ErrorCode);
	}



	return 0;
}