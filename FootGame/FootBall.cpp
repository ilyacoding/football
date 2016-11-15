//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("UnitAuth.cpp", FormAuth);
USEFORM("UnitMain.cpp", BallGame);
USEFORM("UnitMenu.cpp", FormMenu);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFormMenu), &FormMenu);
		Application->CreateForm(__classid(TBallGame), &BallGame);
		Application->CreateForm(__classid(TFormAuth), &FormAuth);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
