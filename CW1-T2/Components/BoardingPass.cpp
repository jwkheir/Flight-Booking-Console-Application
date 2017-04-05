#include "stdafx.h"
#include "BoardingPass.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
BoardingPass::BoardingPass(std::string fullName, std::string seatNumber, std::string From, std::string To, std::string FlightNo, std::string boarding, std::string departue)
{
	this->fullName = fullName;
	this->seatNumber = seatNumber;
	this->From = From;
	this->To = To;
	this->FlightNo = FlightNo;
	this->boarding = boarding;
	this->departure = departue;
}

void BoardingPass::PrintBP()
{
	extString->PrintLine("Passenger Full Name: " + fullName, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("From: " + From, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("To: " + To, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Flight No: " + FlightNo, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Seat Number: " + seatNumber, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Boarding: " + boarding, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Departure: " + departure, false, false, true, true, true, 0, 1, '-');
	extString->PrintLine("Check In - Main Terminal: 1,  Gate: 1", false, false, true, true, true, 0, 1, '-');
}

BoardingPass::~BoardingPass()
{

}