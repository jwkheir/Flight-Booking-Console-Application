#include "stdafx.h"
#include "Flight.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
int Flight::instances = 0;

Flight::Flight()
{

}
Flight& Flight::operator=(const Flight& element){
	return *this;
};
Flight::Flight(std::vector<std::string> data)
{
	this->instances++;
	this->STD = data[0];
	this->flight = data[1];
	this->destination = data[2];
	this->checkIn = data[3];
	this->status = data[4];
	this->next = NULL;
	this->key = flight;
	this->id = instances;
	passengers = new Stack<Passenger>(MAX_SEATS);
	for (int i = 0; i < MAX_SEATS; i++)
	{
		Passenger * passenger = new Passenger(" ", " ", std::to_string(i), false);
		passengers->Push(*passenger);
	}

	this->priorityQueue = new PriorityQueue(MAX_SEATS);

	this->availableSeats = MAX_SEATS;
	this->allocatedSeats = 0;

	this->flightMenu = dataM.RetrieveXmlListOfListData("FlightMenu.xml", "Menu", "List", "menuitem");
	this->passengerTable = new HashTable<Passenger>(MAX_SEATS);
}

void Flight::ListFLight(Flight * flight)
{
	extString->PrintLine("STD: " + flight->status, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Flight Number: " + flight->flight, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Destination: " + flight->destination, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Check-In: " + flight->checkIn, false, false, false, false, true, 0, 1, '-');
	extString->PrintLine("Available Seats: " + std::to_string(availableSeats), false, false, true, true, true, 0, 1, '-');
	extString->PrintLine(std::to_string(id) + ". Book This Flight (Will Automatically Check-In the passenger)", false, true, true, false, true, 0, 1, '=');
}

/*
* UPDATES STACK ITEM I.E. PASSENEGER AND INSERTS THE PASSENEGER IN THE HASH TABLE WITH THE SEAT NUMBER BEING THE HASH VALUE
*/
Flight * Flight::BookFlight()
{
	System<User>::system->Display();
	if (availableSeats > 0)
	{
		std::string details[2];

		for (int i = 0; i < 2; i++)
		{
			 details[i] = extString->returnInput("Please enter the passenger's " + Passenger::details[i] + "");
		}

		passengers->stackData[availableSeats - 1].passportNumber = details[0];
		passengers->stackData[availableSeats - 1].fullName = details[1];
		passengers->stackData[availableSeats - 1].checkedIn = true;
		passengers->stackData[availableSeats - 1].seatNumber = std::to_string(allocatedSeats);
		passengers->stackData[availableSeats - 1].priorityKey = passengers->top;
		passengers->stackData[availableSeats - 1].key = passengers->stackData[availableSeats - 1].seatNumber;
		tempPassenger = &passengers->stackData[availableSeats - 1];
		passengerTable->insertItem(tempPassenger);
		

		passengerTable->printHistogram();
		availableSeats--;
		allocatedSeats++;
		DisplayFlightMenu();
	}
	else
	{
		extString->PrintLine("Sorry, No Seats are available for this flight", false, false, false, false, true, 0, 1, '-');
		Sleep();
		System<User>::system->Display();
		System<User>::system->Menu();
	}

	return this;
}

void Flight::AmendBooking(Passenger * passenger)
{
	extString->PrintLine("AMEND BOOKING: ", true, true, true, false, true, 0, 1, '=');
	std::string details[3];
	for (int i = 0; i < 3; i++)
	{
		details[i] = extString->returnInput("Please enter the passenger's " + Passenger::details[i] + "");
	}

	ConfirmBooking(passenger);
}


/*
* CREATES A BOARDING PASS UPON CONFIRMING THE BOOKING - COMPOSITION
*/
void Flight::ConfirmBooking(Passenger * passenger)
{
	extString->PrintLine("BOARDING PASS: ", true, true, true, false, true, 0, 1, '=');
	passenger->BP = new BoardingPass(passenger->fullName, passenger->seatNumber, "Bucks Airport", destination, flight, status, STD);
	passenger->BP->PrintBP();

	extString->PrintLine("TERMS & CONDITIONS DISCLAIMER: ", false, true, true, true, true, 1, 1, '=');

	std::cout << "Notify Passenger they have now been checked-in. \nNow booking has been processed, tickets are NON-REFUDABLE.";
	std::cout << "\n\nPassenger's are only allowed ONE piece of luggage: \n\n Weight: Max 23kg \n\n Dimensions: 56 x 45 x 25 cm" << std::endl;

	char result[1];
	do
	{
		std::strcpy(result, extString->returnInput("\n\nDo they agree Y/N (IN CAPS): ").c_str());
	} while (!((result[0] == 'Y') || (result[0] == 'N')));

	if (result[0] == 'Y')
	{
		extString->PrintLine("\t\tPRINTING ", false, true, true, false, true, 0, 1, '=');
		Sleep();
		System<User>::system->Display();
		System<User>::system->Menu();
	}
	else
	{
		passenger = new Passenger("", "", "", false);
		passenger->BP = new BoardingPass("", "", "", "", "", "", "");
		CancelBooking();
	}
}

/*
* RETURNS A PASSENEGER FROM THE HASH TABLE 
*/
Passenger * Flight::GetPassenger(std::string key)
{
	Passenger * pass = passengerTable->getItemByKey(key);
	return (pass != nullptr) ? pass : nullptr;
}

/*
* ASSIGNS A PRIORITY (INT) TO A PASSENEGER
*/
void Flight::AssignPriority(Passenger * pass)
{
	priorityQueue->Insert(atoi(pass->seatNumber.c_str()));
}

void Flight::AssignAllPriority()
{
	for (int i = 0; i < passengers->maxSize; i++)
	{
		if (passengers[i].stackData->checkedIn == true)
		{
			priorityQueue->Insert(atoi(passengers[i].stackData->seatNumber.c_str()));
		}
	}
}

/*
* POPS ALL PASSNEGERS FROM STACK AND REMOVES ALL PRIORITIES FROM QUEUE 
*/
bool Flight::Deboard()
{
	for (int i = 0; i < priorityQueue->Size(); i++)
	{
		priorityQueue->Remove();
	}

	for (int i = 0; i < passengers->maxSize; i++)
	{
		passengers->Pop();
	}

	return true;
}

void Flight::CancelBooking()
{
	
	extString->PrintLine("CANCELLING BOOKING", true, true, true, false, true, 6, 1, '=');
	Sleep();
	System<User>::system->Menu();
}

void Flight::DisplayFlightMenu()
{
	int menuItems = 0;
	
	for (std::vector<std::string>::iterator it = flightMenu.begin(); it != flightMenu.end(); ++it)
	{
		extString->PrintLine(*it, false, true, true, false, false, 0, 0, '=');
		menuItems++;
	}

	int result = 0;
	do
	{
		result = atoi(extString->returnInput("Please enter a valid menu item number: ").c_str());
	}while(!extInt->CompareValue(result - 1, menuItems));

	SetMenuItem(result);
}

void Flight::SetMenuItem(int item)
{
	switch (item)
	{
		case 1:
			ConfirmBooking(tempPassenger);
			break;
		case 2:
			AmendBooking(tempPassenger);
			break;
		case 3:
			CancelBooking();
			break;
	}
}


void Flight::Sleep()
{
	extString->PrintLine("RETURNING TO MAIN MENU...", false, true, true, false, true, 6, 1, '=');
	clock_t goal = clock() + 4000;
	while (goal > clock()) continue;
}

