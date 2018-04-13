#include<stdio.h>
#include<vector>
 
#define max(a,b) a > b ? a : b
 
using namespace std;
 
int dfs_time(int w,vector<int> order[],int time[],int visit[]) {
	int maxtime=0;
 
	if (visit[w]) return time[w];
 
	visit[w] = 1;
 
	for (int i = 0;i<order[w].size(); i++) {
		int temp = dfs_time(order[w][i], order, time,visit);
		maxtime=max(maxtime,temp);
	}
 
	time[w] += maxtime;
 
	return time[w];
}
 
int main(void) {
	int t;
 
	scanf("%d", &t);
 
	while (t--) {
		int n, k,cons_time[1111],w;
		vector<int> order[1111];
		int first, second;
		int visit[1111] = { 0 };
 
		scanf("%d %d", &n, &k);
 
		for(int i=0;i<n;i++) scanf("%d", &cons_time[i+1]);
 
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &first, &second);
			order[second].push_back(first);
		}
 
		scanf("%d", &w);
 
		int mintime = dfs_time(w,order,cons_time,visit);
 
		printf("%d\n", mintime);
 
	}
	return 0;
}
