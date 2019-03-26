#include <bits/stdc++.h>

#define MAX 110
#define INF 999999.9

using namespace std;
vector<pair <double, double> > tree(MAX);

void mst(int freckles) {
    vector<int> checkedNode(MAX, 0);
    vector<double> dist(MAX, INF);
    int nodeToCheck = 0;
    double min = INF;
    double total = 0;
    double freckleEdge = 0;

    dist[nodeToCheck] = 0.0;

    while(!checkedNode[nodeToCheck]) {
        checkedNode[nodeToCheck] = 1;

        for(int i=0; i<freckles; i++) {
            if(!checkedNode[i]) {
                freckleEdge = sqrt(pow(tree[nodeToCheck].first - tree[i].first, 2) + pow(tree[nodeToCheck].second - tree[i].second, 2));
                if(freckleEdge<dist[i]) dist[i] = freckleEdge; // Keeps the smallest distance between two nodes to connect them
            }
        }

        nodeToCheck = 0;

        for(int i=0; i<freckles; i++) {
            if(!checkedNode[i]) {
                if(dist[i] < min) {
                    nodeToCheck = i; // Will check what other freckles to connect from this node
                    min = dist[i];
                }
            }
        }

        if(nodeToCheck != 0) {
            total += min;
        }
        min = INF;
    }
    printf("%.2f\n", total);
}

int main() {
    int cases;
    int freckles;
    double x, y;
    pair<double, double> coords;

    cin >> cases;

    while(cases--) {
        cin >> freckles;

        for(int i=0; i<freckles; i++) {
            cin >> x >> y;
            coords = make_pair(x, y);
            tree[i] = coords;
        }

        mst(freckles);
        if(cases) cout << endl;
    }
    return 0;
}