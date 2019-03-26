#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(string s) {
  int sizeString = s.length();
  int dec = 0;
  int base = 1;

  for(int i = (sizeString - 1); i >= 0; i--) {
    dec += base * ((int)s[i] - 48);
    
    base = base*2;
  }

  return dec;
}

int mdc(int a, int b) {
  int r = a%b;
  
  if(r == 0)
    return b;

  return mdc(b, r);
}

int main() {
  int nPairs = 0;
  string pair1;
  string pair2;

  int decimal1 = 0;
  int decimal2 = 0;

  while(scanf(" %d", &nPairs) != EOF) {

    for(int i = 0; i < nPairs; i++) {
      cin >> pair1;
      cin >> pair2;

      decimal1 = binaryToDecimal(pair1);
      decimal2 = binaryToDecimal(pair2);

      cout << "Pair #" << i+1 << ": ";

      if(mdc(decimal1, decimal2) != 1)
        cout << "All you need is love!" << endl;
      else
        cout << "Love is not all you need!" << endl;

    }
  }
  return 0;
}