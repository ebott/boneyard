#include <utility>
#include <iostream>
#include <functional>

std::pair<double&,double&> getFloats()
{
   //create two new doubles on the heap with new
   double* val1 = new double;
   double* val2 = new double;

   printf("Enter value one: \n");
   scanf("%lf",val1);
   printf("You entered (printed inside fcn): %f",*val1);
   printf("\nEnter value two: \n");
   scanf("%lf",val2);
   printf("You entered (printed inside fcn): %f\n",*val2);
   
   return std::make_pair(std::ref(*val1),std::ref(*val2));
}

void getFloatsPassByREALRef(double& i, double& j)
{
   printf("Enter value one: \n");
   scanf("%lf",&i);

   printf("Enter value two: \n");
   //maybe setting up the point initially is better
   //or more human-readable... ???
   double* jp = &j;
   scanf("%lf",jp);
}

int main()
{
   //I tried to return both in a std::pair, doesnt work thus
   //far
   std::pair<double&,double&> numPair = getFloats();
   double& val1 = std::get<0>(numPair);
   double& val2 = std::get<1>(numPair);
   std::cout << "From inside main(), you entered: "
      << val1
      << " and "
      << val2
      << std::endl;

   /*
   double* thing1 = new double;
   double* thing2 = new double;
   //getFloatsPassByREALRef(*thing1,*thing2);
   printf("%f\n",*thing1);
   printf("%f\n",*thing2);
   delete thing1;
   delete thing2;
   */
}
