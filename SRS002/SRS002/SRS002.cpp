// SRS002.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main() 
{
	size_t allo = 4;
	char name[257];
	auto list = new char *[allo];
	auto next = 0;
	char* newname;
	while (true)
	{
		while (cin.peek() != '\n')
		{
			//cout << "Enter names: " << endl;
			if (allo == next)
			{
				allo = allo * 2;
				auto listtemp = new char *[allo];
				for (auto i{ 0 }; i != next; ++i)
				{
					listtemp[i] = list[i];
				}
				delete[] list;
				list = listtemp;
			}
			std::cin >> name;
			newname = new char[strlen(name) + 1];
			if (strlen(name) >= 257)
			{
				cout << "please re-enter data." << endl;
				break;
			}
			//memcpy(newname, name, strlen(name) + 1);
			strcpy_s(newname, strlen(name) + 1, name);
			list[next] = newname;
			next = next + 1;
		}

		while (next != 0) //cin.good()
		{
			--next;
			cout << list[next] << " ";
		}
	}
		delete[] newname;
		return 0;
}
