#include <bits/stdc++.h>

const int MAX=1e5+1;

using namespace std;

int pai[MAX], rk[MAX]={0}, resposta;


int acha(int a)
{
	if (pai[a]==a)
		return a;

	int t = a;

	while (pai[t]!=t)
		t = pai[t];

	while (pai[a]!=a)
	{
		int c = pai[a];
		pai[a] = t;
		a = c;
	}

	return t;
}


void une (int a, int b)
{
	a = acha(a);
	b = acha(b);

    if(a == b) return;

    // Lowers answer because A and B are of same religion
    resposta--;

	if (rk[a] > rk[b])
	{
		pai[b] = a;
	}
	else if (rk[a] < rk[b])
	{
		pai[a] = b;
	}
	else
	{
		pai[a] = b;
		rk[b]++;
	}

}

int main()
{
	int m, n, caseN = 1;

	vector<int> v;

	scanf("%d %d", &n, &m);

    while(n != 0 || m != 0) {

        for (int i=0; i<=n; i++)
        {
            pai[i] = i;
        }
        
        resposta = n;

        for (int i=0; i<m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            une(a, b);
        }

        cout << "Case " << caseN << ": " << resposta << endl;
        caseN++;
        scanf("%d %d", &n, &m);
    }
	return 0;
}