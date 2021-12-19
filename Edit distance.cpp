
//LEETCODE SOLUTION FOR EDIT DISTANCE PROBLEM

/* Question - Given two strings s1 and s2, return the minimum number of operations required to convert s1 to s2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

*/

class Solution {
public:
    #define loop(i,n) for(int i=0;i<n;i++)
    #define looper(i,s,n) for(int i=s;i<n;i++)
    
    int minDistance(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        int dp[m+1][n+1];
        loop(i,m+1) dp[i][0]=i; // deleting all
        loop(i,n+1) dp[0][i]=i; // inserting all
        looper(i,1,m+1) {
            looper(j,1,n+1) {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]; // then no operation
                else dp[i][j]=min(dp[i][j-1] ,min(dp[i-1][j], dp[i-1][j-1]))+1;
                // dp[i][j-1] (deleted one elemnet from s1, i.e. i-1 is increased to i, and then processed.) , dp[i-1][j] (inserting 1 element int s1 equal to s2[j-1] so j-1 is increased j and then processed), dp[i-1][j-1] (replace element in s1 i.e. s1[i] to make it equal to s2[j-1]).
            }
        }
        return dp[m][n];
    }
};