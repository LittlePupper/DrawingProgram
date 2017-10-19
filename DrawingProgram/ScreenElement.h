/// \file	ScreenElement.h.
/// \author	Nora White
/// \date	2017-09-28
/// \brief	Declares the screen element class

#pragma once
#include <istream>
#include "Screen.h"

/// \namespace	std
/// \brief	.

using namespace std;

/// \class	ScreenElement
/// \brief	A screen element.

class ScreenElement
{
public:
	/// \fn	ScreenElement::~ScreenElement();
	/// \brief	Destructor

	~ScreenElement();

	/// \fn		virtual void ScreenElement::draw(Screen &screen) = 0;
	/// \brief	Pure abstract method for drawing itself to the screen
	/// \param	&screen	Screen, a reference to screen

	virtual void draw(Screen &screen) = 0;

	/// \fn		virtual void ScreenElement::read(istream &is) = 0;
	/// \brief	Pure abstract method for reading the given input stream
	/// \param	&is		istream, a reference to the input stream to read

	virtual void read(istream &is) = 0;
};