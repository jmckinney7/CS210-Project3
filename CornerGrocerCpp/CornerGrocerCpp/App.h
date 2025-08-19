#ifndef APP_H
#define	APP_H

#include "Grocer.h"


class App {
private:
	Grocer _grocer; // Instance of Grocer class to manage the grocery store operations
	void Settings(); // Displays and manages settings for the application

public:
	App() = default; // Default constructor
	void Init(); // Initializes the application
	void MainMenu(); // Displays the main menu and handles user input
};

#endif //APP_H