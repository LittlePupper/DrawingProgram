/// \file	Exception.h
/// \author	Nora White
/// \date	2017-10-19
/// \brief	Declares the exception classes

#pragma once
#include <stdexcept>

/// \namespace	std
/// \brief		The default namespace
using namespace std;

/// \class	invalid_coordinates_error
/// \brief	An exception that is derived from the runtime_error class. Thrown when coordinates are out of bounds.
class invalid_coordinates_error : public runtime_error
{
public:
	invalid_coordinates_error() : runtime_error("Those coordinates are out of bounds. Try something else!") {}
};

/// \class	input_format_error
/// \brief	An exception that is derived from the runtime_error class. Thrown when the format provided is incorrect.
class input_format_error : public runtime_error
{
public:
	input_format_error() : runtime_error("The input you gave is not in the correct format. Try again.") {}
};

/// \class	invalid_line_error
/// \brief	An exception that is derived from the runtime_error class. Thrown when the line to be drawn is diagonal.
class invalid_line_error : public runtime_error
{
public:
	invalid_line_error() : runtime_error("This line is diagonal. Please only give horizontal or vertical coordinates.") {}
};

/// \class	invalid_screen_error
/// \brief	An exception that is derived from the runtime_error class. Thrown when the screen hasn't been created yet.
class invalid_screen_error : public runtime_error
{
public:
	invalid_screen_error() : runtime_error("The screen hasn't been created yet. Please create a screen.") {}
};