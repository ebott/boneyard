#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <deque>
using namespace std;

struct markov_chainer
{

   markov_chainer(int l)
      :prefix_len_(l)
      {
         //seed the prefix deque      
         for(size_t j=0; j < prefix_len_; ++j)
         {
            prefix.push_back("\n");
         }
      }

   ~markov_chainer()
   {
      /*
      TODO: this!
      */
   }

   void add(string& new_word)
   {
        if(prefix.size() == prefix_len_)
        {
            state_list[prefix].push_back(new_word);
            prefix.pop_front();
        } 
        prefix.push_back(new_word);
   }

   void gen_output(int outwords)
   {
      Prefix chain_prefix;
      for(size_t j=0; j < prefix_len_; ++j)
      {
         chain_prefix.push_back("\n");
      }
      
      for(int i=0; i < outwords; ++i)
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

   private:
      size_t prefix_len_;
      typedef deque<string> Prefix;
      Prefix prefix;
      map<Prefix,vector<string>> state_list;

      };
