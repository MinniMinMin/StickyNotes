#include "trie.h"

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])


// Returns new trie node (initialized to NULLs)
trieNode_t* getNode() {
    trieNode_t* pNode =  pNode = (trieNode_t*) malloc(sizeof(trieNode_t));
 
    if (pNode) {
        int i;
 
        pNode->isEndOfWord = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trieNode_t* root, char* key, task_t* t) {
    int level;
    int length = strlen(key);
    int index;
 
    trieNode_t* pCrawl = root;
 
    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->task = t;
}

// Returns true if key presents in trie, else false
bool search(trieNode_t* root, char *key) {
    int level;
    int length = strlen(key);
    int index;
    trieNode_t* pCrawl = root;
 
    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index]) return false;
 
        pCrawl = pCrawl->children[index];
    }
    
    // can change to ->task when working fully on searching
    return pCrawl->isEndOfWord;
}
