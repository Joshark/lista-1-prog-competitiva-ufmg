#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > rows;
vector<char> col;
vector<int> amountVisited(6, 0);
pair<int, int> robotCoords;
int b, w;
// 0-E, 1-N, 2-W, 3-S
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int direction = 0;

bool canTurnRight = false;

void turnLeft() {
    direction++;
    if(direction > 3) direction = 0;
}

void turnRight() {
    direction--;
    if(direction < 0) direction = 3;
}

void moveRobot() {
    int visited[rows.size()][rows[0].size()];
    fill(amountVisited.begin(), amountVisited.end(), 0);

    for(int i=0; i<rows.size(); i++)
        for(int j=0; j<rows[0].size(); j++)
            visited[i][j] = 0;
    
    int x = robotCoords.first;
    int y = robotCoords.second;

    do {
        if(x+dy[direction] < b && x+dy[direction] >= 0 && y-dx[direction] < w && y-dx[direction] >= 0) {
            if(canTurnRight && rows[x+dy[direction]][y-dx[direction]] == '0') {
                turnRight();
                canTurnRight = false;
                continue;
            }
        }
        // Edges of maze
        if(x+dx[direction] >= b || x+dx[direction] < 0 || y+dy[direction] >= w || y+dy[direction] < 0) {
            turnLeft();
            continue;
        }

        // Checks for walls directly in front;
        if(rows[x+dx[direction]][y+dy[direction]] == '1') {
            turnLeft();
            continue;
        }

        if(x+dy[direction] < b && x+dy[direction] >= 0 && y-dx[direction] < w && y-dx[direction] >= 0) {
            // Checks for walls on the right

            if(rows[x+dy[direction]][y-dx[direction]] == '1') {
                canTurnRight = true;
            }
        }

        visited[x][y]++;
        x += dx[direction];
        y += dy[direction];
    } while(x != (b-1) || y != 0);

    for(int i=0; i<rows.size(); i++) {
        for(int j=0; j<rows[0].size(); j++) {
            if(rows[i][j] == '0') {
                amountVisited[visited[i][j]]++;
            }
        }
    }
}

int main() {
    char tile;

    scanf(" %d %d", &b, &w);

    while(b != 0 || w != 0) {
        for(int i=0; i<b; i++) {
            for(int j=0; j<w; j++) {
                scanf(" %c", &tile);
                col.push_back(tile);
            }
            rows.push_back(col);
            col.clear();
        }

        // Starts on bottom left
        robotCoords = make_pair((b-1), 0);
        moveRobot();

        for(int i=0; i<5; i++) {
            printf("%3d", amountVisited[i]);
        }

        cout << endl;
        rows.clear();
        direction = 0;
        scanf(" %d %d", &b, &w);
    }
    return 0;
}