#include "MainFunction.h"

void writeLog(std::string log, int log_key)
{
	//////////////////////////
	//	log_key = 0: error;
	//	log_key = 1: succes;
	//////////////////////////
	std::cout << "\n";
	if (log_key == 1)
	{
		std::cout << "++++";
	}
	else
	{
		std::cout << "----";
	}

	std::cout << log;
	
}

void writeLog(std::stringstream &ss, int log_key)
{
	std::string log;
	ss >> log;
	std::cout << "\n";
	if (log_key == 1)
	{
		std::cout << "++++";
	}
	else
	{
		std::cout << "----";
	}

	std::cout << log;
}