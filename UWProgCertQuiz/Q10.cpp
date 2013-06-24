#include <iostream>
#include <vector>

int main()
{
   std::string str = "I love spaces ! ! ! ";
   char charstr[30] = "I also love them spaces! ! ";

   std::cout << "The string: \"" 
      << str 
      << "\" \n...and the char array: \"" 
      << charstr 
      << "\""
      << std::endl;

   std::string newStr;
   for(int i=0; i<str.size(); ++i)
   {
      if(str[i] != ' ')
      {
         newStr.push_back(str[i]);
      }
   }
   std::cout << newStr 
      << std::endl
      << std::endl;;

   //try to do the same thing here without push_back
   char noSpaceStr[sizeof(charstr)];
   int j = 0;
   for(int i=0; charstr[i]; ++i)
   {
      if(charstr[i] != ' ')
      {
         std::cout << charstr[i];
         noSpaceStr[j] = charstr[i];
         ++j;
      }
   }
   std::cout << noSpaceStr
      << "end?"
      << std::endl;
   
}
