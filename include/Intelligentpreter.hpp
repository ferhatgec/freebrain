/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef INTELLIGENTPRETER_HPP
#define INTELLIGENTPRETER_HPP

#include <iostream>
#include "../Library/FileSystemPlusPlus.h"


class FIntelligentpreter {
public:
	FIntelligentpreter();
	~FIntelligentpreter();
	static bool FindObject(std::string, std::string);
	void FlaScriptInterpreter(std::string);
	void GetBtwString(std::string, std::string, std::string, std::string &);
	std::string EraseAllSubString(std::string &, const std::string &);	
	std::string AsciiGen(int);
};

#endif // INTELLIGENTPRETER_HPP
