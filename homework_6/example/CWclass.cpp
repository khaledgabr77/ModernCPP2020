#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass() { cout << " default " << endl; }
  // Copy (&) and Move (&&) constructors
  MyClass(const MyClass &other) { cout << "copy" << endl; }
  MyClass(MyClass &&other) { cout << "move" << endl; }
  // Copy (&) and Move (&&) operators
  MyClass &operator=(const MyClass &other) { cout << "copy operator " << endl; }
  MyClass &operator=(MyClass &&other) { cout << "move operator " << endl; }
};
int main() {
  MyClass a;
  MyClass b = a;
  a = b;
  MyClass c = std ::move(a);
  c = std::move(b);
}