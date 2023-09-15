//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    typedef pair<int,int>p;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // pair<int,int>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        vector<bool>inmst(V,0);
        int sum=0;
        while(!pq.empty())
        {
            auto p =pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;
            if(inmst[node]==true) continue;
            inmst[node]=true;
            sum+=wt;
            for(auto &temp :adj[node])
            {
                int neighbour = temp[0];
                int weight = temp[1];
                if(inmst[neighbour]==false)
                {
                    pq.push({weight,neighbour});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends