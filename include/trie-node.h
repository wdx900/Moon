#include <iostream>
#include <cstring>
#include <map>
#include "token-buffer.h"

using namespace std;

class TrieNode {
public:
	TrieNode() {};
	TrieNode(string str);
	virtual ~TrieNode();
	
public:
	string character;
	map<string, TrieNode*> children;
	bool is_leaf;
};

class Trie {
public:
	typedef TrieNode Node;
	typedef TrieNode* PNode;
	
	Trie();
	
public:
	bool insert(TokenBuffer &token_buffer);
	//bool insert(const char *str);

	bool find(TokenBuffer &token_buffer);
	//bool find(const char *str);

	//bool erase(Iterator begin, Iterator end);
	//bool erase(const char *str);

	//int size(PNode);
public:
	PNode root;

};

TrieNode::TrieNode(string str):character(str),
							   is_leaf(false) {
}

TrieNode::~TrieNode(){
	children.clear();
}

Trie::Trie():root(new Node("")) {}

bool Trie::insert(TokenBuffer &token_buffer) {
	PNode cur = root;
	PNode pre;
	Token token;
	TokenBuffer::Iterator *token_iterator = token_buffer.iterator();
	while(token_iterator->next(token)) {
		if(cur->children.find(token.t_text) == cur->children.end()) {
			cur->children.insert(pair<string, TrieNode*>(token.t_text, new Node(token.t_text)));
		}
		pre = cur;
		cur = cur->children[token.t_text];
	}
	cur->is_leaf = true;
	return true;
}



bool Trie::find(TokenBuffer &token_buffer) {
	PNode cur = root;
	Token token;
	TokenBuffer::Iterator *token_iterator = token_buffer.iterator();
	cout << "begin to find" << endl;
	while(token_iterator->next(token)) {
		cout << token.t_text;
		if(cur->children.find(token.t_text) == cur->children.end()) {
			return false;
		}
		cur = cur->children[token.t_text];
	}
	if(cur->is_leaf)
		return true;
	return false;
}

