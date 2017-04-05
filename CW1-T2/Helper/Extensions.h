#pragma once
#include "stdafx.h"


/*
* Author: Jack Kheir
* Updated: 27/05/16
* Helped class for the common tasks
*/
template <class T>
class Extensions
{
	private:
		T result;
		static const std::string wDays[7];
	public:
		Extensions();
		void PrintLine(T value, bool clear, bool preHeader, bool afterHeader, bool newBeforeLine, bool newAfterLine, int numNewLines, int numAfterNewLines, char headerType);
		T returnInput(T prompt);
		T getDateTime(const tm* now);
		bool CompareValue(T value, int iterations);
		void Sleep();
		~Extensions();
};

template <class T>
const std::string Extensions<T>::wDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

template <class T>
Extensions<T>::Extensions()
{

}

template <class T>
void Extensions<T>::Sleep()
{
	PrintLine("RETURNING TO MAIN MENU...", false, true, true, false, true, 6, 1, '=');
	clock_t goal = clock() + 4000;
	while (goal > clock()) continue;
}


template <class T>
void Extensions<T>::PrintLine(T value, bool clear, bool preHeader, bool afterHeader,  bool newBeforeLine, bool newAfterLine, int numNewLines, int numAfterNewLines, char headerType)
{
	std::string newLines = "";
	if (clear) system("cls");
	if (newBeforeLine) std::cout << newLines.assign(numNewLines, '\n');
	

	switch (headerType)
	{
		case '=':
			if (preHeader) std::cout << "============================" << std::endl;
			std::cout << value << std::endl;
			if (afterHeader) std::cout << "===========================" << std::endl;
			break;
		case '-':
			if (preHeader) std::cout << "----------------------------" << std::endl;
			std::cout << value << std::endl;
			if (afterHeader) std::cout << "----------------------------" << std::endl;
			break;
	}

	if (newAfterLine) std::cout << newLines.assign(numAfterNewLines, '\n');
}

template <class T>
T Extensions<T>::returnInput(T prompt){
	std::cout << prompt;
	std::getline(std::cin, result);
	return result;
}

template <class T>
bool Extensions<T>::CompareValue(T value, int iterations)
{
	for (int i = 0; i < iterations; i++)
	{
		if (i == value)
		{
			return true;
		}
	}
	return false;
}


template <class T>
T Extensions<T>::getDateTime(const tm* now)
{
	T dateTime = wDays[(int)(now->tm_wday)];
	dateTime.append(" " + std::to_string(now->tm_mday));
	dateTime.append("/" + std::to_string(now->tm_mon + 1));
	dateTime.append("/" + std::to_string(now->tm_year + 1900));

	char buffer[80];
	strftime(buffer, 80, "%H:%M%p", now);
	dateTime.append(" " + std::string(buffer));

	return dateTime;
}


template <class T>
Extensions<T>::~Extensions()
{

}

