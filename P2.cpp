#include <iostream> 
#include <string>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int isSlump(string s) {
  int aux = 0;
  string newSlump;

  if(s[s.size() - 1] != 'G') {
    return 0;
  }

  if(s.size() == 1 && s[0] == 'G') {
    return 1;
  }

  if(s[0] == 'D' || s[0] == 'E') {
    if(s[1] != 'F')
      return 0;

    newSlump = s.substr(1, s.size());
    while(newSlump[aux] == 'F') {
      aux++;
    }

    newSlump = newSlump.substr(aux);

    if(isSlump(newSlump))
      return 1;
  }


  return 0;
}

int isSlimp(string s, bool has_c = false) {
  size_t h_pos;
  size_t c_pos;

  if(s[0] != 'A') {
    return 0;
  }

  s = s.substr(1, s.size());

  h_pos = s.find_last_of('H');

  if(h_pos == 0 && has_c && (s[h_pos + 1] == 'C' || s[h_pos + 1] == '\0'))
    return 1;
  else if(h_pos == 0 && !has_c)
    return 1;

  if(s[0] == 'B') {
    c_pos = s.find_last_of('C');
    if(c_pos != -1 && isSlimp(s.substr(1, c_pos - 1), true)) {
      return 1;
    }
  } else {
    c_pos = s.find_first_of('C');
    if(c_pos != -1 && isSlump(s.substr(0, c_pos)))
      return 1;
  }

  return 0;
}

int main() {
  int lines = 0;
  size_t slimp_size;
  string slurpy;
  string slump;
  string slimp;
  

  cin >> lines;
  cout << "SLURPYS OUTPUT" << endl;

  for(int i = 0; i < lines; i++) {
    cin >> slurpy;

    slimp_size = slurpy.find_last_of('C');
    if(slimp_size == -1) slimp_size = slurpy.find_last_of('H');

    slump = slurpy.substr(slimp_size + 1);
    slimp = slurpy.substr(0, slimp_size + 1);

    if(isSlimp(slimp)) {
      if(isSlump(slump))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  cout << "END OF OUTPUT" << endl;
  return 0;
}