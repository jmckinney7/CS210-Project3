//Header files
#include "Menu.h"
#include "Utility.h"

void Menu::AddItem(const std::string& item) // Adds an item to the menu
{
	_items.push_back(item); // Store the item in the vector
}

void Menu::Display() const // Displays the menu to the console
{
	// Display the menu title and items in a formatted manner
	std::string banner = Utility::NCharString('=', 15) + " " + _title + " " + Utility::NCharString('=', 15);
	std::cout << banner << std::endl;

	for (size_t i = 0; i < _items.size(); ++i) { // Loop through each item in the menu
		std::cout << (i + 1) << ": " << _items[i] << std::endl; // Display the item with its index
	}

	std::cout << Utility::NCharString('=', static_cast<int>(banner.size())) << std::endl; // Print a line of equal signs to match the banner length
	std::cout << std::endl;
}

size_t Menu::GetMenuSize() const // Returns the number of items in the menu (size_t is an unsigned long long type)
{
	return _items.size(); // Return the size of the items vector
}
