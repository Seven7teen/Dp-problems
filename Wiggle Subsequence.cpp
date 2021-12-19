
//LEETCODE SOLUTION FOR WIGGLE SUBSEQUENCE  

/* Question - A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

*/



//Solution 1 : 
//Using 2d DP with O(2n) space and O(2*n*n) time complexity

class Solution {
public:
    int wiggleMaxLength(vector<int>&v) {
        int n=v.size(),f;
        vector<vector<int>>dp(2,vector<int>(n)); // Use modification of LIS for 2 linear vectors
        dp[0][0]=1;
        dp[1][0]=1;
        for(int i=1;i<n;i++) {
            dp[0][i]=1; //1st row stores count of the longest wiggle subsequence with last element as increased element
            dp[1][i]=1; //2nd row stores count of the longest wiggle subsequence with last element as decreased element
            //filling first row, using previous values of 2nd row to fill 1st row values (LIS modification)
            f=0;
            for(int j=0;j<i;j++) {
                if(v[i]>v[j] && dp[0][i]<dp[1][j]+1) {
                    f=1;
                    dp[0][i] = dp[1][j]+1; //
                }
            }
            if(f==0) dp[0][i] = max(dp[0][i],dp[0][i-1]);
            //filling second row, using previous values of 1st row to fill 2nd row values (LIS modification)
            f=0;
            for(int j=0;j<i;j++) {
                if(v[i]<v[j] && dp[1][i]<dp[0][j]+1) {
                    f=1;
                    dp[1][i] = dp[0][j]+1;
                }
            }
            if(f==0) dp[1][i] = max(dp[1][i],dp[1][i-1]); 
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};


//Solution 2:
// tracking change in sign of the difference between elements and traversing with O(n) time and O(1) space.
class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int ans = 1, prev=0,d; // here final answer stored in ans, prev is the previous difference, d stores current difference
        for (int i = 1; i < v.size(); ++i) {
            int d = v[i] - v[i-1]; 
            if (d != 0) {
                if (prev * d <= 0) ++ans; // here it checks the change in sign of the difference
                prev = d; 
            }
        }
        return ans; 
    }
};