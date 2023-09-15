//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool help(int arr[],int N,int pos,int sum,int target,vector<vector<int>>&dp)
    {
        if(2*sum==target)
        return 1;
        
        if(pos>=N || sum> target/2)
        return 0;
        
        if(dp[pos][sum]!=-1)
        return dp[pos][sum];

        bool a = help(arr,N,pos+1,sum+arr[pos],target,dp);
        
        bool b = help(arr,N,pos+1,sum,target,dp);
        
        dp[pos][sum]= a||b;
        return dp[pos][sum];
        
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2)
        return 0;
        vector<vector<int>>dp(N+1,vector<int>((sum/2)+1,-1));
        bool ans = help(arr,N,0,0,sum,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends