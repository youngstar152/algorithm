#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

void patatokukashi(char *str, char *s1, char *s2);

int main(void)
{
  int x, y, h, w;
  char str[80], s1[80], s2[80];

  printf("Please input string: ");
  fgets(str, sizeof(str), stdin);
  str[strlen(str)-1] = '\0';
  patatokukashi(str, s1, s2);

  initscr();
  noecho();
  cbreak();
  curs_set(0);
  timeout(0);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, h, w);

  y = h/2;
  x = w-strlen(str);
  while (1) {
    erase();
    border(0,0,0,0,0,0,0,0);
    if (x >= w/2) {
      mvprintw(y,x,"%s",str);
    } else {
      mvprintw(y-2,x,"%s",s1);
      mvprintw(y+2,x,"%s",s2);
    }
    refresh();
    x--;
    if (x == 0)
      break;
    usleep(100000);
  }
  endwin();
  return 0;
}

void patatokukashi(char *str, char *s1, char *s2){
    int i;
    for(i=0;i<strlen(str);i++){
        if (i%2 ==0){
            s1[i/2] = str[i];
        }
        else {
            s2[i/2] = str[i];
        }
    if (strlen(str)%2 ==0){
        s1[strlen(str)/2]='\0';
    }else {
        s1[strlen(str)/2 + 1]='\0';
    }
    
    s2[strlen(str)/2] = '\0';
    }


}
