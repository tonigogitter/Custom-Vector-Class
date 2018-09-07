#pragma once
using namespace std;
#include<iostream>
#include<cmath>
class SimpleVector
{
private:
	int  *_array;
	int _numElements;
	int _capacity;
public:
	SimpleVector()//This is the default Constructor that automatically sets zero elements inside the array with a maximum possibility of 10 elements for capacity.
	{
		_numElements = 0;
		_capacity = 10;
		_array = new int[_capacity];
	}

	SimpleVector(int x)//This is the second constructor that takes a integer as a parameter and the sets that integer for the capacity (maximum size/number of elements allowed) for the dynamic array
	{
		_numElements = 0;
		_capacity = x;
		_array = new int[_capacity];
	}

	~SimpleVector()// Finally this deconstructor (only one allowed) and couts/displays message to let user know its been called, mostly for testing purposes
	{
		delete _array;
		cout << "Deconstructor is called" << endl;

	}

	//Below are the methods prototypes and the method definitions are in the SimpleVecotr cpp which scopes this class inorder to define it.

	int empty();

	int size();

	void push_back(int x);

	void reverse();

	void set(int x, int i);

	void clear();

	void pop_back();

	void extend();

	int insert(int x, int i);

	//
	const int& operator[](int i) const;

	int& operator[](int i);

	void print();// Additonally function for testing

	
}
;
