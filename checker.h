#include <iostream>
#include <string>
#include <fstream>
using std::string;

class checker{
private:
  bool debug;
  bool swap;
  bool chk_stat(std::ifstream& fin);
  void chk_swap(std::ifstream& fin);

  void chk_hdr(std::ifstream& fin); // 0x00
  void chk_fmt(std::ifstream& fin); // 0x200
public:
  void do_check(string name, bool swap);

  checker(bool dbg = false);
  ~checker();
};
