/***********************************************************************
 *
 *             Trie: Datastructure.
 *
 **********************************************************************/

#ifndef TRIE_H
#define TRIE_H

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

#define ALPHABET_SIZE 26

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];
	bool endOfWord;	
};

TrieNode* CreateTrie();
void Insert(TrieNode* root, const string key);
bool Search(TrieNode* root, const string key);
bool PrefixSearch(TrieNode* root, const string prefix);
void Delete(TrieNode* root, const string key);


#endif
