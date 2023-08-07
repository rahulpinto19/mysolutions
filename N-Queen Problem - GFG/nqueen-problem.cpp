//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    bool issafe(vector<vector<int>>&board,int x,int y)
    {
        for(int i=0;i<x;i++)
        {
            if(board[i][y])
            return 0;
        }
        int i=x,j=y;
        while(i>=0 and j>=0)
        {
            if(board[i][j])
            return 0;
            i--;j--;
        }
        i=x;j=y;
        while(i>=0 and j<board.size())
        {
            if(board[i][j])
            return 0;
            i--;j++;
        }
        return 1;
    }
    void help(vector<vector<int>>&board,vector<int>&set,int x,int y)
    {
        if(x>=board.size())
        {
            ans.push_back(set);
        return;}
        for(int i=0;i<board.size();i++)
        {
            if(issafe(board,x,i))
            {
                board[x][i]=1;
                set.push_back(i+1);
                help(board,set,x+1,i);
                set.pop_back();
                board[x][i]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>set;
        help(board,set,0,0);    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends