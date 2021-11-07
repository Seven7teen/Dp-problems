//Calculate the sum of all elements in a submatrix in constant time

/* Given an MxN integer matrix and two coordinates (p, q) and (r, s) 
representing top-left and bottom-right coordinates of a submatrix of it, 
calculate the sum of all elements present in the submatrix. 
Here, 0 <= p< r < M and 0 <= q < s < N. */

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;


//function for querying
int msum(vector<vector<int>>&dp, int p, int q, int r, int s) {
    int ans=0;
    ans+= dp[r][s];
    if(p!=0) ans-=dp[p-1][s];
    if(q!=0) ans-=dp[r][q-1];
    if(p!=0 && q!=0) ans+=dp[p-1][q-1];
    return ans;
}

vector<vector<int>> createDP(vector<vector<int>>&a) {
    int m=a.size();
    int n=a[0].size(),sum;
    vector<vector<int>>dp(m,vector<int>(n));
    dp[0][0]=a[0][0];
    int temp=a[0][0];

    //First row
    looper(i,1,n) {
        temp+=a[0][i];
        dp[0][i]=temp;
    }

    //First column
    temp=a[0][0];
    looper(i,1,m) {
        temp+=a[i][0];
        dp[i][0]=temp;
    }

    // Other cells
    looper(i,1,m) {
        looper(j,1,n) {
            dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    return dp;
}

int main()
{
    vector<vector<int>> mat =
    {
        { 0, 2, 5, 4, 1 },
        { 4, 8, 2, 3, 7 },
        { 6, 3, 4, 6, 2 },
        { 7, 3, 1, 8, 3 },
        { 1, 5, 7, 9, 4 }
    };
    int m=mat.size();
    int n=mat[0].size();
 
    // (p, q) and (r, s) represent top-left and bottom-right coordinates of the submatrix
    int p , q , r , s ;
    cin>>p>>q>>r>>s;
 
    // calculate the submatrix sum
    vector<vector<int>>dp = createDP(mat);
    loop(i,m) {
        loop(j,n) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout << msum(dp, p, q, r, s)<<endl;
 
    return 0;
}


