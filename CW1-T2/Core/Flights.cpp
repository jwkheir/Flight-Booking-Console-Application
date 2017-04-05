#include "stdafx.h"
#include "Flights.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
Flights::Flights()
{
	menuItems = 0;
	flightdata = data.RetrieveXmlListOfListData("Flights.xml", "Flights", "Flight", "item");
	menu = data.RetrieveXmlListOfListData("FlightsMenu.xml", "Menu", "List", "menuitem");
	flightTable = new HashTable<Flight>(MAX_FLIGHTS);
}

bool Flights::AddExisitingFlights()
{
	if (AddFlights(flightdata))
	{
		return true;
	}
	return false;
}

/*
* USES THE FLIGHT DATA RETRIEVED FROM XML AND ADDED THEM TO BOTH THE 
* FLIGHTS VECTOR AND HASH TABLE OF LINKED LIST
*
* EACH FLIGHT WILL HAVE A KEY TO HASH
*/
bool Flights::AddFlights(std::vector<std::string> flightData)
{	
	std::vector<std::string> tempFlight;
	int count = 0;
	
	if (!flightData.empty())
	{
		for (int i = 0; i < (int)(flightData.size() / FLIGHT_FIELDS); i++)
		{
			for (int j = 0; j < FLIGHT_FIELDS; j++)
			{
				tempFlight.push_back(flightData[count]);
				count++;
			}
			Flight * flight = new Flight(tempFlight);
			this->flights.push_back(*flight);
			flightTable->insertItem(flight);
			tempFlight.clear();
		}
		//SortFlights();
		return true;
	}
	else{
		return false;
	}
	
}

/*
* CALLED ONCE A FLIGHT HAS BEEN UPDATED
* EASIEST WAY OF UPDATING THEM, WITHOUT SEARCH THE WHOLE TABLE
*/
void Flights::updateFlights()
{
	flightTable = nullptr;

	flightTable = new HashTable<Flight>(MAX_FLIGHTS);

	for (int i = 0; i < flights.size(); i++)
	{
		flightTable->insertItem(&flights[i]);
	}
}

//ATTEMPTED ENHANCED BUBBLE ALGORITHM TO SWAP VECTOR ITEMS BUT NO LUCK
void Flights::SortFlights()
{
	Extensions<std::vector<Flight>> extFlights;
	std::vector<Flight> sortedFlights;

	const int ten = 4;
	int * compareData = new int[ten];
	for (int i = 0; i < 4; i++)
	{
		compareData[i] = std::atoi(flights[i].STD.c_str());
	}

	//flights = EnhancedBubbleSort(flights, compareData, flights.size());
}

//std::vector<Flight> * Flights::EnhancedBubbleSort(std::vector<Flight> * data, int * compareData, int size)
//{
//
//	int count = 0;
//	bool sorted = false;
//	for (int i = 0; i < size; i++){
//		if (sorted) return data;
//		sorted = true;
//		for (int j = 0; j < (size - 1); j++)
//		{
//			count++;
//			if (std::atoi(data[j]->STD.c_str()) > std::atoi(&data[j + 1]->STD.c_str())){
//				Flight swap = data[i];
//				data[i] = data[j];
//				data[j] = swap;
//				sorted = false;
//			}
//		}
//	}
//	return data;
//}


void Flights::ListFLights()
{
	System<User>::system->Display();
	extString->PrintLine("CURRENT FLIGHTS: ", false, false, true, true, true, 2, 0, '=');
	for (int i = 0; i < flights.size(); i++)
	{
		flights[i].ListFLight(&flights[i]);
		menuItems++;
	}

	DisplayFlightsMenu();
}

/*
* REQUIRES A FLIGHT NUMBER THAT IS THE HASH VALUE THAT IS USED TO LOOK UP A FLIGHT IN THE HASH TABLE
*/
void Flights::SearchForFlight(std::string prompt)
{
	updateFlights();
	System<User>::system->Display();
	extString->PrintLine("FLIGHT SEARCH: ", false, false, true, true, true, 2, 0, '=');
	menuItems = flights.size();
	extString->PrintLine(prompt + " \n\nor enter \"3\" to return to the Main Menu: ", false, true, true, false, false, 0, 1, '-');
	std::string key = extString->returnInput("Flight No (IN CAPS): ");
	
	if (key != "3")
	{
		System<User>::system->Display();
		Flight * flight = flightTable->getItemByKey(key);
		if (flight != nullptr)
		{
			extString->PrintLine("FLIGHT FOUND: ", false, false, false, false, true, 0, 1, '-');
			flight->ListFLight(flight);
			DisplayFlightsMenu();
		}
		else
		{
			SearchForFlight("We Could not find flight: " + key + " - Please try again: ");
		}
	}
	else
	{
		System<User>::system->Display();
		System<User>::system->Menu();
	}
}

