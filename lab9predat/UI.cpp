#include "pch.h"
#include "UI.h"







UI::UI(const Service serviceStatue, string & output): service{serviceStatue}
{
	this->list = output;
}

void UI::run()
{
	//std::string dataInput[6];
	char mode = 'A';
	char command[10000], arguments[10][10000], archmagesInput[10000];
	char *line;
	int repeat = 1, arguments_counter = 0;
	int stop = 1;
	int current = 0;
	
	do {
		try {
			arguments_counter = 0;
			cout << "Enter a command:";
			cin.getline(archmagesInput, 10000);
			line = strtok(archmagesInput, " ");
			strcpy(command, line);
			while (line) {
				line = strtok(NULL, ",");
				if (line != NULL) {
					strcpy(arguments[arguments_counter], line);
					arguments_counter++;
				}
			}
			if (strcmp(command, "exit") == 0) {
				break;
			}
			else if (strcmp(command, "fileLocation") == 0)
			{
				if (arguments_counter == 1)
				{
					std::string filepath = arguments[0];
					this->file = filepath;


					fstream File(filepath);

					//if (File.is_open())//is_open-> is good
					//{




						//size_t index = path.find(".");
						//path.erase(0, index + 1);
					MyList list;
					//list = new HTMLandCSVrepository { this->output };
					Repository* newRepository;
					newRepository = new FileRepository{ filepath };
					Service newService{ newRepository,list };
					UI newUI{ newService,this->list };
					newUI.run();
					return;
					//this->service.changePathofFile(filepath);

				//}
				}
			}
			else if (strcmp(command, "mylistLocation") == 0)
			{
				if (arguments_counter == 1) {
					this->output = arguments[0];
					//MyList* list;
					//this->mylist = new HTMLandCSVrepository{ this->output };
					//Repository* newRepository;
					//newRepository = new FileRepository{ this->file };
					//Service newService{ newRepository,list };
					//UI newUI{ newService,this->list };
					//newUI.run();
					//return;
				}
			}
			else if (strcmp(command, "add") == 0 && mode == 'A') {
				if (arguments_counter == 4) {

					ui_addGuardianStatue(arguments[0], arguments[1], atoi(arguments[2]), arguments[3]);
				}
				else
					cout << "wrong syntax" << endl;
			}
			else if (strcmp(command, "delete") == 0 && mode == 'A') {
				if (arguments_counter == 1)
					ui_removeGuardianStatue(arguments[0]);
				else
					cout << "wrong syntax" << endl;
			}
			else if (strcmp(command, "update") == 0 && mode == 'A') {
				if (arguments_counter == 4) {
					ui_updateGuardianStatue(arguments[0], arguments[1], atoi(arguments[2]), arguments[3]);

				}
				else
					cout << "wrong syntax" << endl;

			}
			else if (strcmp(command, "list") == 0 && mode == 'A') {
				if (arguments_counter == 0) {
					ui_list();
					

				}
				else
					cout << "wrong syntax" << endl;

			}
			else if (strcmp(command, "save") == 0 && mode == 'B')
			{
				if (arguments_counter == 1) {
					ui_addTOMylist(arguments[0]);
				}
				else
					cout << "" << endl;
			}
			else if (strcmp(command, "mylist") == 0 && mode == 'B') {
				if (arguments_counter == 0) {
					ui_print_mylist();
				}
			}
			else if (strcmp(command, "list") == 0 && mode == 'B') {
				if (arguments_counter == 2) {

					if (strcmp(arguments[0], " ") == 0)
					{
						//cout << "nu aici trebuia";
						cout << ui_listAge(atoi(arguments[1]));
					}
					else {
						//cout << "aici";
						cout << ui_listMatAge(arguments[0], atoi(arguments[1]));
					}
				}
				if (arguments_counter == 1) {
					//cout << "unu";
					cout << ui_listAge(atoi(arguments[0]));
				}
			}
			else if (strcmp(command, "next") == 0 && mode == 'B') {
				if (arguments_counter == 0) {
					vector<GuardianStatue> guardianStatue = this->service.get_allStatues();
					//GuardianStatue* guardianStatue = this->service.get_GuardianStatues();
					cout << guardianStatue[current].get_powerWordName() << "," << guardianStatue[current].get_material() << "," << guardianStatue[current].get_age() << "," << guardianStatue[current].get_corporealForm() << endl;
					current += 1;
					if (current == this->service.getRepository()->getEncyclopedia().size())
						current = 0;
				}
				else
					cout << "wrong syntax";
			}
			else if (strcmp(command, "mode") == 0)
			{

				if (arguments_counter == 1) {


					if (strcmp(arguments[0], "A") == 0) {


						mode = 'A';
					}
					else if (strcmp(arguments[0], "B") == 0) {

						mode = 'B';
					}
				}
			}
		}
		catch (Exceptions& exception)
		{
			cout << exception.get_error_message() << endl;
		}
		} while (repeat == 1);
	}


UI::~UI()
{
}

