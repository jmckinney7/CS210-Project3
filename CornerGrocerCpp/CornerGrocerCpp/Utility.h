#ifndef UTILITY_H
#define UTILITY_H
#define NOMINMAX // Prevent Windows.h from defining min and max macros

// Libraries
#include <string>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <random>
#include <Windows.h>

enum class Color { // Console colors for the Corner Grocer application (used with SetConsoleTextAttribute)
	DEFAULT = 7,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15
};

namespace Utility { // Utility functions for the Corner Grocer application
	std::string NCharString(char c, int n); // Returns a string of n characters c
	void ClearScreen(); // Clears the console screen
	void PressAnyKeyToContinue(); // Waits for the user to press any key to continue
	void Sleep(int milliseconds); // Sleep for a specified number of milliseconds
	void SetConsoleColor(const Color& color); // Sets the console color based on the Color enum
	void RandomlySetConsoleColor(); // Randomly changes the console color

	// This function is used to get the user's choice from a menu depending on the enum type T
	template<typename T> // Function to get validated input from the user
	T GetValidatedInput(int size)
	{
		int choice; 
		bool isValid = false;
		std::cin.exceptions(std::ios::failbit);

		// Loop until a valid input is received
		while (!isValid) {
			std::cout << "Enter your choice (" << 1 << "-" << size << "): ";

			try { // Attempt to read input
				std::cin >> choice;
				isValid = true;
			}
			catch (std::ios::failure& e) { // Catch input failure exceptions
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue; // Prompt again if input is invalid
			}
		}

		return static_cast<T>(choice); // Return the validated input cast to the enum type T
	}
}

#endif //UTILITY_H