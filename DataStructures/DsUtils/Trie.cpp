#include "Trie.h"

#define FOR(i,a,b) for( int i = (a); i <(b); ++i)
#define ASK_KEY(ch) (ch - 'a');

static TrieNode* NewTrieNode()
{
	TrieNode* tmp = new TrieNode();
	
	FOR(i, 0, ALPHABET_SIZE)
		tmp->children[i] = NULL;

	tmp->endOfWord = false;

	return tmp;
}


TrieNode* CreateTrie()
{
	return NewTrieNode();
}

void Insert(TrieNode* root, const string key)
{
	TrieNode* pCrawl = root;

	FOR(level, 0, key.size())
	{
		int k = ASK_KEY(key[level]);

		if(pCrawl->children[k] == NULL)
		{
			pCrawl->children[k] = NewTrieNode();
		}

		pCrawl = pCrawl->children[k];
	}

	pCrawl->endOfWord = true;
}

bool Search(TrieNode* root, const string key)
{
	TrieNode* pCrawl = root;

	FOR(level, 0, key.size())
	{
		int k = ASK_KEY(key[level]);

		if(pCrawl->children[k] == NULL)
		{
			return false;
		}

		pCrawl = pCrawl->children[k];
	}

	return pCrawl !=NULL && pCrawl->endOfWord;
}


bool PrefixSearch(TrieNode* root, const string prefix)
{
	TrieNode* pCrawl = root;

	FOR(level, 0, key.size())
	{
		int k = ASK_KEY(key[level]);

		if(pCrawl->children[k] == NULL)
		{
			return false;
		}

		pCrawl = pCrawl->children[k];
	}

	return true;
}

static bool DeleteKeyRec(TrieNode* node, int level, const string& key)
{
}

void Delete(TrieNode* root, const string key)
{

}
