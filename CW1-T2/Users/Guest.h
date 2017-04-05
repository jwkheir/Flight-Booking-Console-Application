#pragma once
#include "User.h"
#include "Flights.h"


/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Guest : public User
{
public:
	Guest * next;
	std::string key;
public:
	Guest();
	Guest(std::vector<std::string> guest);
	void DisplayMenu();
	void SetMenuItem(int menuItem);
	std::string getUserName();
	bool virtual SetSessionData(const tm* loggedIn);
	Session * GetSessionData();
	~Guest();
};

