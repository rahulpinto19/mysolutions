//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        unordered_map<int,vector<int>>g;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(graph[i][j] || i==j)
                g[i].push_back(j);
            }
        }
        vector<vector<int>>ans(N,vector<int>(N,0));
        for(auto x:g)
        {
            vector<int>vis(N,0);
            queue<int>q;
            q.push(x.first);
            while(!q.empty())
            {
                int size = q.size();
                while(size--)
                {
                    int val = q.front();
                    q.pop();
                    if(vis[val]!=1)
                    for(auto k:g[val])
                    {
                        q.push(k);
                        // cout<<x.first<<" "<<k<<endl;
                        ans[x.first][k]=1;
                    }
                    vis[val]=1;
                }
            }
        }
        // for(int i=0;i<N;i++)
        // ans[i][i]=1;
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
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends