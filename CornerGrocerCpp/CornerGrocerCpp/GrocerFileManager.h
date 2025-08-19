#ifndef GROCER_FILE_MANAGER_H
#define GROCER_FILE_MANAGER_H

// Libraries
#include <map>
#include <string>
#include <fstream>
#include <iostream>

namespace GrocerFileManager { // File management for the Corner Grocer application
	std::map<std::string, int> CollectGrocerItems(); // Collects items from the grocer file and returns a map of item names and their quantities
	void BackupGrocerItems(const std::map<std::string, int>& grocerList); // Backs up the current grocer items to a file
}

#endif //GROCER_FILE_MANAGER_H