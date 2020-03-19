// laboratory5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "UI.h"
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


	/*
	std::string file_name;
	std::string file_path;
	char command[1000],arguments[10][1000],input[1000];
	char *line;
	int arguments_counter = 0;
	//file_name = "file.txt";
	while (true) {
		getline(cin, file_name);
		if (file_name == "exit")
		{
			return 0;
		}
		strcpy(input, file_name.c_str());
		line = strtok(input, " ");
		strcpy(command, line);
		while (line) {
			line = strtok(NULL, ",");
			if (line != NULL) {
				strcpy(arguments[arguments_counter], line);
				arguments_counter++;
			}
		}
		file_path = arguments[0];
		cout << file_path;

		fstream openTheFile(file_path);
		if(openTheFile.good() and command=="fileLocation")
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


	}*/

	//fstream file;
	//file.open(file_name);
	MyList mylist;
	Repository* repository = new FileRepository{file_path};
	Service service{ repository,mylist };
	UI ui{service};
	ui.run();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
