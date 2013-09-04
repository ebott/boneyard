using namespace std;
#include <queue>

struct BST_smart_node
{
   BST_smart_node(int i, string str)
      :key_(i)
      ,value_(str)
      ,parent_(nullptr)
      ,l_child_(nullptr)
      ,r_child_(nullptr)
   {}

   ~BST_smart_node()
   {
      delete r_child_;
      delete l_child_;
   }
 
   int key() const
   {
      return key_;
   }

   void key(int new_key)
   {
      key_ = new_key;
   }

   string value() const
   {
      return value_;
   }

   void value(string new_value)
   {
      value_ = new_value;
   }

   BST_smart_node* l_child() const
   {
      return this->l_child_;
   }

   void l_child(BST_smart_node* new_child)
   {
      this->l_child_ = new_child; 
   }

   BST_smart_node* r_child() const
   {
      return this->r_child_;
   }

   void r_child(BST_smart_node* new_child)
   {
      this->r_child_ = new_child; 
   }

   BST_smart_node* parent() const
   {
      return this->parent_;
   }

   void parent(BST_smart_node* new_parent)
   {
      this->parent_ = new_parent;
   }

   template <typename FunType1, typename FunType2>
   void binary_trans
      (int target_key, FunType1 hit_fcn, FunType2 miss_fcn)
   {
      BST_smart_node* curr_node = this;
      bool searching = true;
      while(searching == true)
      {
         if(target_key == curr_node->key())
         {
            hit_fcn(curr_node);
            searching = false;
         }
         else if(target_key < curr_node->key())
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
         else if(target_key > curr_node->key())
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
   void DFT(FunType visit)
   {
      BST_smart_node* curr_node = this;
      if(curr_node == nullptr)
      {
         return;
      }

      curr_node->l_child()->DFT(visit);
      visit(curr_node);
      curr_node->r_child()->DFT(visit);
   }

   template <typename FunType>
   void BFT(FunType visit)
   {
      BST_smart_node* curr_node = this;
      queue<BST_smart_node*>  node_queue;
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

   BST_smart_node* in_order_successor()
   {
      //find the left-most child of right subtree
      BST_smart_node* curr_node = this->r_child();
      bool done = false;
      while(done == false)
      {
         if(curr_node->l_child() != nullptr)
         {
            curr_node = curr_node->l_child();
         }
         else
         {
            done = true;
         }
      }
      return curr_node;
   }

   private:
      int key_;
      string value_;
      BST_smart_node* parent_;
      BST_smart_node* l_child_;
      BST_smart_node* r_child_;

};
