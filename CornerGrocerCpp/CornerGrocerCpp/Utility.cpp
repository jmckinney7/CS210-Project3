//Header files
#include "Utility.h"

std::string Utility::NCharString(char c, int n)
{
	return std::string(n, c); //Return a string consisting of 'n' characters of 'c'
}

void Utility::ClearScreen()
{
#ifdef _WIN32 //Windows only method of clearing
	system("cls");
#else //Every other platform
	system("clear");
#endif
}

void Utility::PressAnyKeyToContinue()
{
	std::cout << std::endl;
	std::cout << "Press any key to continue..." << std::endl;
	(void)_getch(); //Using _getch() to avoid waiting for Enter key specifically
	ClearScreen(); //Clear the screen after key press
}

void Utility::Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); //Sleep for the specified milliseconds
}

void Utility::SetConsoleColor(const Color& color) //Set the console color based on the Color enum
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Get the console handle
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(color)); //Set the console text attribute to the specified color
}

void Utility::RandomlySetConsoleColor() //Randomly set the console color to a value between 7 and 15 (inclusive)
{
	static std::mt19937 rng(std::random_device{}()); //Seeded once with a random device
	std::uniform_int_distribution<int> dist(7, 15); //Range: 7 to 5 inclusively 

	int randomColor = dist(rng); //Generate a random number in the specified range
	SetConsoleColor(static_cast<Color>(randomColor)); //Set the console color to the randomly generated value
}
