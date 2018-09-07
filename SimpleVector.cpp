#include "SimpleVector.h"
#include<cmath>
#include <iostream>
using namespace std;


int SimpleVector:: empty()
{
	// Based on two conditions, first checks if the Array is empty by checking the value of _numElements and if it is zero- it is empty. If not then it is not empty.
	// Returns an integer type, 1 if empty, 0 if not empty. Cout Statements were just for testing. So can be commented out and couted in main.cpp.
	if (_numElements == 0)
	{
		cout << "The array simpleVector is empty" << endl;
		return 1;
	}
	else
	{
		cout << "The array simpleVector is not empty" << endl;
		return 0;
	}
}

int SimpleVector:: size()// This method/function just checks the current most updated version of _numElements (the private member) in the _array and returns the value of the number of elements as an integer.
{
	return _numElements;
}

void SimpleVector:: push_back(int x)// This is one way to populate the dynamically created array by placing one at a time integer in the last place in the array and as you keep calling this function,
// it pushes back that integer deeper towards the beginning of the array to allow for more elements to be pushed into the array.
{
//The following if statement first checks the current number of elements in the array and if it is equal to capacity, it means we have to extend capacity to allow for more elements to be plugged into the array
	//For this occur, we call the extend function, that increases the capacity of the dynamically created array.
	
	
	if (_numElements== _capacity)
	{
		extend();
	}
	
	
	// Next the logics behind the statements below, is first we update the number of elements as the user is pushing/adding another element (so incrementing num_element).

	++_numElements;
	_array[_numElements - 1] = x; // This is assigning the value for last element of the array with the value the user inputs for the parameter of this funciton int x.
	cout << _array[_numElements-1] << endl; // This is now printing that assigned element from inside the array, for testing purposes to show the element is being pushed back inside the array.
}

void SimpleVector::reverse()
{
	for (int i = 0; i < _numElements / 2; i++)
	{
		int x = _array[i];// Assigns each element to x as a temporary placeholder.
		_array[i] = _array[_numElements - i - 1];// This assigns the current value of the array to the last element of the array each time. So the first element is assigned with the value of the last element, the second element with the second last, the third element with the third last.
		_array[_numElements - i - 1] = x;// This function assigns the last value and counting down the array elements to the temporary value of x which is the current element. So the last element's value is now the first elements value, the second last's value is the 2nd element and etc.
	}
}

void SimpleVector:: set(int x, int i)// Takes the parameters of int x as the value of the element you want to set as and int i the index of the array for which the value will go into.
{
	if (!(i < 0) && (i < _numElements))// First check that the index entered as the parameter is valid with the range of the number of Elements inside the array and not negative.
	{
		_array[i] = x;// A simple statement that makes the indexed element inside the array equal the int x value that was provided.
	}
	else
		cout << "Index out of bounds" << endl;	// To show the user the index that he/she wanted to replace in was invalid.
}

void SimpleVector::clear()// Deletes all the values of all current elements int he array. 
{
	for (int i = 0; i < _numElements; i++)// This for loop goes through all existing elements and sets them to NULL meaning no value.
	{
		_array[i] = NULL;
	}
	_numElements = 0;// After all elements have no value, it means there are no elements in the array which is why _numElements is set to 0.
	cout << "Array has been cleared" << endl;// Just for testing purposes to see if called or not.
}
void SimpleVector:: pop_back()// Deletes the last element of the array by assigning it as NULL, meaning no value and element deleted. 
//This also means number of elements is decremented by one to show the reduction.
{
	_array[_numElements - 1] = NULL;
	--_numElements;
}

void SimpleVector:: extend()// This extend function allocates more memorary locations to array's capacity if the user is trying to add more elements than the current set capacity.
{
	cout << "Extended" << endl;// Printing extended, to show if this method is being called when used. For testing purposes.
	_capacity = 2 * _capacity; //Setting current capacity as twice as previous.
	
	int *_1Array= new int[_capacity];// Creating a new temporary array to copy all elements from old array before re-assigning with new capacity.

	for (int i = 0; i < _numElements; i++)// Assigning and copying all elements from old array to new temporary array.
	{
		
		
			_1Array[i] = _array[i];
	}
	

delete[] _array;// Deleting new array
	_array =_1Array;// Assigning old Array as new Array by reference. So when an array element is called, the old is pointing to the new temp array. And both are the same now.


}

int SimpleVector::insert(int x, int i)//This function inserts a new element into the array at a specific index which means it moves the current element and the rest of the elements after it ahead by one.
{
	if (i >= 0 && i < _numElements)// First checks if the index is in between the first and last element of the array as this function will not add a new element at the last index of th array (like a vector).
	{
		if (_numElements == _capacity)// Checks if current number of elements has reached capacity, if show it calls the extend function to allocated more spaces to the array in order to insert one more element.
		{
			extend();
		}

		_numElements++;// Updates and increases the numElements to add one more as insert adds one more element.
		for (int a = i; a < _numElements; a++)// Assigning loop starting at the index the user entered in the parameter.
		{
			int tempy = _array[a];// Creating a temporary int variable and assigning it the current indexed element and afterwards in the loop to remember the old pre-exisitng value at each place (to be used later).
			_array[a] = x;// Assigns the current index in the array to be the value the user passed in the parameter for the first run in the loop.
			// Afterwards, for the second and more runs of the loop this assigns the old pre-existing values to a index one ahead.
			x = tempy;// This reassigns x as the old pre-existing value in order for the second and more runs of the loop to assign old values to index + 1 ahead. For shifting elements.

		}

	}

	else
		return 1;



	

}
//  Below is a non-specified function for the assignment, just used for my testing purposes.
void SimpleVector::print() {

	for (int i = 0; i < _numElements; i++)
	{

		cout << _array[i] << endl;
	}
}

// Funciton/Method Definitions for Overloading Operators
int& SimpleVector::operator[](int i) {
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}


const int& SimpleVector:: operator[](int i) const {
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}