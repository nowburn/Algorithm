#include <iostream>
#include <queue>

using namespace std;

/*
 *二分搜索树
 * 
 */

template <typename Key, typename Value>
class BST
{
 public:
   BST()
   {
      root = NULL;
      count = 0;
   }
   ~BST()
   {
      destroy(root);
   }

   int size()
   {
      return count;
   }

   bool isEmpty()
   {
      return count == 0;
   }

   void insert(Key key, Value value)
   {
      root = insert(root, key, value);
   }

   bool contain(Key key)
   {
      return contain(root, key);
   }

   Value *search(Key key)
   {
      return search(root, key);
   }

   void preOrder()
   {
      preOrder(root);
   }

   void inOrder()
   {
      inOrder(root);
   }

   void postOrder()
   {
      postOrder(root);
   }

   void levelOrder()
   {
      queue<Node *> q;
      q.push(root);

      while (!q.empty())
      {
         Node *node = q.front();
         q.pop();
         cout << node->value << endl;
         if (node->left)
            q.push(node->left);
         if (node->right)
            q.push(node->right);
      }
   }

 private:
   struct Node
   {
      Key key;
      Value value;
      Node *left;
      Node *right;

      Node(Key key, Value value)
      {
         this->key = key;
         this->value = value;
         this->left = this->right = NULL;
      }
   };
   Node *root;
   int count;

   Node *insert(Node *node, Key key, Value value)
   {
      if (node == NULL)
      {
         count++;
         return new Node(key, value);
      }

      if (key == node->key)
         node->value = value;
      else if (key < node->value)
         node->left = insert(node->left, key, value);
      else
         node->right = insert(node->right, key, value);
   }

   bool contain(Node *node, Key key)
   {
      if (node == NULL)
         return false;
      if (node->key == key)
         return true;
      else if (key < node->key)
         return contain(node->left, key);
      else
         return contain(node->right, key);
   }

   Value *search(Node *node, Key key)
   {
      if (node == NULL)
         return NULL;
      if (node->key == key)
         return &(node->value);
      else if (key < node->key)
         return search(node->left, key);
      else
         return search(node->right, key);
   }

   void preOrder(Node *node)
   {
      if (node)
      {
         cout << node->value << endl;
         preOrder(node->left);
         preOrder(node->right);
      }
   }

   void inOrder(Node *node)
   {
      if (node)
      {
         inOrder(node->left);
         cout << node->value << endl;
         inOrder(node->right);
      }
   }

   void postOrder(Node *node)
   {
      if (node)
      {
         postOrder(node->left);
         postOrder(node->right);
         cout << node->value << endl;
      }
   }

   void destroy(Node *node)
   {
      if (node)
      {
         destroy(node->left);
         destroy(node->right);

         delete node;
         count--;
      }
   }
};

int main()
{
   BST<int, int> bst;
   srand(time(NULL));
   // for (int i = 1; i <= 10; i++)
   // {
   //    bst.insert(i, i);
   // }
   // cout << bst.contain(10) << endl;
   // cout << bst.contain(100) << endl;
   // int *value = bst.search(10);
   // cout << bst.search(100) << endl;

   // cout << *value << endl;
   // *value = 20;
   // cout << *bst.search(10) << endl;

   for (int i = 0; i < 5; i++)
   {
      int a = rand() % 100;
      bst.insert(a, a);
   }

   bst.inOrder();
   cout << "=====================" << endl;
   bst.levelOrder();

   return 0;
}
