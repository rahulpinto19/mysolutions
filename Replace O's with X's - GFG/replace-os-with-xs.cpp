//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>&mat ,int i,int j)
    {
        if(i>=mat.size() || i<0 ||j>=mat[0].size() || j<0 || mat[i][j]=='X' || mat[i][j]=='c')
        return;
        mat[i][j] ='c';
        int arr[5] ={-1,0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            int start = i+arr[k];
            int end = j+arr[k+1];
            if(start < mat.size() and start>=0 and end>=0 and end<mat[0].size() and mat[start][end]=='O')
            {
                dfs(mat,start,end);
            }
        }
      //  return ;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++)
        {
            if(mat[i][m-1]=='O')
            dfs(mat,i,m-1);
            if(mat[i][0]=='O')
            dfs(mat,i,0);
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O')
            dfs(mat,0,j);
            if( mat[n-1][j]=='O')
            dfs(mat,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<mat[i][j]<<" ";
                if(mat[i][j]=='O')
                mat[i][j]='X';
                if(mat[i][j]=='c')
                mat[i][j]='O';
            }
            // cout<<endl;
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends