#include"tree.h"
#include <iostream>
using namespace std;


int main() {
	Tree tr;
	/*tr.Add("zina",12);
	tr.Add("galya",34);
	tr.Add("aolik",46);
	tr.Add("liza",2);
	tr.Add("petya",56);
	tr.Add("toma",15);
	tr.Add("valik",1);
	tr.Add("makar",3);
	tr.Add("sasha",8);*/
	//tr.PrintByNumbers();
	//tr.PrintByNames();
	//cout << tr.SearchByNumber(11)->number << endl;
	//tr.PrintByNames();
	//tr.NextByNumber();
	//cout << tr.cur->number << endl;
	//tr.SearchDiapasone(11,50);
	//tr.SaveToFile("D:/My.txt");
	tr.ReadFromFile("D:/My.txt");
	tr.SearchByName("liza");
	ofstream f("D:/find.txt");
	while (tr.cur->name < "sasha") {
	tr.AddCurrentToFile(f);
	tr.NextByName();
	}
	f.close();
	//tr.PrintByNames();
	return 0;
}