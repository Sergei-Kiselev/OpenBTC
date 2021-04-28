#pragma once
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

class RawInput {
public:
	/* Future Development */
	/* End FD */
	std::string MerkleRootHash;
	int BtcClientVersion = 2;
	std::string PreviousBlockHash;
};