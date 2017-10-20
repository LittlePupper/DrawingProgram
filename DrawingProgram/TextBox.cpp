// \author	Nora White
// \date	2017-10-19

#include "stdafx.h"
#include "TextBox.h"
#include "Exception.h"

// \fn		TextBox::TextBox(int row = 20, int col = 40, char letter = '!', string phrase = "HelloWorld");
// \brief	Constructor for TextBox which takes in 4 parameters
// \param	row   	(Optional) int, the row of which the text will be on
// \param	col   	(Optional) int, the column of which the first character of the text will start on
// \param	letter	(Optional) char, the letter to use as the border in the box
// \param	phrase	(Optional) string, the phrase to display on the screen

TextBox::TextBox(int row, int col, char letter, string phrase)
{
	this->row = row;
	this->col = col;
	this->letter = letter;
	this->phrase = phrase;
}

// \fn		TextBox::~TextBox();
// \brief	Destructor

TextBox::~TextBox()
{
	delete text;
	delete box;
}

// \fn		virtual void TextBox::draw(Screen &screen);
// \brief	Draws the box and text to the given screen
// \param	&screen	Screen, a reference to screen

void TextBox::draw(Screen &screen)
{
	box->draw(screen);
	text->draw(screen);
}

// \fn		virtual void TextBox::read(istream &is);
// \brief	Reads the given input stream 
// \param	&is		istream, reference to the input stream to read

void TextBox::read(istream &is)
{
	is >> row >> col >> letter >> phrase;
	text = (new Text(row, col, phrase));
	box = (new Box(row - 2, col - 3, row + 2, col + 2 + phrase.length(), letter));
}