#include ".test.hpp"
#include "component.hpp"

TEST(basic)
{
   component testor("Ulysses.txt");
   cout << "With a one-word prefix string: " << endl;
   testor.generate(50,1);
   cout << "With a two-word prefix string: " << endl;
   testor.generate(50,2);
   cout << "With a three-word prefix string: " << endl;
   testor.generate(50,3);
}
