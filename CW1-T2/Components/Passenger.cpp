#include "stdafx.h"
#include "Passenger.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
std::string Passenger::details[3] = { "Passport Number:", "Full Name: ", "Seat Number: "};

Passenger::Passenger()
{
}

Passenger::Passenger(std::string passportNumber, std::string fullName, std::string seatNumber, bool checkedIn)
{
	this->passportNumber = passportNumber;
	this->fullName = fullName;
	this->seatNumber = seatNumber;
	this->checkedIn = checkedIn;

	this->next = NULL;
	this->key = " ";
	BP = new BoardingPass(" ", " ", " ", " ", " ", " ", " ");
}

Passenger::~Passenger()
{
}
