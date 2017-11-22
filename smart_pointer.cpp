#include <iostream>


template <typename T>
class SmartPointer {
private:
    T* resource;
public:
    SmartPointer (T* p) {resource = p;}
    ~SmartPointer () {delete resource;}
    T& operator*() {return *resource;}
    T* operator->() {return resource;}
};



class MyClass {
private:
    int x;
public:
    MyClass () {std::cout << "MyClass ctor" << std::endl;}
    ~MyClass () {std::cout << "MyClass dtor" << std::endl;}
    void set (int a) {x = a;}
    void foo () {std::cout << x << std::endl;}
};

int main ()
{
    SmartPointer<MyClass> ob (new MyClass);
    ob->set(7);
    ob->foo();
}
