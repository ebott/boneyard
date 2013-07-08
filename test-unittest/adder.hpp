#include <iostream>

struct adder
{
   adder(int i)
      :value_(i)
   {}

   int additup()
   {
      return ++value_;
   }

   private:
      int value_;
};
