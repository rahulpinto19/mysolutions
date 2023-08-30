//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int pos=0;
    stack<int> s1;
    stack<pair<int,int>>s2;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s2.empty())
           return -1;
            return s2.top().first;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
        if(s1.empty())
        return -1;
        int val = s1.top();
         s1.pop();
        if(s2.top().second==pos)
        s2.pop();    
        pos--;
        return val;
       }
       
       /*push element x into the stack*/
       void push(int val)
       {
           pos++;
        if(s2.empty())
        s2.push({val,pos});
        else
        {
            if(s2.top().first>val)
            s2.push({val,pos});
        }    
        s1.push(val);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends