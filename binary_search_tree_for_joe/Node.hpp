#ifndef NODE_HPP
#define NODE_HPP

template <class T>
struct Node
{
  // the data, type T
  T data;

  // the children nodes;
  Node* left = 0;
  Node* right = 0;

  Node(const T& t) { data = t; }
  ~Node() { delete left; delete right; }
};

#endif
