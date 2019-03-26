#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

char colors[MAX] = {0};
char color1 = 'B';
char color2 = 'W';
bool bicolor = true;

void search(int i, char color, char *colors, vector<int> *graph) {
  if(colors[i] != 0) { 
    if(!(color == colors[i])) {
      bicolor=false;
    }
  } else {
    colors[i]=color;             
    for(int j=0;j<graph[i].size();j++) {
      char nextColor = (color == color1) ? color2 : color1;
      search(graph[i][j], nextColor, colors, graph);
    }
  }
}

int main() {
  int cases;
  int a, b, n;

  scanf(" %d", &cases);
  while(cases != 0) {
    bicolor = true;
    vector<int> graph[cases];

    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &a, &b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    
    search(0, color1, colors, graph);

    if(bicolor) {
        cout << "BICOLORABLE." << endl;
    } else {
        cout << "NOT BICOLORABLE." << endl;
    }

    memset(colors, 0, sizeof(colors));
    scanf(" %d", &cases);
  }

  return 0;
}