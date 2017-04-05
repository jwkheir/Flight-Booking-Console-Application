// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include "../tinyxml/tinyxml.h"
#include "Extensions.h"
#include "System.h"
#include <algorithm>    // std::swap

//typedef void(*RequiredFunction)();
//std::vector<RequiredFunction> menuListItems;
// TODO: reference additional headers your program requires here
extern Extensions<std::string> * extString;
extern Extensions<int> * extInt;