#include "Tree.h"


int main() {
	Tree tr;
	tr.Add("1241-AO-7","Zndfnica");
	tr.Add("1234-AO-7","Zadnica");
	tr.Add("1235-AO-7","Zasfgica");
	tr.Add("1238-AO-7","fdgadnica");
	tr.Add("1236-AO-7","Zdghdghnica");
	tr.Add("1237-AO-7","dgha");
	tr.Add("1242-AO-7","Zndfnica");
	tr.Add("1243-AO-7","Zndfnica");
	tr.Add("1244-AO-7","Zndfnica");
	tr.Add("1245-AO-7","Zndfnica");
	tr.Add("1246-AO-7","Zndfnica");
	tr.Add("1240-AO-7","Zndfnica");
	tr.Add("1239-AO-7","nfdfdnica");
	//tr.Print(tr.root);
	//tr.Print("1232-AO-7","1250-AO-7");
	tr.PrintAll();
	return 0;
}