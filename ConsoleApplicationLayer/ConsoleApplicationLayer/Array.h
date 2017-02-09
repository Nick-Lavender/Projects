// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-05-2017
// ***********************************************************************
// <copyright file="Array.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once

#include <iostream>
#include	"Exception.h"

template<typename T>
class Array
{
public:
	
	Array();	
	Array(int length, int start = 0);	
	Array(const Array &obj);	
	~Array();	
	Array& operator=(const Array &rhs);	
	T& operator[](int index);
	
	int getStartIndex();	
	void setStartIndex(int index);	
	int getLength();	
	void setLength(int length);	
	void Purge();	
	friend ostream& operator<<(ostream os, const Array<T> &obj);

private:
	T* m_array;
	int m_length;
	int m_start_index;
};

template<typename T>
ostream & operator<<(ostream os, const Array<T> & obj)
{
	cout << "Not implemented in Array class << op";
	return os;
}
template<typename T>
Array<T>::Array() : m_array(nullptr)
				  , m_length(0)
				  , m_start_index(0)
{}
template<typename T>
Array<T>::Array(int length, int start) : m_length(length)
									   , m_start_index(start)
{
	if (length < 0)
	{
		throw Exception("Invalid: negative range. Array CTOR");
	}
	m_array = new T[length];
}
template<typename T>
Array<T>::Array(const Array & obj)
{
	this->m_array = new T[obj.m_length];
	this->m_length = obj.m_length;
	this->m_start_index = obj.m_start_index;

	for (auto index = m_start_index; index < m_length; index++)
	{
		this->m_array[index] = obj.m_array[index];
	}
}
template<typename T>
Array<T>::~Array()
{
	Purge();
}
template<typename T>
Array<T>& Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		this->m_length = rhs.m_length;
		this->m_start_index = rhs.m_start_index;
		this->m_array = new T[rhs.m_length];
		for (auto index = m_start_index; index < rhs.m_length; index++)
		{
			this->m_array[index] = rhs.m_array[index];
		}
	}
	return *this;
}
template<typename T>
T & Array<T>::operator[](int index)
{
	if (index < 0 - m_start_index || index > m_length - m_start_index)

	{
		throw Exception("Out of Bounds in Array op []");
	}

	return m_array[index - m_start_index];
}
template<typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}
template<typename T>
void Array<T>::setStartIndex(int index)
{
	m_start_index = index;
}
template<typename T>
int Array<T>::getLength()
{
	return m_length;
}
template<typename T>
void Array<T>::Purge()
{
	delete[] m_array;
	m_array = nullptr;
}
template<typename T>
void Array<T>::setLength(int length)
{
	if (length <= 0)
	{
		throw Exception("Invalid length. Array setLength.");
	}

	int temp_length = m_length < length ? m_length : length;
	T *temp_array = new T[length];

	for (auto index = 0; index < temp_length; index++)
	{
		temp_array[index] = m_array[index];
	}
	delete[] m_array;
	m_array = temp_array;
	m_length = length;
}
