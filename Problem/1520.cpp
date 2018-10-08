#include<stdio.h>

int field[555][555];
int xNextGo[4]={1,0,-1,0};
int yNextGo[4]={0,1,0,-1};
int dp[555][555];

int m,n;

int goDownHill(int x,int y){
	if(x==n && y==m) return 1;
	else if(dp[y][x]!=-1) return dp[y][x];	//visited
	int nowHeight = field[y][x];
	dp[y][x]=0; // check visit

	for(int i=0;i<4;i++){
		int xNext = x+xNextGo[i];
		int yNext = y+yNextGo[i]; 
		int nextHeight = field[yNext][xNext];
		if(nextHeight<nowHeight
			&& xNext>0 && xNext<=n
			&& yNext>0 && yNext<=m){
			dp[y][x] += goDownHill(xNext,yNext);			
		}
	}
	return dp[y][x];
}

int main(void){
	scanf("%d %d",&m,&n);

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&field[i][j]);
			dp[i][j]=-1; // Initialize
		}
	}

	int answer = goDownHill(1,1);	
	printf("%d",answer);
	
	return 0;
}
