using namespace std;

/*
 * the general node element for my basic BST work
 * I hope that this struct will be useable across multiple
 * BST applications.      ebott
 */

struct BST_node
{
   BST_node(int i, string str)
      :key_(i)
      ,value_(str)
      ,parent_(nullptr)
      ,l_child_(nullptr)
      ,r_child_(nullptr)
   {}

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

   BST_node* l_child() const
   {
      return this->l_child_;
   }

   void l_child(BST_node* new_child)
   {
      this->l_child_ = new_child; 
   }

   BST_node* r_child() const
   {
      return this->r_child_;
   }

   void r_child(BST_node* new_child)
   {
      this->r_child_ = new_child; 
   }

   BST_node* parent() const
   {
      return this->parent_;
   }

   void parent(BST_node* new_parent)
   {
      this->parent_ = new_parent;
   }


   private:
      int key_;
      string value_;
      struct BST_node* parent_;
      struct BST_node* l_child_;
      struct BST_node* r_child_;
};
