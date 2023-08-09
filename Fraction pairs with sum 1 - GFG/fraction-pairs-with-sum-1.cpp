//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        int ans =0;
        map<pair<int,int>,int>map;
        for(int i=0;i<n;i++)
        {
            int gcd = __gcd(num[i],den[i]);
            num[i]/=gcd;
            den[i]/=gcd;
            int x = num[i];
            int y = den[i];
            
            int z = y-x;
            if(map.count({z,y}))
            ans+=map[{z,y}];
            map[{x,y}]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends