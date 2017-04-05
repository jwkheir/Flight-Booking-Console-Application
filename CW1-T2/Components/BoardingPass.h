#pragma once
#include "stdafx.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class BoardingPass
{
private:
	//Extensions<std::string> extString;
public:
	std::string fullName;
	std::string seatNumber;
	std::string From;
	std::string To;
	std::string FlightNo;
	std::string boarding;
	std::string departure;

	BoardingPass(std::string fullName, std::string seatNumber, std::string From, std::string To, std::string FlightNo, std::string boarding, std::string departue);
	void PrintBP();
	~BoardingPass();
};

