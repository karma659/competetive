#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    int r[20], c[20];
    int x;
    scanf("%d", &n);
    
      for(int i=0;i<n;i++){
        scanf("%d",&x);
        c[x-1]=i;
    }
    
    while(scanf("%d",&x)==1){
        r[x-1]=0;
        for(int i=1;i<n;i++){
            scanf("%d",&x);
            r[x-1]=i;
        }
        int dp[25][25] = {};
        for(int i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(r[i-1] == c[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ?
                        dp[i-1][j] : dp[i][j-1];
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}

