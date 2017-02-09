// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-05-2017
//
// Last Modified By : nickl
// Last Modified On : 02-06-2017
// ***********************************************************************
// <copyright file="Testing.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#define _CRTDBG_MAP_ALLOC
#include <iostream>

using std::cout;
using std::endl;

#include <Windows.h>
#include <crtdbg.h> 

#include	"Array2D.h"
#include	"Context.h"
#include	"ConInfoStruct.h"
#include	"CoordinateDecorator.h"

using namespace ConsoleApplicationLayer;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ConInfoStruct *consoleInfo = new ConInfoStruct;
	ConsoleContext *board = new ConsoleContext(*consoleInfo);
	CoordinateDecorator coordDec(board);

	while (coordDec.Draw() && board->ReadInput());

	board->Purge();
	delete board;
	return 0;
}


