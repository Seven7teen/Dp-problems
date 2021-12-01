//Pots of Gold Game Problem using Dynamic Programming

/* There are two players, A and B, in Pots of gold game, and pots of gold arranged in a line, each containing some gold coins. 
The players can see how many coins are there in each gold pot, and each player gets alternating turns in which the player can
pick a pot from either end of the line. The winner is the player who has a higher number of coins at the end. The objective is
to “maximize” the number of coins collected by A, assuming B also plays “optimally”, and A starts the game. */

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int mcoin(int a[], int i, int j, vector<vector<int>>&t, bool flag) {
    if(flag==0) { // for player flag=0
        if(i==j) return t[i][j] = a[i];
        if(t[i][j] != -1) return t[i][j];
        if(i+1==j) return t[i][j] = max(a[i],a[j]);
        return t[i][j] = max(a[i]+mcoin(a,i+1,j,t, !flag), a[j]+mcoin(a,i,j-1,t,!flag));
    }
    else { // after the opponent turn ( what will be returned to player's points)
        if(i==j) return 0;
        if(t[i][j] != -1) return t[i][j];
        return t[i][j] = min(mcoin(a,i+1,j,t, !flag), mcoin(a,i,j-1,t,!flag)); 
        // because opponent will take the max of these two.. so player
        //will get the min one, which is being added in the if statments.
    }
}

int main()
{   int n;
    cin>>n;

    // pots of gold arranged in a line
    int coin[n];
    loop(i,n) cin>>coin[i];
    // total number of pots (`n` is even)
    vector<vector<int>>t(n+1,vector<int>(n+1,-1));
    cout << "The Maximum coins collected by player is "
         << mcoin(coin, 0, n - 1,t,0);
    // cout<<endl;
    // loop(i,n+1) {
    //     loop(j,n+1) cout<<t[i][j]<<" ";
    //     cout<<endl;
    // }
 
    return 0;
}