/*
* REQUIRES A FLIGHT NUMBER, WHICH THEN ALLOWS TO FIND A PASSENGER, WHICH THEN ALLOWS FOR AN ASSIGNMENT TO OCCUR
* fOR PRIORITY QUEUE
*/
void Flights::BoardPassenger(std::string pt)
{
	updateFlights();
	System<User>::system->Display();
	extString->PrintLine("FLIGHT SEARCH: ", false, false, true, true, true, 2, 0, '=');
	Flight * flight;
	std::string prompt = pt;
	do
	{
		std::string key = extString->returnInput(prompt);
		flight = flightTable->getItemByKey(key);
		prompt = "We did not find flight: " + key + ", please try again: ";
	} while (!(flight != nullptr));

	System<User>::system->Display();
	extString->PrintLine("FLIGHT FOUND: ", false, false, true, true, true, 2, 0, '=');
	Passenger * pass;
	do
	{
		std::string key = extString->returnInput("Please enter the passenger's seat number: ");
		pass = flight->GetPassenger(key);
		prompt = "We did not find a passenger with the seat number: " + key + ", please try again: ";
	} while (!(pass != nullptr));

	flight->AssignPriority(pass);

	System<User>::system->Display();
	extString->PrintLine("PASSENGER BOARDED: ", false, false, true, true, true, 2, 0, '=');

	char result[1];
	do
	{
		std::strcpy(result, extString->returnInput("\n\nBoard another passenger Y/N (IN CAPS): ").c_str());
	} while (!((result[0] == 'Y') || (result[0] == 'N')));

	if (result[0] == 'Y')
	{
		BoardPassenger("Enter Flight Number: ");
	}
	else
	{
		System<User>::system->Display();
		System<User>::system->Menu();
	}
}

/*
* ASSIGNS ALL PASSENEGERS ON LOOKED UP FLIGHT A PRIORITY
*/
void Flights::BoardAllPassengers(std::string pt)
{
	updateFlights();
	System<User>::system->Display();
	extString->PrintLine("FLIGHT SEARCH: ", false, false, true, true, true, 2, 0, '=');
	Flight * flight;
	std::string prompt = pt;
	do
	{
		std::string key = extString->returnInput(prompt);
		flight = flightTable->getItemByKey(key);
		prompt = "We did not find flight: " + key + ", please try again: ";
	} while (!(flight != nullptr));

	flight->AssignAllPriority();

	System<User>::system->Display();
	extString->PrintLine("All Passengers Boarded: ", false, false, true, true, true, 2, 0, '=');

	extString->Sleep();
	System<User>::system->Display();
	System<User>::system->Menu();
}

/*
* REMOVES ALL PASSENEGERS FROM PRIORITY QUEUE
*/
void Flights::DeboardAllPassengers(std::string pt)
{
	updateFlights();
	System<User>::system->Display();
	extString->PrintLine("FLIGHT SEARCH: ", false, false, true, true, true, 2, 0, '=');
	Flight * flight;
	std::string prompt = pt;
	do
	{
		std::string key = extString->returnInput(prompt);
		flight = flightTable->getItemByKey(key);
		prompt = "We did not find flight: " + key + ", please try again: ";
	} while (!(flight != nullptr));

	bool deboarded = flight->Deboard();

	if (deboarded)
	{
		flightTable->removeItem(flight->key);
	}

	extString->PrintLine("All Passengers Deboarded: ", false, false, true, true, true, 2, 0, '=');
	extString->Sleep();
	System<User>::system->Display();
	System<User>::system->Menu();
}

void Flights::DisplayFlightsMenu()
{
	int result = 0;
	do
	{
		result = atoi(extString->returnInput("Please enter a valid menu item number OR enter 3 to return to main menu: ").c_str());
	} while (!(extInt->CompareValue(result - 1, menuItems) || (result == 3)));
	SetMenuItem(result);
}

void Flights::SetMenuItem(int menuItem)
{
	if (menuItem != 3)
	{
		flights[menuItem-1].BookFlight();
		
	}
	else
	{
		System<User>::system->Display();
		System<User>::system->Menu();
	}
}

Flights::~Flights()
{
}
