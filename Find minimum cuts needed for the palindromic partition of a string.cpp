//Find minimum cuts needed for the palindromic partition of a string

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

bool isPalin(string s) {  // Palindrome check function
    int n=s.size();
    loop(i,n/2) {
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}

int mcuts(string a,unordered_map<string,int>&mp) { // map stores a string as key and minimum no. of cuts required for it to be a palindrome.
    if(mp.find(a)!=mp.end()) return mp[a];
    if(isPalin(a)) return mp[a] = 0;
    int ans=INT_MAX;
    for(int i=1;i<a.size();i++) {
        ans=min(ans,1+mcuts(a.substr(0,i),mp)+mcuts(a.substr(i),mp));
    }
    return mp[a] = ans;
}

int main()
{
    string X = "BABABCBADCEDE";    
    int n=X.size(); // BAB|ABCBA|DCD
    unordered_map<string,int>mp;
    cout << "The minimum cuts required are " << mcuts(X,mp);
 
    return 0;
}