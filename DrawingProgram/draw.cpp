// draw.cc : Defines the entry point for the console application.
// \author	Nora White
// \date	2017-10-19

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
#include "Box.h"
#include "ScreenElement.h"
#include "Text.h"
#include "TextBox.h"
#include "Exception.h"

using namespace std;

//	\fn		char menu()
//	\brief	Prints the menu and returns a char of the selected option
//	\return	char	The selected menu option
char menu()
{
	char x;
	cout << endl << "=============MAIN MENU=============" << endl << endl;
	cout << "N: New screen" << endl;
	cout << "B: Draw a box" << endl;
	cout << "T: Draw some text" << endl;
	cout << "R: Draw a textbox" << endl;
	cout << "D: Display all objects" << endl;
	cout << "K: Undo draw element" << endl;
	cout << "Q: Quit" << endl << endl << "> ";
	cin >> x;
	return x;
}

//	\fn		bool screenExists(Screen *screenPtr)
//	\brief	Checks if the screen exists
//	\return	bool	A boolean value describing if the Screen * exists
//	\throws	invalid_screen_error
bool screenExists(Screen *screenPtr)
{
	if (screenPtr == nullptr)
	{
		throw invalid_screen_error();
	}
	else
		return true;
}

//	\fn		Box* createNewBox(Screen &screen)
//	\brief	Creates a new Box object and draws it to the screen
//	\return	Box*	A pointer to the created Box object
Box* createNewBox(Screen &screen)
{
	Box* boxPtr = new Box();
	cout << endl << "Enter box dimensions in the form of [top left row] [top left column] "
		"[bottom left row] [bottom left column] [letter for border]." << endl << "Example: 0 0 23 79 +" << endl << endl << "> ";
	boxPtr->read(cin);
	boxPtr->draw(screen);
	return boxPtr;
}

//	\fn		Text* createNewText(Screen &screen)
//	\brief	Creates a new Text object and draws it to the screen
//	\return	Text*	A pointer to the created Text object
Text* createNewText(Screen &screen)
{
	Text* textPtr = new Text();
	cout << endl << "Enter text dimensions in the form of [row] [starting column] "
		"[text with no spaces]." << endl << "Example: 12 35 HelloWorld" << endl << endl << "> ";
	textPtr->read(cin);
	textPtr->draw(screen);
	return textPtr;
}

//	\fn		TextBox* createNewTextBox(Screen &screen)
//	\brief	Creates a new TextBox object and draws it to the screen
//	\return	TextBox*	A pointer to the created TextBox object
TextBox* createNewTextBox(Screen &screen)
{
	TextBox* textBoxPtr = new TextBox();
	cout << endl << "Enter textbox dimensions in the form of [row] [starting column] [letter for border] "
		"[text with no spaces]." << endl << "Example:8 35 @ WowThisIsCool" << endl << endl << "> ";
	textBoxPtr->read(cin);
	textBoxPtr->draw(screen);
	return textBoxPtr;
}

//	\fn		int main()
//	\brief	The main function that continually loops through a menu,
//			drawing and erasing until the user quits the program
int main()
{
	bool running = true;
	Screen* screenPtr = nullptr;
	vector<ScreenElement*> screenElements;

	cout << "CPSC 2720 - Fall 2017" << endl;
	cout << "Drawing Program" << endl;
	cout << "Nora White" << endl;

	//screenPtr = new Screen();

	while (running) 
	{
		try {
			switch (toupper(menu()))
			{
				case 'N': // Create new screen
					delete screenPtr;
					screenPtr = new Screen();
					screenElements.clear();
					break;
				case 'B': // Create new box
					if (screenExists(screenPtr))
						screenElements.push_back(createNewBox(*screenPtr));
					break;
				case 'T': // Create new text
					if (screenExists(screenPtr))
						screenElements.push_back(createNewText(*screenPtr));
					break;
				case 'R': // Create new text box
					if (screenExists(screenPtr))
						screenElements.push_back((Box*)createNewTextBox(*screenPtr));
					break;
				case 'D': // Draw the screen
					if (screenExists(screenPtr))
					{
						cout << endl;
						cout << *screenPtr;
					}
					break;
				case 'K': // Undo the last drawn element
					if (screenElements.size() > 0) // Checks to see if the vector has elements
					{
						screenPtr->clear();
						delete screenElements.back();
						screenElements.pop_back();
						for (int i = 0; i < screenElements.size(); i++)
							screenElements[i]->draw(*screenPtr);
					}
					else
						cout << endl << "There are no elements to draw." << endl;
					break;
				case 'Q': // Quit
					running = false;
					break;
				default:
					cout << endl << "Please choose a different letter" << endl;
			}
		}
		catch (invalid_coordinates_error & e) // Prints the error for invalid coordinates
		{
			cout << endl << e.what() << endl;
		}
		catch (invalid_screen_error & e) // Prints the error if no screen exists yet
		{
			cout << endl << e.what() << endl;
		}
		catch (input_format_error & e) // Prints the error if the input format is incorrect
		{
			cin.clear();
			cin.ignore();
			cout << endl << e.what() << endl;
		}
	}
	return 0;
}