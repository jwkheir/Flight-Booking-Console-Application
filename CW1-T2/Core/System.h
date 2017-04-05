#pragma once
#include "stdafx.h"
#include "DataManager.h"
#include "HashTable.h"
#include "Users.h"
#include "Flights.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
template <class T>
class System
{
	private:
		Users * users;
		Flights * flights;
		bool initialised;
		time_t t;
		const struct tm * now;
		static int instances;
		T * currentUser;
		Session * session;
	public:
		static System * system;
		System(const tm* time, T * currentUser);
		bool InitialiseSystem();
		void Menu();
		void Display();
		void AdminSystem();
		~System();
};

template <class T>
int System<T>::instances = 0;

template <class T>
System<T> * System<T>::system = 0;

template <class T>
System<T>::System<T>(const tm* time, T * currentUser)
{
	system = this;
	this->now = time;
	instances++;
	this->currentUser = currentUser;
}

template <class T>
bool System<T>::InitialiseSystem()
{
	flights = new Flights();
	initialised = flights->AddExisitingFlights();
	currentUser->flights = flights;

	users = new Users();
	initialised = users->AddExistingUsers();

	initialised = currentUser->SetSessionData(now);
	session = currentUser->GetSessionData();
	initialised = (session != nullptr);
	return initialised;
}

template <class T>
void System<T>::Menu()
{
	int result = 0;
	do
	{
		Display();
		currentUser->DisplayMenu();
		result = atoi(extString->returnInput("Please enter a valid menu item number: ").c_str());
	} while (!extInt->CompareValue(result, currentUser->menuItems));
	currentUser->SetMenuItem(result);
}


template <class T>
void System<T>::Display()
{
	t = time(0);
	now = localtime(&t);
	extString->PrintLine("Bucks Airport Terminal " + std::to_string(instances) + " - \nFlight Clerk, Test Simulation", true, false, false, false, true, 0, 1, '-');
	extString->PrintLine(extString->getDateTime(now), false, false, true, false, false, 0, 0, '-');
	extString->PrintLine("This Simulation Software is for testing purposes only, \nplease read the instructions below:", false, true, true, true, true, 1, 1, '=');

}

template <class T>
void System<T>::AdminSystem()
{
	Flights * clerkBookedFlights = flights;
	Admin * admin = users->Login();
	System<User> * sys = new System<User>(now, admin);
	bool initialised = sys->InitialiseSystem();
	flights->addBookedFlights(clerkBookedFlights);
	if (initialised) sys->Menu();
}

template <class T>
System<T>::~System<T>()
{
}