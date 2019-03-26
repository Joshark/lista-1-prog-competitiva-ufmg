#include <bits/stdc++.h>

#define MAX 110
#define INF 999999

using namespace std;

int m[MAX][MAX];

int main() {
    int edges, nodes, tests;
    int a, b, weight;
    int testA, testB;
    int nCases = 1;

    scanf(" %d %d %d", &nodes, &edges, &tests);
    while(nodes != 0 || edges != 0 || tests != 0) {
        for(int i=0; i<=nodes; i++)
            for(int j=0; j<=nodes; j++)
                m[i][j] = INF;


        while(edges--) {
            scanf(" %d %d %d", &a, &b, &weight);
            m[a][b] = weight;
            m[b][a] = weight;
        }

        for(int k=1; k<=nodes; k++) {
            for(int i=1; i<=nodes; i++) {
                for(int j=1; j<=nodes; j++) {
                    m[i][j] = min(m[i][j], max(m[i][k], m[k][j]));
                }
            }
        }

        printf("Case #%d\n", nCases);

        while(tests--) {
            scanf(" %d %d", &testA, &testB);

            if(m[testA][testB] == INF) cout << "no path";
            else cout << m[testA][testB];

            cout << endl;
        }


        scanf(" %d %d %d", &nodes, &edges, &tests);
        if(nodes != 0 || edges != 0 || tests != 0) {
            nCases++;
            cout << endl;
        }
    }
    
    return 0;
}