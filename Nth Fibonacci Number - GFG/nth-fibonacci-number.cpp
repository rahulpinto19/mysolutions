//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n)
    {
         int mod=1e9+7;
        if (n<3)
            return 1;
        int a=1,b=1,ans;
        for (int i=3; i<=n; i++){
            ans=(a+b)%mod;
            a=b;
            b=ans;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends