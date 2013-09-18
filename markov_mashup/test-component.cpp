#include ".test.hpp"
#include "component.hpp"

TEST(basic)
{
   component testor("Ulysses.txt");

   testor.generate(50,2);

}
