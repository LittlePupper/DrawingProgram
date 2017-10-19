#pragma once
#include <stdexcept>

using namespace std;

struct invalid_coordinates_error : public runtime_error {
	const char * what() const throw () {
		return "Those coordinates are out of bounds. Try something else!";
	}
};

struct input_format_error : public runtime_error {
	const char * what() const throw () {
		return "The input you gave is not in the correct format. Try again.";
	}
};

struct invalid_line_error : public runtime_error {
	const char * what() const throw () {
		return "This line is diagonal. Please only give horizontal or vertical coordinates.";
	}
};

struct invalid_screen_error : public runtime_error {
	const char * what() const throw () {
		return "The screen hasn't been created yet. Please create a screen.";
	}
};
