//Maximum Sum Subarray Problem (Kadane’s Algorithm)

/* Input:  {-2, 1, -3, 4, -1, 2, 1, -5, 4}
 
Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6. */

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

int kadane(int a[], int n) {
    int sofar=INT_MIN,ending=0;
    for(int i=0;i<n;i++) {
        ending+=a[i];
        if(ending<a[i]) ending=a[i]; 
        if(sofar<ending) sofar=ending;
    }
    return sofar;
}

int main()
{
    int arr[] = {  -8, -3, -6, -2, -5, -4 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "The maximum sum of a contiguous subarray is " <<
            kadane(arr, n);
 
    return 0;
}
 