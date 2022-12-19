#include <bits/stdc++.h>
class Node {
public:
  Node *links[26];
  int cntEndWith = 0, cntPrefix = 0;
  bool containsKey(char &ch) { 
    return (links[ch - 'a'] != NULL);
  }
  void put(char &ch, Node *node) {
    links[ch - 'a'] = node; 
  }
  Node *get(char ch) { 
    return links[ch - 'a']; 
  }
  void incPre() { 
    cntPrefix++;
  }
  void delPre() { 
    cntPrefix--; 
  }
  void incEnd() { 
    cntEndWith++;
  }
  void delEnd() { 
    cntEndWith--;
  }
  int getPre() { 
    return cntPrefix;
  }
  int getEnd() { 
    return cntEndWith;
  }
};

class Trie {
private:
  Node *root;

public:
  Trie() {
    root = new Node(); }

  void insert(string &word) {
    // Write your code here.
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
      node->incPre();
    }
    node->incEnd();
  }

  int countWordsEqualTo(string &word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i]))
        return 0;
      else
        node = node->get(word[i]);
    }
    node->getEnd();
  }

  int countWordsStartingWith(string &word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i]))
        return 0;
      else
        node = node->get(word[i]);
    }
    node->getPre();
  }

  void erase(string &word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i]))
        return;
      else {
        node = node->get(word[i]);
        node->delPre();
      }
    }
    node->delEnd();
  }
};
