#include<stdio.h>

int fibodp[50][2];

void fibocheck(int n) {

	if (fibodp[n][0] || fibodp[n][1]) return;
	else {
		fibocheck(n - 1);
		fibocheck(n - 2);

		fibodp[n][0] = fibodp[n - 1][0] + fibodp[n - 2][0];
		fibodp[n][1] = fibodp[n - 1][1] + fibodp[n - 2][1];
	}

	return;
}

int main(void) {
	int t;

	fibodp[0][0] = 1;
	fibodp[1][1] = 1;
	
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		fibocheck(n);

		printf("%d %d\n", fibodp[n][0], fibodp[n][1]);
	}

	return 0;
}