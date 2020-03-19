// laboratory5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "UI.h"
#include "Test.h"
#include <iostream>
using namespace std;

int main()
{
	
	std::string file_path;
	while (true)
	{
		cout << "Enter a command: ";
		getline(cin, file_path);
		if (file_path == "exit")
		{
			return 0;
		}
		size_t position = file_path.find(" ");
		std::string command = file_path.substr(0, file_path.find(" "));
		file_path.erase(0, position + 1);
		fstream openTheFile(file_path);
		if (openTheFile.good() and command == "fileLocation")
		{
			break;
		}
		else
		{
			ofstream AnotherFile(file_path);
			if (AnotherFile.good() and command == "fileLocation")
			{
				break;
			}
		}

	}
	

	//Test::TestAll();

	
	MyList mylist;
	Repository* repository = new FileRepository{file_path};
	Service service{ repository,mylist };
	UI ui{service};
	ui.run();
	

}


