#include <iostream>
#include "Trie.h"

using namespace std;


int main()
{
    Trie t;
    int n ,q ;
    cin>>n;
    cin>>q;
    for(int i = 0 ; i< n ; i++)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    string st [q];
    for(int i = 0 ; i< q ; i++)
    {
        string s ;
        cin>>s;
        st[i]= s;
    }
    for(int i = 0 ; i < q ; i++)
    {
        cout<<t.findCount(st[i])<<endl;
    }
    return 0;
}
