#pragma once
#include "Flights.h"
#include "DataManager.h"
#include "Session.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class User
{
protected:
	std::string username, password, role;
	DataManager data;
	//Extensions<std::string> extString;
	std::vector<std::string> menu;
public:
	Session * session;
	int menuItems;
	Flights * flights;
public:
	User();
	User(std::vector<std::string> data);
	bool virtual SetSessionData(const tm* loggedIn) = 0;
	virtual Session * GetSessionData() = 0;
	virtual void DisplayMenu() = 0;
	virtual void SetMenuItem(int menuItem) = 0;
	virtual std::string getUserName() = 0;
	~User();
};

