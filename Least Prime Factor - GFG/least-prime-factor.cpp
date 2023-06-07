//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int set(int a)
    {
        int k=2;
        if(a>3)
        {
            while(k<=a)
            {
                if(a%k==0)
                return k;
                k++;
            }
        }
        return a;
    }
    vector<int> leastPrimeFactor(int n) 
    {
        if(n==0)
        return {};
        vector<int>ans;
        int k=0;
        while(k<=n)
        {
          //  cout<<k;
            ans.push_back(set(k));
            k++;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends