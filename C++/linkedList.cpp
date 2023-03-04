#include <iostream>

//Node class
class Node {
private:
  //private members
  int data;
  Node *next;

public:
  //Setters and Getters
  void setData(int v) { data = v; }
  void setNext(Node *p) { next = p; }
  int getData() { return data; }
  Node *getNext() { return next; }
};

//Integer Linked List class
class IntLinkedList {
private:
  Node *first;

public:
  //Construct.
  IntLinkedList() { first = NULL; }
  //func. add to start
  void addBeg(int v) {
    Node *node = new Node;
    (*node).setData(v);
    (*node).setNext(first);
    first = node;
  }
  //func: add to end.
  void addEnd(int v) {
    Node *node = new Node;
    (*node).setData(v);
    (*node).setNext(NULL);
    if (first == NULL) {
      first = node;
      return;
    }

    Node *nodeLast = new Node;
    nodeLast = first;
    while ((*nodeLast).getNext() != NULL) {
      nodeLast = (*nodeLast).getNext();
    }
    (*nodeLast).setNext(node);
  }

  //func. : del one from start
  void deleteBeg() {
    if (first == NULL)
      return;
    Node *node = new Node;
    node = first;
    first = (*first).getNext();
    delete node;
  }
  //func. : del one from end
  void deleteEnd() {
    if (first == NULL)
      return;
    Node *node = new Node;
    Node *nodeBeforeLast = new Node;
    node = first;
    while ((*node).getNext() != NULL) {
      nodeBeforeLast = node;
      node = (*node).getNext();
    }
    (*nodeBeforeLast).setNext(NULL);
    delete node;
  }
  //func. : del the nodes containing the given value
  void deleteVal(int v) {
    if (first == NULL)
      return;
    Node *node = new Node;
    Node *previousNode = new Node;
    node = first;
    while (node != NULL) {
      if ((*node).getData() == v) {
        first == (*node).getNext();
        if (node == first) {
          first = (*node).getNext();
        } else {
          (*previousNode).setNext((*node).getNext());
        }
      }
      previousNode = node;
      node = (*node).getNext();
    }
  }
  //print the list
  void printList() {
    if (first == NULL)
      return;
    Node *node = new Node;
    node = first;
    std::cout << "\nList:   ";
    while (node != NULL) {
      std::cout << (*node).getData() << "  ";
      node = (*node).getNext();
    }
    std::cout << "\n";
  }
//reverse the list
  void reverseList() {
    if (first == NULL)
      return;
    Node *before = NULL, *after = NULL, *node;
    node = first;
    while (node != NULL) {
      after = (*node).getNext();
      (*node).setNext(before);
      before = node;
      node = after;
    }
    first = before;
  }
};

//func. MAIN
int main() {
  IntLinkedList list; //obj: IntLinkedList

  for (;;) { //endless loop

    //getting options and executing according to the given option
    char option;
    std::cout << "Available Options:"
              << "\n";
    std::cout << "\t1 --> Insert a node at the beginning."
              << "\n";
    std::cout << "\t2 --> Insert a node at the end."
              << "\n";
    std::cout << "\t3 --> Delete a node at the beginning."
              << "\n";
    std::cout << "\t4 --> Delete a node at the end."
              << "\n";
    std::cout << "\t5 --> Delete nodes with value v."
              << "\n";
    std::cout << "\t6 --> Reverse the list."
              << "\n";
    std::cout << "\nEnter operation number(1-6):"
              << " ";
    std::cin >> option;

    int val;
    switch (option) {
    case '1':
      std::cout << "\nEnter Value(Integer):"
                << " ";
      std::cin >> val;
      list.addBeg(val);
      list.printList();
      break;
    case '2':
      std::cout << "\nEnter Value(Integer):"
                << " ";
      std::cin >> val;
      list.addEnd(val);
      list.printList();
      break;
    case '3':
      list.deleteBeg();
      list.printList();
      break;
    case '4':
      list.deleteEnd();
      list.printList();
      break;
    case '5':
      std::cout << "\nEnter Value(Integer):"
                << " ";
      std::cin >> val;
      list.deleteVal(val);
      list.printList();
      break;
    case '6':
      list.reverseList();
      list.printList();
      break;
    default:
      std::cout << "\nNot a valid option."
                << "\n";
      std::cin.get();
    }

    std::cin.get();
    std::cin.get();
  }

  return 0;
}