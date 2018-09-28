#include<stdio.h>
#include<algorithm>

using namespace std;

int field[111][111];

int save_stack[111];
int top=0;

int m, n, k;

int dfs(int x,int y) {
	if(field[x][y]==-1) return 0;
	if(field[x][y]) return 0;

	field[x][y] = 1;

	int sum = 1;
	if(x-1>=0) {
		sum+=dfs(x-1,y);
	}
	if(x+1<n) {
		sum+=dfs(x+1,y);	
	}
	if(y-1>=0) {
		sum+=dfs(x, y-1);
	}
	if(y+1<m) {
		sum+=dfs(x, y+1);
	}

	field[x][y]=sum;
	return sum;
}

int main(void) {
	scanf("%d %d %d", &m, &n, &k);

	for(int i=0; i<k; i++) {
		int left_x, left_y, right_x, right_y;
		scanf("%d %d %d %d", &left_x, &left_y, &right_x, &right_y);

		for(int x=left_x; x<right_x; x++) {
			for(int y=left_y; y<right_y; y++) {
				field[x][y]=-1; // -1 means blocked
			}
		}
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			int res = dfs(j, i);

			if(res)save_stack[top++] = res;
		}
	}

	printf("%d\n", top);
	sort(save_stack,save_stack+top);
	for(int i=0; i<top; i++) {
		printf("%d ", save_stack[i]);
	}

	return 0;
}
