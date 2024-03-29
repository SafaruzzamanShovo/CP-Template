#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int val[N], wt[N];
int dp[N][N];



int knapsack(int n, int w){

    if( w <= 0) return 0;
    if( n <= 0 ) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if (wt[n-1] > w) dp[n][w] = knapsack(n-1, w);
    else dp[n][w] = max(knapsack(n-1, w), knapsack(n-1, w-wt[n-1])+val[n-1]);
    return dp[n][w];

}


int main(){
    memset(dp,-1,sizeof(dp));
    int n, w; cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];

    cout << knapsack(n, w);

}
