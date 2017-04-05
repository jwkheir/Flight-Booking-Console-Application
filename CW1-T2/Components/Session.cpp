#include "stdafx.h"
#include "Session.h"
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
int Session::instances = 0;

Session::Session(const tm* loggedIn)
{
	this->loggedIn = loggedIn;
	this->id = 0;
	instances++;
	this->id = instances;
	this->dateTimeStamp = extString->getDateTime(loggedIn);
}

Session::~Session()
{

}