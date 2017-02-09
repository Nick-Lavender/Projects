// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-05-2017
// ***********************************************************************
// <copyright file="Array2D.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include	"Exception.h"
#include	"Row.h"
#include	"Array.h"
#include	"Cell.h"

/// <summary>
/// The maximum row
/// </summary>
/// TODO Edit XML Comment Template for MAX_ROW
const int MAX_ROW = 100;
/// <summary>
/// The maximum col
/// </summary>
/// TODO Edit XML Comment Template for MAX_COL
const int MAX_COL = 100;

template <typename T>
class Array2D
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Array2D" /> class.
	/// </summary>
/// <summary>
/// Initializes a new instance of the <see cref="Array2D"/> class.
/// </summary>
/// TODO Edit XML Comment Template for Array2D
	Array2D();
	/// <summary>
	/// Initializes a new instance of the <see cref="Array2D" /> class.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
/// <summary>
/// Initializes a new instance of the <see cref="Array2D"/> class.
/// </summary>
/// <param name="row">The row.</param>
/// <param name="col">The col.</param>
/// TODO Edit XML Comment Template for Array2D
	Array2D(int row, int col);
	/// <summary>
	/// Initializes a new instance of the <see cref="Array2D" /> class.
	/// </summary>
	/// <param name="Size">The size.</param>
/// <summary>
/// Initializes a new instance of the <see cref="Array2D"/> class.
/// </summary>
/// <param name="Size">The size.</param>
/// TODO Edit XML Comment Template for Array2D
	Array2D(COORD& Size);

	/// <summary>
	/// Selects the specified row.
	/// </summary>
	/// <param name="cpy">The cpy.</param>
/// <summary>
/// Initializes a new instance of the <see cref="Array2D"/> class.
/// </summary>
/// <param name="cpy">The cpy.</param>
/// TODO Edit XML Comment Template for Array2D
	Array2D(const Array2D<T>& cpy);
	/// <summary>
	/// Finalizes an instance of the <see cref="Array2D" /> class.
	/// </summary>
/// <summary>
/// Finalizes an instance of the <see cref="Array2D"/> class.
/// </summary>
/// TODO Edit XML Comment Template for ~Array2D
	~Array2D();

	/// <summary>
	/// Operator=s the specified RHS.
	/// </summary>
	/// <param name="rhs">The RHS.</param>
	/// <returns></returns>
/// <summary>
/// Operator=s the specified RHS.
/// </summary>
/// <param name="rhs">The RHS.</param>
/// <returns>Array2D&lt;T&gt;&.</returns>
/// TODO Edit XML Comment Template for operator=
	Array2D<T>& operator=(const Array2D<T>& rhs);
	Row<T> operator[](int row);
	Row<T> operator[](int row) const;
	/// <summary>
	/// Operator[]s the specified row.
	/// </summary>
	/// <returns>Row&lt;T&gt;.</returns>
	/// TODO Edit XML Comment Template for operator[]
	/// TODO Edit XML Comment Template for GetRow
	int GetRow();
	/// <summary>
	/// Gets the row.
	/// </summary>
	/// <returns>int.</returns>
	int GetRow() const;
	/// <summary>
	/// Gets the col.
	/// </summary>
	/// <returns>int.</returns>
	int GetCol();

	/// <summary>
	/// Sets the row.
	/// </summary>
	/// <param name="rows">The rows.</param>
	void SetRow(int rows);
	/// <summary>
	/// Sets the col.
	/// </summary>
	/// <param name="cols">The cols.</param>
	void SetCol(int cols);
	/// <summary>
	/// Selects the specified row.
	/// </summary>
	/// <param name="row">The row.</param>
	/// <param name="col">The col.</param>
	/// <returns>T &.</returns>
	T& Select(int row, int col);


	/// <summary>
	/// The m col
	/// </summary>
/// <summary>
/// The m row
/// </summary>
/// <summary>
/// The m array
/// </summary>
private:
	/// <summary>
	/// The m array
	/// </summary>
	/// TODO Edit XML Comment Template for m_array
	Array<T> m_array;
	/// <summary>
	/// The m row
	/// </summary>
	/// TODO Edit XML Comment Template for m_row
	int m_row;
	/// <summary>
	/// The m col
	/// </summary>
	/// TODO Edit XML Comment Template for m_col
	int m_col;
};



template <typename T>
Array2D<T>::Array2D(): m_row(0)
                     , m_col(0) {}


template <typename T>
Array2D<T>::Array2D(int row, int col) : m_row(row)
									  , m_col(col)
{
	try
	{
		m_array = Array<T>(row * col);
	}
	catch (const Exception& e)
	{
		cout << e.getMessage() << endl;
	}
}



template <typename T>
Array2D<T>::Array2D(COORD &Size)
{
	try
	{
		m_array = Array<T>(Size.X * Size.Y);
		m_row = Size.X;
		m_col = Size.Y;
	}
	catch (const Exception& e)
	{
		cout << e.getMessage() << endl;
	}
}



template <typename T>
Array2D<T>::Array2D(const Array2D<T>& cpy)
{
	m_array = cpy.m_array;
	m_col = cpy.m_col;
	m_row = cpy.m_row;
}


template <typename T>
Array2D<T>::~Array2D()
{
	m_col = 0;
	m_row = 0;
}


template <typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.GetRow();
		m_col = rhs.m_col;
	}
	return *this;
}

template <typename T>
Row<T> Array2D<T>::operator[](int row)
{
	if (row >= 0 && row < m_row)
	{
		return Row<T>((*this), row);
	}

	throw new Exception("Out of Bounds Array2D op[]");
}

template <typename T>
Row<T> Array2D<T>::operator[](int row) const
{
	if (row >= 0 && row <= m_row)
	{
		return Row<T>(const_cast<Array2D&>(*this), row);
	}

	throw new Exception("Out of Bounds Array2D op[] const");
}



template <typename T>
int Array2D<T>::GetRow()
{
	return m_row;
}



template <typename T>
int Array2D<T>::GetRow() const
{
	return m_row;
}



template <typename T>
void Array2D<T>::SetRow(int rows)
{
	if (rows > 0 && rows < MAX_ROW)
	{
		if (m_row != rows)
		{
			Array<T> temp(m_col * rows, 0);
			for (int i = 0; i < (rows * m_col); i++)
			{
				temp[i] = m_array[i];
			}
			m_row = rows;
			m_array.~Array();
			m_array = temp;
		}
	}
	else
		throw new Exception("Out of bounds Array2D.SetRow(int rows)");
}



template <typename T>
int Array2D<T>::GetCol()
{
	return m_col;
}



template <typename T>
void Array2D<T>::SetCol(int cols)
{
	if (cols > 0 && cols <= MAX_COL)
	{
		if (m_col != cols)
		{
			Array<T> temp(m_row * cols, 0);
			for (int i = 0; i < m_row; i++)
			{
				for (int i = 0; i < (m_row * cols); i++)
				{
					temp[i] = m_array[i];
				}
			}
			m_col = cols;
			m_array.~Array();
			m_array = temp;
		}
	}
	else
		throw new Exception("Array2D.SetCol(int col) out of bounds col");
}




template <typename T>
T& Array2D<T>::Select(int row, int col)
{
	if (row < m_row && row >= 0 && col < m_col && col >= 0)
	{
		return m_array[m_col * row + col];
	}

	throw new Exception("Out of Bounds Array2D Select");
}
