//Total possible solutions to a linear equation of `k` variables
/* Given a linear equation of k variables, count the total number of possible solutions to it.

Sample Input: 
n, no. of coefficients = 4
rhs, right hand side value of equation = 8
n coefficients = {1,3,5,7}

Sample Output:
6
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int count(int w[],int n, int W) {
    int dp[n+1][W+1];
    loop(i,W+1) dp[0][i]=0; // if array is empty then for positive value of W, there is no solution.
    loop(i,n+1) dp[i][0]=1; // for W=0, we can take 0 no. of times all coeff to get 1 solution.
    looper(i,1,n+1) {
        looper(j,1,W+1) {
            if(w[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i][j-w[i-1]]; // not included + included (with unbounded knapsack)
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{   
    int n, rhs;
    // n = number of elements in array, rhs = right hand side value of the equation
    cin>>n>>rhs;
    int coeff[n];
    loop(i,n) cin>>coeff[i];
    cout <<count(coeff,n, rhs);
 
    return 0;
}