#ifndef BST_HPP
#define BST_HPP

#include <sstream>
#include <queue>
#include <stack>
#include "Node.hpp"

const std::string INDENT = "     ";

template <class T>
class BST
{
private:
  // the root of the tree (the top parent)
  Node<T>* root = 0;
public:
  BST<T>() {}
  ~BST<T>() { delete root; }

  // add a Node of type T to the tree
  void add(Node<T>* n);
  // add a Node of type T to the tree starting at a sub root
  void add(Node<T>* n, Node<T>* sub_root);

  // output the tree visually
  void display(); // helper function
  void display(Node<T>* sub_root, std::string indent); // recursive

  void BFS();
  void DFS();
};

/*
  This is the add function, it will add a node to the tree
  If the root is null it becomes the root, otherwise it will
    recursively call add with appropriate sub roots to find its place
*/
template <class T>
void BST<T>::add(Node<T>* n)
{
  // check if the tree is empty
  if (!root)
    root = n;
  else
    add(n, root);
}

/*
  will traverse down the tree
  <= goes left
  > goes right
  when it finds a null ptr it will add the node to the tree
*/
template <class T>
void BST<T>::add(Node<T>* n, Node<T>* sub_root)
{
  if (n->data <= sub_root->data)
    if (sub_root->left)
      add(n, sub_root->left);
    else
      sub_root->left = n;
  else
    if (sub_root->right)
      add(n, sub_root->right);
    else
      sub_root->right = n;
}

template <class T>
void BST<T>::display()
{
  std::cout << "--------- BINARY SEARCH TREE ---------" << std::endl;
  display(root, "");
  std::cout << "--------------------------------------" << std::endl;
}

template <class T>
void BST<T>::display(Node<T>* sub_root, std::string indent)
{
  if (!sub_root)
  {
    std::cout << indent << "NULL" << std::endl;
    return;
  }

  display(sub_root->right, indent + INDENT);
  std::cout << indent << sub_root->data << std::endl;
  display(sub_root->left, indent + INDENT);
}

template <class T>
void BST<T>::BFS()
{
  std::queue<Node<T>*> q;
  q.push(root);
  while(!q.empty())
  {
    if (Node<T>* n = q.front())
    {
      std::cout << "[" << n->data << "]";
      q.push(n->left);
      q.push(n->right);
    }
    q.pop();
  }
  std::cout << std::endl;
}

template <class T>
void BST<T>::DFS()
{
  std::stack<Node<T>*> s;
  s.push(root);
  while(!s.empty())
  {
    Node<T>* n = s.top();
    s.pop();
    if (n)
    {
      std::cout << "[" << n->data << "]";
      s.push(n->left);
      s.push(n->right);
    }
  }
  std::cout << std::endl;
}
#endif
