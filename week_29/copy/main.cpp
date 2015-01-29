#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>
using namespace std;
int choise = 0;

bool CopyFile(const char *source,const char *destination){
	const int size=65536;
	FILE *src,*dest;
	
	if(!(src=fopen(source,"rb"))){
		return false;
	}
	
	int handle=_fileno(src);
	
	
	char *data=new char[size];
	if(!data){
		return false;
	}
	
	if(!(dest=fopen(destination,"wb"))){
		delete []data;
		return false;
	}
	int realsize;
	while (!feof(src)){
		
		realsize=fread(data,sizeof(char),size,src);
		
		fwrite(data,sizeof(char),realsize,dest);
	}

	
	fclose(src);
	fclose(dest);
	return true;
}




bool Copy(string source, string destination)                        
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
			if (_mkdir((destination + fileinfo->name + "\\").c_str())) {
				_mkdir((destination + fileinfo->name + "\\.").c_str());
				_mkdir((destination + fileinfo->name + "\\..").c_str());
					
			}
			Copy(source + fileinfo->name + "\\",destination + fileinfo->name + "\\");
		} else {
			_finddata_t *file = new _finddata_t;
			long well = _findfirst((destination + fileinfo->name).c_str(),file);
			if (well != -1) {
				if (choise == 0 || choise == 1 || choise == 3) {
				cout << "The file:" << endl << file->name << endl <<
					"size: " << file->size << endl <<
					"already exists" << endl;
				cout << "Choose a variant to do:" << endl <<
					"1. Replace with " << file->name << endl <<
					"size: " << file->size << "." << endl;
				cout << "2. Replace for all files." << endl;
				cout << "3. Scip for this file." << endl;
				cout << "4. Scip for all files." << endl;
				cout << "5. Cancel." << endl;
				
				cin >> choise;
				}
				_findclose(well);
				delete file;
				switch (choise) {
				case 1:
					cout << "Copying from:" << endl <<
						source + fileinfo->name << endl <<
						"To:" << destination + fileinfo->name << endl;
					if (CopyFile((source + fileinfo->name).c_str(),(destination + fileinfo->name).c_str())) {
						cout << "Ok" << endl <<
						"----------------------------" << endl;

					} else { cout << "File is not copied"<< endl <<
						"----------------------------" << endl;}
					break;
				case 2:
					cout << "Copying from:" << endl <<
						source + fileinfo->name << endl <<
						"To:" << destination + fileinfo->name << endl;
					if (CopyFile((source + fileinfo->name).c_str(),(destination + fileinfo->name).c_str())) {
						cout << "Ok" << endl <<
						"----------------------------" << endl;

					} else { cout << "File is not copied"<< endl <<
						"----------------------------" << endl;}
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
			}

		
		
		}
		MayWeWork = _findnext(done, fileinfo);        
	}
	
	// Очистка памяти
	_findclose(done);
	delete fileinfo;
	return true;
}






int main(int argc, char **argv){
	if (argc >= 3) {
		if (Copy(argv[1],argv[2]))
		cout << endl << "All files are copied" << endl;
	
	} else {
		if (argc == 2) {
			cout << "The source folder is:" << endl <<
				argv[1] << endl <<
				"Enter the destination folder to copy to:" << endl;
			string destination;
			cin >> destination;
			if (Copy(argv[1],destination))
				cout << endl << "All files are copied" << endl;
		} else {
			cout << "Enter the source folder:" << endl;
			string source;
			cin >> source;
			cout << "Enter the destination folder:" << endl;
			string destination;
			cin >> destination;
			if (Copy(source,destination))
				cout << endl << "All files are copied" << endl;
		}
	
	}
	system("pause");
	return 0;
}