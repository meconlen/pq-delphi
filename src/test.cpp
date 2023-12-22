#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "lcg.hpp"

int main(int argc, char** argv)
{
	lcg g{};

	if(argc < 8) {
		std::cout << argc << std::endl;
		return 1;
	}

	std::cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << " " << argv[6] << " " << argv[7] << std::endl;
	for(int i = 0; i < 60 * 1000; i++) {
		g.randomize(std::atoll(argv[1]), atoll(argv[2]), atoll(argv[3]), atoll(argv[4]), atoll(argv[5]), atoll(argv[6]), atoll(argv[7]) + i);
		std::cout << i ;
		for(int j = 0; j < 6; j++) {
			std::cout << " : " << 3 + g.random(6) + g.random(6) + g.random(6);
		}
		std::cout << std::endl;
	}
	return 0;
}