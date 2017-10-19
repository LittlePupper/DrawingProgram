// \author	Nora White
// \date	2017-09-28

#include "stdafx.h"
#include "Screen.h"
#include <stdlib.h>

// \fn		Screen::Screen(int rows = 24, int columns = 80);
// \brief	Constructor
// \param	rows   	(Optional) int, the total rows available to be drawn on
// \param	columns	(Optional) int, the total columns available to be drawn on

Screen::Screen(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

	screenVector.resize(rows);
	for (int i = 0; i < rows; i++)
		screenVector[i].resize(columns);

	clear();
}

// \fn		Screen::~Screen();
// \brief	Destructor

Screen::~Screen()
{
}

// \fn		void Screen::clear();
// \brief	Clears itself to its blank state (before any ScreenElements 
// 			have been drawn on it)

void Screen::clear()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			screenVector[i][j] = ' ';
}

// \fn		void Screen::set(int row, int col, char ch);
// \brief	Sets
// \param	row	int, the row of which the char is being drawn to
// \param	col	int, the column of which the char is being drawn to
// \param	ch char, the char that is being drawn

void Screen::set(int row, int column, char letter)
{
	screenVector[row][column] = letter;
}

// \fn		friend std::ostream Screen::&operator<<(std::ostream &output, const Screen &screen);
// \brief	Stream insertion operator
// \param	&output	ostream, the stream that requires outputting
// \param 	&screen	Screen, a reference to screen
// \return	The stream of letters put together into a screen-like shape

ostream & operator<<(ostream &output, const Screen &screen)
{
	for (int i = 0; i < screen.rows; i++) {
		for (int j = 0; j < screen.columns; j++)
			output << screen.screenVector[i][j];
		output << endl;
	}
	return output;
}