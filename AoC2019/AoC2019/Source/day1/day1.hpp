#pragma once

#include "vector"

using namespace std;

class Day1
{
public:
   Day1(std::vector<int> input);
   virtual ~Day1();

   std::pair<int, int> GetSolution();
   static int CalculateFuel(int mass);

private:
   std::vector<int> input_;

   // Enums
   enum Part
   {
      Part1,
      Part2
   };


   struct Module
   {
      int mass_;
      int fuelMassPart1_;
      int fuelMassPart2_;

      // Let the constructor do the work
      Module(int m = 0)
      {
         mass_ = m;
         fuelMassPart1_ = (mass_ / 3) - 2;
         fuelMassPart2_ = Day1::CalculateFuel(mass_);
      }
   };
};