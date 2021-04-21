#include <iostream>
#include <string>
#include <sstream>

std::string StringToHex(std::string PreString) {
  std::string iString = PreString, hString;
  int iTemp = 0;
  std::stringstream is, hs;

  is << iString; 
  is >> iTemp; // convert string to int
  hs << std::hex << iTemp; // push int through hex manipulator
  hString = hs.str(); // store hex string
  
  return hString;
}

void STHDriverInit() {
	std::string DMI;
	std::cout << "Decimal Input: ";
	std::cin >> DMI;
	
	std::string STHContainer;
	
	STHContainer = StringToHex(DMI);
	
	std::cout << STHContainer << "\n";
	
}

std::string LittleEndian(std::string InputHex) {
	int IHLen;
	IHLen = InputHex.size();
	return "pop";
}
