//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool help(vector<vector<char>>&board,string &word,int pos ,int x,int y)
    {
        if(pos>=word.size())
        return 1;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || word[pos]!=board[x][y])
        return 0;
        char ch = board[x][y];
        board[x][y]='#';
        bool a = help(board,word,pos+1,x+1,y);
        bool b = help(board,word,pos+1,x-1,y);
        bool c = help(board,word,pos+1,x,y+1);
        bool d = help(board,word,pos+1,x,y-1);
        board[x][y]=ch;
        return a || b||c||d;
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j])
                if(help(board,word,0,i,j))
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends