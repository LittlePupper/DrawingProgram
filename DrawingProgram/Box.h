/// \file	Box.h.
/// \author	Nora White
/// \date	2017-09-28
/// \brief	Declares the box class

#pragma once
#include "ScreenElement.h"
#include "Line.h"

/// \namespace	std
/// \brief		The default namespace

using namespace std;

/// \class	Box
/// \brief	A box that is derived from the ScreenElement class

class Box : public ScreenElement
{
private:
	/// \brief	The row of the top left corner of the box
	int upRow;
	/// \brief	The column of the top left corner of the box
	int upCol;
	/// \brief	The row of the bottom right corner of the box
	int botRow;
	/// \brief	The column of the bottom right corner of the box
	int botCol;
	/// \brief	The letter to use as the box border
	char letter;
	/// \brief	The top line pointer
	Line* topLine;
	/// \brief	The bottom line pointer
	Line* bottomLine;
	/// \brief	The left line pointer
	Line* leftLine;
	/// \brief	The right line pointer
	Line* rightLine;

public:

	/// \fn	Box::Box(int upRow = 5, int upCol= 5, int botRow = 20, int botCol = 15, char letter = '!');
	/// \brief	Constructor for Box which takes in 5 parameters
	/// \param	upRow 	(Optional) int, the row of the top left corner of the box
	/// \param	upCol 	(Optional) int, the column of the top left corner of the box
	/// \param	botRow	(Optional) int, the row of the bottom right corner of the box
	/// \param	botCol	(Optional) int, the column of the bottom right corner of the box
	/// \param	letter	(Optional) The letter to use as the box border

	Box(int upRow = 5, int  upCol = 5, int botRow = 20, int botCol = 15, char letter = '!');

	/// \fn		Box::~Box();
	/// \brief	Destructor

	~Box();

	/// \fn		virtual void Box::draw(Screen &screen);
	/// \brief	Draws itself to the given screen
	/// \param	&screen	Screen, a reference to screen

	virtual void draw(Screen &screen);

	/// \fn		virtual void Box::read(istream &is);
	/// \brief	Reads the given input stream
	/// \param	&is		istream, a reference to the input stream to read

	virtual void read(istream &is);

protected:

	/// \fn	void Box::constructLines();
	/// \brief	Creates all of the lines required to make the box

	void constructLines();
};
