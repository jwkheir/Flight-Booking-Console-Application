#pragma once
#include "Guest.h"
#include "Admin.h"
#include "Flight.h"
#include "DataManager.h"
#include "HashTable.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Users
{
private:
	int roles[3];
	std::vector<Guest> guests;
	std::vector<std::string> guest;
	std::vector<std::string> userData;
	DataManager data;
	//Extensions<std::string> extString;
	const int MAX_USERS = 13;
	const int USER_FIELDS = 4;
public:
	HashTable<Guest> * guestTable;
private:
	void CreateUserDB();
public:
	Users();
	bool AddExistingUsers();
	bool AddUsers(std::vector<std::string> userData);
	Guest * RequestGuest();
	Admin * Login();
	~Users();
};

