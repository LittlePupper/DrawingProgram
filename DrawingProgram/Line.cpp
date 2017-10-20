// \author	Nora White
// \date	2017-10-19

#include "stdafx.h"
#include "Line.h"
#include "Exception.h"
#include <assert.h>

// \fn	Line::Line(int startRow = 5, int startCol = 5, int endRow = 5, int endCol = 10, char letter = '*');
// \brief	Constructor
// \param	startRow	(Optional) int, the start row of the line
// \param	startCol	(Optional) int, the start column of the line
// \param	endRow  	(Optional) int, the end row of the line
// \param	endCol  	(Optional) int, the end column of the line
// \param	letter  	(Optional) char, the letter to use to make the line
// \throws	invalid_line_error

Line::Line(int startRow, int startCol, int endRow, int endCol, char letter)
{
	if ((startRow == endRow) || (startCol == endCol))
	{
		this->startRow = startRow;
		this->startCol = startCol;
		this->endRow = endRow;
		this->endCol = endCol;
		this->letter = letter;
	}
	else
		throw invalid_line_error();
};

// \fn	Line::~Line();
// \brief	Destructor

Line::~Line()
{
}

// \fn		virtual void Line::draw(Screen &screen);
// \brief	Draws itself to the given screen
// \param	&screen	Screen, a reference to screen
// \throws	input_format_error

void Line::draw(Screen &screen)
{
	if ((startCol > endCol) || (startRow > endRow))
		throw input_format_error();
	else
	{
		if (startRow == endRow)
			for (int i = startCol; i <= endCol; i++)
				screen.set(startRow, i, letter);
		else
			for (int i = startRow; i <= endRow; i++)
				screen.set(i, startCol, letter);
	}
}

// \fn		virtual void Line::read(istream &is);
// \brief	Reads the given input stream
// \param	&is		istream, reference to the input stream to read
// \throws	invalid_line_error

void Line::read(istream &is)
{
	is >> startRow >> startCol >> endRow >> endCol >> letter;
	if ((startRow != endRow) || (startCol != endCol))
		throw invalid_line_error();
}
