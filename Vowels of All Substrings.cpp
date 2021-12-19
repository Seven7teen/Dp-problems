/*Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.
A substring is a contiguous (non-empty) sequence of characters within a string.
Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations. */

//Approach 1: Using Dp (time limit exceed)

class Solution {
public:
    #define loop(i,s,n) for(int i=s;i<n;i++)
    
    bool isVowel(char a) {
        return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
    }
    
    long long countVowels(string str) {
        long long n=str.size();
        vector<vector<long long>>dp(n,vector<long long>(n));
        if(isVowel(str[0])) dp[0][0]=1;
        else dp[0][0]=0;
        loop(i,1,n) {
            if(isVowel(str[i])) {
                dp[0][i]=dp[0][i-1]+1;
                dp[i][i]=1;
            }
            else dp[0][i]=dp[0][i-1];
        }
        loop(i,1,n) {
            loop(j,i+1,n) {
                dp[i][j]=dp[i-1][j] - dp[i-1][i-1];
                
            }
        }
        long long sum=0;
        loop(i,0,n) loop(j,i,n) sum+=dp[i][j];
        return sum;
    }
};


Approach 2: (pre calculation)

class Solution {
public:
    long long countVowels(string s) {
 
        long long int i,ans=0,n=s.length();
        for(i=0;i<n;++i){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                long long int l=n-i;   // no. of substrings starting with current character
                ans+=(i*l)+(l);  /* no. of substring where the character is included but is not the starting 
                character. (no. of characters on the left of the cyrrent character * no. of substrings starting 
                with current character. Take example as xxxxxaxxx. */
            }
        }
 
        return ans;
    }
};
