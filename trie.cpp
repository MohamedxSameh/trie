#include "Trie.h"
#include<iostream>
using namespace std;



//*******************
//*GET NODE FUNCTION
//*******************
Trie::Node* Trie :: getNode(string word)
{
        Trie::Node * curr = root;
        for(int i = 0 ; i< word.length() ; i ++)
        {
            char ch = word[i];
            if(curr->e == 0) return 0;
            for(int j = 0 ; j < curr-> e ; j++)
            {
                if(ch == curr->children[j]->c)
                {
                    curr = curr->children[j];
                    break;
                }
            }
        }
        return curr;
}

//******************
//*SEARCH FUNCTION
//******************
bool Trie::search(string word)
{
    Trie::Node * curr = root;
    for(int i = 0 ; i< word.length(); i++)
    {
        char ch = word[i];
        if(curr->e == 0) return false;
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
    if(curr->isWord) return true;
    else return false;
}

//****************
//*INSERT FUNCTION
//****************
void Trie::insert(string word)
{
    Trie::Node * curr = root;
    if(search(word)){
        curr = getNode(word);
        curr->count++;
        return;
    }
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
    curr->count++;
}

//****************
//*REMOVE FUNCTION
//****************
void Trie::remove (string word){
    if (!search(word)){
        cout<<"This word already doesn't exist"<<endl;
        return;
    }
    Trie::Node * curr = getNode(word);
    curr->isWord=false;
    cout<<"Word removed"<<endl;
}

//****************
//*FINDCOUNT FUNCTION
//****************
int Trie::findCount(string word)
{
    Trie::Node * curr = getNode(word);
    if(curr==0) return 0;
    int counter=0;
    return fin(curr,counter);
}

//*******************
//*RECURSIVE FUNCTION
//*******************
int Trie :: fin(Node * curr,int counter)
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

//*******************
//*DISPLAY FUNCTION
//*******************
void Trie::display()
{
    Trie::Node * curr = root ;
    d(curr);
}
void Trie:: d(Node* curr)
{
    if(curr->e == 0) return;
    for(int i = 0 ; i<curr->e ; i ++)
    {
        curr=curr->children[i];
        cout<<curr->c;
        if(curr->isWord) break;
        d(curr);
    }
}