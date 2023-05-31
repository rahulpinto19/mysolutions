//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) 
    {
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++)
        hash[arr[i]]++;
        int ans=-1;
        int m=1000000;
        for(auto x:hash)
        {
            if( m>x.second )
            {
                m=x.second;
                ans=x.first;
            }
            else if(m==x.second)
            {
                ans=max(ans,x.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends