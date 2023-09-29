//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void setzero(vector<vector<int>>&grid,int i,int j)
    {
        grid[i][j]=0;
        int arr[5]={-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int x = i+arr[k];  int y = j+arr[k+1];
            if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y])
            {
                setzero(grid,x,y);
            }
        }
    }
    int ans = 0;
    void count(vector<vector<int>>&grid,int i,int j,int cnt)
    {
        ans = max(ans,cnt);
        grid[i][j]=0;
        int arr[5] ={-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int x = i+arr[k];  int y = j +arr[k+1];
            if(x>=0 and y>=0 and  x<grid.size() and y<grid[0].size() and grid[x][y])
            {
                cnt++;
                count(grid,x,y,cnt);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0])
            setzero(grid,i,0);
            if(grid[i][n-1])
            setzero(grid,i,n-1);
        }
        for(int j=0;j<n;j++)
        {
            if(grid[0][j])
            setzero(grid,0,j);
            if(grid[m-1][j])
            setzero(grid,m-1,j);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends