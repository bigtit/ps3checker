#include <cstdio>
#include <iomanip>
#include "checker.h"
using std::cout;

#define error(str) \
  cout << __FILE__ << ", " << __LINE__ << ": " << str << '\n'

void status(string str){
  cout << str << "\n";
}

void checker::do_check(string name, bool swap){
  std::ifstream freader(name.c_str(), std::ios::binary);
  freader >> std::noskipws;
  chk_stat(freader);
  return;
}

checker::checker(bool dbg):debug(dbg){}
checker::~checker(){};

bool checker::chk_stat(std::ifstream& fin){
  status("checking statistics");
  fin.seekg(0, std::ios::end);
  // size
  auto pos = fin.tellg();
  if(pos!=0x1000000L){
    error("size error, exits");
    return false;
  }
  // 0x00s and 0xffs
  char tmp;
  std::streamsize count0, countf;
  count0 = countf = 0;
  fin.seekg(0, std::ios::end);
  while(fin.good()){
    fin.read(&tmp, 1);
    if(tmp==0x00) ++count0;
    else if(tmp==0xff) ++countf;
  }
  // show result
  cout.setf(std::ios::fixed);
  cout << std::setprecision(2) << "0x00: " << 100*(double)count0/pos << "% ";
  cout << ((count0>3083652 && count0<4867070)? "ok":"bad") << "\n";
  cout << std::setprecision(2) << "0xff: " << 100*(double)countf/pos << "% ";
  cout << ((countf>1748186 && countf<1758252)? "ok":"bad") << "\n";

  return true;
}

void checker::chk_hdr(std::ifstream& fin){
  status("checking hdr");
  fin.seekg(0, std::ios::beg); // here we start
  std::vector<char> tmp(16);
  fin.read(&tmp[0], 16); // blank/unknown
  fin.read(&tmp[0], 16); // magic no.
  fin.read(&tmp[0], 16); // size of magic no. area
  return;
}
void checker::chk_fmt(std::ifstream& fin){
  status("checking hdr");
  return;
}
