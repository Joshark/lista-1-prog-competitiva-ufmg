#include <bits/stdc++.h>

using namespace std;

char board[9][9];
bool check = false;
pair<int, int> blackKing;
pair<int, int> whiteKing;

void checkRook(char r, pair<int, int> pos) {
	int x;
	int y;

	y = pos.second;

	for(int dx = -1; dx <= 1; dx+=2) {
		x = pos.first;

		for(int i = 0; i < 8; i++) {
			if(x+dx < 0 || x+dx > 8)
				break;

			x += dx;

			if(r=='r' && board[x][y] != '.' && board[x][y] != 'K') break;
			if(r=='R' && board[x][y] != '.' && board[x][y] != 'k') break;

			if(r == 'r' && x == whiteKing.first && y == whiteKing.second) {
				cout << "white king is in check." << endl;
				check = true;
				return;
			}

			if(r == 'R' && x == blackKing.first && y == blackKing.second) {
				cout << "black king is in check." << endl;
				check = true;
				return;
			}
		}
	}

	x = pos.first;

	for (int dy = -1; dy <= 1; dy+=2) {
		y = pos.second;

		for(int i = 0; i < 8; i++) {
			if(y+dy < 0 || y+dy > 8)
				break;

			y += dy;

			if(board[x][y] != '.' && board[x][y] != 'k' && board[x][y] != 'K') break;

			if(r == 'r' && x == whiteKing.first && y == whiteKing.second) {
				cout << "white king is in check." << endl;
				check = true;
				return;
			}

			if(r == 'R' && x == blackKing.first && y == blackKing.second) {
				cout << "black king is in check." << endl;
				check = true;
				return;
			}
		}
	}
}

void checkBishop(char b, pair<int, int> pos) {
	int x = pos.first;
	int y = pos.second;


	for(int dx = -1; dx <= 1; dx+=2)
		for(int dy = -1; dy <= 1; dy+=2) {
			x = pos.first;
			y = pos.second;

			for(int i=0; i<8; i++) {
				if(x+dx < 0 || x+dx > 8 || y+dy < 0 || y+dy > 8)
					break;

				x += dx;
				y += dy;

				if(b == 'b' && board[x][y] != '.' && board[x][y] != 'K') break;
				if(b == 'B' && board[x][y] != '.' && board[x][y] != 'k') break;

				if(b == 'b' && x == whiteKing.first && y == whiteKing.second) {
					cout << "white king is in check." << endl;
					check = true;
					return;
				}

				if(b == 'B' && x == blackKing.first && y == blackKing.second) {
					cout << "black king is in check." << endl;
					check = true;
					return;
				}
			}
		}
}

void checkQueen(char q, pair<int, int> pos) {
	int x = pos.first;
	int y = pos.second;


	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			if(dx == 0 && dy == 0) continue;

			x = pos.first;
			y = pos.second;

			for(int i=0; i<8; i++) {
				if(x+dx < 0 || x+dx > 8 || y+dy < 0 || y+dy > 8)
					break;

				x += dx;
				y += dy;

				if(q == 'q' && board[x][y] != '.' && board[x][y] != 'K') break;
				if(q == 'Q' && board[x][y] != '.' && board[x][y] != 'k') break;

				if(q == 'q' && x == whiteKing.first && y == whiteKing.second) {
					cout << "white king is in check." << endl;
					check = true;
					return;
				}

				if(q == 'Q' && x == blackKing.first && y == blackKing.second) {
					cout << "black king is in check." << endl;
					check = true;
					return;
				}
			}
		}
	}
}

void checkKnight(char k, pair<int, int> pos) {
	int x;
	int y;

	for(int dx=-2, dy=-1; dx < 0; dx++, dy--) {
		x = pos.first;
		y = pos.second;

		x += dx;
		y += dy;


		if(k == 'n' && x == whiteKing.first && y == whiteKing.second) {
			cout << "white king is in check." << endl;
			check = true;
			return;
		}

		if(k == 'N' && x == blackKing.first && y == blackKing.second) {
			cout << "black king is in check." << endl;
			check = true;
			return;
		}

		x = pos.first;
		y = pos.second;

		x += dx;
		y -= dy;

		if(k == 'n' && x == whiteKing.first && y == whiteKing.second) {
			cout << "white king is in check." << endl;
			check = true;
			return;
		}

		if(k == 'N' && x == blackKing.first && y == blackKing.second) {
			cout << "black king is in check." << endl;
			check = true;
			return;
		}

		x = pos.first;
		y = pos.second;

		x -= dx;
		y -= dy;

		if(k == 'n' && x == whiteKing.first && y == whiteKing.second) {
			cout << "white king is in check." << endl;
			check = true;
			return;
		}

		if(k == 'N' && x == blackKing.first && y == blackKing.second) {
			cout << "black king is in check." << endl;
			check = true;
			return;
		}

		x = pos.first;
		y = pos.second;

		x -= dx;
		y += dy;

		if(k == 'n' && x == whiteKing.first && y == whiteKing.second) {
			cout << "white king is in check." << endl;
			check = true;
			return;
		}

		if(k == 'N' && x == blackKing.first && y == blackKing.second) {
			cout << "black king is in check." << endl;
			check = true;
			return;
		}
	}
}

void checkPawn(pair<int, int> pos, int d) {
	int x = pos.first;
	int y = pos.second;

	if(d == 1 && (x+d == whiteKing.first && y+1 == whiteKing.second || x+d == whiteKing.first && y-1 == whiteKing.second)) {
		cout << "white king is in check." << endl;
		check = true;
		return;
	}

	if(d == -1 && (x+d == blackKing.first && y+1 == blackKing.second || x+d == blackKing.first && y-1 == blackKing.second)) {
		cout << "black king is in check." << endl;
		check = true;
		return;
	}
}

void checkPiece(char piece, pair<int, int> coords) {
	switch(piece) {
		case 'p':
			checkPawn(coords, 1);
			break;
		case 'P':
			checkPawn(coords, -1);
			break;
		case 'r':
		case 'R':
			checkRook(piece, coords);
			break;
		case 'b':
		case 'B':
			checkBishop(piece, coords);
			break;
		case 'n':
		case 'N':
			checkKnight(piece, coords);
			break;
		case 'q':
		case 'Q':
			checkQueen(piece, coords);
			break;
	}
}

int main() {
	int gameN = 1;
	bool playing = true;

	do {
		playing = false;

		for(int i=0; i<8; i++) {
			for(int j=0; j<8; j++) {
				scanf(" %c", &board[i][j]);

				if(board[i][j] != '.') playing = true;

				if(board[i][j] == 'k')
					blackKing = make_pair(i, j);
				else if(board[i][j] == 'K')
					whiteKing = make_pair(i, j);
			}
		}

		if(!playing) break;

		cout << "Game #" << gameN << ": ";
		for(int i=0; i<8; i++) {
			for(int j=0; j<8; j++) {
				if(board[i][j] != '.') {
					checkPiece(board[i][j], make_pair(i, j));
				}

				if(check) break;
			}

			if(check) break;
		}

		if(!check) cout << "no king is in check." << endl;

		blackKing = make_pair(-9,-9);
		whiteKing = make_pair(-9,-9);

		check = false;
		gameN++;
	} while(playing);

	return 0;
}