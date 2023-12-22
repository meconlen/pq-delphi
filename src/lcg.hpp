#include <cstdint>

class lcg {
private:
   uint64_t m{4294967296};
   uint64_t a{134775813};
   uint64_t c{1};
   uint64_t seed{0};

public:

   lcg() = default;
   lcg(uint64_t m, uint64_t a, uint64_t c) : m(m), a(a), c(c) {}

   uint64_t randomize(void);
   uint64_t randomize(uint64_t s);
   uint64_t randomize(uint64_t year, uint64_t month, uint64_t day, uint64_t hour, uint64_t minute, uint64_t second, uint64_t ms);

   uint64_t random(void);
   uint64_t random(uint64_t n);

   ~lcg() = default;
};

