#include <iostream>
#include <string>

using namespace std;

int main() {
  int i = 0, j = 0;
  int stringSize = 0;
  bool printAy = false;
  string s;
  char savedChar = 0;

  while(getline(cin, s)) {
    stringSize = s.length();
    i = 0;

    while(i < stringSize) {
      if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        printAy = true;
      }
      else if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {
        printAy = true;
        savedChar = s[i];
        i++;
      } else {
        cout << s[i];
      }

      if(printAy) {
        for(j = i; j < stringSize; j++) {
          if(s[j] <= 64 || (s[j] >= 91 && s[j] <= 96) || (s[j] >= 123 && s[j] <= 127)) {
            break;
          }

          cout << s[j];
        }

        if(savedChar != 0)
          cout << savedChar;

        cout << "ay";

        if(j < stringSize) {
          cout << s[j];
        }
        i = j;
      }
      i++;
      printAy = false;
      savedChar = 0;
    }
    cout << endl;
  }

  return 0;
}