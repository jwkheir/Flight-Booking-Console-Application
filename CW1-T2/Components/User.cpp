#include "stdafx.h"
#include "User.h"

/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
User::User()
{

}


User::User(std::vector<std::string> data)
{
	this->username = data[0];
	this->password = data[1];
	this->role = data[2];
}

void User::DisplayMenu()
{

}


User::~User()
{
}
