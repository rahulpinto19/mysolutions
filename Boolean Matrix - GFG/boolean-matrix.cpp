//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void help(queue<pair<int,int>>&q,vector<vector<int>>&mat,vector<int>&row,vector<int>&col)    
    {
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(col[j]==-1)
            for(int k=0;k<mat.size();k++)
            {
                mat[k][j]=1;
            }
            col[j]=1;
            if(row[i]==-1)
            for(int k=0;k<mat[0].size();k++)
            {
                mat[i][k]=1;
            }
            row[i]=1;
        }
    }
    void booleanMatrix(vector<vector<int> > &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        
        vector<int>row(m,-1);
        vector<int>col(n,-1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                q.push({i,j});
            }
        }
        help(q,mat,row,col);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends