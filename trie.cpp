#include "Trie.h"
#include<iostream>
using namespace std;

void Trie::insert(string word)
{
    Trie::Node * curr = root;
    for(int i = 0 ; i<word.length(); i++)
    {
        char chr = word[i];
        int x = curr->e;
        if(x==0)
        {
            curr->children[x]=new Trie::Node(chr);
            curr->e++;
            curr= curr->children[x];
        }else
        {
            for(int j = 0 ; j< x ; j++)
            {
                if(chr == curr->children[j]->c)
                {
                    curr=curr->children[j];
                    break;
                }else if(j == (x-1) )
                {
                    curr->children[x]=new Trie::Node(chr);
                    curr->e++;
                    curr= curr->children[x];
                }
            };
        };
    }
    curr->isWord = true;
    if(search(word)) curr->count++;
}
bool Trie::search(string word)
{
    Trie::Node * curr = root;
    for(int i = 0 ; i< word.length(); i++)
    {
        char ch = word[i];
        for(int j = 0 ; j < curr->e ; j++)
        {
            if (ch == curr->children[j]->c)
            {
                curr=curr->children[j];
                break;
            }
            if(j == (curr->e)-1 )
            {
                return false;
            }
        }
    }
    return true;
}
int Trie::findCount(string word)
{
    Trie::Node * curr = root;
    int counter=0;
    for(int i = 0 ; i< word.length() ; i++)
    {
        char ch = word[i];
        int x = curr->e;
        for(int j = 0; j<x;j++)
        {
            if(ch == curr->children[j]->c)
            {
                curr= curr->children[j];
                break;
            }
            if(j == x-1)return 0;
        }
    };

    return fin(curr,counter);
}
int Trie :: fin(Trie::Node * curr,int counter)
{
    int x = counter;
    if(curr->isWord)
    {
        x+=curr->count;
        counter=x;
    }
    if(curr->e == 0) return x;
    for(int i = 0 ; i< curr->e ; i ++)
    {
        x = fin(curr->children[i],x);

    }
    return x;
};