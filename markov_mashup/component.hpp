#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <deque>
using namespace std;


struct component
{

   component(string inputfile, int words, int length)
      :filename_(inputfile)
      ,outwords_(words)
      ,prefix_len_(length)
      {
         string buff;
         Prefix prefix;
         for(size_t j=0; j < prefix_len_; ++j)
            {
               prefix.push_back("\n");
            }

         ifstream infile (filename_);

         while(!getline(infile,buff).eof())
         {
            parse_words(prefix, buff);
         }

         gen_output();
      } 

   ~component()
   {
      /*
      TODO: this!
      */
   }

   private:
      string filename_;
      int outwords_;
      size_t prefix_len_;
      typedef deque<string> Prefix;
      map<Prefix,vector<string>> state_list;

      void add(Prefix& prefix, string& new_word)
      {
           if(prefix.size() == prefix_len_)
           {
               state_list[prefix].push_back(new_word);
               prefix.pop_front();
           } 
           prefix.push_back(new_word);
      }

      void parse_words(Prefix& prefix, string& input_line)
      {
         int char_ptr = 0;
         int space_ptr = 0;
         int len = 0;
         string this_word = "";

         while(space_ptr != -1)
         {
            char_ptr = get_next_what(input_line,space_ptr,false);
            space_ptr = get_next_what(input_line,char_ptr,true);

            if(space_ptr != -1 && char_ptr != -1)
            {
               len = space_ptr - char_ptr;
               this_word = input_line.substr(char_ptr,len); 
               if(this_word.length() > 0)
               {
                  add(prefix, this_word);
               }
            }
            char_ptr = space_ptr;
         }
      }

      int get_next_what(string str, int start, bool space)
      {
         //if looking for next char, bool space is false
         for(size_t i = start; i<str.length(); ++i)
         {
            if( (str.at(i) == ' ') == space)
            {
               return i;
            }
            if(space && (i == str.length()-1))
            {
               return i+1;
            }
         }
         return -1;
      }

      void gen_output()
      {
         Prefix chain_prefix;
         for(size_t j=0; j < prefix_len_; ++j)
         {
            chain_prefix.push_back("\n");
         }
         
         for(int i=0; i < outwords_; ++i)
         {
            vector<string>& suffix_list = state_list[chain_prefix];
            string& word = suffix_list[ rand() % suffix_list.size()];
           
            if(word == "\n")
            {
               break;
            }
            cout << word << " ";
            chain_prefix.pop_front();
            chain_prefix.push_back(word);
         }
         cout << "." << endl;
      }
};
