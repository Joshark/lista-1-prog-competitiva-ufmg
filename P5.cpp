#include <bits/stdc++.h>

using namespace std;
int main() {
	int m;
	int aux;
	int n;
	int curDistrict;
	vector<int> districts(100, 0);

	scanf(" %d", &n);
	while(n != 0) {
		m = 1;
		curDistrict = 0;
		districts[curDistrict] = 1;

		for(int i=1; i < n; i++) {
			aux = m;
			while(aux > 0) {
				curDistrict++;

				if(curDistrict > (n - 1)) curDistrict = 0;

				if(districts[curDistrict] == 0) aux--;
			}

			districts[curDistrict] = 1;

			if(curDistrict == 12 && i < (n - 1)) {
				++m;
				curDistrict = 0;
				i = 0;
				fill(districts.begin(), districts.end(), 0);
				districts[curDistrict] = 1;
			}
		}

		cout << m << endl;
		fill(districts.begin(), districts.end(), 0);
		scanf(" %d", &n);
	}
	return 0;
}
// 1, 12, 6, 18, 13,