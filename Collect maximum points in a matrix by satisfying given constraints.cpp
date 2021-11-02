//Collect maximum points in a matrix by satisfying given constraints


#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int fm(vector<vector<int>>&a,int m,int n) {
    vector<vector<int>>dp(m,vector<int>(n));
    if(a[0][0]==-1) return 0;
    else dp[0][0]=a[0][0];
    for(int i=0,j=1;j<n;j++) {
        if(a[i][j]==-1) break;
        else dp[i][j]=dp[i][j-1]+a[i][j];
    }
    for(int i=1;i<m;i++) {
        if(i%2==0) {
            if(a[i][0]==-1) dp[i][0]=0;
            else dp[i][0]=a[i][0]+dp[i-1][0];
            for(int j=1;j<n;j++) {
                if(a[i][j]!=-1) 
                dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        else {
            if(a[i][n-1]==-1) dp[i][n-1]=0;
            else dp[i][n-1]=a[i][n-1]+dp[i-1][n-1];
            for(int j=n-2;j>=0;j--) {
                if(a[i][j]!=-1) 
                dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i][j+1]);
            }
        }
    }
    int ans = INT_MIN;
    loop(i,m) {
        loop(j,n) {
            cout<<dp[i][j]<<" ";
            ans = max(ans,dp[i][j]);
        }
        cout<<endl;
    }
    return ans;
}


int main()
{
    vector<vector<int>> mat =
    {
        { 1, 1, -1, 1, 1 },
        { 1, 0, 0, -1, 1 },
        { 1, 1, 1, 1, -1 },
        { -1, -1, 1, 1, 1 },
        { 1, 1, -1, -1, 1 }
    };
    int m=mat.size(),n=mat[0].size();
    cout <<fm(mat, m,n);
 
    return 0;
}
