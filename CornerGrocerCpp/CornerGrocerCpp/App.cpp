//Header files
#include "App.h"
#include "Menu.h"
#include "GrocerFileManager.h"
#include "Utility.h"

enum class MainMenuOption { // Represents the options available in the main menu (expandable)
	SearchFrequency = 1,
	FrequencyList = 2,
	Histogram = 3,
	Exit = 4,
	Settings = 5
};

enum class SettingsOption { // Represents the settings options in the menu (expandable)
	ChangeTheme = 1,
	Back = 2
};

// Initialization function for the application
void App::Init() {
	std::map<std::string, int> grocerFrequencyList; // Create a map to hold the frequency list of items
	grocerFrequencyList = GrocerFileManager::CollectGrocerItems(); // Collect the frequency list from the file manager
	GrocerFileManager::BackupGrocerItems(grocerFrequencyList); // Backup the frequency list to a file (frequency.dat)
	_grocer.SetGrocerFrequencyList(grocerFrequencyList); // Set the frequency list in the Grocer object
}

// Settings function (menu)
void App::Settings() {// Displays the settings menu and handles user input
	Menu settingsMenu("Corner Grocer: Settings"); // Create a settings menu with title
	settingsMenu.AddItem("Randomly Change Console Color"); // Option to change console color randomly
	settingsMenu.AddItem("Back to Main Menu"); // Option to go back to the main menu

	SettingsOption choice; // Variable to store user's choice from the settings menu

	do { // Loop until the user chooses to go back to the main menu
		Utility::ClearScreen(); // Clear the console screen before displaying the menu
		settingsMenu.Display(); // Display the settings menu
		choice = Utility::GetValidatedInput<SettingsOption>(settingsMenu.GetMenuSize());

		switch (choice) {
			case SettingsOption::ChangeTheme: // If user chooses to change console color
				Utility::RandomlySetConsoleColor();
				break;
			case SettingsOption::Back: // If user chooses to go back to the main menu
				std::cout << "Returning to Main Menu...\n";
				Utility::Sleep(1000); // Pause for 1 second before going back
				break;
			default: 
				std::cout << "Invalid choice!\n"; 
				Utility::Sleep(1000); // Pause for 1 second before action
				break;
		}
	} while (choice != SettingsOption::Back);
}

void App::MainMenu() // Main menu function to display options and handle user input
{
	Menu mainMenu("Corner Grocer"); // Create a main menu with title
	mainMenu.AddItem("Search Frequency");
	mainMenu.AddItem("Print Frequency List");
	mainMenu.AddItem("Histogram Display");
	mainMenu.AddItem("Exit the Program");
	mainMenu.AddItem("Settings");

	MainMenuOption choice; // Variable to store user's choice from the main menu

	do { // Loop until the user chooses to exit the program
		Utility::ClearScreen();
		mainMenu.Display();
		choice = Utility::GetValidatedInput<MainMenuOption>(mainMenu.GetMenuSize());

		switch (choice) {
		case MainMenuOption::SearchFrequency:
			std::cout << "Loading Search Frequency...\n";
			Utility::Sleep(1000); // Pause for 1 second before search frequency display
			_grocer.RequestItemFrequency(); // Request item frequency from the user
			break;
		case MainMenuOption::FrequencyList:
			std::cout << "Loading Frequency List...\n";
			Utility::Sleep(1000); // Pause for 1 second before frequency list display
			_grocer.PrintFrequencyList(); // Print the frequency list of items
			break;
		case MainMenuOption::Histogram:
			std::cout << "Loading Histogram Display...\n";
			Utility::Sleep(1000); // Pause for 1 second before histogram display
			_grocer.PrintHistogramList(); // Print the histogram of item frequencies
			break;
		case MainMenuOption::Exit:
			std::cout << "Exiting...\n";
			Utility::Sleep(1000); // Pause for 1 second before exiting
			std::cout << "Thank you for using Corner Grocer Application!\n";
			break;
		case MainMenuOption::Settings:
			std::cout << "Loading Settings...\n";
			Utility::Sleep(1000); // Pause for 1 second before viewing settings
			Settings(); // Call the settings function to display settings menu
			break;
		default: 
			std::cout << "Invalid choice!\n"; 
			Utility::Sleep(1000); // Pause for 1 seconds before action
			break;
		}
	} while (choice != MainMenuOption::Exit);
}
