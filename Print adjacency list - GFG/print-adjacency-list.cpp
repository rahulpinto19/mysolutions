//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) 
    {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans;
        for(auto x:edges)
        {
            mp[x.first].push_back(x.second);
            mp[x.second].push_back(x.first);
        }
        for(int i=0;i<V;i++)
        {
            int size = mp[i].size();
            auto k = mp[i];
            int j=0;
            vector<int>temp;
            while(size--)
            {
                temp.push_back(k[j++]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends