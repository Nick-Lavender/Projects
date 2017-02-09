// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="Cell.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <Windows.h>
#include <stdio.h>
#include	"CellColor.h"


/// <summary>
/// The ConsoleContext namespace.
/// </summary>
/// TODO Edit XML Comment Template for ConsoleContext
namespace ConsoleApplicationLayer
{
	/// <summary>
	/// Class Cell.
	/// </summary>
	/// <seealso cref="SMALL_RECT" />
	/// TODO Edit XML Comment Template for Cell
	class Cell : public SMALL_RECT
	{
	public:

		/// <summary>
		/// Initializes a new instance of the <see cref="Cell" /> class.
		/// </summary>
		/// / The cellcolor
		/// TODO Edit XML Comment Template for Cell
		Cell();

		/// <summary>
		/// Initializes a new instance of the <see cref="Cell" /> class.
		/// </summary>
		/// <param name="dimensions">The dimensions.</param>
		/// / The covered
		/// TODO Edit XML Comment Template for Cell
		explicit Cell(SMALL_RECT dimensions);
		/// <summary>
		/// Initializes a new instance of the <see cref="Cell" /> class.
		/// </summary>
		/// <param name="obj">The object.</param>
		/// TODO Edit XML Comment Template for Cell
		Cell(const Cell &obj);
		/// <summary>
		/// Finalizes an instance of the <see cref="Cell" /> class.
		/// </summary>
		/// TODO Edit XML Comment Template for ~Cell
		~Cell();

		/// <summary>
		/// The covered
		/// </summary>
		/// <param name="rhs">The RHS.</param>
		/// <returns>ConsoleContext.Cell &.</returns>
		Cell& operator=(const Cell &rhs);
		/// <summary>
		/// Purges this instance.
		/// </summary>
		/// TODO Edit XML Comment Template for Purge
		void Purge();

	private:
		/// <summary>
		/// The hot
		/// </summary>
		/// TODO Edit XML Comment Template for hot
		bool hot = false;
		/// <summary>
		/// The flag
		/// </summary>
		/// TODO Edit XML Comment Template for flag
		bool flag = false;
		/// <summary>
		/// The bomb
		/// </summary>
		/// TODO Edit XML Comment Template for bomb
		bool bomb = false;
		/// <summary>
		/// The covered
		/// </summary>
		/// TODO Edit XML Comment Template for covered
		bool covered = true;
		/// <summary>
		/// The cellcolor
		/// </summary>
		/// TODO Edit XML Comment Template for cellcolor
		PCELL_COLOR cellcolor;
	};



	inline Cell::Cell() : SMALL_RECT({0, 0, 3, 3})
	                    , cellcolor(nullptr) {}



	inline Cell::Cell(SMALL_RECT dimensions) : SMALL_RECT(dimensions)
	                                         , cellcolor(nullptr) {}


	inline Cell::Cell(const Cell & obj)
	{
		*this = obj;
	}



	inline Cell& Cell::operator=(const Cell& rhs)
	{
		if (this != &rhs)
		{
			flag = rhs.flag;
			bomb = rhs.bomb;
			covered = rhs.covered;
			cellcolor = new CELL_COLOR();
			cellcolor->bg = rhs.cellcolor->bg;
			cellcolor->bg = rhs.cellcolor->fg;
			cellcolor->intensity = rhs.cellcolor->intensity;
		}
		return *this;
	}


	inline Cell::~Cell() {}


	inline void Cell::Purge()
	{
		delete cellcolor;
		cellcolor = nullptr;
	}
}
