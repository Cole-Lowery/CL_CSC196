#include "Math/Math.h"
#include "core/Random.h"
#include <iostream>

#define NAME "edward"

int main() {
	std::cout << NAME << std::endl;
	std::cout << "Hello World!" << std::endl;
	std::cout << viper::pi << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << viper::random::getRandomFloat() << std::endl;
	}
}