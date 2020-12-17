#include "Trie.h"
#include<iostream>
using namespace std;

//Trie::Trie()

//*****************
//INSERT METHOD
//*****************

void Trie::insert(string word)
{
    Trie::Node * curr = root;
    for(int i = 0 ; i<word.length(); i++)
    {
        char chr = word[i];
        int index = chr - 'a';
        if (curr->children[index] == 0)
            {
                curr->children[index]=new Trie::Node(chr);
                curr = curr->children[index];
                if(i == (word.length() -1) )
                    {
                        curr->isWord = true;
//                        cout<<"word is added"<<endl;
                    }
            };
    }
}

//*****************
//INSERT METHOD
//*****************

void Trie::search(string word)
{
    Trie::Node * curr = root;
    for(int i = 0 ; i< word.length(); i++)
    {
        char ch = word[i];
        int index = ch - 'a';
        if (curr->children[index] == 0 || curr->children[index]->c != ch)
        {
            cout<<word<<" is not found in trie"<<endl;
            return;
        }

        curr=curr->children[index];
    }
    cout<<word <<" is found in trie"<<endl;
   }