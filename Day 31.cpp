// Implement Trie (Prefix Tree)
struct Node {
    Node* links[26];
    bool end = false;
    bool containsKey(char ch) { return (links[ch-'a'] != NULL); }
    void put(char ch, Node* node) { links[ch-'a'] = node; }
    Node* get(char ch) { return links[ch-'a']; }
    void setEnd() { end = true; }
    bool isEnd() { return end; }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i < size(word); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i < size(word); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i < size(prefix); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

// Trie (Insert and Search)
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key) {
    auto node = root;
    for(int i=0; i<key.size(); i++) {
        if(!node->children(key[i] - 'a')) {
            node->children[key[i] - 'a'] = new TrieNode();
        }
        node = node->children[key[i] - 'a'];
    }
    node->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) {
    auto node = root;
    for(int i=0; i<key.size(); i++) {
        if(!node->children(key[i] - 'a')) {
            return 0;
        }
        node = node->children[key[i] - 'a'];
    }
    return node->isLeaf;
}