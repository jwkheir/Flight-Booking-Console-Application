#include "stdafx.h"
#include "Users.h"
#include "Guest.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
Users::Users()
{
	userData = data.RetrieveXmlListOfListData("Users.xml", "Users", "User", "item");
	guestTable = new HashTable<Guest>(MAX_USERS);
}


bool Users::AddExistingUsers()
{
	if (AddUsers(userData))
	{
		return true;
	}
	return false;
}

bool Users::AddUsers(std::vector<std::string> userData)
{
	std::vector<std::string> tempUser;
	int count = 0;
	if (!userData.empty())
	{
		for (int i = 0; i < (int)(userData.size() / USER_FIELDS); i++)
		{
			for (int j = 0; j < USER_FIELDS; j++)
			{
				tempUser.push_back(userData[count]);
				count++;
			}
			if (tempUser[2] == "Guest")
			{
				Guest * user = new Guest(tempUser);
				guestTable->insertItem(user);
			}

			tempUser.clear();
		}
		return true;
	}
	else{
		return false;
	}

}

//MAIN CPP USES THIS TO REQUEST GUEST
Guest * Users::RequestGuest()
{
	for (int i = 0; i < 3; i++)
	{
		guest.push_back("Guest");
	}
	Guest * tempGuest = new Guest(guest);
	return tempGuest;
}


//ADMIN LOGIN
Admin * Users::Login()
{
	extString->PrintLine("ADMIN LOGIN", true, true, true, true, true, 0, 0, '-');
	std::string details[2] = {"username", "Password"};
	std::string result = "";

	for (int i = 0; i < 2; i++)
	{
		do
		{
			result = extString->returnInput("Please enter a " + details[i] + ": ").c_str();
		} while (!(result == "Admin"));
	}
	return new Admin();
}


Users::~Users()
{
}
