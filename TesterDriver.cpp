#include <istream>
#include <iostream>
#include "Scheduler.h"
int main() {
  int mode=0;
  std::cout<<"File(0) or Input(1)" << std::endl;
  std::cin >> mode;
  Scheduler s;
  s.Run();
}
