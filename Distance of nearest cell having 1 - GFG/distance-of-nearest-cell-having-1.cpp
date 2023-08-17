//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    vector<vector<bool>>vis(mat.size(),vector<bool>(mat[0].size(),0)); 
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j])
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else
                vis[i][j]=0;
            }
        }
        int ind[5] ={-1,0,1,0,-1};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();
            mat[x][y]=step;
            for(int i=0;i<4;i++)
            {
                int newx = x+ind[i],newy = y+ind[i+1];
                if(newx>=0 and newx<mat.size() and newy>=0 and newy<mat[0].size() and !vis[newx][newy])
                {
                    vis[newx][newy]=1;
                    q.push({{newx,newy},step+1});
                }
            } 
        }
        return mat;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends