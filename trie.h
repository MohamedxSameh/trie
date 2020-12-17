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
            Node *children[26]={0};
            Node(char ch)
            :c(ch) ,isWord(false)
            {};

        };

    public:
//        Trie();
        //INSERT METHOD
        void insert (string word);
        //SEARCH METHOD
        void search (string word);
        //SEARCH QUERY
        int sq (string word);
        //ROOT NODE
        Node * root = new Node('*');

    protected:
};

#endif // TRIE_H