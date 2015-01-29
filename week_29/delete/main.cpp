#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>
using namespace std;

int choise = 0;

bool Delete(string source)                        
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
			if (-1 == _rmdir((source + fileinfo->name + "\\").c_str())){
				Delete(source + fileinfo->name + "\\");
				_rmdir((source + fileinfo->name + "\\").c_str());
			}
			
			
		
		} else {
			if (fileinfo->attrib == _A_RDONLY) {
				if (choise == 0 || choise == 1 || choise == 3) {
				cout << "The file:" << endl << fileinfo->name << endl <<
					"size: " << fileinfo->size << endl <<
					"is READ_ONLY" << endl;
				cout << "Choose a variant to do:" << endl <<
					"1. Delete." << endl;
				cout << "2. Delete all such files." << endl;
				cout << "3. Scip for this file." << endl;
				cout << "4. Scip for all such files." << endl;
				cout << "5. Cancel." << endl;
				
				cin >> choise;
				}
				switch (choise) {
				case 1:
					cout << "Deleting" << endl <<
					source + fileinfo->name << endl;
					if (!remove((source + fileinfo->name).c_str()))
						cout << "Ok" << endl << "-----------------------------" << endl;
					break;
				case 2:
					cout << "Deleting" << endl <<
					source + fileinfo->name << endl;
					if (!remove((source + fileinfo->name).c_str()))
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

			cout << "Deleting" << endl <<
				source + fileinfo->name << endl;
			if (!remove((source + fileinfo->name).c_str()))
				cout << "Ok" << endl << "-----------------------------" << endl;

			}

		}
		MayWeWork = _findnext(done, fileinfo);        
	}
	
	// Очистка памяти
	_findclose(done);
	delete fileinfo;
	_rmdir(source.c_str());
}

int main(int argc, char** argv){
	if (argc >= 2) {
		if (Delete(argv[1]))
			cout << "All files deleted" << endl;
	} else {
		cout << "Enter the source to delete:" << endl;
		string source;
		cin >> source;
		if (Delete(source))
			cout << "All files deleted" << endl;
	}

	return 0;
}