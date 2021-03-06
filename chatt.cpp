#include <stdexcept>
#include <cstdio>
#include "win.h"
#include "utils.h"
#include "wsa.h"
#include "stun.h"
#include "cproto.h"
#include "gui.h"
//testkommentar
// Huvudfilen

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	try // Fånga alla körtidsfel så att man kan visa en ruta med felet
	{
		wsaHandler.initialise();

		MainWindow mw;
		while (mw) mw.update();
	}
	catch (const WSAException& e) // WSAException har en felkod som man kan skriva ut
	{
		std::stringstream ss;
		ss << e.what();
		ss << "\r\nError code: ";
		ss << e.errCode;
		MessageBoxA(
			nullptr,
			ss.str().c_str(),
			"Error",
			MB_ICONERROR | MB_TASKMODAL
		);
		return EXIT_FAILURE;
	}
	catch (const std::exception& e) // Andra fel som ärver från std::exception
	{
		MessageBoxA(nullptr, e.what(), "Error", MB_ICONERROR | MB_TASKMODAL);
		return EXIT_FAILURE;
	}
	catch (...) // För fel som inte ärver från std::exception (som de borde göra)
	{
		MessageBoxW(nullptr, L"Unknown error", L"Error", MB_ICONERROR | MB_TASKMODAL);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
