#include "pch.h"
#include "Container.h"
#include <iostream>

int main()
{
	bool quit = false;
	Container container;

	bool loaded = container.load();
	if (loaded = true) {
		std::cout << "Save data loaded successfully." << std::endl;
	}
	else if (loaded = false) {
		std::cout << "Save data not present. Creating new save data." << std::endl;
		container.save();
	}

	container.optionSelection(!quit);
}