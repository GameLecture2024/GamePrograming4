#pragma once

/*
*   ����(���� �迭)�� Ư¡
*   - ���̰� ���� �� �ִ�. ���� ũ�� ��ȯ�� �����ϴ�.
*   - �ڵ����� ũ�Ⱑ ����ȴ�.
* 
*   int arr[20];
*/

/*
*  int sizeũ��;
*  int capacity���뷮;
* 
*  int arr = new int[5];  size0. capacity 5.
*  size 6 int[6];
*  arr = new int[10];
* 
*  resize();
*  int size, capacity;
*/

// int R = int;
// auto AA

// value�� �ش��ϴ� Ÿ���� T�� ��ȯ�غ�����.
template<typename T>  // int, double, string
class MyVector
{
private:
	int size;	   // 1 double 
	int capacity;  // 4.4 "4"
	T* vec;	       // double* int* std::string*

public:
	// ������
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// �Ҹ���
	~MyVector()
	{
		delete[] vec;
	}

	T& operator[](int idx) // vec[1.1] =  
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		// size : ���� �迭�� ����ִ� ������ ����
		// nsize : �����Ϸ��� �������� ũ��

		// ������ ������ ������
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}
		// capacity ��� �����ұ�/
		capacity = nsize;

		T* arr = new T[nsize];

		// vec[0] ,vec[1] ... size
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;	// ������ vec ����Ű�� �ִ� ������ �޸� �����Ѵ�. 32gb
		vec = arr;		// vec�� ���ο� ������ �ٽ� �����Ѷ�. (arr�� �ּҸ� �����Ѷ�)
		//delete[] arr;
		
	}
	void push_back(const T& element)	// vec.push_back(6)
	{
		// capacity  <= size		
		if (capacity <= size)
		{
			capacity = capacity * 2;  // 
			resize(capacity);
		}

		vec[size] = element;
		size++;
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;		
	}

	int Size() { return size; }
};

void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}

// int size() {return size;}

#include <iostream>

void test2()
{
	MyVector<int> vec(5);


	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i + 1);

		std::cout << vec[i] << " ";
	}

	vec.push_back(6);
	std::cout << std::endl;

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	// 
	MyVector<double> vec2(5);
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back(i + 0.1);

		std::cout << vec2[i] << " ";
	}
}