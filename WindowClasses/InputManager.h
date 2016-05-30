#ifndef INPUT_Manager
#define INPUT_Manager

#include <Windows.h>
#include <conio.h>

using namespace std;
namespace myconsolewindows
{
	extern class BasicWindow;

	class InputManagerInterface
	{
	protected:
		BasicWindow*& refToCurrentWindowPtr;
	public:
		InputManagerInterface(BasicWindow*& refToCurWinPtr);
		virtual bool Check() = 0;
	};

	// ��������� �� ��������� �������: �������, Enter, Escape
	class BasicKeyboardInputManager : public InputManagerInterface
	{
	protected:
		bool KeyReact(wchar_t key);
	public:
		BasicKeyboardInputManager(BasicWindow *& refToAct) : InputManagerInterface(refToAct)
		{

		}

		bool Check() override;
	};

	class MouseKeyboardInputManager : public BasicKeyboardInputManager
	{
	protected:
		bool CheckMouseInput();
		HWND hwndConsole;
		RECT rectConsole;
		POINT posCursor;

		void CutWindowRect();
		bool IntersectConsoleRect();
	public:
		MouseKeyboardInputManager(BasicWindow*& refToWin) : BasicKeyboardInputManager(refToWin)
		{
			hwndConsole = GetConsoleWindow();
		}

		bool Check() override;
	};
}


#endif