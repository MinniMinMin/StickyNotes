#include "task.h"
#include "trie.h"

int main() {
   task_t* t = createTask();
   
   trieNode_t* root = getNode();

   insert(root, t->Name, t);

   printf("Does task exist: %s\n", search(root, t->Name) ? "yes" : "no"); // if 1 pritns true, if 0 prints no

   free(t);
}

task_t* createTask() {
   task_t* t = malloc(sizeof(task_t));

   printf("What is the title of the task?\n");
   char title[MAXTITLELENGTH];
   scanf(" %49[^\n]", title);
   t->Name = strdup(title);

   printf("What is the description of the task?\n");
   char desc[MAXTITLELENGTH];
   scanf(" %99[^\n]", desc);
   t->description = strdup(desc);

   t->isCompleted = false;

   return t;
}

void freeTask(task_t* t) {
   free(t->Name);
   free(t->description);
   free(t);
}

void readTask(task_t* t) {
   printf("The name of the task is: %s\n", t->Name);

   if (t->isCompleted == true) printf("The task has been completed\n");
   else printf("The task has yet to be done\n");
}