#include <istream>
#include <iostream>
#include "Scheduler.h"
int main() {
  int mode = 0;
  int procs = 8;
  std::cout<<"Enter \"0\" for File Input or \"1\" for Keybord Input" << std::endl;
  std::cin >> mode;
  std::cout<<"Enter number of processors in your cluster" << std::endl;
  std::cin >> procs;
  Scheduler s(mode,procs);
  s.Run();
}
