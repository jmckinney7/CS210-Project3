#ifndef GROCER_H
#define GROCER_H

// Libraries
#include <map>
#include <string>
#include <iostream>

class Grocer { // Class to manage grocery items and their frequencies
private:
	std::string _grocerItem; // Item name - mainly used for input (searches)
	std::map<std::string, int> _grocerHistogramList; // Histogram of items with their frequencies
	std::map<std::string, int> _grocerFrequencyList; // Frequency list of items

public:
	Grocer() : _grocerFrequencyList({}), _grocerHistogramList({}) {} // Default constructor initializes empty frequency and histogram lists
	void SetGrocerFrequencyList(const std::map<std::string, int>& list); // Sets the frequency list of items
	void RequestItemFrequency(); // Requests the frequency of a specific item
	void PrintFrequencyList() const; //	Prints the frequency list of items
	void PrintHistogramList() const; // Prints the histogram of items and their frequencies
};

#endif //GROCER_H