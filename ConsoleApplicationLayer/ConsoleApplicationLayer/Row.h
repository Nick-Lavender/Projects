// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="Row.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <iostream>

template<typename T>
class Array2D;



template<typename T>
class Row
{
public:	

	/// <summary>
	/// Operator[]s the specified col.
	/// </summary>
	/// <returns></returns>
	Row();

	/// <summary>
	/// Operator[]s the specified col.
	/// </summary>
	/// <param name="array">The array.</param>
	/// <param name="row">The row.</param>
	/// <returns></returns>
	Row(Array2D<T> & array, int row);
	/// <summary>
	/// Operator[]s the specified col.
	/// </summary>
	/// <param name="col">The col.</param>
	/// <returns></returns>
	/// / Operator[]s the specified col.
	T& operator[](int col);
	/// <summary>
	/// The m row
	/// </summary>
	/// / <returns></returns>
	T& operator[](int col) const;
private:
	/// <summary>
	/// Operator[]s the specified col.
	/// </summary>
	/// <param name="col">The col.</param>
	/// <returns></returns>
	Array2D<T> & m_Array2d;
	int m_row;
	/// <summary>
	/// The m array2d
	/// </summary>
};





template<typename T>
Row<T>::Row(): m_row(0) {}




template<typename T>
Row<T>::Row(Array2D<T>& array, int row) : m_Array2d(array), m_row(row)
{}


template<typename T>
T& Row<T>::operator[](int col)
{
	if (col >= 0 && col < m_Array2d.GetCol())
	{
		return m_Array2d.Select(m_row, col);
	}
	throw new Exception("Out of Bounds. Row op[]");
}


template<typename T>
T& Row<T>::operator[](int col)const
{
	if (col >= 0 && col <= m_Array2d.GetCol())
	{
		return m_Array2d.Select(m_row, col);

	}
	throw new Exception("Out of Bounds. Row op[] const");
}
