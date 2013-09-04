#include <iostream>
#include "BST_smart_node.hpp"
 
using namespace std;

struct smart_BST
{
   smart_BST(int root_key, string root_val)
      :root_(new BST_smart_node(root_key,root_val))
   {}

   ~smart_BST()
   {
      delete root_;
   }

   void insert_node(int new_key, string new_val)
   {
      auto insert_fcn = [&] (BST_smart_node* n)
      {
         BST_smart_node* new_node = 
            new BST_smart_node(new_key,new_val);
         if(new_key <= n->key())
         {
            n->l_child(new_node);
            new_node->parent(n);
         }
         else if(new_key > n->key())
         {
            n->r_child(new_node);
            new_node->parent(n);
         }
      };

      root_->binary_trans(new_key,insert_fcn,insert_fcn);
   }

   void print_tree() const
   {
      auto print_node = [&] (BST_smart_node* n)
      {
         cout << n
            << "  "
            << n->key()
            << "  "
            << n->value()
            << endl;
      };

      root_->BFT(print_node);
   }

   void inorder_print() const
   {
      cout << "Printing tree in-order..." << endl;
      auto print_node = [&] (BST_smart_node* n)
      {
         cout << n
            << "  "
            << n->key()
            << "  "
            << n->value()
            << endl;
      };
      root_->DFT(print_node);
   }

   void find_node(int key_wanted)
   {
      auto node_found = [&] (BST_smart_node* n)
      { 
         /*
         cout << "Node found: "
            << n
            << "  "
            << n->key()
            << "  "
            << n->value()
            << endl;
            */
      };

      auto node_not_found = [&] (BST_smart_node* n)
      {
         /*
         cout << "Node not found, looking for: "
            << key_wanted
            << ".  Closest match: "
            << n
            << "  "
            << n->key()
            << "  "
            << n->value()
            << endl;
            */
      };

      root_->binary_trans(key_wanted, node_found, node_not_found);
   }

   void delete_node (int doomed_key)
   {
      auto node_not_found = [&] (BST_smart_node* n)
      {
         cout << "No matching node to delete..." << endl;
      };

      auto node_delete = [&] (BST_smart_node* n)
      {
         cout << "Node found, deleting..." << endl;
         
         if((n->l_child() == nullptr) & (n->r_child() == nullptr))
         {
            leaf_delete(n);
         }

         if((n->l_child() == nullptr) ^ (n->r_child() == nullptr))
         {
            single_parent_delete(n);
         }

         if((n->l_child() != nullptr) & (n->r_child() != nullptr))
         {
            double_parent_delete(n);
         }
      };

      root_->binary_trans(doomed_key, node_delete, node_not_found);
   }

   private:
      BST_smart_node* root_;
      
      void leaf_delete(BST_smart_node* doomed_node)
      {
         cout << "Deleting leaf node..." << endl;
         parent_pointer_shift(doomed_node, nullptr);
         delete doomed_node;
      }

      void single_parent_delete(BST_smart_node* doomed_node)
      {
         cout << "Deleting a single parent node..." << endl;
         if(doomed_node->r_child() != nullptr)
         {
            BST_smart_node* orphan = doomed_node->r_child();
            parent_pointer_shift(doomed_node, orphan);
         }
         else if(doomed_node->l_child() != nullptr)
         {
            BST_smart_node* orphan = doomed_node->l_child();
            parent_pointer_shift(doomed_node, orphan);
         }
         doomed_node->parent(nullptr);
         doomed_node->r_child(nullptr);
         doomed_node->l_child(nullptr);
         delete doomed_node;
      }

      void double_parent_delete(BST_smart_node* doomed_node)
      {
         cout << "Swapping double parent node with successor"
            << ", then deleting successor..." 
            << endl;
         
         BST_smart_node* swap_node = doomed_node->in_order_successor();
         //store info from swap_node into temp vars
         //then delete swap_node
         //then shift temp vars into n
         int new_key = swap_node->key();
         string new_value = swap_node->value();

         if((swap_node->l_child() != nullptr)^(swap_node->r_child() != nullptr))
         {
            single_parent_delete(swap_node);
         }
         else
         {
            leaf_delete(swap_node);
         }
         doomed_node->key(new_key);
         doomed_node->value(new_value);
      }

      void parent_pointer_shift(BST_smart_node* doomed_node,  
               BST_smart_node* new_child)
      {
         BST_smart_node* parent_of_doomed = doomed_node->parent(); 
         if(parent_of_doomed->r_child() == doomed_node)
         {
            parent_of_doomed->r_child(new_child);
         } 
         if(parent_of_doomed->l_child() == doomed_node)
         {
            parent_of_doomed->l_child(new_child);
         }

         if(new_child != nullptr)
         {
            new_child->parent(parent_of_doomed);
         }
      }
};
