//Header files
#include "GrocerFileManager.h"

std::map<std::string, int> GrocerFileManager::CollectGrocerItems() {
	constexpr const char* filePath = "CS210_Project_Three_File.txt"; // Define the file path to read grocer items from
	std::ifstream inputFile(filePath); // Open the file for reading
	std::map<std::string, int> grocerList; // Create a map to store grocer items and their frequencies

	if (!inputFile.is_open()) { // Check if the file was opened successfully
		std::cerr << "Error: Could not open the file." << std::endl;
		return {}; // Exit the function if file cannot be opened
	}

	std::string item;
	while (inputFile >> item) { // Loop until the end of the file
		grocerList[item]++; // Increment the frequency of the item in the map
	}

	if (grocerList.empty()) // Check if the map is empty after reading the file
	{
		std::cerr << "Warning: No items loaded from file.\n";
	}

	// After reading all items, close the input file
	
	inputFile.close(); // Close the file after reading (this is actually done automatically when the ifstream object goes out of scope, but it's good practice)
	return grocerList; // Return the collected grocer items
}

void GrocerFileManager::BackupGrocerItems(const std::map<std::string, int>& grocerList) {
	std::ofstream backupFile("frequency.dat"); // Open a file for writing backup data

	if (!backupFile.is_open()) { // Check if the backup file was opened successfully
		std::cerr << "Error: Could not create backup file." << std::endl;
		return; // Exit the function if backup file cannot be created
	}

	for (const auto& pair : grocerList) { // Iterate through the map of grocer items
		backupFile << pair.first << " " << pair.second << std::endl;
	}

	backupFile.close(); //	Close the backup file after writing
}