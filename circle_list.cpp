#include <iostream>

class List {
public: 
    struct Node {
        Node* next;
        int data;
    };
private:
    Node* m_head;
    int length;
public: 
    List();
    void add(int elem);
    Node* getposition(int pos);
    int getlength();
    void circle(Node* a);
    int getnode();
};

List::List() {
  this->length = 0;
  this->m_head = nullptr;
}

void List::add(int elem) {
  List::Node* node = new Node();
  List::Node* current = m_head;
  if(current == nullptr) {
    m_head = node;
    m_head->data = elem;
    m_head->next = current;
    length++;
    return;
  }
  while(current->next) {
    current = current->next;
  }
  current->next = node;
  current->next->data = elem;
  length++;
  return;
}
 
List::Node* List::getposition(int pos) {
  int count = 0;
  List::Node* current = this->m_head;
  while(count++ < pos){
    current = current->next;
  }
  return current;
}

void List::circle(List::Node* current) {
  int i = 0;
  while(i <= List::getlength()+6) {
    std::cout << " -----> " << m_head->data;
    m_head = m_head->next;
    if (m_head->next == nullptr) {
      m_head->next = current;
    }
    ++i;
  }
}

int List::getlength() {
  return length;
}

int List::getnode() {
  int i = 0;
  List::Node* head = m_head;
  while(i++ <= List::getlength()) {
    if (head->next == m_head) {
      std::cout << std::endl << " <- node -> " << head->data; //it prints the data of the node which one serves as the node in the circle
      return head->data;
    } 
    else
    head = head->next;
  }
}


int main () 
{
  List my_list;
  my_list.add(1);
  my_list.add(2);
  my_list.add(3);
  my_list.add(4);
  my_list.add(5);
  my_list.circle(my_list.getposition(3));
  my_list.getnode();
}