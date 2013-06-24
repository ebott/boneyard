#include <iostream>

/*
Take a look at the MIN macro on this page.

http://www.net-snmp.org/docs/man/netsnmp_library.html

This macro makes a classic mistake. What is it? Write some code that
exposes the flaw.

   :{>

Hint: You can pass any value to a and b. Macros perform textual
substitution, then allow the compiler to work with the result. What if
a and b are nontrivial? What a or b has a side effect?

inside the link:
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
*/


//put that bad boy here...
#define MIN(a,b) (((a) < (b)) ? (a) : (b))


int main() 
{
   
   int x = 1;
   int y = 1;   

   std::cout << "x is initially: "
      << x 
      << std::endl
      << "then run macro with x++..."
      << std::endl;
   x = MIN(x++,1000);
   std::cout << "now x is: "
      << x 
      << std::endl;

   std::cout << "y is initially: "
      << y 
      << std::endl
      << "then run macro with ++y..."
      << std::endl;
   x = MIN(++y,1000);
   std::cout << "now y is: "
      << y 
      << std::endl;

}
