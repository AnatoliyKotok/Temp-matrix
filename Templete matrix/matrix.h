#pragma once
#include<iostream>
#include<ctime>
using namespace std;
template<typename T,size_t size_r=3,size_t size_c=3>
class Matrix
{
public:
	
	Matrix(const T& number = T());
	template<typename T, size_t size_r, size_t size_c>
	friend std::ostream& operator << (std::ostream& out, const Matrix<T, size_r,size_c>obj);
	friend std::ostream& operator >>(std::iostream& in, Matrix<T,size_r,size_c> obj);
	T& operator()(int r, int c);
	T sum();
	T print();
	T max()const;
	T min()const;
	//T operator+(int s);
	T& operator =( Matrix& other);
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
private:
	T arr[size_r][size_c];
};


template<typename T, size_t size_r, size_t size_c>
inline Matrix<T, size_r, size_c>::Matrix(const T& number)
{
	
	for (size_t i = 0; i < size_c; i++)
	{
		for (size_t j = 0; j < size_r; j++)
		{
			arr[i][j] = number;
		}
		cout << endl;
	}
	
}

template<typename T, size_t size_r, size_t size_c>
inline T& Matrix<T, size_r, size_c>::operator()(int r, int c)
{
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			if (r > size_r ||r<0||c>size_c||c<0) {
				cout << "Incorect index" << endl;
				exit(0);
			}
			else {
				return arr[r-1][c-1];
			}
		}
	}
}

template<typename T, size_t size_r, size_t size_c>
inline T Matrix<T, size_r, size_c>::sum()
{
	int sum = 0;
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			 sum += arr[i][j];
		}
	}
	cout << "Sum->";
	return sum;
}

template<typename T, size_t size_r, size_t size_c>
inline T Matrix<T, size_r, size_c>::print()
{
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			cout << arr[i][j] << "\t";
		}
	cout << endl;
	}
	return 0;
}


template<typename T, size_t size_r, size_t size_c>
inline T Matrix<T, size_r, size_c>::max() const
{
	int max=0;
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	cout << "Max->";
	return max;

}

template<typename T, size_t size_r, size_t size_c>
inline T Matrix<T, size_r, size_c>::min() const
{
	int min = 0;
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
	}
	cout << "Min->";
	return min;
}

//template<typename T, size_t size_r, size_t size_c>
//inline T Matrix<T, size_r, size_c>::operator+(int s)
//{
//	Matrix temp;
//	for (size_t i = 0; i < size_r; i++)
//	{
//		for (size_t j = 0; j < size_c; j++)
//		{
//		    temp.arr[i][j]=arr[i][j] + s;
//		}
//	}
//	return (temp);
//}


template<typename T, size_t size_r, size_t size_c>
inline T& Matrix<T, size_r, size_c>::operator=(Matrix& other)
{
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			arr[i][j] = other.arr[i][j];
		}
	}
}

template<typename T, size_t size_r, size_t size_c>
inline bool Matrix<T, size_r, size_c>::operator==(const Matrix& other)
{
	return *this==other;
}

template<typename T, size_t size_r, size_t size_c>
inline bool Matrix<T, size_r, size_c>::operator!=(const Matrix& other)
{
	return !(*this==other);
}





template<typename T, size_t size_r, size_t size_c>
inline std::ostream& operator<<(std::ostream& out, const Matrix<T, size_r, size_c> obj)
{
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			out << obj.arr[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}
template<typename T, size_t size_r, size_t size_c>
inline std::ostream& operator>>(std::iostream& in,  Matrix<T,size_r,size_c> obj)
{
	for (size_t i = 0; i < size_r; i++)
	{
		for (size_t j = 0; j < size_c; j++)
		{
			in >> obj.arr[i][j];
		}
		cout << endl;
	}
	return in;
}

