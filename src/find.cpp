#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "lcg.hpp"

int main(int argc, char** argv)
{
	lcg g{};

	uint64_t str{0}, con{0}, dex{0}, inte{0}, wis{0}, cha{0};
	uint64_t s{0}, c{0}, d{0}, i{0}, w{0}, h{0};

	str = atoll(argv[8]);
	con = atoll(argv[9]);
	dex = atoll(argv[10]);
	inte = atoll(argv[11]);
	wis = atoll(argv[12]);
	cha = atoll(argv[13]);

	std::cout << str << " " << con << " " << dex << " " << inte << " " << wis << " " << cha << std::endl;

	for(int j = 0; j < 60 * 60 * 1000; j++) {
 		g.randomize(std::atoll(argv[1]), atoll(argv[2]), atoll(argv[3]), atoll(argv[4]), atoll(argv[5]), atoll(argv[6]), atoll(argv[7]) + j);

		s = 3 + g.random(6) + g.random(6) + g.random(6);
		c = 3 + g.random(6) + g.random(6) + g.random(6);
		d = 3 + g.random(6) + g.random(6) + g.random(6);
		i = 3 + g.random(6) + g.random(6) + g.random(6);
		w = 3 + g.random(6) + g.random(6) + g.random(6);
		h = 3 + g.random(6) + g.random(6) + g.random(6);



		if(str == s && con == c && dex == d && inte == i && wis == w && cha == h) {
			std::cout << j << " : " << s << " : " << c << " : " << d << " : " << i << " : " << w << " : " << h << std::endl;
			g.random();
			g.random();
			s = 3 + g.random(6) + g.random(6) + g.random(6);
			c = 3 + g.random(6) + g.random(6) + g.random(6);
			d = 3 + g.random(6) + g.random(6) + g.random(6);
			i = 3 + g.random(6) + g.random(6) + g.random(6);
			w = 3 + g.random(6) + g.random(6) + g.random(6);
			h = 3 + g.random(6) + g.random(6) + g.random(6);
			std::cout << s << " : " << c << " : " << d << " : " << i << " : " << w << " : " << h << std::endl;
			s = 3 + g.random(6) + g.random(6) + g.random(6);
			c = 3 + g.random(6) + g.random(6) + g.random(6);
			d = 3 + g.random(6) + g.random(6) + g.random(6);
			i = 3 + g.random(6) + g.random(6) + g.random(6);
			w = 3 + g.random(6) + g.random(6) + g.random(6);
			h = 3 + g.random(6) + g.random(6) + g.random(6);
			std::cout << s << " : " << c << " : " << d << " : " << i << " : " << w << " : " << h << std::endl;
			s = 3 + g.random(6) + g.random(6) + g.random(6);
			c = 3 + g.random(6) + g.random(6) + g.random(6);
			d = 3 + g.random(6) + g.random(6) + g.random(6);
			i = 3 + g.random(6) + g.random(6) + g.random(6);
			w = 3 + g.random(6) + g.random(6) + g.random(6);
			h = 3 + g.random(6) + g.random(6) + g.random(6);
			std::cout << s << " : " << c << " : " << d << " : " << i << " : " << w << " : " << h << std::endl;
			break;
		}
	}

	return 0;
}