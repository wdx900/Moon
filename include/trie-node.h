#ifndef _TRIE_NODE_H_
#define _TRIE_NODE_H_


#include <iostream>
#include <cstring>
#include <map>
#include <vector>

#include "token-buffer.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {};
	TrieNode(string str):character(str),is_leaf(false) {}

	virtual ~TrieNode(){children.clear();}
	
public:
	string character;
	map<string, TrieNode*> children;
	bool is_leaf;
};

class Trie {
public:
	typedef TrieNode Node;
	typedef TrieNode* PNode;
	
	Trie():root(new Node("")) {};
	
public:
	bool insert(string words, vector<int> words_list);
	//bool insert(const char *str);

	bool find(string &words, vector<int> words_list);
	//bool find(const char *str);

	//bool erase(Iterator begin, Iterator end);
	//bool erase(const char *str);

	//int size(PNode);
public:
	PNode root;

};


#endif
