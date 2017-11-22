#include <iostream>
#include <iterator>

class Node {
    int data;
    Node* next;
  public:
    Node() {};
    void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Add(int data) {
      Node* newNode = new Node();
      newNode->SetData(data);
      newNode->SetNext(NULL);
      Node *tmp = head;
      if ( tmp != NULL ) {
        while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
        }
      tmp->SetNext(newNode);
      }
      else {
      head = newNode;
      }
    }
    void Delete(int data) {
      Node *tmp = head;
      if ( tmp == NULL )
      return;
      if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL;
      }
      else {
        Node *prev;
        do {
          if ( tmp->Data() == data ) break;
            prev = tmp;
            tmp = tmp->Next();
        } while ( tmp != NULL );
        prev->SetNext(tmp->Next());
        delete tmp;
      }
    }
    void Print() {
      Node *tmp = head;
      if ( tmp == NULL ) {
        std::cout << "EMPTY" << std::endl;
        return;
      }
      if ( tmp->Next() == NULL ) {
        std::cout << tmp->Data();
        std::cout << " --> ";
        std::cout << "NULL" << std::endl;
      }
      else {
      do {
        std::cout << tmp->Data();
        std::cout << " --> ";
        tmp = tmp->Next();
      }
      while ( tmp != NULL );
      std::cout << "NULL" << std::endl;
      }
    } 
};

class Stack {
private: 
  List my_list;
public:
  void push(int a) {
    my_list.Add (a);
  };
  void pop (int a) {
       my_list.Delete(a);
  };
 
  void print() {
    my_list.Print();
    }
};
int main()
{
    Stack st;
    st.push(100);
    st.print();
    st.pop(100);
    st.print();
}
