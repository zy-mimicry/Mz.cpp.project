/*
 * 单向链表的实现
 */
#include <stdio.h>
#include <stdlib.h>

#define FALSE 1
#define TRUE  0

#define FIND 1
#define UNFIND 0

typedef struct NODE{
  struct NODE* link;
  int value;
}Node;

int insert_node(register Node** linkp, int value);
Node* query_node(register Node** linkp, int value);
int delete_node(register Node** linkp, int value);
int list_size(Node** linkp);
void print_list(Node* list);

int main (int argc, char ** argv){
  Node* __list = NULL;

  printf("Just test the singly linked list\n");
  printf("Insert some values.\n");
  insert_node(&__list, 10);
  insert_node(&__list, 20);
  insert_node(&__list, 30);
  insert_node(&__list, 20);
  print_list(__list);

  printf("---query-----\n");
  query_node(&__list,20);
  query_node(&__list,30);
  query_node(&__list,40);
  query_node(&__list,10);
  print_list(__list);

  printf("---delete-----\n");
  delete_node(&__list, 40);
  print_list(__list);
  printf("\n");

  delete_node(&__list,20);
  query_node(&__list,20);
  print_list(__list);
  printf("\n");

  delete_node(&__list,20);
  query_node(&__list,20);
  print_list(__list);
  return 0;
}

//Insert list node archieve - OK
int insert_node(register Node** linkp, int value){
  register Node* current;
  register Node* new;

  while((current = *linkp) != NULL && current->value < value)
    linkp = &current->link; // Followed...

  new = (Node*) malloc(sizeof(Node));
  if (new == NULL)
    return FALSE;
  new->value = value;

  /* printf("new value is %d\n",new->value); */
  new->link = current;
  *linkp = new;
  return TRUE;
}

//Query list node archieve
Node* query_node(register Node** linkp, int value){
  while(*linkp != NULL) {
    if ((*linkp)->value == value){
      printf("Find it.\n");
      return *linkp;
    }
    linkp = &(*linkp)->link;
  }
  printf("Un find it.\n");
  return NULL;
}

//Size of the list archieve -- OK
int list_size(Node** linkp){
  int ret = 0;
  while(*linkp != NULL){
    linkp = &(*linkp)->link;
    ret += 1;
  }
  return ret;
}

//Delete list node archieve -- OK
int delete_node(register Node** linkp, int value){
  Node* pre = (*linkp);
  Node* temp;
  printf("deleting...\n");
  while(*linkp != NULL && (*linkp)->value != value){
    pre = *linkp;
    linkp = &(*linkp)->link;
  }
  if (*linkp == NULL){
    printf("delete fail\n");
    return FALSE;
  }else{
    temp = pre->link;
    pre->link = (*linkp)->link;
    free(temp);
    /* 1. free can't set pointer to NULL, so do it */
    /* 2. When one value in the list, pre == (*linkp) is true, then after free shoude do this */
    if (pre == (*linkp)){
      (*linkp) = NULL;
    }
    printf("deleted\n");
  }
  return TRUE;
}


//Print list nodes archieve. -- OK
void print_list(Node* list){
  int i,size = list_size(&list);
  printf("List size is :%d \nNode: ", size);
  for (i=0; i<size; i++){
    printf("%d ", list->value);
    list = list->link;
  }
  printf("\n");
}


