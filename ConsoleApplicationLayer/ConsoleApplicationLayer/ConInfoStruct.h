#pragma once
#include <Windows.h>
#include <stdio.h>

#include	"ConClientExcept.h"
#include	"CellColor.h"
#include	"Array2D.h"
#include	"Cell.h"


namespace ConsoleApplicationLayer
{
	

	struct ConInfoStruct
	{
		ConInfoStruct();
		~ConInfoStruct();
		ConInfoStruct(const ConInfoStruct& obj);
		ConInfoStruct& operator=(const ConInfoStruct& rhs);
		void Purge();

		HWND Hwnd;
		HANDLE Hin;
		HANDLE Hout;
		HWND Hwndnew;
		HANDLE HnewIn;
		HANDLE HnewOUT;
		COORD MaxScrnSz;
		COORD ConCursor;
		DWORD oldConsoleMode;
		SMALL_RECT boardDimsns;
		Array2D<Cell>* cellArry;
		DWORD numberOfRecordsRead;
		wchar_t* uniChar = nullptr;
		ConClientExcept* excep_error;
		DWORD ContextMenuConsoleMode;
		DWORD ContextMenuConsoleModeOld;
		static const DWORD maxRecords = 10;
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		INPUT_RECORD inputRecords[maxRecords];
		DWORD newConsoleMode = ENABLE_WINDOW_INPUT |
			ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;

		ConInfoStruct& GetReference() { return *this; }
		const CONSOLE_CURSOR_INFO CursorInfo = { 1, FALSE };
	};

	inline ConInfoStruct::ConInfoStruct()
		: Hwnd(nullptr)
		, Hin(nullptr)
		, Hout(nullptr)
		, Hwndnew(nullptr)
		, HnewIn(nullptr)
		, HnewOUT(nullptr)
		, oldConsoleMode(0)
		, cellArry(nullptr)
		, numberOfRecordsRead(0)
		, excep_error(nullptr)
		, ContextMenuConsoleMode(0)
		, ContextMenuConsoleModeOld(0)
	{
		// TODO: Double check ConInfoStruct no arg CTOR
	}

	inline ConInfoStruct::ConInfoStruct(const ConInfoStruct& obj)
		: Hwnd(nullptr)
		, Hin(nullptr)
		, Hout(nullptr)
		, Hwndnew(nullptr)
		, HnewIn(nullptr)
		, HnewOUT(nullptr)
		, oldConsoleMode(0)
		, cellArry(nullptr)
		, numberOfRecordsRead(0)
		, excep_error(nullptr)
		, ContextMenuConsoleMode(0)
		, ContextMenuConsoleModeOld(0)
	{
		// TODO: ConInfoStruct Copy CTOR.
	}

	inline ConInfoStruct& ConInfoStruct::operator=(const ConInfoStruct& rhs)
	{
		// TODO: Finish ConInfoStruct OP =.
		return *this;
	}
	inline ConInfoStruct::~ConInfoStruct()
	{
		// TODO: ConInfoStruct DTOR.
	}

	inline void ConInfoStruct::Purge()
	{
		if (excep_error)
		{
			excep_error->Purge();
			delete excep_error;
			excep_error = nullptr;
		}
	}
}
