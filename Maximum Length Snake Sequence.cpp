//Maximum Length Snake Sequence
/* Given a square matrix, print the maximum length snake sequence in it. 
A snake sequence is defined as a sequence of numbers where each new number, 
which can only be located to the right or down of the current number, is 
either plus or minus one. */

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
#define vector2d(a) vector<vector<int>>a
#define vect2d(a,m,n,init) vector<vector<int>>a(n,vector<int>(m,init));
using namespace std;

// function for length of longest path (no. of cells in the path)
int fmaxx(vector<vector<int>>&a) {
    int m=a.size(),l,r;
    int n=a[0].size();
    vect2d(dp,m,n,1);
    looper(i,1,n) if(a[0][i]==a[0][i-1]+1 || a[0][i]==a[0][i-1]-1) dp[0][i]+=dp[0][i-1]; // first column
    looper(i,1,m) if(a[i][0]==a[i-1][0]+1 || a[i][0]==a[i-1][0]-1) dp[i][0]+=dp[i-1][0]; //first row
    looper(i,1,m) {
        looper(j,1,n) {
            l=0;
            r=0;
            if(a[i][j]==a[i-1][j]+1 || a[i][j]==a[i-1][j]-1) l = dp[i][j]+dp[i-1][j]; //from top
            if(a[i][j]==a[i][j-1]+1 || a[i][j]==a[i][j-1]-1) r = dp[i][j]+dp[i][j-1]; //from left
            dp[i][j]=max(l,r);
        }
    }
    int ans=0;
    loop(i,m) {
        loop(j,n) {
            ans=max(ans,dp[i][j]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid =
    {
        { 7, 5, 2, 3, 1 },
        { 3, 4, 1, 4, 4 },
        { 1, 5, 6, 7, 8 },
        { 3, 4, 5, 8, 9 },
        { 3, 2, 2, 7, 6 }
    };
 
    cout<<fmaxx(grid)<<endl;
 
    return 0;
}