// \author	Nora White
// \date	2017-10-19

#include "stdafx.h"
#include "Text.h"
#include "Exception.h"

// \fn		Text::Text(int row = 20, int col = 40, string phrase = "HelloWorld");
// \brief	Constructor for Text which takes in 3 parameters
// \param	row   	(Optional) int, the row of which the text will be on
// \param	col   	(Optional) int, the column of which the first character of the text will start on
// \param	phrase	(Optional) string, the phrase to display on the screen

Text::Text(int row, int col, string phrase)
{
	this->row = row;
	this->col = col;
	this->phrase = phrase;
};

// \fn		Text::~Text();
// \brief	Destructor

Text::~Text()
{
}

// \fn		virtual void Text::draw(Screen &screen);
// \brief	Draws itself to the given screen
// \param	&screen	Screen, a reference to screen

void Text::draw(Screen &screen)
{
	for (int i = 0; i < phrase.length(); i++)
		screen.set(row, col + i, phrase[i]);
}

// \fn		virtual void Text::read(istream &is);
// \brief	Reads the given input stream
// \param	&is		istream, reference to the input stream to read
// \throws	input_format_error

void Text::read(istream &is)
{
	is >> row >> col >> phrase;
	if (is.fail())
	{
		throw input_format_error();
	}
}
