#include <iostream>
#include "Trie.h"

using namespace std;


int main()
{
    Trie t;
    t.insert("dog");
    t.insert("sameh");
    t.insert("cat");

    t.search("cat");
    t.search("mohamed");
    t.search("dog");

    return 0;
}
