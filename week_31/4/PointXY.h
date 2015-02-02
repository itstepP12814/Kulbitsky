#pragma once

#include <iostream>
using namespace std;

class PointXY{
private:
	int X;
	int Y;
public:
	PointXY(){
		X=Y=0;
	}

	void SetPoint(int iX,int iY){
		X=iX;
		Y=iY;
	}

	void Show(){
		cout<<"----------------------------\n\n";
		cout<<X<<"\t"<<Y<<"\n\n";
		cout<<"----------------------------\n\n";
	}

};

