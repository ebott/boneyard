#include <iostream>
#include "BST_node.hpp"
#include <queue>
#include <functional>

using namespace std;

struct BST
{
   BST(int root_key, string root_val)
      :root_(new BST_node(root_key, root_val))
   {}

   ~BST()
   {
      // TODO recursively delete nodes
   }
/*
   void insert_node(int new_key, string new_val)
   {
      BST_node* new_node = new BST_node(new_key,new_val);
      BST_node* curr_node = root_;
      
      while(curr_node != nullptr)
      {
         if(new_key >= curr_node->key())
         {
            //move left or insert left
            if(curr_node->l_child())
            {
               curr_node = curr_node->l_child();  
            }
            else 
            {
               curr_node->l_child(new_node);
               new_node->parent(curr_node);
               curr_node = nullptr;
            }
         }
         else if(new_key < curr_node->key())
         {
            //move right or insert right
            if(curr_node->r_child())
            {
               curr_node = curr_node->r_child();  
            }
            else
            {
               curr_node->r_child(new_node);
               new_node->parent(curr_node);
               curr_node = nullptr;
            }
         }
         else
         {
            //we shoud never get here
            throw "ack!";
         }
      }
   }
*/
   void insert_node(int new_key, string new_val)
   {

      auto insert_fcn = [&] (BST_node* n)
      {
         BST_node* new_node = new BST_node(new_key,new_val);
         cout << "hitting the func!" << endl;
         if(new_key <= n->key())
         {
            //this convention means that dupe keys
            //all goes to the left
            n->l_child(new_node);
            new_node->parent(n);
         }
         else if(new_key > n->key())
         {
            n->r_child(new_node);
            new_node->parent(n);
         }
      };

      binary_trans(root_,new_key,insert_fcn,insert_fcn);
   }

   void print_tree()
   {
      BFT(root_,
         [] (BST_node* n)
         {
            cout << n 
               << " "
               << n->key()
               << " "
               << n->value()
               << endl;
         });
   }

   void find_value(int key_wanted)
   {
      cout << "Looking for key "
         << key_wanted
         << endl;

      auto found = [] (BST_node* n)
      {
         cout << "FOUND IT!" << endl;
         cout << n 
            << " "
            << n->key()
            << " "
            << n->value()
            << endl;

      };      
      
      auto not_found = [] (BST_node* n)
      {
         cout << "NOT FOUND IT!" << endl;
      };

      binary_trans(root_, key_wanted, found, not_found);
      /*
      BFT(root_,
         [&] (BST_node* n)
         {
            if(n->key() == key_wanted)  
            {
               cout << "FOUND IT!" 
                  <<  n->value() 
                  << endl;
            }
         });*/
   }
   
   
   void find_key(string val_wanted)
   {
      BFT(root_,
         [&] (BST_node* n)
         {
            if(n->value() == val_wanted)
            {
               cout << "FOUND THIS ONE!"
                  << n->key()
                  << endl;
            }
         });
   }
   
   //REALLLLY NEED TO THINK ABOUT ~BST method!!!!
   private:
      struct BST_node* root_;

      void print_node(BST_node* n)
      {
            cout << n 
               << " "
               << n->key()
               << " "
               << n->value()
               << endl;
      }

      template <typename FunType1, typename FunType2>
      void binary_trans
      (BST_node* curr_node, int target_key, FunType1 hit_fcn, FunType2 miss_fcn)
      {
         bool searching = true;
         while(searching == true)
         {
            if(target_key == curr_node->key())
            {
               hit_fcn(curr_node);
               searching = false;
            }
            else if(target_key > curr_node->key())
            {
               //move left or return
               if(curr_node->l_child())
               {
                  curr_node = curr_node->l_child();  
               }
               else 
               {
                  miss_fcn(curr_node);
                  searching = false;
               }
            }
            else if(target_key < curr_node->key())
            {
               //move right or return
               if(curr_node->r_child())
               {
                  curr_node = curr_node->r_child();  
               }
               else
               {
                  miss_fcn(curr_node);
                  searching = false;
               }
            }
            else
            {
               //we shoud never get here
               throw "ack!";
            }
         }

      }

      template <typename FunType>
      void DFT(BST_node* curr_node, FunType visit) const
      {
         if(curr_node == nullptr)
         {
            return;
         }

         DFT(curr_node->l_child(), visit);
         visit(curr_node);
         DFT(curr_node->r_child(), visit);
      }

      template <typename FunType>
      void BFT(BST_node* curr_node, FunType visit)
      {
         queue<BST_node*>  node_queue;
         node_queue.push(curr_node);

         while(node_queue.size() != 0)
         {
            if(curr_node->l_child())
            {
               node_queue.push(curr_node->l_child());
            }
            if(curr_node->r_child())
            {
               node_queue.push(curr_node->r_child());
            }

            visit(curr_node);
            node_queue.pop();
            curr_node = node_queue.front();
         }
      }     
};

