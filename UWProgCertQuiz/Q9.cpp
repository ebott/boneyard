#include <iostream>

std::pair<double,double> getFloats()
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
}

int main()
{
   getFloats();

}
