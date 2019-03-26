#include <bits/stdc++.h>

using namespace std;

char board[8][8];
char curPlayer;
char play;
vector<pair<int, int> > legalMoves;

void checkMoves(int x, int y) {
	char opponent = curPlayer == 'W' ? 'B' : 'W';
	bool foundOpponent;

	for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {

      if(dx == 0 && dy == 0) continue;

			foundOpponent = false;

      for(int i=1; i < 8; i++) {
        int cordXCheck = x + i * (dx);
        int cordYCheck = y + i * (dy);
        if(cordXCheck < 0 || cordXCheck > 7 || cordYCheck < 0 || cordYCheck > 7)
        	break;

        if(board[cordXCheck][cordYCheck] == curPlayer)
        	break;

        if(board[cordXCheck][cordYCheck] == '-') {
					if(!foundOpponent) break;
					auto possibleMove = make_pair(cordXCheck + 1, cordYCheck + 1);

					if(find(legalMoves.begin(), legalMoves.end(), possibleMove) != legalMoves.end())
						break;

        	legalMoves.push_back(possibleMove);
					break;
				}

        if(board[cordXCheck][cordYCheck] == opponent) {
					foundOpponent = true;
        	continue;
        }

      }
    }
  }
}

void checkBoard() {
	for(int i=0; i<8; ++i) {
		for(int j=0; j<8; ++j) {
			if(board[i][j] != curPlayer) 
				continue;

			checkMoves(i, j);
		}
	}
}

bool compare(const pair<int, int> &i, const pair<int, int> &j) {
	 	if(i.first == j.first) return i.second < j.second;
    return i.first < j.first;
}

void printMoves() {
	checkBoard();

	sort(legalMoves.begin(), legalMoves.end(), compare);
	
	if(legalMoves.size() > 0)
		for(int i=0; i<legalMoves.size(); i++) {
			cout << "(" << legalMoves[i].first << "," << legalMoves[i].second << ")";
			if(i < legalMoves.size() - 1)
			cout << " ";
		}
	else cout << "No legal move.";

	cout << endl;
}

void fillBoard(int stopX, int stopY, int x, int y, int dx, int dy) {
	for(int i=1; i<8; ++i) {
		x += dx;
		y += dy;
		board[x][y] = curPlayer == 'W' ? 'W' : 'B';

		if(x == stopX && y == stopY) return;
	}
}

void makeMove(int x, int y) {
	legalMoves.clear();
	checkBoard();

	if(legalMoves.size() == 0)
		curPlayer = curPlayer == 'W' ? 'B' : 'W';

	char opponent = curPlayer == 'W' ? 'B' : 'W';
	bool foundOpponent;
	bool filled = false;
	for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {

      if(dx == 0 && dy == 0) continue;
			foundOpponent = false;
			filled = false;

      for(int i=1; i < 8; i++) {
        int cordXCheck = x + i * (dx);
        int cordYCheck = y + i * (dy);

        if(cordXCheck < 0 || cordXCheck > 7 || cordYCheck < 0 || cordYCheck > 7)
        	break;

				if(board[cordXCheck][cordYCheck] == '-') break;

        if(board[cordXCheck][cordYCheck] == opponent) {
					foundOpponent = true;
        	continue;
        }

        if(board[cordXCheck][cordYCheck] == curPlayer) {
					if(foundOpponent) {
						fillBoard(x, y, cordXCheck, cordYCheck, -dx, -dy);
						filled = true;
						break;
					} else 
						break;
				}
      }
    }
  }

	if(!filled && board[x][y] == '-') board[x][y] = curPlayer;
}

void countPieces() {
	int whiteCounter = 0, blackCounter = 0;
	for(int i=0; i<8; ++i) {
		for(int j=0; j<8; ++j) {
			if(board[i][j] == 'B') blackCounter++;
			else if(board[i][j] == 'W') whiteCounter++;
		}
	}
	if(blackCounter >= 10) cout << "Black - ";
	else cout << "Black -  ";

	cout << blackCounter;

	if(whiteCounter >= 10) cout << " White - ";
	else cout << " White -  ";

	cout << whiteCounter << endl;
}

int main() {
	int nGames;
	int move;
	bool firstLoop = false;
	scanf(" %d", &nGames);

	while(nGames--) {
		for(int i=0; i<8; ++i) {
			for(int j=0; j<8; ++j) {
				scanf(" %c", &board[i][j]);
			}
		}

		scanf(" %c %c", &curPlayer, &play);

		while(play != 'Q') {
			switch(play) {
				case 'L':
					printMoves();
					break;
				case 'M':
					scanf(" %d", &move);
					int x = (move/10) - 1;
					int y = (move%10) - 1;
					makeMove(x, y);
					countPieces();
					curPlayer = curPlayer == 'W' ? 'B' : 'W';
					break;
			}
			legalMoves.clear();
			scanf(" %c", &play);
		}

		for(int i=0; i<8; ++i) {
			for(int j=0; j<8; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}

		if(nGames) cout << endl;
	}

	return 0;
}