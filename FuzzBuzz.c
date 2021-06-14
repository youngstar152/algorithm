#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void npc(char ch, int i)
{
  printf("%c: ", ch);
  if (i % 3 == 0 && i % 5 == 0) {
    printf("Fizz Buzz\n");
  } else if (i % 3 == 0) {
    printf("Fizz\n");
  } else if (i % 5 == 0) {
    printf("Buzz\n");
  } else {
    printf("%d\n", i);
  }
}

int checka(int i, char str[])
{
  if (i % 3 == 0 && i % 5 == 0) {
    if (strcmp("Fizz Buzz",str) == 0){
    return 1;
    }
  } else if (i % 3 == 0) {
    if (strcmp("Fizz", str) == 0){
    return 1;
    }
  } else if (i % 5 == 0) {
    if (strcmp("Buzz", str) == 0){
    return 1;
    }
  } else {
    if(i == atoi(str)){
      return 1;
    }   
  }
  return 0;
}

int main(void)
{
  int i, r;
  char str[20];

  for (i = 1; i <= 20; i+=4) {
    printf("A? ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    r = checka(i, str);
    if (r == 0) {
      printf("B,C,D: Doubt!\n");
      exit(EXIT_SUCCESS);
    }
    npc('B', i+1);
    npc('C', i+2);
    npc('D', i+3);
  }
  return 0;
}
