#include <iostream>
#include <cstring>
#include <map>
#include <vector>
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

TrieNode::TrieNode(string str):character(str),
							   is_leaf(false) {
}

TrieNode::~TrieNode(){
	children.clear();
}

Trie::Trie():root(new Node("")) {}

bool Trie::insert(string words, vector<int> words_list) {
	PNode cur = root;
	int position = 0;	
	for(int i = 0; i< words_list.size(); ++i) {
		string text = words.substr(position, words_list[i]);
		if(cur->children.find(text) == cur->children.end()) {
			cur->children.insert(pair<string, TrieNode*>(text, new Node(text)));
		}
		cur = cur->children[text];
		position += words_list[i]; 
	}
	cur->is_leaf = true;
	return true;
}



bool Trie::find(string &words, vector<int> words_list) {
	PNode cur = root;
	int position = 0;
	//cout << "begin to find word:" << words_list.size()<<endl;
	for(int i = 0; i < words_list.size(); ++i){
		string text = words.substr(position, words_list[i]);
		//cout << text << endl;
		if(cur->children.find(text) == cur->children.end()) {
			return false;
		}
		position += words_list[i];
		cur = cur->children[text];
	}
	if(cur->is_leaf)
		return true;
	return false;
}

