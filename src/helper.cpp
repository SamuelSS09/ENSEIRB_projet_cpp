#include "helper.h"


namespace helper{

	std::vector<std::string> split_string(const std::string& s, char delimiter){

		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, delimiter))
		{
		  tokens.push_back(token);
		}
		return tokens;
	}

}
