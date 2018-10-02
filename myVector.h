#pragma once
#pragma once
#include <iostream>

using namespace std;

class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size);
	void pushBack(int item);
	void pushBack(int *, int size);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i < V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		//os<<"test"<<endl;
		return os;
	}

	myVector operator +(myVector const &rhs)
	{
		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++)
			V3[i] = lhs.vPtr[i] + rhs.vPtr[i];
		//Print that it really is the bigger of the two.
		//Don't do this in your program!
		cout << "newVector size: " << newVector.maxSize << endl;

		return V3;
	}
	myVector operator -(myVector const &rhs)
	{
		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++)
			V3[i] = lhs.vPtr[i] - rhs.vPtr[i];

		//Print that it really is the bigger of the two.
		//Don't do this in your program!
		cout << "newVector size: " << newVector.maxSize << endl;


		return V3;
	}
	myVector operator *(myVector const &rhs)
	{
		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++)
			V3[i] = lhs.vPtr[i] * rhs.vPtr[i];

		//Print that it really is the bigger of the two.
		//Don't do this in your program!
		cout << "newVector size: " << newVector.maxSize << endl;


		return V3;
	}
	myVector operator /(myVector const &rhs)
	{
		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++)
			V3[i] = lhs.vPtr[i] / rhs.vPtr[i];

		//Print that it really is the bigger of the two.
		//Don't do this in your program!
		cout << "newVector size: " << newVector.maxSize << endl;


		return V3;
	}
	bool operator ==(myVector const &rhs)
	{

		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++) {
			if (!(lhs.vPtr[i] == rhs.vPtr[i]))
				return false;
		}
		return true;
	}
	myVector operator =(myVector const &rhs)
	{
		myVector V3;
		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector V3(max);


		for (int i = 0; i < max; i++)
			V3[i] = rhs.vPtr[i];

		//Print that it really is the bigger of the two.
		//Don't do this in your program!
		cout << "newVector size: " << V3.maxSize << endl;


		return V3;
	}


};


/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
myVector::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new int[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void
* @return void
*/
void myVector::print() {
	for (int i = 0; i < index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
void myVector::pushBack(int item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

/**
* Function popBack
*   Returns value from vector
* @param none
* @return {int} : last item on vector
*/
int myVector::popBack() {

	index--;

	if (index < 0) {
		//dammit
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
int* myVector::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}

int* myVector::resize(int size) {

	return _resize(size);

}

int* myVector::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	int* vBigger = new int[newSize];

	//copy everything over
	for (int i = 0; i < index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
double myVector::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
int myVector::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
void myVector::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
int myVector::vSize() {
	return maxSize;
}

