#pragma once
#include	"IConsoleContext.h"
#include	"Context.h"

namespace ConsoleApplicationLayer
{
	class Decorator : public IConsoleContext
	{
	public:
		explicit Decorator(IConsoleContext* inner)
		{
			console_context = inner;
		}

		BOOL Draw() override
		{
			draw_op_success = console_context->Draw();
			return draw_op_success;
		}

	protected:
		IConsoleContext* console_context;
		ConInfoStruct *common_struct = CommStruct;
	private:
		BOOL draw_op_success = true;
	};
}
