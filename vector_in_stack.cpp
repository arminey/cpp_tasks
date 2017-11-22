#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
class Stack {
private: 
  std::vector<T> my_vec;
public:
  void push(T a) {
    my_vec.push_back(a);
  };
  void pop () {
    try {
      my_vec.pop_back();
      if (my_vec.empty()) {
        throw "Error"; 
      }
    }
    catch (const char* x) {
       std::cout << x << ": Vector is empty, there aren't any elements." << std::endl;
    }
  };
  int peek () const {
    std::cout << "Peek of vector: ";
    return *(my_vec.end()-1); 
  };
  int size () const {
    std::cout << "Size of vector: ";
    return my_vec.size();
  };
  void print() {
    std::cout << "Elements of vector: ";
    for(typename std::vector<T>::iterator it = my_vec.begin(); it != my_vec.end(); ++it) {
      std::cout << *it << ' ' ;
    }
    std::cout << std::endl;
  }
};

int main () 
{
  Stack<int> st;
  st.push(5);
  st.push(7);
  st.print();
  std::cout << st.peek() << std::endl;
  st.pop();
  std::cout << st.size() << std::endl;
  st.pop();
}