#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
 

const char logo[][128]={
"__   __  __   __ ",
"\\ \\ / / /_ | /_ |",
" \\ V /   | |  | |",
"  > <    | |  | |",
" / . \\   | |  | |",
"/_/ \\_\\  |_|  |_|",
"                   ",
"Hitachi ULSI Systems"
};
               
               
Display *d;
Window w;

int sleeping=5;
void *stop(void *p){
   sleep(sleeping);
   exit(1);
}

int main(int argc, char **argv) {
   int i,slp=0;
//   Display *d;
//   Window w;
   XEvent e;
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 150, 100, 1,
                           BlackPixel(d, s), WhitePixel(d, s));
   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);
 
   if(argc>1){
      sleeping=atoi(argv[1]);
      if(sleeping>0){
      printf("sleep %d\n",sleeping);
         pthread_t th_stop;
         pthread_create(&th_stop, 0, stop, 0);
      }
   }
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
         for(i=0;i<8;i++){
            XDrawString(d,w, DefaultGC(d,s), 5, i*10+20 , logo[i], strlen(logo[i]));
         }
      }
      if (e.type == KeyPress)
         break;
   }
 
   XCloseDisplay(d);
   return 0;
}
