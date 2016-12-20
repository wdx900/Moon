#include "trie-node.h"'

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

