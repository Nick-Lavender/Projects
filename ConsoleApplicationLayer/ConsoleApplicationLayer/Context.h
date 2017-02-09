#pragma once
#include	"IConsoleContext.h"

namespace ConsoleApplicationLayer
{
	using namespace Enums;

	class ConsoleContext : public IConsoleContext
	{
	public:
		ConsoleContext() = delete;
		ConsoleContext(ConInfoStruct& commonStruct);
		BOOL InitWindow();
		BOOL ReadInput();
		BOOL ProcessMouseInput();
		BOOL ProcessKeyInput();
		BOOL Update();
		ConInfoStruct& GetCommonStruct();
		ConsoleContext(const ConsoleContext& obj) = delete;
		ConsoleContext& operator=(const ConsoleContext& rhs) = delete;
		BOOL Draw() override;
		void Purge();
	};

	inline ConsoleContext::ConsoleContext(ConInfoStruct &commonStruct) 
	{
		CommStruct = &commonStruct;
		InitWindow();
	}
	inline BOOL ConsoleContext::InitWindow()
	{
		CommStruct->Hin = GetStdHandle(STD_INPUT_HANDLE);
		CommStruct->Hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleDisplayMode(CommStruct->Hout, CONSOLE_FULLSCREEN_MODE, nullptr);
		SetCursorPos(0, 0);

		GetConsoleScreenBufferInfo(CommStruct->Hout, &CommStruct->bufferInfo);
		SetConsoleScreenBufferSize(CommStruct->Hout, CommStruct->bufferInfo.dwMaximumWindowSize);
		SetConsoleCursorInfo(CommStruct->Hout, &CommStruct->CursorInfo);
		GetConsoleMode(CommStruct->Hin, &CommStruct->oldConsoleMode);

		return returnVal;
	}
	inline BOOL ConsoleContext::ProcessMouseInput()
	{
		CommStruct->ConCursor = CommStruct->
			inputRecords[CommStruct->numberOfRecordsRead]
			.Event.MouseEvent.dwMousePosition;
		// TODO: Finish ProcessMouseInput().

		return returnVal;
	}

	inline BOOL ConsoleContext::Update()
	{
		return returnVal;
	}

	inline ConInfoStruct& ConsoleContext::GetCommonStruct()
	{
		return *CommStruct;
	}

	inline BOOL ConsoleContext::ReadInput()
	{
		SetConsoleMode(CommStruct->Hin, CommStruct->newConsoleMode);
		ReadConsoleInput(CommStruct->Hin
			, CommStruct->inputRecords
			, CommStruct->maxRecords
			, &CommStruct->numberOfRecordsRead);
		if (CommStruct->numberOfRecordsRead)
		{
			DWORD index = 0;
			while (CommStruct->numberOfRecordsRead--) // TODO: IMMEDIATE: Processing this in reverse is a bad idea!
			{
				switch (CommStruct->inputRecords[CommStruct->numberOfRecordsRead].EventType)
				{
				case MOUSE_EVENT:
					ProcessMouseInput();
					Update();
					break;

				case KEY_EVENT:
					ProcessKeyInput();
					Update();
					break;

				case WINDOW_BUFFER_SIZE_EVENT:
					Update();
					break;

				case MENU_EVENT:
					Update();
					break;

				default:
					Update();
					break;
				}
			}
		}
		FlushConsoleInputBuffer(CommStruct->Hin);
		return returnVal; // TODO: Finish ReadInput()
	}

	inline BOOL ConsoleContext::ProcessKeyInput()
	{
		if (CommStruct->inputRecords[CommStruct->numberOfRecordsRead]
			.Event.KeyEvent.uChar.AsciiChar == QUIT)
		{
			returnVal = false;
			// TODO: Finish ProcessKeyInput().
		}
		else
		{
			if (!CommStruct->inputRecords[CommStruct->numberOfRecordsRead]
				.Event.KeyEvent.bKeyDown &&
				CommStruct->inputRecords[CommStruct->numberOfRecordsRead]
				.Event.KeyEvent.uChar.AsciiChar == DRAW_COORD)
			{
				FLAGS = (FLAGS ^ DISPLAY_COORD);
				returnVal = true;
			}
		}
		return returnVal;
	}

	inline BOOL ConsoleContext::Draw()
	{		
		return returnVal;
	}

	inline void ConsoleContext::Purge()
	{
		CommStruct->Purge();
		delete CommStruct;
		CommStruct = nullptr;
	}
}
