#include <iostream>
#include <cstdlib>
#include "BST.hpp"

int main()
{
  srand(19);

  BST<int> *b = new BST<int>();
  for (int i = 0; i < 10; ++i)
  {
    b->add(new Node<int>(rand() % 100));
  }
  b->display();
  std::cout << "\nBFS: ";
  b->BFS();
  std::cout << "\nDFS: ";
  b->DFS();

}
