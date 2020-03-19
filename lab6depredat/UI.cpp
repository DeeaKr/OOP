//#include "pch.h"
#include "UI.h"







void UI::run()
{
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
							if (strcmp(arguments[0], ""))
								cout << this->service.listAge(atoi(arguments[1]));
							else
								ui_list_material_age(arguments[0], atoi(arguments[1]));
						}
						if (arguments_counter == 1) {
							cout << this->service.listAge(atoi(arguments[0]));
						}
					}
					else if (strcmp(command, "next") == 0 && mode == 'B') {
						if (arguments_counter == 0) {
							GuardianStatue* guardianStatue = this->service.get_GuardianStatues();
							cout << guardianStatue[current].get_powerWordName()<<","<< guardianStatue[current].get_material()<<","<< guardianStatue[current].get_age()<<","<< guardianStatue[current].get_corporealForm()<<endl;
							current += 1;
							if (current == this->service.getRepository().getEncyclopedia().getSize())
								current = 0;
						}
						else 
							cout << "wrong syntax";
					}
					else if (strcmp(command, "mode") == 0)
					{
						//cout << arguments_counter;
						if (arguments_counter == 1) {
							//cout << arguments[0];

							if (strcmp(arguments[0],"A")==0) {

								//cout << mode;
								mode = 'A';
							}
							else if (strcmp(arguments[0],"B")==0) {
								//cout << mode;
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

void UI::ui_list_material_age(const std::string& material,int age)
{
	int index = 0;
	//GuardianStatue guardianStatue;
	string guardianStatue;

	//mylist = this->service.getRepository().repository_listMaterialAge(material, age);
	/*if (mylist.isEmpty() == true)
	{
		cout << "There are none"<<endl<<"Here is what we have in the encyclopedia:"<<endl;
		ui_list();
	}*/
	
	
	guardianStatue=this->service.listMatAge(material, age);
	cout << guardianStatue;

	
	



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


