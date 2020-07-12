/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sstream>
#include <fstream>
#include <iostream>
#include "../include/Intelligentpreter.hpp"

// Libraries
#include "../Library/FileSystemPlusPlus.h"
#include "../Library/Colorized.hpp"
#include "../Library/StringTools.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

FIntelligentpreter::FIntelligentpreter() { }
FIntelligentpreter::~FIntelligentpreter() { }

int pr_check;
int check;
int intest;
int load;
std::string inp;
std::string loadstr;
std::string test;
std::string alltext;
std::string linebyline;


// Get Between String    
void 
FIntelligentpreter::GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {  
    int start = oStr.find(sStr1);   
    if (start >= 0) {       
      std::string tstr = oStr.substr(start + sStr1.length());        
      int stop = tstr.find(sStr2);      
      if (stop >1)          
        rStr = oStr.substr(start + sStr1.length(), stop);
      else
        rStr ="error";  
    }
    else
       rStr = "error"; 
}    

std::string 
FIntelligentpreter::EraseAllSubString(std::string & mainString, const std::string & erase) {
    size_t pos = std::string::npos;
    while((pos = mainString.find(erase)) != std::string::npos) {
        mainString.erase(pos, erase.length());
    }
    return mainString;
} 

bool
FIntelligentpreter::FindObject(std::string object, std::string find) {
	if(object.find(find) == 0) {
		return true;
	} else {
		return false;
	}
}

/*
	!-> (print)
	:>_ (begin)	
	_<:>: (end)
	~ (number)
	~+ (1)
	~++(2)
	~+++ (3)
	~++++ (4)
	~+++++ (5)
	~++++++ (6)
	~+++++++ (7)
	~++++++++ (8)
	~+++++++++ (9)
	~++++++++++ (10)
	
	~ (0)
	+~ (-1)
	++~ (-2)
	+++~ (-3)
	++++~ (-4)
	+++++~ (-5)
	++++++~ (-6)
	+++++++~ (-7)
	++++++++~ (-8)
	+++++++++~ (-9)
	++++++++++~ (-10)
	
	!->:>_^>4<^_<:
	!->:>_<\>"4"</>_<:>:
	!->:>__<:>:
	
	[!->:>_^> ? <^_<:] ?* (~++++++++++++++++++++++++++++++++++++++++++++++++++) 
	*? >*!->:>_^>(~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)<*>(~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)<^_<:
*/

std::string 
FIntelligentpreter::AsciiGen(int len) {
	std::string rtr = "~";
	for(int i = 0; i != len; i++) {
		rtr.append("+");
	}
	return rtr;
}

void 
FIntelligentpreter::FlaScriptInterpreter(std::string file) {
	std::string line;
    	std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    	if(readfile.is_open()) {
        while (std::getline(readfile, line)) { // !->:>_^>119<^_<:
      	if(line.length() != 0) {
      		
      		// !~ Single comment line in FreeBrain
      		if(line[1] == '!~') {
      			line.erase();
      		}
      
      	 	if(FindObject(line, "!->") == true) {
      		 	if(FindObject(line, "!->:>_") == true) {
				if(stringtools::GetBetweenString(line, ":>_^>", "<^_<:") != "error") {
				std::string assign = stringtools::GetBetweenString(line, ":>_^>", "<^_<:");
					if(assign[0] == '~') {
						int value = EraseAllSubString(assign, "~").length();
						printf("%c", value);
					} else {
						char c = assign[0];
						std::cout << "print";
    						printf("%c", c);
					}
				}
			}
       		 }
        	
       		if(FindObject(line, "[") == true) {
        		std::string assign = stringtools::GetBetweenString(line, "[", "]");
        		if(assign != "error") {
        			if(FindObject(assign, "!->:>_^>") == true) {
        			std::string btw = stringtools::GetBetweenString(assign, "^>", "<^");
        			if(btw != "error") {
        				if(btw == " ? ") {
        				assign = stringtools::GetBetweenString(line, "?* (", ") *?");
        					if(assign != "error") {
        					int value = EraseAllSubString(assign, "~").length();
        						if(value == 50) {
        							assign = stringtools::GetBetweenString(line, "*? !->:>_^>(" , ")<*>");
        							if(assign != "error") {
        								value = EraseAllSubString(assign, "~").length();
        								if(value == 92) {
        								assign = stringtools::GetBetweenString(line, "<*>(", ")<^_<:");
        									if(assign != "error") {
        									value = EraseAllSubString(assign, "~").length();
        										if(value == 110) {
        										printf("\n");
        										} else if(value == 111) {
        										printf("add ( for assign.\n");
        										} else {
											printf("value variable not equal with n\n");        												}
        									} else if(value == 93) {
        										printf("add ( for assign.\n");
        									} else {
        										printf("assign equal with error\n");
        									}
        								} else {
        									printf("value variable not equal with slash (\\)\n");
        								}
        								}
        							}
        						}	
        					}
        				}
        			}
        		}	
      		}	
        			
		if(line[0] == '~') {
			line = EraseAllSubString(line, "~");
			int value = EraseAllSubString(line, " ").length();
			std::cout << value;
		} 
			
		if(line.back() == '~') {
			line = EraseAllSubString(line, "~");
			int value = -(EraseAllSubString(line, " ").length());
			std::cout << value;
		}
	} else {
		
	}
	}
}
}
