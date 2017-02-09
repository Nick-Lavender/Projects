// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-03-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="CellColor.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <Windows.h>

namespace ConsoleApplicationLayer
{
	typedef struct cellColor
	{
		cellColor() : fg(0)
			, bg(0)
			, intensity(0) {}

		SHORT fg;
		SHORT bg;
		SHORT intensity;
	} *PCELL_COLOR, CELL_COLOR;
}
