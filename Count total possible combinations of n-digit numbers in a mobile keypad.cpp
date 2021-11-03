//Count total possible combinations of n-digit numbers in a mobile keypad
/* Given a positive number n and a mobile keypad having digits from 0 to 9 associated with each key, count the total possible combinations of digits having length n . We can start with any digit and press only four adjacent keys of any digit. The keypad also contains * and # keys, which we are not allowed to press.

Input:  n = 2
 
Output: 36
 
Explanation: Total possible combinations are 36 [00, 08, 11, 12, 14, 21, 22, 23, 25, 32, 33, 36, 41, 44, 45, 47, … ,96, 98, 99]
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int isValid(int i, int j)
{
    if (i == 3 && (j == 0 || j == 2)) {
        return 0;
    }
 
    return (i >= 0 && i <= 3 && j >= 0 && j <= 2);
}

multimap<int,int> fillmap(vector<vector<char>> &a, int m, int n) {
    multimap<int,int> mmp;
    
    int row[] = { 0, -1, 0, 1,0 };
    int col[] = { -1, 0, 1, 0,0 };
 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {            for (int k = 0; k < 5; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
 
                if (isValid(i, j) && isValid(r, c)) {
                    mmp.insert(make_pair(a[i][j] - '0', a[r][c] - '0'));
                }
            }
        }
    }
    return mmp;
}

int getAns(multimap<int,int> &mmap, unordered_map<string, int>&mp, int i, int k) {
    string temp = to_string(i) + "|" + to_string(k);
    // cout<<endl;
    // cout<<temp<<endl;
    if(mp.find(temp)==mp.end()) {
        int temp_cnt=0;
        for (auto it = mmap.find(i);
                (it != mmap.end() && it->first == i); it++) {
            temp_cnt += getAns(mmap, mp,it->second, k-1);
        }
        mp[temp]=temp_cnt;
    }
    return mp[temp];
}

int findCount(int k, vector<vector<char>> &a) {
    int m=4,n=3;
    multimap<int,int>mmap = fillmap(a,m,n);
    unordered_map<string, int>mp;
    loop(i,m) {
        loop(j,n) {
            if(i==3 && (j==0 || j==2)) continue;
            else {
                string t;
                t=a[i][j];
                string str=t+"|"+to_string(1);
                // cout<<str<<endl;
                mp[str]=1;
            }
        }
    }
    int cnt=0;
    loop(i,10) {
         cnt+=getAns(mmap,mp,i,k);
    }
    return cnt;
    
}

int main() {
    int n = 4;
 
    vector<vector<char>> keypad =
    {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' }
    };
 
    cout << findCount(n, keypad);
 
    return 0;
}