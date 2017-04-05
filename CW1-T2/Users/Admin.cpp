#include "stdafx.h"
#include "Admin.h"


Admin::Admin()
{
}

void Admin::DisplayMenu()
{
	menu = data.RetrieveXmlListData("AdminMenu.xml", "Menu", "List", "menuitem");

	extString->PrintLine("Admin Menu", false, false, true, true, false, 1, 1, '-');
	for (std::vector<std::string>::iterator it = menu.begin(); it != menu.end(); ++it) 
	{
		extString->PrintLine(*it, false, false, true, true, true, 0, 0, '-');
		menuItems++;
	}
}

void Admin::SetMenuItem(int menuItem)
{
	switch (menuItem)
	{
		case 1:
			//flights->SearchForFlightToBoard("Enter a flight number ");
			break;
		case 2:
			break;
		case 3:

			break;
	}
}

std::string Admin::getUserName()
{
	return username;
}

bool Admin::SetSessionData(const tm* loggedIn)
{
	session = new Session(loggedIn);
	return (session != nullptr);
}

Session * Admin::GetSessionData()
{
	return session;
}

Admin::~Admin()
{
}
