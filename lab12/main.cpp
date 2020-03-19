#include "FirstGuI.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
#include <string>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMessageBox message;
	message.setText("Do you want File or In Memory repository?");
	QPushButton *filebutton = message.addButton(("File"), QMessageBox::ActionRole);
	QPushButton *memory = message.addButton(("In Memory"), QMessageBox::ActionRole);
	message.exec();
	if (message.clickedButton() == filebutton) {
		MyList list;
		std::string file = "new.txt";
		Repository* repo = new FileRepository{ file };
		Service service{ repo,list };
		FirstGuI ui{ service };
		//FirstGuI w;
		ui.show();
		return a.exec();
	}
	else if (message.clickedButton() == memory) {
		MyList list;
		//std::string file = "new.txt";
		Repository* repo = new Repository;
		Service service{ repo,list };
		FirstGuI ui{ service };
		//FirstGuI w;
		ui.show();
		return a.exec();
	}
	
	
}
