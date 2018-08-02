#include "Trie.h"

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ASK_KEY(ch) (ch - 'a');

Trie::Trie()
{
    endOfWord = false;
    FOR(i,0,ALPHABET_SIZE) 
        children[i] = nullptr;
}

Trie::~Trie()
{
    FOR(i,0,ALPHABET_SIZE) 
    {
        delete children[i];
        children[i] = nullptr;
    }
}

void Trie::Insert(const std::string key)
{
    Trie *pCrawl = this;

    FOR(level, 0, key.size())
    {
        int k = ASK_KEY(key[level]);

        if (pCrawl->children[k] == NULL)
        {
            pCrawl->children[k] = new Trie();
        }

        pCrawl = pCrawl->children[k];
    }

    pCrawl->endOfWord = true;
}

bool Trie::Search(const std::string key)
{
    Trie *pCrawl = this;

    FOR(level, 0, key.size())
    {
        int k = ASK_KEY(key[level]);

        if (pCrawl->children[k] == NULL)
        {
            return false;
        }

        pCrawl = pCrawl->children[k];
    }

    return pCrawl != NULL && pCrawl->endOfWord;
}

bool Trie::PrefixSearch(const std::string key)
{
    Trie *pCrawl = this;

    FOR(level, 0, key.size())
    {
        int k = ASK_KEY(key[level]);

        if (pCrawl->children[k] == NULL)
        {
            return false;
        }

        pCrawl = pCrawl->children[k];
    }

    return true;
}

bool Trie::NoChildren()
{
    FOR(i,0,ALPHABET_SIZE)
        if(this->children[i] != nullptr)
            return false;

    return true;
}

bool Trie::DeleteKeyRec(Trie *root, int level, const std::string &key)
{
    if(root == nullptr)
        return false;

    if(level == key.length())
    {
        if(root->endOfWord)
        {
            root->endOfWord = false;
 
            return root->NoChildren();
        }
    }
    else
    {
        int k = ASK_KEY(key[level]);
        if(DeleteKeyRec(root->children[k], level+1, key))
        {
            delete root->children[k];
            root->children[k] = nullptr;

            return !(root->endOfWord) && root->NoChildren();
        }
    }

    return false;
}

void Trie::Delete(const std::string key)
{
    DeleteKeyRec(this, 0, key);
}
