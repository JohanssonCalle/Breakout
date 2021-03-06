// Input.h

#pragma once

enum EMouseButton {
	MB_LEFT,
	MB_RIGHT,
	MB_COUNT
};

class Keyboard {
	friend class Engine;
public:
	Keyboard();

	bool IsDown(int key) const;
	bool IsDownOnce(int key) const;
	bool IsDownOnceAny() const;

	void PostUpdate();

private:
	bool m_current[256];
	bool m_previous[256];
};

class Mouse {
	friend class Engine;
public:
	Mouse();

	int GetX() const;
	int GetY() const;
	bool IsDown(EMouseButton button) const;
	bool IsDownOnce(EMouseButton button) const;
	bool IsDownOnceAny() const;

	void PostUpdate();

private:
	bool m_current[MB_COUNT];
	bool m_previous[MB_COUNT];
	int m_x;
	int m_y;
};
