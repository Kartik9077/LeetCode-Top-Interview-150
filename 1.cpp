#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int x=stoi(a);
        int n=sqrt(x);
        if(n*n!=x){
            cout<<"-1"<<endl;
        }
        else{
            cout<<"0"<<' '<<n<<endl;
        }
    }
return 0;
}