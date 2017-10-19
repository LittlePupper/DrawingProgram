// \author	Nora White
// \date	2017-09-28

#include "stdafx.h"
#include "Box.h"

// \fn	Box::Box(int upRow = 5, int upCol= 5, int botRow = 20, int botCol = 15, char letter = '!');
// \brief	Constructor for Box which takes in 5 parameters
// \param	upRow 	(Optional) int, the row of the top left corner of the box
// \param	upCol 	(Optional) int, the column of the top left corner of the box
// \param	botRow	(Optional) int, the row of the bottom right corner of the box
// \param	botCol	(Optional) int, the column of the bottom right corner of the box
// \param	letter	(Optional) The letter to use as the box border

Box::Box(int upRow, int upCol, int botRow, int botCol, char letter)
{
	this->upRow = upRow;
	this->upCol = upCol;
	this->botRow = botRow;
	this->botCol = botCol;
	this->letter = letter;
	constructLines();
}

// \fn		Box::~Box();
// \brief	Destructor

Box::~Box()
{
	delete topLine;
	delete bottomLine;
	delete leftLine;
	delete rightLine;
}

// \fn		virtual void Box::draw(Screen &screen);
// \brief	Draws itself to the given screen
// \param	&screen	Screen, a reference to screen

void Box::draw(Screen &screen)
{
	topLine->draw(screen);
	bottomLine->draw(screen);
	leftLine->draw(screen);
	rightLine->draw(screen);
}

// \fn		virtual void Box::read(istream &is);
// \brief	Reads the given input stream
// \param	&is		istream, a reference to the input stream to read

void Box::read(istream &is)
{
	is >> upRow >> upCol >> botRow >> botCol >> letter;
	constructLines();
}

// \fn	void Box::constructLines();
// \brief	Creates all of the lines required to make the box

void Box::constructLines()
{
	topLine = (new Line(upRow, upCol, upRow, botCol, letter));
	bottomLine = (new Line(botRow, upCol, botRow, botCol, letter));
	leftLine = (new Line(upRow, upCol, botRow, upCol, letter));
	rightLine = (new Line(upRow, botCol, botRow, botCol, letter));
}
