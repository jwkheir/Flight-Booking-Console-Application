#pragma once
#include "stdafx.h"


/*
* Author: Jack Kheir
* Updated: 27/05/16
*/
class DataManager
{
public:
	std::vector<std::string> RetrieveXmlListData(std::string file, std::string root, std::string listElement, std::string listItem)
	{
		TiXmlDocument doc;
		bool loadOkay = doc.LoadFile(file.c_str());
		if (!loadOkay)	std::cout << "Failed to load file.";

		std::vector<std::string> items;
		TiXmlNode * pRoot = doc.FirstChildElement(root.c_str());
		TiXmlElement * pElement = pRoot->FirstChildElement(listElement.c_str());
		TiXmlElement * pSubElement = pElement->FirstChildElement(listItem.c_str());
		int count = 0;
		while (pSubElement != nullptr)
		{
			std::string item = (std::string)pSubElement->GetText();
			items.push_back(item);
			count++;
			pSubElement = pSubElement->NextSiblingElement(listItem.c_str());
		}

		return items;
	}


	std::vector<std::string> RetrieveXmlListOfListData(std::string file, std::string root, std::string listElement, std::string listItem)
	{
		TiXmlDocument doc;
		bool loadOkay = doc.LoadFile(file.c_str());
		if (!loadOkay)	std::cout << "Failed to load file.";

		std::vector<std::string> items;
		TiXmlNode * pRoot = doc.FirstChildElement(root.c_str());
		TiXmlElement * pElement = pRoot->FirstChildElement(listElement.c_str());
		TiXmlElement * pSubElement = pElement->FirstChildElement(listItem.c_str());
		int count = 0;
		while (pElement != nullptr && pSubElement != nullptr)
		{
			while (pSubElement != nullptr)
			{
				std::string item = (std::string)pSubElement->GetText();
				items.push_back(item);
				count++;
				pSubElement = pSubElement->NextSiblingElement(listItem.c_str());
			}
			pElement = pElement->NextSiblingElement("Flight");
			if (pElement != nullptr) pSubElement = pElement->FirstChildElement(listItem.c_str());
		}
		return items;
	}


};

