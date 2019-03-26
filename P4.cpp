#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
  int qtdGroup;
  int qtdGifting;
  int amount;
  string giving;
  string receiving;
  string person;
  bool firstLoop = true;
  unordered_map<string, int> gifters;
  vector<string> names;
  
  while(scanf("%d", &qtdGroup) != EOF) {
    if(!firstLoop) cout << endl;

    for(int i = 0; i < qtdGroup; i++) {
      cin >> person;

      names.push_back(person);
    }

    for(int j = 0; j < qtdGroup; j++) {
      cin >> giving;
      cin >> amount;
      cin >> qtdGifting;

      if(qtdGifting == 0) continue;

      amount /= qtdGifting;

      for(int k = 0; k < qtdGifting; ++k) {
        cin >> receiving;
        gifters[receiving] += amount;
        gifters[giving] -= amount;
      }
    }

    for(auto it : names) {
      cout << it << " " << gifters[it] << endl;
    }

    gifters.clear();
    names.clear();
    firstLoop = false;
  }

  return 0;
}