/// \file	Screen.h.
/// \author	Nora White
/// \date	2017-09-28
/// \brief	Declares the screen class

#pragma once
#include <iostream>
#include <vector>

/// \namespace	std
/// \brief		The default namespace

using namespace std;

/// \class	Screen
/// \brief	A screen which is an abstraction for a two-dimensional 
/// 		array of characters. All ScreenElements draw to Screen.


class Screen
{
private:
	/// \brief	The total rows available to be drawn on
	int rows;
	/// \brief	The total columns available to be drawn on
	int columns;
	/// \brief	Vector of characters that ScreenElement draws to
	vector <vector<char>> screenVector;


public:

	/// \fn		Screen::Screen(int rows = 24, int columns = 80);
	/// \brief	Constructor
	/// \param	rows   	(Optional) int, the total rows available to be drawn on
	/// \param	columns	(Optional) int, the total columns available to be drawn on

	Screen(int rows = 24, int columns = 80);

	/// \fn		Screen::~Screen();
	/// \brief	Destructor

	~Screen();

	/// \fn		void Screen::clear();
	/// \brief	Clears itself to its blank state (before any ScreenElements 
	/// 		have been drawn on it)

	void clear();

	/// \fn		void Screen::set(int row, int col, char ch);
	/// \brief	Sets
	/// \param	row	int, the row of which the char is being drawn to
	/// \param	col	int, the column of which the char is being drawn to
	/// \param	ch 	char, the char that is being drawn

	void set(int row, int col, char ch);

	/// \fn		friend std::ostream Screen::&operator<<(std::ostream &output, const Screen &screen);
	/// \brief	Stream insertion operator
	/// \param	&output	ostream, the stream that requires outputting
	/// \param 	&screen	Screen, a reference to screen
	/// \return	The stream of letters put together into a screen-like shape

	friend std::ostream &operator<<(ostream &output, const Screen &screen);
};


