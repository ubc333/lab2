#include <iostream>
#include <thread>

void passbyvalue(bool setme) {
  setme = true;
}

void passbyref(bool& setme) {
  setme = true;
}

int main() {

  bool b1 = false;
  passbyvalue(std::ref(b1));
  std::cout << "b1: " << b1 << std::endl;

  bool b2 = false;
  passbyref(std::ref(b2));
  std::cout << "b2: " << b2 << std::endl;

  bool b3 = false;
  std::thread t3(passbyvalue, std::ref(b3));
  t3.join();
  std::cout << "b3: " << b3 << std::endl;

  bool b4 = false;
  std::thread t4(passbyref, std::ref(b4));
  t4.join();
  std::cout << "b4: " << b4 << std::endl;

  return 0;

}