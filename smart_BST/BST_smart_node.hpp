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
      // should this be a private fcn????
      // this method will delete node its called on and ALL
      // ITS CHILDREN!  we want this, no??
      //
      // Then deleteing the larger tree struct is simply a
      // metter of deleting the root;

      //recursive outline:
      //1)call this delete routine on your children (if they
      //exist).
      //2)delete yourself
   }

   int key() const
   {
      return key_;
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


   private:
      int key_;
      string value_;
      struct BST_smart_node* parent_;
      struct BST_smart_node* l_child_;
      struct BST_smart_node* r_child_;

      template <typename FunType1, typename FunType2>
      binary_trans(int target_key, FunType1 hit_fcn, Funtype2 miss_fcn)
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
      void DFT(FunType visit) const
      {
         BST_smart_node* curr_node = this;
         if(curr_node == nullptr)
         {
            return;
         }

         DFT(curr_node->l_child(), visit);
         visit(curr_node);
         DFT(curr_node->r_child(), visit);
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
};
