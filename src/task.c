#include "task.h"
#include "trie.h"

int main() {

   printf("Hello! What would you like to do?\n");
   
   trieNode_t* root = getNode();

   while (1) {
      if (options(root) == 0) break;
      // now need to deal with memory issues
      // and make it so notes are properly saved and not wiped after use!
   }

   return 1;
}

int options(trieNode_t* r) {
   printf("c: create task, s: search for task, e: stop program\n");
   char option[MAXTITLELENGTH];
   scanf(" %49[^\n]", option);
   
   if (strcmp(option, "c") == 0) {
      task_t* t = createTask();
      insert(r, t->Name, t); // create task then add to trie
   }
   else if (strcmp(option, "s") == 0) {
      printf("What would you like to search for?\n");
      char lookup[MAXTITLELENGTH];
      scanf(" %49[^\n]", lookup);
      printf("%s\n", search(r, lookup) ? "This exists!" : "This does not exist!");
   }
   else if (strcmp(option, "e") == 0) {
      printf("Exiting!\n");
      return 0;
   }
   else {
      printf("ERROR! Don't recognize command");
      return 0;
   }
   return 1;
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