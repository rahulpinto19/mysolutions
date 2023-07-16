//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void help(stack<int>&stk,int size,int mid)
    {
        if(!stk.size() || size==mid)
        return ;
        int val =stk.top();
        stk.pop();
        help(stk,size,mid+1);
        if(mid!=size/2)
        {
            stk.push(val);
        }
    }
    void deleteMid(stack<int>&s, int size)
    {
        help(s,size,0);
            return ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends