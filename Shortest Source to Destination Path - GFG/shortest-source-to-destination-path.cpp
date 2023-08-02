//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//editing 
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
    {
        if(A[0][0]==0)
        return -1;
        int d[5] ={-1,0,1,0,-1};
        int cnt =0;
        queue<pair<int,int>>q;
        q.push({0,0});
        A[0][0]=0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int f =q.front().first;
                int s = q.front().second;
                q.pop();
                if(f==X and s==Y)
                return cnt;
               for(int i =0;i<4;i++)
               {
                   int nx=f+d[i] , ny=s+d[i+1];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1)
                    {
                        A[nx][ny]=0;
                        q.push({nx,ny});
                    }
               }
            }
            cnt++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends