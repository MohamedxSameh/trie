#include <iostream>
#include "Trie.h"

using namespace std;


int main()
{
    Trie t;
    // t.insert("bulldog");
    t.insert("cat");
    t.insert("dog");
    t.insert("dogged");
    // t.insert("doggedly");
    // t.insert("doggerel");
    // t.insert("dogma");

    t.display();





    // Trie t;
    // int n ,q ;
    // cin>>n;
    // cin>>q;
    // for(int i = 0 ; i< n ; i++)
    // {
    //     string s;
    //     cin>>s;
    //     t.insert(s);
    // }
    // string st [q];
    // for(int i = 0 ; i< q ; i++)
    // {
    //     string s ;
    //     cin>>s;
    //     st[i]= s;
    // }
    // for(int i = 0 ; i < q ; i++)
    // {
    //     cout<<t.findCount(st[i])<<endl;
    // }
    // return 0;

}
