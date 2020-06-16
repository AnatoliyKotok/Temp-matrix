#include<iostream>
#include"matrix.h"

using namespace std;

int main() {
	const int rows = 3;
	const int cols = 3;
	Matrix<int, rows, cols> obj(34);
	cout << obj << endl;
	obj.print();
	cout << obj.max() << endl;
	cout << obj.min() << endl;
	cout << obj.sum() << endl;
	Matrix<int, rows, cols>obj2 = obj;
	obj2.print();

	
}
	