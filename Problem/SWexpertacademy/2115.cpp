#include<stdio.h>

int dfs(int idx, int filter_size,int bottle_size, int sum, int max, int bottle[]){
	if((idx==filter_size) || (sum>bottle_size)) return max;

	int square=bottle[idx]*bottle[idx];
	int res=max,temp;

	temp=dfs(idx+1,filter_size,bottle_size,sum+bottle[idx],max+square,bottle);
	if(res<temp) res = temp;
	temp=dfs(idx+1,filter_size,bottle_size,sum,max,bottle);
	if(res<temp) res = temp;
	
	return res;
}

int findExpensive(int filter_size,int bottle_size, int y_idx, int x_idx,int beehive[][15]){
	int bottle[6];
	int max = 0;

	// Copy the data
	for(int i=0;i<filter_size;i++){
		bottle[i] = beehive[y_idx][x_idx+i];
	}
	
	max = dfs(0,filter_size,bottle_size,0,0,bottle);

	return max;
}

void convolution(int total_size,int filter_size,int bottle_size,int beehive[][15], int result[][15]){
	for(int i=0;i<total_size;i++){
		for(int j=0;j<total_size-filter_size+1;j++){
			// Find maximum
			result[i][j]=findExpensive(filter_size,bottle_size,i,j,beehive);
		}
	}
}

int getMaximumEffort(int total_size, int filter_size,int res_conv[][15]){
	// TODO: Restart

	int res=0;
	int max_first=0,max_second=0;

	for(int i=0;i<total_size;i++){
		for(int j=0;j<total_size-filter_size+1;j++){
			if(max_first<res_conv[i][j]){
				max_second=max_first;
				max_first=res_conv[i][j];
			}
		}
	}

	res = max_first+max_second;

	return res;
}

int main(void){
	int t,cnt=0;

	scanf("%d",&t);

	while(cnt<t){
		int n,m,c;
		int beehive[15][15];
		int result[15][15];

		scanf("%d %d %d",&n,&m,&c);

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&beehive[i][j]);
			}
		}

		int res;
		
		// Make a convolution arr with filter
		convolution(n,m,c,beehive,result);
		res = getMaximumEffort(n,m,result);

		cnt++;
		printf("#%d %d",cnt,res);
	}

	return 0;
}
