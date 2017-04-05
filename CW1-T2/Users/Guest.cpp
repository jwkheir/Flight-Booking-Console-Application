#include "stdafx.h"
#include "Guest.h"


/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
Guest::Guest()
{

}

Guest::Guest(std::vector<std::string> guest) :User(guest)
{
	this->menuItems = 0;
	this->key = guest[0];
	this->next = NULL;
}


/*
* Retrieves XML and stores it in a vector to print out for the menu
*/
void Guest::DisplayMenu()
{
	menu = data.RetrieveXmlListData("GuestMenu.xml", "Menu", "List", "menuitem");

	extString->PrintLine("Flight Clerk Menu", false, false, true, true, false, 1, 1, '-');
	for (std::vector<std::string>::iterator it = menu.begin(); it != menu.end(); ++it) {
		extString->PrintLine(*it, false, false, true, true, true, 0, 0, '-');
		menuItems++;
	}
}

void Guest::SetMenuItem(int menuItem)
{
	switch (menuItem)
	{
		case 1:
			flights->ListFLights();
			break;
		case 2:
			flights->SearchForFlight("Enter a flight number ");
			break;
		case 3:
			flights->BoardPassenger("Enter a flight number: ");
			break;
		case 4:
			flights->BoardAllPassengers("Enter a flight number: ");
			break;
		case 5:
			flights->DeboardAllPassengers("Enter a flight number: ");
			break;
	}
}

std::string Guest::getUserName()
{
	return username;
}


/*
* For login time and user details
*/
bool Guest::SetSessionData(const tm* loggedIn)
{
	session = new Session(loggedIn);
	return (session != nullptr);
}

Session * Guest::GetSessionData()
{
	return session;
}

Guest::~Guest()
{
}
