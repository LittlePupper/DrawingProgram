/// \file	Line.h.
/// \author	Nora White
/// \date	2017-09-28
/// \brief	Declares the line class

#pragma once
#include "cassert"
#include "ScreenElement.h"

/// \namespace	std
/// \brief		The default namespace

using namespace std;

/// \class	Line
/// \brief	A line that is derived from the ScreenElement class and is used to make boxes

class Line : public ScreenElement
{
public:

	/// \fn	Line::Line(int startRow = 5, int startCol = 5, int endRow = 5, int endCol = 10, char letter = '*');
	/// \brief	Constructor
	/// \param	startRow	(Optional) int, the start row of the line
	/// \param	startCol	(Optional) int, the start column of the line
	/// \param	endRow  	(Optional) int, the end row of the line
	/// \param	endCol  	(Optional) int, the end column of the line
	/// \param	letter  	(Optional) char, the letter to use to make the line

	Line(int startRow = 5, int startCol = 5, int endRow = 5, int endCol = 10, char letter = '*');

	/// \fn	Line::~Line();
	/// \brief	Destructor

	~Line();

	/// \brief	The start row of the line
	int startRow;
	/// \brief	The start column of the line
	int startCol;
	/// \brief	The end row of the line
	int endRow;
	/// \brief	The end column of the line
	int endCol;
	/// \brief	The letter to use to make the line
	char letter;

	/// \fn		virtual void Line::draw(Screen &screen);
	/// \brief	Draws itself to the given screen
	/// \param	&screen	Screen, a reference to screen

	virtual void draw(Screen &screen);

	/// \fn		virtual void Line::read(istream &is);
	/// \brief	Reads the given input stream
	/// \param	&is		istream, reference to the input stream to read

	virtual void read(istream &is);
};