#pragma once
#include <EngineOGL/OPrerequisites.h>

class ORect {

public:
	ORect() {

	}
	ORect(i32 width, i32 height): width(width),height(height) {

	}
	ORect(i32 width, i32 height,i32 left, i32 top) : width(width), height(height),left(left),top(top) {

	}
	ORect(const ORect& rect) : width(rect.width), height(rect.height), left(rect.left), top(rect.top) {

	}
    



	i32 width = 0, height = 0, left = 0, top = 0;






};
