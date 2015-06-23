#include <iostream>
#include <iomanip>
#include "checker.h"
#include <getopt.h>
using std::cout;
using std::setw;
using std::endl;
using std::string;

void show_help(string appname){
  cout << "Usage: " << appname << " options [inputfile]" << endl;
  cout << " -h --help" << setw(40) << "Display help information." << endl;
  cout << " -t --trvk" << setw(40) << "Set the trvkpatches flag." << endl;
  cout << " -f --force" << setw(38) << "Set the forcepatch flag." << endl;
  cout << " -a --autoexit" << setw(33) << "Set the autoexit flag." << endl;
  cout << " -s --swap" << setw(38) << "Enable the swap option." << endl;
  cout << " -d --debug" << setw(30) << "Show debug info." << endl;
}

int main(int argc, char** argv){
  int next_op;
  const char* const short_op = "htfasd";
  const struct option long_op[] = {
  };
  string appname = argv[0];
  do{
    next_op = getopt_long(argc, argv, short_op, long_op, NULL);
    switch(next_op){
      case 'h':
      case -1:
      default:
        break;
    }
  }while(next_op!=-1);

  if(optind >= argc){
    show_help(appname);
    return 1;
  }

  checker cc(false);
  cc.do_check(argv[optind], false);

  return 0;
}
