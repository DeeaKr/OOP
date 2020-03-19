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
	char command[100], arguments[10][100], archmagesInput[100];
	char *line;
	int repeat = 1, arguments_counter = 0;
	int stop = 1;
	int current = 0;
	do {
		arguments_counter = 0;
		cout << "Enter a command:";
		cin.getline(archmagesInput, 100);
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
				std::string parameters[2];
				std::string filepath = arguments[0];

				
				fstream File(filepath);
				cout << filepath;
				if (File.is_open())//is_open-> is good
				{
					
					
					
					
					//size_t index = path.find(".");
					//path.erase(0, index + 1);
					MyList list;
					Repository* newRepository;
					newRepository = new FileRepository{ filepath };
					Service newService{ newRepository,list };
					UI newUI{ newService,this->list };
					newUI.run();
					return;
					//this->service.changePathofFile(filepath);

				}
			}
		}
		else if (strcmp(command, "add") == 0 && mode=='A' ) {
				if (arguments_counter == 4) {

					ui_addGuardianStatue(arguments[0], arguments[1], atoi(arguments[2]), arguments[3]);
					}
				else
					cout << "wrong syntax" << endl;
				}
		else if (strcmp(command, "delete") == 0 && mode=='A') {
				if (arguments_counter == 1)
					ui_removeGuardianStatue(arguments[0]);
				else
					cout << "wrong syntax" << endl;
				}
		else if (strcmp(command, "update") == 0 && mode=='A') {
				if (arguments_counter == 4) {
					ui_updateGuardianStatue(arguments[0], arguments[1], atoi(arguments[2]), arguments[3]);

				}
				else
					cout << "wrong syntax" << endl;

				}
		else if (strcmp(command, "list") == 0 && mode=='A') {
				if (arguments_counter == 0) {
					ui_list();
					/*vector<GuardianStatue> statues = this->service.get_allStatues();
					string GuardianStatueString;
					for (auto& guardianStatue : statues)
						GuardianStatueString += guardianStatue.convert_to_string();
					cout << GuardianStatueString;*/

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
							
							if (strcmp(arguments[0], " ")==0)
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
							cout << guardianStatue[current].get_powerWordName()<<","<< guardianStatue[current].get_material()<<","<< guardianStatue[current].get_age()<<","<< guardianStatue[current].get_corporealForm()<<endl;
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
							

							if (strcmp(arguments[0],"A")==0) {

								
								mode = 'A';
							}
							else if (strcmp(arguments[0],"B")==0) {
								
								mode = 'B';
							}
						}
					}
		} while (repeat == 1);
	}


UI::~UI()
{
}

void UI::ui_addGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	if (this->service.service_addGuardianStatue(powerWordName, material, age, corporealForm) == 1)
		cout << "This Guardian Statue is already in the Encyclopedia"<<endl;
	
}
void UI::ui_addTOMylist(const std::string & powerWordName)
{
	this->service.service_addTOMylist(powerWordName);

}

void UI::ui_print_mylist()
{
	
	cout << service.print_myList();
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
		
	/*for (index = 0; index < guardianStatue.size(); index++) {

		if (guardianStatue[index].get_age() < age)
		{
			GuardianStatueString += guardianStatue[index].convert_to_string();
			
		}
	}*/

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


	/*for (index = 0; index < guardianStatue.size(); index++) {

		if (guardianStatue[index].get_material() == material && guardianStatue[index].get_age() < age)
		{
			
			GuardianStatueString += guardianStatue[index].convert_to_string();
			
		}*/
	

	return GuardianStatueString;
}


	
	

void UI::ui_removeGuardianStatue(const std::string & powerWordName)
{
	if (this->service.service_removeGuardianStatue(powerWordName) == 1)
		cout << "There is no such Guardian Statue in the Encyclopedia"<<endl;


}


void UI::ui_updateGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	if (this->service.service_updateGuardianStatue(powerWordName, material, age, corporealForm) == 1)
		cout << "There is no such Guardian Statue to be updated" << endl;
}


