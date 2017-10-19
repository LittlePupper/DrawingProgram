// \author	Nora White
// \date	2017-09-28

#include "stdafx.h"
#include "Line.h"
#include <assert.h>

// \fn	Line::Line(int startRow = 5, int startCol = 5, int endRow = 5, int endCol = 10, char letter = '*');
// \brief	Constructor
// \param	startRow	(Optional) int, the start row of the line
// \param	startCol	(Optional) int, the start column of the line
// \param	endRow  	(Optional) int, the end row of the line
// \param	endCol  	(Optional) int, the end column of the line
// \param	letter  	(Optional) char, the letter to use to make the line

Line::Line(int startRow, int startCol, int endRow, int endCol, char letter)
{
	assert((startRow == endRow) || (startCol == endCol));
	this->startRow = startRow;
	this->startCol = startCol;
	this->endRow = endRow;
	this->endCol = endCol;
	this->letter = letter;
};

// \fn	Line::~Line();
// \brief	Destructor

Line::~Line()
{
}

// \fn		virtual void Line::draw(Screen &screen);
// \brief	Draws itself to the given screen
// \param	&screen	Screen, a reference to screen

void Line::draw(Screen &screen)
{
	if (startRow == endRow)
		for (int i = startCol; i <= endCol; i++)
			screen.set(startRow, i, letter);
	else
		for (int i = startRow; i <= endRow; i++)
			screen.set(i, startCol, letter);
}

// \fn		virtual void Line::read(istream &is);
// \brief	Reads the given input stream
// \param	&is		istream, reference to the input stream to read

void Line::read(istream &is)
{
	is >> startRow >> startCol >> endRow >> endCol >> letter;
}
