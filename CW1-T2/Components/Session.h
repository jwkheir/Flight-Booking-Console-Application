#pragma once
/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class Session
{
private:
	int id;
	static int instances;
	const tm* loggedIn;
	//Extensions<std::string> extString;
public:
	std::string dateTimeStamp;
public:
	Session(const tm* loggedIn);
	~Session();
};


