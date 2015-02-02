#pragma once

#include "PointXY.h"

class Figura{
private:
	
	PointXY *obj;

	
	int count;
	
	int color;
	
public:

	
	Figura(){
		count=color=0;
		obj=NULL;
	}

	
	void CreateFigura(int cr,int ct){
		
		if(ct<3) exit(0);
		
		count=ct;
		color=cr;
		
		obj = new PointXY[count];
		if(!obj) exit(0);

		
		int tempX,tempY;
		for(int i=0;i<count;i++){
			cout<<"Set X\n";
			cin>>tempX;
			cout<<"Set Y\n";
			cin>>tempY;
			obj[i].SetPoint(tempX,tempY);
		}
	}

	
	void ShowFigura(){
		cout<<"----------------------------\n\n";
		cout<<"Color "<<color<<"\n\nPoints - "<<count<<"\n\n";
		for(int i=0;i<count;i++){
			obj[i].Show();
		}	
	}

	
	~Figura(){
		if(obj!=NULL) delete[]obj;
	}


};

