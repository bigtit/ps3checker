#include <iostream>
#include "checker.h"

int main(int argc, char** argv){
  checker cc(false);
  cc.do_check(argv[1], false);
  return 0;
}

