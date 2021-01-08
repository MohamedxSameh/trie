#ifndef TRIE_H
#define TRIE_H
#include<iostream>
using namespace std;


class Trie
{
    private:
        class Node
        {
        public:
            char c;
            bool isWord;
            bool displayed;
            int e = 0 ;
            int count=0;
            Node *children[26]={0};
            Node(char ch)
            :c(ch) ,isWord(false), displayed(false)
            {};
        };
    public:
        void insert (string word);
        void remove (string word);
        Node* getNode(string word);
        void display ();
        bool search (string word);
        int findCount (string word);
        int fcr(Node * p,int counter);
        void dr(Node* p, string str);
        Node * root = new Node('*');
};

#endif // TRIE_H