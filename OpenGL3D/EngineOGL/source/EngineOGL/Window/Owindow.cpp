#include <EngineOGL/Window/Owindow.h>
#include <Windows.h>
#include <assert.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
	{
		Owindow* window = (Owindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		break;
	}

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);

	}
	return NULL;
}




Owindow::Owindow()
{

	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGLGAMETEST";
	wc.lpfnWndProc = WndProc;


	assert(RegisterClassEx(&wc));

	RECT rc = {
		0,
		0,
		1024,
		768
	};

	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,false);


	m_handle =  CreateWindowEx(NULL, L"OGLGAMETEST", L"TEST|OpenGL", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left,rc.bottom - rc.top,NULL,NULL,NULL,NULL);

	assert(m_handle);
	SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow((HWND)m_handle, SW_SHOW);
	UpdateWindow((HWND)m_handle);


}

Owindow::~Owindow()
{
	DestroyWindow(HWND(m_handle));

}

void Owindow::onDestroy()
{
	m_handle = nullptr;
}

bool Owindow::isClosed()
{
	return !m_handle;
}
