#include <bits/stdc++.h>
  
using namespace std;

int main() {
  int n, m, i, j;
  int cont = 1;
  char type;
  bool firstLoop = false;
  pair<int, int> pairs;
  vector< pair<int, int> > h;
  vector< pair<int, int> > v;
  map<char, vector<pair<int, int> > > lines;

  int vCheck1 = 0, vCheck2 = 0;
  int hCheck1 = 0, hCheck2 = 0;
  int tam;
  int amtEqual = 0;
  pair<int, int> checkPair;
  pair<int, int> inversePair;
  vector<int> contTamanho(9, 0);

  while(scanf("%d", &n) != EOF) {
    scanf(" %d", &m);

    if(firstLoop)
      cout << endl << "**********************************" << endl << endl;

    for(int k = 0; k < m; k++) {
      scanf(" %c", &type);
      scanf(" %d", &i);
      scanf(" %d", &j);

      pairs = make_pair(i, j);

      switch(type) {
        case 'H':
          h.push_back(pairs);
          lines[type] = h;
          break;
        case 'V':
          v.push_back(pairs);
          lines[type] = v;
          break;
      }
    }

    tam = n - 1;
    while(tam > 0) {

        for(hCheck1 = 1; hCheck1 < n; hCheck1++) {
          amtEqual = 0;

          if(hCheck1 + tam > n) break;

          for(int l = 1; l <= n; l++) {
            vCheck1 = 0;
            vCheck2 = 0;
            if(l + tam > n) break;


            for(hCheck2 = l; hCheck2 < n; hCheck2++) {
              checkPair = make_pair(hCheck1, hCheck2);

              if(vCheck1 > 0) {
                inversePair = make_pair(vCheck1, vCheck2);
              } else {
                inversePair = make_pair(hCheck2, hCheck1);
                vCheck1 = hCheck2;
                vCheck2 = hCheck1;
              }

              if(find(lines['H'].begin(), lines['H'].end(), checkPair) != lines['H'].end() && find(lines['V'].begin(), lines['V'].end(), inversePair) != lines['V'].end()) {
                  amtEqual++;
                  if(amtEqual == tam) break;
                  vCheck2++;
              }
                else {
                  vCheck1 = 0;
                  vCheck2 = 0;
                  amtEqual = 0;
                  break;
                }
            }

            if(amtEqual == tam) {
              int aux, aux2;
              aux = inversePair.first;
              aux2 = inversePair.second;

              vCheck1 = hCheck2 + 1;
              vCheck2 = hCheck1;

              for(int auxCheck = aux; auxCheck < auxCheck + tam; auxCheck++) {
                checkPair = make_pair(aux2 + 1, auxCheck);
                inversePair = make_pair(vCheck1, vCheck2);

                if(find(lines['H'].begin(), lines['H'].end(), checkPair) != lines['H'].end() && find(lines['V'].begin(), lines['V'].end(), inversePair) != lines['V'].end()) {
                  amtEqual++;
                  vCheck2++;
                  if(amtEqual == (tam*2)) {
                    break;
                  }
                } else {
                  amtEqual = 0;
                  break;
                }
              }
            }
            if(amtEqual == (tam*2)) {
              contTamanho[tam]++;
              amtEqual = 0;
            }
          }
          
        }

        --tam;
    }
    vector<int>::iterator iit = adjacent_find(contTamanho.begin(), contTamanho.end(), not_equal_to<int>());

    cout << "Problem #" << cont << endl << endl;
    if(iit == contTamanho.end()) {
      cout << "No completed squares can be found." << endl;
    } 
    else {
      for(auto it = contTamanho.begin(); it != contTamanho.end(); it++) {
        if((it - contTamanho.begin()) == 0 || *it == 0) continue;
        cout << *it << " square (s) of size " << it - contTamanho.begin() << endl;
      }
    }
    fill(contTamanho.begin(), contTamanho.end(), 0);
    h.clear();
    v.clear();
    lines.clear();
    cont++;
    firstLoop = true;
  }


  return 0;
}