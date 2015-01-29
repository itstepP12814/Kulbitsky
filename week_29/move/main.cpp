#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>
using namespace std;

int choise = 0;

bool Move(string source, string destination)                        
{	
	
    _finddata_t *fileinfo=new _finddata_t;	
	long done = _findfirst((source + "*.*").c_str(),fileinfo);
	int MayWeWork = done;	
	while (MayWeWork!=-1)
	{	
		if (fileinfo->attrib == _A_SUBDIR) {
			if (fileinfo->name[0] == '.') {
				MayWeWork = _findnext(done, fileinfo);
				continue;
			}
			if (rename((source + fileinfo->name + "\\").c_str(), (destination + fileinfo->name + "\\").c_str())){
				Move(source + fileinfo->name + "\\", destination + fileinfo->name + "\\");
				rename((source + fileinfo->name + "\\").c_str(), (destination + fileinfo->name + "\\").c_str());
			}
			
			
		} else {
			if (fileinfo->attrib == _A_RDONLY) {
				if (choise == 0 || choise == 1 || choise == 3) {
				cout << "The file:" << endl << fileinfo->name << endl <<
					"size: " << fileinfo->size << endl <<
					"is READ_ONLY" << endl;
				cout << "Choose a variant to do:" << endl <<
					"1. Move." << endl;
				cout << "2. Move all such files." << endl;
				cout << "3. Scip for this file." << endl;
				cout << "4. Scip for all such files." << endl;
				cout << "5. Cancel." << endl;
				
				cin >> choise;
				}
				switch (choise) {
				case 1:
					cout << "Moving from" << endl <<
					source + fileinfo->name << endl << "To" << endl <<
					source + fileinfo->name << endl;
					if (!rename((source + fileinfo->name).c_str(), (destination + fileinfo->name).c_str()))
						cout << "Ok" << endl << "-----------------------------" << endl;
					break;
				case 2:
					cout << "Moving from" << endl <<
					source + fileinfo->name << endl << "To" << endl <<
					source + fileinfo->name << endl;
					if (!rename((source + fileinfo->name).c_str(), (destination + fileinfo->name).c_str()))
						cout << "Ok" << endl << "-----------------------------" << endl;
					break;
				case 3:
					MayWeWork = _findnext(done, fileinfo); 
					continue;
					break;
				case 4:
					MayWeWork = _findnext(done, fileinfo); 
					continue;
					break;
				case 5:
					return false;
				default:
					MayWeWork = _findnext(done, fileinfo); 
					continue;
					break;
				}
			
			} else {
				cout << "Moving from" << endl <<
					source + fileinfo->name << endl << "To" << endl <<
					source + fileinfo->name << endl;
					if (!rename((source + fileinfo->name).c_str(), (destination + fileinfo->name).c_str()))
						cout << "Ok" << endl << "-----------------------------" << endl;
			
			}
		
		}
		MayWeWork = _findnext(done, fileinfo);        
	}
	
	
	_findclose(done);
	delete fileinfo;
	rename(source.c_str(), destination.c_str());
}

int main(int argc, char** argv){
	if (argc >= 3) {
		if (Move(argv[1],argv[2]))
		cout << endl << "All files are moved" << endl;
	
	} else {
		if (argc == 2) {
			cout << "The source folder is:" << endl <<
				argv[1] << endl <<
				"Enter the destination folder to move to:" << endl;
			string destination;
			cin >> destination;
			if (Move(argv[1],destination))
				cout << endl << "All files are moved" << endl;
		} else {
			cout << "Enter the source folder:" << endl;
			string source;
			cin >> source;
			cout << "Enter the destination folder:" << endl;
			string destination;
			cin >> destination;
			if (Move(source,destination))
				cout << endl << "All files are moved" << endl;
		}
	
	}
	
	return 0;
}