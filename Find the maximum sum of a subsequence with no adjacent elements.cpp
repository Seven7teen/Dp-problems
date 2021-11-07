//Find the maximum sum of a subsequence with no adjacent elements
/*Input:  { 1, 2, 9, 4, 5, 0, 4, 11, 6 }
Output: The maximum sum is 26
 
The maximum sum is formed by subsequence { 1, 9, 5, 11 } */


//VARIATION OF LONGEST INCREASING SUBSEQUENCE
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int lisA(vector<int>&a, int n) {
    int dp[n];
    dp[0]=a[0];
    looper(i,1,n) {
        dp[i]=a[i];
        for(int j=0;j<i-1;j++) {
            dp[i]=max(dp[j]+a[i], dp[i]);
        }
    }
    int ans = INT_MIN;
    loop(i,n) ans = max(dp[i],ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 20, 3 };
    int n = nums.size();
 
    cout << "The maximum sum is " << lisA(nums, n);
 
    return 0;
}