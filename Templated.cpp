#include <iostream>
#include <string>
#include "myVector.h"
using namespace std;

template <typename T>
class myVector {
private:
	T *theVector;
	int vSize;
	int index;
public:
	myVector(int size);

	void push_back(T arry[], int index);
	void print();
	void push(T);


};


template <typename T>
myVector<T>::myVector(int size) {
	vSize = size;
	index = 0;
	theVector = new T[vSize];
}

template <typename T>
void myVector<T>::push(T item) {

	theVector[index++] = item;
}

template <typename T>
void myVector<T>::print() {
	for (int i = 0; i < vSize; i++) {
		cout << theVector[i] << " ";
	}
}
template <typename T>
void myVector<T>::push_back(T arry[], int i) {
	theVector[index++] = arry[i];
}






int main() {
	myVector<string> V1(10);
	myVector<int> V2(10);

	char c;


	for (int i = 0; i < 10; i++) {
		c = char((i % 26) + 65);
		V1.push(string(1, c));
	}


	for (int i = 0; i < 10; i++) {
		V2.push(i);
	}

	V1.print();
	cout << endl;
	V2.print();
	cout << endl;

	myVector V = V1 + V2;

	V.print();

	cout << V.size() << endl;
	cout << V.vSize() << endl;

	for (int i = 0; i<498; i++) {
		V.popBack();
	}

	cout << V.size() << endl;

	V.size(15);

	cout << V.vSize() << endl;

	V.print();

	cout << V[3] << endl;

	V.print();

	V[2] = 11;

	cout << V[2] << endl;

	int x = 99;

	//this statement when overloading
	cout << x << endl;
	//is equivalent to this:
	cout << *(&x) << endl;

	V.print();

	int *a = new int[10]; //a[0]
	int *b = a;
	for (int i = 0; i<10; i++) {
		*b = rand() % 99;
		b++;
	}
	for (int i = 0; i<10; i++) {
		cout << a[i] << " ";
	}


}
