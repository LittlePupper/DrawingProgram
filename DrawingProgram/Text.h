/// \file	Text.h
/// \author	Nora White
/// \date	2017-10-19
/// \brief	Declares the text class

#pragma once
#include <string>
#include "ScreenElement.h"

/// \namespace	std
/// \brief		The default namespace

using namespace std;

/// \class	Text
/// \brief	A line of text that is derived from the ScreenElement class

class Text : public ScreenElement
{
private:
	/// \brief	The row of which the text will be on
	int row;
	/// \brief	The column of which the first character of the text will start on
	int col;
	/// \brief	The phrase to display on the screen
	string phrase;

public:

	/// \fn		Text::Text(int row = 20, int col = 40, string phrase = "HelloWorld");
	/// \brief	Constructor for Text which takes in 3 parameters
	/// \param	row   	(Optional) int, the row of which the text will be on
	/// \param	col   	(Optional) int, the column of which the first character of the text will start on
	/// \param	phrase	(Optional) string, the phrase to display on the screen

	Text(int row = 20, int col = 40, string phrase = "HelloWorld");

	/// \fn		Text::~Text();
	/// \brief	Destructor

	~Text();

	/// \fn		virtual void Text::draw(Screen &screen);
	/// \brief	Draws itself to the given screen
	/// \param	&screen	Screen, a reference to screen

	virtual void draw(Screen &screen);

	/// \fn		virtual void Text::read(istream &is);
	/// \brief	Reads the given input stream
	/// \param	&is		istream, reference to the input stream to read
	/// \throws	input_format_error

	virtual void read(istream &is);
};