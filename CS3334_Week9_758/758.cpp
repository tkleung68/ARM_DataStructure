
#include <iostream>
using namespace std;

void bucketsort(int fab[], int n, int d) {
	int total[16] = { 0 };
	int *c;
	c = new int[n];
	int last,i;

	for (i = 0; i < n; i++)
		++total[(fab[i] >> d) & 15];

	for (i = last = 0; i < 16; i++) {
		last += total[i];
		total[i] = last - total[i];
	}

	for (i = 0; i < n; i++) 
		c[total[(fab[i] >> d) & 15]++] = fab[i];
	
	for ( i = 0; i < n; i++)
		fab[i] = c[i];

	delete[] c;
}

void radixsort(int fab[], int n, int d) {
	bucketsort(fab, n, 0);
	for (int i = 4; (d>>i) != d; i+=4)
		bucketsort(fab, n, i);
}

int main() {
	ios_base::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, q, count = 0;;
		int  *fab;
		cin >> n >> q;
		fab = new int[n];
		fab[0] = fab[1] = 1;

		for (int i = 2; i < n; i++) {
			fab[i] = (fab[i - 2] + fab[i - 1]) % q;
			if (fab[i] > count)
				count = fab[i];
		}
	
		radixsort(fab, n, count);
		long long int total = 0;
		for (int i = 0; i < n; i++) 
			total += ((long long int)fab[i] * (i + 1))%q;

		printf("%lld\n", total%q);
		delete[] fab;
	}
	return 0;
}

