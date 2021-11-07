//Find the probability that a person is alive after taking `n` steps on an island.

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

//Assumes all steps carry 0.25 probability

double pb(int N, int x, int y, int n, map<string,double>&dp) {
    if(n==0) return 1.0;
    string temp = to_string(x) + "|" + to_string(y) + "|" + to_string(n); //key
    if(dp.find(temp)==dp.end()) {
        double p=0.0;
        if(x>0) p+=0.25*pb(N, x-1, y, n-1, dp);
        if(y>0) p+=0.25*pb(N, x, y-1, n-1, dp);
        if(x<N-1) p+=0.25*pb(N, x+1, y, n-1, dp);
        if(y<N-1) p+=0.25*pb(N, x, y+1, n-1, dp);
        dp[temp]=p;
    }
    return dp[temp];
}

int main()
{
    int N,n,x,y;
    cin>>N>>n>>x>>y;   // `N × N` island, total number of steps to be taken, starting coordinates
 
    map<string, double> dp;
    cout << "The alive probability is " << pb(N, x, y, n, dp);
 
    return 0;
}


