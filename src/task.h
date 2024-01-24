#ifndef TASK_H
#define TASK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITLELENGTH 50
#define MAXDESCRIPLENGTH 200

typedef struct task {
    char* Name;
    char* description;
    bool isCompleted;
} task_t;

task_t* createTask();
void readTask(task_t* t);
void freeTask(task_t* t);
void options(trieNode_t* r);

#endif
