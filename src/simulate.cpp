#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <locale>
#include <numeric>

#include "lcg.hpp"

std::array<float, 6> weights(std::array<int_fast8_t, 6> s)
{
   std::array<uint64_t, 6> quad_stats {};
   for(auto i = 0; i < 6; i++) {
      quad_stats[i] = uint64_t(s[i]) * uint64_t(s[i]);
   }
   uint64_t sum = std::accumulate(quad_stats.begin(), quad_stats.end(), 0);
   std::array<float, 6> rv {};
   for(auto i = 0; i < 6; i++) {
      rv[i] = (float(quad_stats[i]) / float(sum))/2 + (1.0/12.0);
   }   
   return rv;
}

float str_p(std::array<int_fast8_t, 6> s) 
{
   auto w = weights(s);
   return w[0];
}

std::array<int_fast8_t, 6> random_stats(lcg& g) 
{
   std::array<int_fast8_t, 6> rv{};
   for(auto i = 0; i < 6; i++) {
      rv[i] = 3 + int_fast8_t(g.random(6) + g.random(6) + g.random(6));
   }
   return rv;
}

int main(int argc, char* argv[])
{
	lcg g{};
   auto p1 = std::chrono::system_clock::now();
   auto ts = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
   int day_seconds = ts % 86400;
   int hours = (day_seconds  - (day_seconds % 3600)) / 3600;
   int minutes = day_seconds - (hours * 3600);
   minutes = (minutes - minutes % 60) / 60;
   int seconds = day_seconds - (hours * 3600) - (minutes * 60);
   g.randomize(hours, minutes, seconds, 0);

   std::array<int_fast8_t, 6> start_stats{ 18, 5, 5, 4, 4, 3 };
   std::array<float, 13> p_range{ 0.40, 0.41, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.50, 0.51, 52 };
   std::array<uint64_t, 13> p_count {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   std::array<int_fast8_t, 6> s = {18, 5, 5, 4, 4, 3};
   std::cout << str_p(s) << std::endl;
   auto start_time = std::chrono::system_clock::now();
   std::time_t start_t = std::chrono::system_clock::to_time_t(start_time);
   std:: cout << std::ctime(&start_t);
   std::array<int_fast8_t, 6> t{};
   for(uint64_t i = 0; i < uint64_t(300000000) * uint64_t(3600); i++) {
      if(i % 1440000 == 0) {
         p1 = std::chrono::system_clock::now();
         ts = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
         day_seconds = ts % 86400;
         hours = (day_seconds  - (day_seconds % 3600)) / 3600;
         minutes = day_seconds - (hours * 3600);
         minutes = (minutes - minutes % 60) / 60;
         seconds = day_seconds - (hours * 3600) - (minutes * 60);
         ts = std::chrono::duration_cast<std::chrono::milliseconds>(p1.time_since_epoch()).count();
         int milliseconds = ts % 1000;
         g.randomize(hours, minutes, seconds, milliseconds);
      }
      t = random_stats(g);
      auto p = str_p(t);
      for(auto j = 0; j < 13; j++) {
         if(p >= p_range[j]) {
            p_count[j]++;
         }
      }
      if(p >= p_range[0]) {
         std::array<uint64_t, 12> p_p {};
         for(auto j = 0; j < 12; j++) {
            p_count[j] > 0 ? p_p[j] = i / p_count[j] : uint64_t(0);
         }
         std::cout.imbue(std::locale(""));
         std::cout << std::fixed << i << ", ";
         std::cout << "[" << int(t[0]) << ", " << int(t[1]) << ", " << int(t[2]) << ", " << int(t[3]) << ", " << int(t[4]) << ", " << int(t[5]) << "], ";
         std::cout << p << " ";
         std::cout << "[" << p_p[0];
         for(auto k = 1; k < 12; k++) {
            std::cout << ", " << p_p[k];
         } 
         std::cout << "]";
         std::cout << std::endl;
      }
   }
   auto end_time = std::chrono::system_clock::now();
   std::time_t end_t = std::chrono::system_clock::to_time_t(end_time);
   std:: cout << std::ctime(&end_t);

   return 0;
}