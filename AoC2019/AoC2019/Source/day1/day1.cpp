#include "day1.hpp"

Day1::Day1(std::vector<int> input)
{
   input_ = input;
}

Day1::~Day1()
{

}

int Day1::CalculateFuel(int mass)
{
   auto fuelMass = div(mass, 3);

   if (fuelMass.quot <= 2)
      return 0;

   auto newMass = fuelMass.quot - 2;

   return newMass + Day1::CalculateFuel(newMass);
}

std::pair<int, int> Day1::GetSolution()
{
   // Define lambda to calculate the relevant fuel values
   auto calcFuelMass = [](std::vector<Module> modules, Part part)
   {
      auto sum = 0;
      for (auto i = 0; i < modules.size(); i++)
      {
         if (part == Part1)
         {
            sum += modules.at(i).fuelMassPart1_;
         }
         else
         {
            sum += modules.at(i).fuelMassPart2_;
         }

      }

      return sum;
   };

   // Translate input to modules
   std::vector<Module> mods;
   for (auto i = 0; i < input_.size(); i++)
      mods.emplace_back(Module(input_.at(i)));

   // Perform main task
   return std::make_pair<int, int>(calcFuelMass(mods, Part1), calcFuelMass(mods, Part2));
}