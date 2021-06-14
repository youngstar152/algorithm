#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} slist;

void slist_append(slist **head, int value)
{
  slist *node = (slist *) malloc(sizeof(slist));
  node->value = value;
  node->next = NULL;
  if (*head == NULL) {
    *head = node;
  } else {
    slist *p = *head;
    while (p->next != NULL){
      p = p->next;
	}
    p->next = node;
  }
}

void slist_remove(slist **head, int value)
{
 slist *p = *head;
 slist *q = NULL;
  while (p!= NULL){
    if(p->value == value){
      if(q == NULL){
        *head =p->next;
        free(p);
        p = *head;
      }else{
        q->next = p->next;
        free(p);
        p = q->next;
      }
   }else{
     q=p;
     p=p->next;
   }
    
  }
}

int slist_index(slist *head, int value)
{
  int i = 0;
  slist *p = head;
  while (p != NULL) {
    if (p->value == value){
      break;
	}
    p = p->next;
    i++;
  }
  if (p == NULL){
    return -1;
  }else{
    return i;
  }
}

void slist_free(slist **head)
{
  slist *p = *head;
  slist *q;
  while (p != NULL) {
    q = p;
    p = p->next;
    free(q);
  }
}

void slist_display(slist *head)
{
  slist *p = head;
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
}

int main(void)
{
  slist *head = NULL;
  slist_append(&head, 1);
  slist_append(&head, 2);
  slist_append(&head, 3);
  slist_append(&head, 4);
  slist_append(&head, 5);
  slist_display(head);

  slist_remove(&head, 3);
  slist_display(head);
  slist_remove(&head, 5);
  slist_display(head);
  slist_remove(&head, 1);
  slist_display(head);

  slist_free(&head);
  return 0;
}
