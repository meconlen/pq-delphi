#include <chrono>
#include <cstdint>

#include "lcg.hpp"

uint64_t lcg::randomize(uint64_t s)
{
   uint64_t old_seed{seed};
   seed = s;
   return old_seed;
}

uint64_t lcg::randomize(void)
{
   uint64_t old_seed{seed};
   seed = 0;
   return old_seed;
}


// GetSystemTime(SystemTime); // Get current system time
// RandSeed := SystemTime.wMilliseconds + SystemTime.wSecond * 1000 +
//    SystemTime.wMinute * 60000 + SystemTime.wHour * 3600000;
// end;

uint64_t lcg::randomize(uint64_t year, uint64_t month, uint64_t day, uint64_t hour, uint64_t minute, uint64_t second, uint64_t ms)
{
   uint64_t old_seed {seed};
   seed = ms + second * 1000 + minute * 60000 + hour * 3600000;
   return(old_seed);
}

uint64_t lcg::random(void)
{
   seed = (a * seed + c) % m;
   return seed;
}

uint64_t lcg::random(uint64_t n)
{
   return (random() * n) >> 32;
}