//Libraries
#include <iostream>

//Header files
#include "App.h"
#include "Utility.h"

/*
	Project: Corner Grocer C++ Application
	Developer: Joshua A. McKinney
	Start Date: 8/12/2024
	Course: CS-210
	Professor: Jared Oluoch

	NOTE: The settings menu is an additional feature that I implemented.
*/

int main() {
	Utility::SetConsoleColor(Color::GREEN); // Set console text color to green
	App app; // Create an instance of the App class
	app.Init(); // Initialize the application
	app.MainMenu(); // Display the main menu and handle user input
	return 0;
}