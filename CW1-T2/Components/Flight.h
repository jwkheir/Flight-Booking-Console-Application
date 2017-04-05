#pragma once
#include "Passenger.h"
#include "Stack.h"
#include "PriorityQueue.h"
#include "HashTable.h"
#include "stdafx.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Flight
{

private:
	Stack<Passenger> * passengers;
	Passenger * tempPassenger;
	std::vector<std::string> flightMenu;
	DataManager dataM;
	int id;
	static int instances;
	PriorityQueue * priorityQueue;
	HashTable<Passenger> * passengerTable;
public:
	std::string STD;
	std::string flight;
	std::string destination;
	std::string checkIn;
	std::string status;
	Flight * next;
	std::string key;
	int availableSeats;
	int allocatedSeats;
private:
	const int MAX_SEATS = 2;
	void Sleep();
	void ConfirmBooking(Passenger * passenger);
	void CancelBooking();
public:
	Flight();
	Flight(std::vector<std::string> data);
	Passenger * GetPassenger(std::string key);
	void AssignPriority(Passenger * pass);
	void AssignAllPriority();
	bool Deboard();
	void ListFLight(Flight * flight);
	Flight * BookFlight();
	void AmendBooking(Passenger * passenger);
	void DisplayFlightMenu();
	void SetMenuItem(int item);
	Flight& operator=(const Flight& element);
};

