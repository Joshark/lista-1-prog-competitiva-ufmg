#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int toMove = 0;
	int tileX = 1;
	int tileY = 1;

	scanf(" %d", &n);

	while(n != 0) {
		m = ceil(sqrt(n));

		if(m % 2 == 0) {
			tileX = m;
			tileY = 1;
			toMove = m*m - n;

			if(toMove >= m) {
				tileY = m;
				toMove -= (m-1);
				tileX -= toMove;
			}
			else
				tileY += toMove;	
		}
		else {
			tileY = m;
			tileX = 1;

			toMove = m*m - n;

			if(toMove >= m) {
				tileX = m;
				toMove -= (m-1);
				tileY -= toMove;
			}
			else
				tileX += toMove;
			
		}

		cout << tileX << " " << tileY << endl;

		scanf(" %d", &n);
	}

	return 0;
}