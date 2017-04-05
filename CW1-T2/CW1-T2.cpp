// CW1-T2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "System.h"
#include "User.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/

int DisplayMenu()
{
	int menuItems = 0;
	DataManager data;
	std::vector<std::string> menu = data.RetrieveXmlListData("Menu.xml", "Menu", "List", "menuitem");

	for (std::vector<std::string>::iterator it = menu.begin(); it != menu.end(); ++it) 
	{
		extString->PrintLine(*it, false, true, true, true, true, 0, 0, '-');
		menuItems++;
	}

	int result = 0;
	do
	{
		result = atoi(extString->returnInput("Please enter a valid menu item number: ").c_str());
	} while (!extInt->CompareValue(result - 1, menuItems));

	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	time_t t = time(0);
	struct tm * now = localtime(&t);

	//int result = DisplayMenu();

	/*if (result == 1)
	{*/
	//LOGS FLIGHT CLERK/GUEST ON TO THE SYSTEM
		User * guest = new Guest();
		System<User> * sys = new System<User>(now, guest);
		bool initialised = sys->InitialiseSystem();

		if (initialised) sys->Menu();
	//}//ADMIN USAGE
	//else
	//{
	//	Users * users = new Users();
	//	Admin * admin = users->Login();

	//	System<User> * sys = new System<User>(now, admin);
	//	bool initialised = sys->InitialiseSystem();

	//	if (initialised) sys->Menu();
	//}
	std::cin.get();
	return 0;
}

