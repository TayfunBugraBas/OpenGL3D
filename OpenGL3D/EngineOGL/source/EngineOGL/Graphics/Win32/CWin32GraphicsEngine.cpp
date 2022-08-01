#include <EngineOGL/Graphics/OGraphicsENG.h>
#include <glad/glad_wgl.h>
#include <glad/glad.h>
#include <stdexcept>
#include <assert.h>






OGraphicsENG::OGraphicsENG()
{
	WNDCLASSEX wcc = {};
	wcc.cbSize = sizeof(WNDCLASSEX);
	wcc.lpszClassName = L"3DDummytester";
	wcc.lpfnWndProc = DefWindowProc;
	wcc.style = CS_OWNDC;


	auto classId = RegisterClassEx(&wcc);

	assert(classId);/* it can give assert not initialized error idk why maybe something is broken but it works fine */
	/*i found the error  assert.h must be the last included library... */



	auto dummyWindow = CreateWindowEx(NULL, MAKEINTATOM(classId), L"3DDummytester", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);

	assert(dummyWindow);

	auto dummyDC = GetDC(dummyWindow);

	PIXELFORMATDESCRIPTOR pixelFromatDesc = {};
	pixelFromatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFromatDesc.nVersion = 1;
	pixelFromatDesc.iPixelType = PFD_TYPE_RGBA;
	pixelFromatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFromatDesc.cColorBits = 32;
	pixelFromatDesc.cAlphaBits = 8;
	pixelFromatDesc.cDepthBits = 8;
	pixelFromatDesc.iLayerType = PFD_MAIN_PLANE;


	auto pixelFormat = ChoosePixelFormat(dummyDC, &pixelFromatDesc);
	SetPixelFormat(dummyDC, pixelFormat, &pixelFromatDesc);


	auto dummyContext = wglCreateContext(dummyDC);
	assert(dummyContext);

	wglMakeCurrent(dummyDC, dummyContext);

	if (!gladLoadWGL(dummyDC)) {
		throw std::runtime_error("OGraphics gladwgl fail");
	}
	if (!gladLoadGL()) {
		throw std::runtime_error("OGraphics gladgl fail");
	}

	wglMakeCurrent(dummyDC, 0);
	wglDeleteContext(dummyContext);
	ReleaseDC(dummyWindow, dummyDC);
	DestroyWindow(dummyWindow);


}


OGraphicsENG::~OGraphicsENG()
{
}
