#ifndef MENU_H
#define MENU_H

//Library includes
#include <vector>
#include <string>
#include <iostream>

class Menu { // Represents a simple menu system
private:
	std::vector<std::string> _items; // List of menu items 
	std::string _title; // Title of the menu

public: 
	Menu(const std::string& title) : _title(title) {}
	void AddItem(const std::string& item); // Adds an item to the menu
	void Display() const; // Displays the menu
	size_t GetMenuSize() const; // Returns the number of items in the menu
};

#endif //MENU_H