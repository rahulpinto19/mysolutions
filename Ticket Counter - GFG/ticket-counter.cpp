//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) 
    {
        deque<int> q;
        for(int i=1;i<=N;i++)
        {
            q.push_back(i);
        }
        int sel=0;
        int ans=0,z;
        while(!q.empty())
        {
            if(!(sel%2))
            {
                z=K;
                while(!q.empty() && z)
                {
                    ans=q.front();
                    q.pop_front();
                    z--;
                }
            }
            else
            {
                z=K;
                while(!q.empty() && z)
                {
                    ans=q.back();
                    q.pop_back();
                    z--;
                }
            }
            sel++;
        }
        return ans;
        }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends