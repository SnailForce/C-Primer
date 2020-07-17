// 7.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Screen
{
	friend class WindowMgr;
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(pos h, pos w) : height(h), width(w), contents(h* w, ' ') {}
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h* w, c) {}
	char get() const;
	Screen& move(pos r, pos c);
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display();
private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;
};
inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
inline char Screen::get() const
{
	return contents[cursor];
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}
inline Screen& Screen::display()
{
	cout << contents;
	return *this;
}

class WindowMgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	vector<Screen> screens{ Screen(24, 80,' ') };
};
inline void WindowMgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}
inline WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

int main()
{
	std::cout << "Hello World!\n";
	Screen s(5, 5, 'X');
	s.move(4, 0).set('#').display();
	cout << endl;
	s.display();
	cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
