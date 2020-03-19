
#include "UI.h"







void UI::run()
{
	char mode = 'A';
	char command[100], arguments[10][100], archmagesInput[100];
	char *line;
	int repeat = 1, arguments_counter = 0;
	int stop = 1;
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
		/*if (strcmp(command, "mode") == 0) {
			if (arguments_counter == 1 && strcmp(arguments[0], "A") == 0)
			{
				
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
					*/
					if (strcmp(command, "exit") == 0) {
						break;
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
						}
					}
					else if (strcmp(command, "mode") == 0)
					{
						//cout << arguments_counter;
						if (arguments_counter == 1) {
							//cout << arguments[0];

							if (strcmp(arguments[0],"A")==0) {

								cout << mode;
								mode = 'A';
							}
							else if (strcmp(arguments[0],"B")==0) {
								cout << mode;
								mode = 'B';
							}
						}
					}
			
			//}

		//}
		

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

void UI::ui_list()
{
	cout << service.list();

	/*for (int index = 0; index < this->service.getRepository().getEncyclopedia().getSize(); index++)
	{
		cout << "Power word name:";
		cout << this->service.getRepository().getEncyclopedia().getAllElems()[index].get_powerWordName() << endl;
		cout << "Material:";
		cout << this->service.getRepository().getEncyclopedia().getAllElems()[index].get_material() << endl;
		cout << "Age:";
		cout << this->service.getRepository().getEncyclopedia().getAllElems()[index].get_age() << endl;
		cout << "Corporeal Form:";
		cout << this->service.getRepository().getEncyclopedia().getAllElems()[index].get_corporealForm() << endl;
	}*/
	
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


