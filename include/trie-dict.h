#ifndef TRIE_DICT_H
#define TRIE_DICT_H

#include <fstream>
#include "dict.h"
using namespace std;

template <class CHAR>
class TrieDict : public Dict {

private:
	struct NodeInfo {
		int node_tag;
		vector<CHAR> branch_chars;
		vector<int> branch_index;
	};

protected:
	class TrieTreeNode {
	public:
		TrieTreeNode(int node_tag = 0) 
		: m_node_tag = node_tag {}
		virtual ~TrieTreeNode();
		
	public:
		TrieTreeNode *GetBranch(const CHAR &character);
		bool AddBranch(const CHAR &character,
								TrieTreeNode *&trie_tree_node);
		bool AddBranchReplace(const CHAR &character,
							  TrieTreeNode *trie_tree_node);
	public:
		multimap<CHAR, TrieTreeNode *> branch_table;
		int node_tag;
	};
	
public:
	virtual bool SaveTo(const string &file_name);
	virtual bool LoadFrom(const string &file_name);
	virtual bool Match();

public:
	virtual bool Insert(const string &word, int node_tag);

};

template <class CHAR>
bool TrieDict<CHAR>::TrieTreeNode::AddBranch(const CHAR &character,
											 TrieTreeNode *trie_tree_node) {
	branch_table.insert(pair<CHAR, TrieTreeNode *>(character, tire_tree_node));
	return true;
}

template <class CHAR>
bool TrieDict<CHAR>::SaveTo(const string &file_name) {
	
}	

bool TrieDict<CHAR>::LoadFrom(const string &file_name) {
	ifstream f("");
}

#endif
