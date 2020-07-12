/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include "../include/Intelligentpreter.hpp"
#include "../include/FreeBrain.hpp"

#include "../Library/FileSystemPlusPlus.h"

#define EXIT_SUCCESS 0

void HelpFunction() {
	printf("Fegeya FreeBrain\nfreebrain --b : Interprets your FreeBrain code\nfreebrain --g  <input> : Generates FreeBrain key code with input number\n");
}

int main(int argc, char** argv) {
	FIntelligentpreter interp;
	if(argc > 1) {
		for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);
			if(arg.substr(0, 2) == "--") {
				if(arg == "--help") {
					HelpFunction();
					exit(EXIT_SUCCESS);
				} else if(arg == "--h") {
					HelpFunction();
					exit(EXIT_SUCCESS);
				} else if(arg == "--b" || arg == "--build") {
					std::getline(std::cin, arg);
					interp.FlaScriptInterpreter(arg);
				} else if(arg == "--g" || arg == "--gen") {
					int a;
					std::cin >> a;
					std::cout << interp.AsciiGen(a);
				}
			} else {
				HelpFunction();
			}
		}
        } else {
        	HelpFunction();
        }
        return EXIT_SUCCESS;
}
