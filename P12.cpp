#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int n;
  int hi = 0, lo = 0;
  int amountSheets;
  int amountBlank;

  scanf(" %d", &n);
  while(n != 0) {
    amountSheets = ceil(((float)n/4));
    amountBlank = amountSheets*4 - n;
    hi = n;
    lo = 1;

    cout << "Printing order for " << n << " pages:" << endl;
    for(int i=1; i <= amountSheets; i++) {
      cout << "Sheet " << i << ", front: ";
      
      if(n == 1) {
        cout << "Blank, " << lo << endl;
        break;
      }
      if(amountBlank > 0) {
        cout << "Blank, " << lo << endl;
        amountBlank--;
      } else {
        cout << hi << ", " << lo << endl;
        hi--;
      }

      lo++;

      cout << "Sheet " << i << ", back : ";
      if(amountBlank > 0) {
        cout << lo << ", Blank" << endl;
        amountBlank--;
      } else {
        cout << lo << ", " << hi << endl;
        hi--;
      }

      lo++;
    }
    scanf(" %d", &n);
  }
  return 0;
}