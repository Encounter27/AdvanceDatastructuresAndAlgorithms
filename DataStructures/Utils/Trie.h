/***********************************************************************
 *
 *             Trie: Datastructure.
 *
 **********************************************************************/

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#define ALPHABET_SIZE 256

class Trie
{
    bool endOfWord;
    Trie* children[ALPHABET_SIZE];

    bool NoChildren();
    bool DeleteKeyRec(Trie *root, int level, const std::string &key);
  public:
    Trie();

    void Insert(const std::string key);
    bool Search(const std::string key);
    bool PrefixSearch(const std::string prefix);
    void Delete(const std::string key);

    friend std::ostream &operator << (std::ostream& out, Trie& root);

    ~Trie();
};

class TrieLRU : public Trie
{
    
};

#endif
