//Header files
#include "Grocer.h"
#include "Utility.h"

void Grocer::SetGrocerFrequencyList(const std::map<std::string, int>& list)
{
	_grocerFrequencyList = list; // Sets the grocery frequency list to the provided map
}

void Grocer::RequestItemFrequency() // Requests the user to input an item and checks its frequency in the list
{
	Utility::ClearScreen(); // Clear the screen before displaying the request

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Flush leftover input

	std::cout << "Search for an item: "; // Prompt the user to enter an item
	std::getline(std::cin, _grocerItem); // Read the item from standard input

	auto it = _grocerFrequencyList.find(_grocerItem); // Search for the item in the frequency list
	if (it != _grocerFrequencyList.end()) { // If the item is found in the list (key doesn't return end iterator)
		std::cout << "'" << _grocerItem << "' occurs " << it->second << " times.\n"; // If found, print the frequency
	}
	else {
		std::cout << "'" << _grocerItem << "' does not occur in the list.\n"; // If not found, notify the user
	}

	Utility::PressAnyKeyToContinue(); // Wait for user input before returning to the main menu
}

void Grocer::PrintFrequencyList() const // Prints the entire grocery frequency list to the console
{
	Utility::ClearScreen(); // Clear the screen before displaying the list

	if (_grocerFrequencyList.empty()) // Check if the frequency list is empty
	{
		std::cout << "The grocery frequency list is empty." << std::endl; // If empty, notify the user
		Utility::PressAnyKeyToContinue(); // Wait for user input before returning
		return;
	}

	std::cout << "Grocery Frequency List:" << std::endl; // Print header for the frequency list

	for (const auto& item : _grocerFrequencyList) // Iterate through the frequency list and print each item and its frequency
	{
		std::cout << item.first << " " << item.second << std::endl;
	}

	Utility::PressAnyKeyToContinue(); // Wait for user input before returning to the main menu
}

void Grocer::PrintHistogramList() const // Prints a histogram representation of the grocery frequency list to the console
{
	Utility::ClearScreen(); // Clear the screen before displaying the histogram

	if (_grocerFrequencyList.empty()) // Check if the frequency list is empty
	{
		std::cout << "The grocery frequency list is empty." << std::endl;
		Utility::PressAnyKeyToContinue(); // Wait for user input before returning
		return;
	}
	std::cout << "Grocery Frequency Histogram:" << std::endl; // Print header for the histogram

	for (const auto& item : _grocerFrequencyList) // Iterate through the frequency list and print each item with a histogram bar
	{
		std::cout << item.first << " "; // Print the item name
		std::cout << Utility::NCharString('*', item.second); // Print the item name followed by asterisks representing its frequency
		std::cout << std::endl;
	}

	Utility::PressAnyKeyToContinue(); // Wait for user input before returning to the main menu
}
