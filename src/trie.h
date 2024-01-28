#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Forward declaration of task_t
struct task;
typedef struct task task_t;

typedef struct trieNode {
    struct trieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    task_t* task;
} trieNode_t;

trieNode_t* getNode();
void insert(trieNode_t* root, char* key, task_t* task);
bool search(trieNode_t* root, char* key);

#endif
