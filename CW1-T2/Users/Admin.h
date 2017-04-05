#pragma once
#include "User.h"
class Admin : public User
{
public:
	Admin();
	~Admin();
	bool SetSessionData(const tm* loggedIn);
	Session * GetSessionData();
	void DisplayMenu();
	void SetMenuItem(int menuItem);
	std::string getUserName();
};

