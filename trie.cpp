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
    int size = word.length();
    string str = word;
    Trie::Node * curr = getNode(str);
    for ( int i = 1 ; i<=size ; i++)
    {
        if(curr->e == 0)
        {
            curr =NULL;
            str = word.substr(0,size-i);
            curr = getNode(str);
            curr->e --;
        }else{
            curr->isWord=false;
            return;
        }
    }
    cout<<"------Word removed------"<<endl;
}

//****************
//*FINDCOUNT FUNCTION
//****************
int Trie::findCount(string word)
{
    Trie::Node * curr = getNode(word);
    if(curr==0) return 0;
    int counter=0;
    return fcr(curr,counter);
}

//*******************
//*RECURSIVE FUNCTION
//*******************
int Trie :: fcr(Node * curr,int counter)
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
        x = fcr(curr->children[i],x);

    }
    return x;
};

//*******************
//*DISPLAY FUNCTION
//*******************
void Trie::display()
{
    Trie::Node * curr = root ;
    for(int i = 0 ; i<curr->e ; i++)
    {
        string str ="";
        dr(curr->children[i], str);
    }
}
//*******************
//*RECURSIVE FUNCTION
//*******************
void Trie:: dr(Node* curr, string str)
{
    str += curr->c;
    if(curr->e == 0){
        cout<<str<<endl;
        return;
    }else if(curr->isWord)
    {
        cout<<str<<endl;
    }
    for(int i = 0 ; i<curr->e ; i++)
    {
        dr(curr->children[i], str);
    }
}