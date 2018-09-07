#include"SimpleVector.h"
using namespace std;
#include<iostream>
#include<cmath>

int main()
{

	// What Works: constructor default,Size, clear,empty, reverse, set, insert, popback, pushback
	
	//Push Back with both objects called with default and non-default constructors work with extending capacity and pushing back elements to add more
	
	SimpleVector sv1(4);
	sv1.push_back(2);
	sv1.push_back(3);
	sv1.push_back(4);
	sv1.push_back(5);
	sv1.push_back(6);
	

	
	/*
	SimpleVector sv1;
	sv1.push_back(2);
	sv1.push_back(3);
	sv1.push_back(4);
	sv1.push_back(5);
	sv1.push_back(6);
	sv1.push_back(7);
	sv1.push_back(8);
	sv1.push_back(9);
	sv1.push_back(10);
	sv1.push_back(11);
	sv1.push_back(12);
	sv1.push_back(13);
	sv1.push_back(14);
	*/





	cout<<"The size of the array created is : "<<sv1.size()<<endl;// Check if return type int returns the number 5, because currently it needs cout but the in the memory the value of _numElements is 5 which is right
	//sv1.reverse();//This works perfectly.

	//sv1.set(17, 2); //3rd position

	//sv1.insert(99, 2);
	

	//sv1.pop_back();

	sv1.print();

	cout << "The size of the array created is : " << sv1.size() << endl;
	sv1.clear();//To clear data
	sv1.empty();//To check if empty, return 1 if empty. 

	



}

