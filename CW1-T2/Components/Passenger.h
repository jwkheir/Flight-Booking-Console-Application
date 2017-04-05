#pragma once
#include "BoardingPass.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Passenger
{
public:
	std::string passportNumber;
	std::string fullName;
	std::string seatNumber;
	static std::string details[3];
	bool checkedIn;
	BoardingPass * BP;
	int priorityKey;
	Passenger * next;
	std::string key;
public:
	Passenger();
	Passenger::Passenger(std::string passportNumber, std::string fullName, std::string seatNumber, bool checkedIn);
	~Passenger();
};

