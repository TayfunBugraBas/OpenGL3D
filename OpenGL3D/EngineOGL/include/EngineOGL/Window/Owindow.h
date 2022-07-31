#pragma once


class Owindow
{
public:
	Owindow();
	~Owindow();

	void onDestroy();
	bool isClosed();
private:

	void* m_handle = nullptr;




};

