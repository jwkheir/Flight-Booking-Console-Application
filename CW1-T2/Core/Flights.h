#pragma once
#include "Flight.h"
#include "DataManager.h"
#include "HashTable.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Flights
{
	private:
		std::vector<Flight> flights;
		std::vector<std::string> flightdata;
		std::vector<std::string> menu;
		DataManager data;
		std::vector<Flight> EnhancedBubbleSort(std::vector<Flight> data, int * compareData, int size);
		int menuItems;
		const int MAX_FLIGHTS = 13;
		const int FLIGHT_FIELDS = 5;
	public:
		HashTable<Flight> * flightTable;
	private:
		void Initialise();
		void DisplayFlightsMenu();
		void SortFlights();
	public:
		void updateFlights();
		bool AddFlights(std::vector<std::string> flightData);
		bool AddExisitingFlights();
		void ListFLights();
		void SearchForFlight(std::string prompt);
		void BoardPassenger(std::string prompt);
		void BoardAllPassengers(std::string prompt);
		void DeboardAllPassengers(std::string prompt);
		void BookFlight();
		void SetMenuItem(int menuItem);
		Flights();
		~Flights();
};