void UI::ui_addGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	if (this->service.service_addGuardianStatue(powerWordName, material, age, corporealForm) == 1)
		throw Exceptions("This Guardian Statue is already in the Encyclopedia");
	
}
void UI::ui_addTOMylist(const std::string & powerWordName)
{
	this->service.service_addTOMylist(powerWordName);
	string file = this->output;
	size_t positionOfextension = file.find('.');
	file.erase(0, positionOfextension + 1);
	if (file == "csv" or file == "CSV")
	{


		ui_writeCSVToFile();
	}
	else
		if (file == "html" or file == "HTML")
		{
			ui_writeHTMLToFile();
		}

}

void UI::ui_print_mylist()
{
	

	string file = this->output;
	size_t positionOfextension = file.find('.');
	file.erase(0, positionOfextension + 1);
	if (file == "csv" or file == "CSV")
	{
		
		
		//ui_writeCSVToFile();
	
		string forOpening = "notepad.exe " + this->output;
		system(forOpening.c_str());
	}
	else
		if (file == "html" or file == "HTML")
		{
			//cout << service.print_myList();
			//cout << "works?";
			//ui_writeHTMLToFile();
		
			//string forOpening = "<firefox>" + this->output;
			//system(forOpening.c_str());
			string browser = this->output;
			//LPCSTR br;
			//br=browser.c_str();
			//ShellExecuteA(NULL, NULL, "chrome.exe", br, NULL, SW_SHOWMAXIMIZED);
			//system("PAUSE");
			//ShellExecute(NULL, L"open",L"browser", NULL, NULL, SW_SHOWNORMAL);
		}
}
	

void UI::ui_function_for_list(GuardianStatue& statue)
{
	cout << statue;
	cout << "\n";
}

void UI::ui_writeHTMLToFile()
{
	ofstream file;
	file.open(this->output);
	if (file.is_open())
	{
		file << "<!DOCTYPE html>\n";
		file << "<html>\n";
		file << "\t<head>\n";
		file << "\t\t<title>GuardianStatue</title>\n";
		file << "\t</head>\n";
		file << "\t<body>\n";
		file << "\t\t<table border=\"1\">\n";
		file << "\t\t<tr>\n";
		file << "\t\t\t<td>Power Word Name</td>\n";
		file << "\t\t\t<td>Material</td>\n";
		file << "\t\t\t<td>Age</td>\n";
		file << "\t\t\t<td>Corporeal Form</td>\n";
		file << "\t\t</tr>\n";
		std::vector<GuardianStatue> statues = this->service.get_list();
		for (auto &statue : statues)
		{
			file << "\t\t<tr>\n";
			file << "\t\t\t<td>" << statue.get_powerWordName() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_material() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_age() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_corporealForm() << "</td>\n";
			file << "\t\t</tr>\n";
		}
		file << "\t\t</table>\n";
		file << "\t</body>\n";
		file << "</html>\n";
	}
}

void UI::ui_writeCSVToFile()
{
	ofstream file;
	file.open(this->output);
	if (file.is_open())
	{
		std::vector<GuardianStatue> statuess = this->service.get_list();

		for (auto &statue : statuess)
		{
			file << statue << endl;

		}
	}
}

void UI::ui_list()
{
	cout << service.list();


}

string UI::ui_listAge(int age)
{

	
	string GuardianStatueString;
	
	vector<GuardianStatue> guardianStatue = this->service.get_allStatues();
	//GuardianStatue* all_statues = this->service.get_GuardianStatues();

	
	for (auto& guardianStatues : guardianStatue)
		if(guardianStatues.get_age()<age)
			GuardianStatueString += guardianStatues.convert_to_string();
		
	//for (index = 0; index < guardianStatue.size(); index++) {

		//if (guardianStatue[index].get_age() < age)
		//{
			//GuardianStatueString += guardianStatue[index].convert_to_string();
			
		//}
	//}

	return GuardianStatueString;
	
}

string UI::ui_listMatAge(const std::string & material, int age)
{

	string GuardianStatueString;
	vector<GuardianStatue> guardianStatue = this->service.get_allStatues();
	//GuardianStatue* all_statues = this->service.get_GuardianStatues();

	int index = 0;
	
	
	for(auto& guardianStatues :guardianStatue)
		if(guardianStatues.get_material()==material && guardianStatues.get_age()<age)
			GuardianStatueString += guardianStatues.convert_to_string();


	//for (index = 0; index < guardianStatue.size(); index++) {

		//if (guardianStatue[index].get_material() == material && guardianStatue[index].get_age() < age)
		//{
			
		//	GuardianStatueString += guardianStatue[index].convert_to_string();
			
		//}
	

	return GuardianStatueString;
	
}


	
	

void UI::ui_removeGuardianStatue(const std::string & powerWordName)
{
	int i;
	this->service.service_removeGuardianStatue(powerWordName);
		


}


void UI::ui_updateGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	if (this->service.service_updateGuardianStatue(powerWordName, material, age, corporealForm) == 1)
		throw Exceptions( "There is no such Guardian Statue to be updated");
}




