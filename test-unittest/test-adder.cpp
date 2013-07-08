#include ".test.hpp"
#include "adder.hpp"

TEST(basic)
{
   adder a(19);
   EQ(20,a.additup());
}
