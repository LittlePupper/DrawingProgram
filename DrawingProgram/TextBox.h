/// \file	TextBox.h.
/// \author	Nora White
/// \date	2017-09-28
/// \brief	Declares the text box class

#pragma once
#include <string>
#include "Box.h"
#include "Text.h"

/// \namespace	std
/// \brief		The default namespace

using namespace std;

/// \class	TextBox
/// \brief	A text box that is derived from Box and Text

class TextBox : public Box, public Text
{
private:
	/// \brief	The row of which the text will be on
	int row;
	/// \brief	The column of which the first character of the text will start on
	int col;
	/// \brief	The letter to use as the border in the box
	char letter;
	/// \brief	The phrase to display on the screen
	string phrase;
	/// \brief	The box pointer
	Box* box;
	/// \brief	The text pointer
	Text* text;

public:

	/// \fn		TextBox::TextBox(int row = 20, int col = 40, char letter = '!', string phrase = "HelloWorld");
	/// \brief	Constructor for TextBox which takes in 4 parameters
	/// \param	row   	(Optional) int, the row of which the text will be on
	/// \param	col   	(Optional) int, the column of which the first character of the text will start on
	/// \param	letter	(Optional) char, the letter to use as the border in the box
	/// \param	phrase	(Optional) string, the phrase to display on the screen

	TextBox(int  row = 20, int col = 40, char letter = '!', string phrase = "HelloWorld");

	/// \fn		TextBox::~TextBox();
	/// \brief	Destructor

	~TextBox();

	/// \fn		virtual void TextBox::draw(Screen &screen);
	/// \brief	Draws the box and text to the given screen
	/// \param	&screen	Screen, a reference to screen

	virtual void draw(Screen &screen);

	/// \fn		virtual void TextBox::read(istream &is);
	/// \brief	Reads the given input stream 
	/// \param	&is		istream, reference to the input stream to read

	virtual void read(istream &is);
};