//:graph.cpp
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <cstdio>
#include <cctype>
#include <curses.h>
#include <cstdlib>

#define HEIGHT 8
#define WIDTH  14
#define WDTH(wdth,n) (wdth/n)
using namespace std;
               bool curses_started = false;

               void endCurses() {
                  if (curses_started && !isendwin())
                     endwin();
               }


               void startCurses() {
                  if (curses_started) {
                     refresh();
                  }
                  else {
                     initscr();
                     cbreak();
                     noecho();
                     intrflush(stdscr, false);
                     keypad(stdscr, true);
                     atexit(endCurses);
                     curses_started = true;
                  }
               }
char schr='*';
int let__o[4][2] = {{0,0},{4,0},{4,4},{0,4}};
int let__b[8][2]  = {{0,0},{0,2},{0,4},{4,4},{4,2},{0,2},{4,2},{4,0}};
int let__t[5][2]  = {{0,0},{2,0},{4,0},{2,0},{2,2}};
int let__i[8][2]  = {{2,0},{4,0},{3,0},{3,3},{4,3},{2,3},{3,3},{3,0}};
int let__k[7][2]   = {{4,0},{0,2},{4,4},{0,2},{0,4},{0,0}};
int let__s[][2] = {{4,0},{0,0},{0,2},{4,2},{4,4},{0,4},{4,4}};
int let__l[][2] = {{0,0},{0,4},{4,4}};
int let__f[7][2] = {{0,0},{0,2},{1,2},{0,1},{0,4},{0,0},{1,0}};
int let__p[7][2] = {{0,0},{2,0},{2,2},{0,2},{0,0},{0,4},{0,2}};
int let__u[4][2] = {{4,0},{4,4},{0,4},{0,0}};
int let__x[][2] = {{2,2},{4,4},{2,2},{0,4},{2,2},{4,0},{2,2},{0,0}};
int let__j[][2] = {{4,0},{4,4},{1,4},{1,3}};
int let__c[][2] = {{4,0},{0,0},{0,4},{4,4}};
int let__d[][2] = {{0,0},{3,0},{4,1},{4,3},{0,4}};
int let__m[5][2] = {{0,4},{0,0},{2,3},{4,0},{4,4}};
int let__h[6][2] = {{0,4},{0,0},{0,2},{4,2},{4,4},{4,0}};
int let__z[4][2] = {{0,0},{4,0},{0,4},{4,4}};
int let__a[5][2] = {{0,4},{2,0},{4,4},{3,2},{1,2}};
int let__r[8][2] = {{0,0},{2,0},{2,2},{0,2},{0,0},{0,4},{0,2},{3,4}};
int let__g[6][2] = {{4,0},{0,0},{0,4},{4,4},{4,3},{3,3}};
int let__n[4][2]  = {{0,4},{0,0},{4,4},{4,0}};
int let__e[7][2]   = {{4,0},{0,0},{0,2},{4,2},{0,2},{0,4},{4,4}};
int let__v[3][2]    = {{0,0},{2,4},{4,0}};
int let__w[5][2]     = {{0,0},{1,4},{2,3},{3,4},{4,0}};
int let__y[5][2]     = {{0,0},{2,2},{2,4},{2,2},{4,0}};
int let__q[6][2]     = {{0,0},{4,0},{4,4},{3,3},{4,4},{0,4},};
int max_row=1;
int pos_x=0,pos_y=0;
int max_column=1;
int min_row=1;
int min_column=1;
int min_cell;
int max_cell;
void max_pnt(int ltr[][2],int pnt){
  int mxc=0,mxr=0;
  max_cell=ltr[mxr][mxc];
  for(int c=0;c<pnt;c++){
      if(ltr[c][1]>ltr[mxr][1]){
	mxr = c;
      }
  }
  max_row = ltr[mxr][1];
  mxr=0;mxr=0;
    for(int c=0;c<pnt;c++){
      if(ltr[c][0]>ltr[mxc][0]){
	mxc = c;
      }
  }
  max_column = ltr[mxc][0];
 //   cout << "max";
  return;
}//max_pnt

void min_pnt(int ltr[][2],int pnt){

  int mnc=0,mnr=0;
  min_cell=ltr[mnr][mnc];
  for(int c=0;c<pnt;c++){
      if(ltr[c][1]<ltr[mnc][1]){
	mnc = c;
      }
  }
  min_row = ltr[mnc][1];
  mnr=0;mnc=0;
    for(int c=0;c<pnt;c++){
      if(ltr[c][0]<ltr[mnc][0]){
	mnc = c;
      }
  }
  min_column = ltr[mnc][0];
    //cout << "min" << endl;
  return;
}//min_pnt

void let_print(int ltr[][2],int width,int height,int pn,int flag) {
  int nx,ny;
  move(pos_y,pos_x);
  refresh();
  int ltr2[][2]= {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
char **nltr=new char*[height+1];
  for(int hght=0;hght<height+1;hght++){
    nltr[hght] = new char[width];
  }
  for(int row=0;row<height+1;row++){
   for(int column=0;column<width;column++){
    nltr[row][column]=0; 
   }
  }
  max_pnt(ltr,pn);
  min_pnt(ltr,pn);
  int scale_x = width / max_column;
  int scale_y=  height / max_row;
  for(int c=0;c<pn;c++){
    ltr2[c][0]= ltr[c][0] * scale_x ;
    ltr2[c][1]= ltr[c][1] * scale_y ;
  }
  int pr=ltr2[0][1];
  int pc=ltr2[0][0];
  for(int row=0;row<height+1;row++){
   for(int column=0;column<width;column++){
      for(int c=0;c<pn;c++){
	if(row==ltr2[c][1] && column==ltr2[c][0] ){
	  nltr[row][column]=1;
	  if(c!=pn-1){
	    pr=ltr2[c+1][1];
	    pc=ltr2[c+1][0];
	  } else if(flag!=1){
	    pr=ltr2[0][1];
	    pc=ltr2[0][0];
	  }
	  if(c==pn-1 && flag==1)break;
	      if(row<pr && column==pc){
	      for(int ir=row;ir<=pr;nltr[ir++][pc]=1);
	    } else if(row==pr && column>pc){
	      for(int ic=column;ic>=pc;nltr[pr][ic]=1,ic--);}
	      else if(row>pr && column==pc){
		for(int ir=row;ir>=pr;nltr[ir][pc]=1,ir--);
	      } else if(row==pr && column<pc){
		for(int ic=column;ic<=pc;nltr[pr][ic]=1,ic++);
	      } else {
		int ic=column;
		int ir=row;
		while(ic!=pc || ir!=pr){
		  if(ic>pc){
		   ic--;
		  }
		  if(ir>pr){
		    ir--;
 		  }
		  if(ic<pc){
		    ic++;
		  }
		  if(ir<pr){
		    ir++;
		  }
		  nltr[ir][ic] = 1;
		}
	      }
	}
      }
   }
  }

  for(int row=0;row<height;row++){
     getyx(stdscr,ny,nx);
   for(int column=0;column<width;column++){
     if(nltr[row][column]!=0){addch(schr);}
     else {
      addch(' '); 
     }
   }
   ny++;
    move(ny,nx);
    refresh();
  }
    getyx(stdscr,ny,nx);
  if((nx+width+1)>=COLS){
   pos_y+=(height+1);
   pos_x=0;
  }else {
    pos_x+=(width+1);
  }
  move(pos_y,pos_x);
    refresh();
  for(int hght=0;hght<height+1;hght++){
    delete nltr[hght];
  }
  delete []nltr;
}

void draw_letter(char ltr, int width, int height){
  switch(ltr){
    case 's':
     let_print(let__s,width, height,6,1);
   break;
    case 'b':
      let_print(let__b,width, height,8,0);
    break;
    case 'c':
      let_print(let__c,width, height,4,1);
    break;
    case 'd':
      let_print(let__d,width, height,5,0);
      break;
    case 'f':
      let_print(let__f,width, height,7,1);
      break;
    case 't':
      let_print(let__t,width, height,5,1);
      break;
    case 'j':
      let_print(let__j,width, height,4,1);
      break;
    case 'h':
      let_print(let__h,width, height,6,1);
      break;
    case 'm':
      let_print(let__m,width, height,5,1);
      break;
    case 'o':
      let_print(let__o,width, height,4,0);
      break;
    case 'z':
      let_print(let__z,width, height,4,1);
      break;
     case 'a':
      let_print(let__a,width, height,5,1);
      break;
     case 'p':
      let_print(let__p,width, height,7,1);
      break;
     case 'r':
      let_print(let__r,width, height,8,1);
      break;
     case 'g':
       let_print(let__g,width, height,6,1);
       break;
     case 'u':
       let_print(let__u,width, height,4,1);
       break;  
     case 'v':
       let_print(let__v,width, height,3,1);
       break; 
     case 'w':
       let_print(let__w,width, height,5,1);
       break; 
     case 'n':
       let_print(let__n,width, height,4,1);
       break;
     case 'k':
       let_print(let__k,width, height,7,1);
       break;
     case 'e':
       let_print(let__e,width, height,7,1);
       break;
     case 'i':
       let_print(let__i,width, height,8,1);
       break;
     case 'l':
       let_print(let__l,width, height,3,1);
       break;
     case 'x':
       let_print(let__x,width, height,8,1);
       break;
     case 'y':
       let_print(let__y,width, height,5,1);
       break;
     case 'q':
       let_print(let__q,width, height,6,0);
       break;
     case ' ':
	move(pos_y,pos_x+width);
	pos_x+=width;
	refresh();
       break;
  //  default:
     // cout << "No found letter" << endl;
  }
};


int main(int argc,char **argv){
  startCurses();
  int height = 6;
  int width =  5;
  int font_size;
    if(argc<1){
   cerr << "No found arguments" << endl;
   exit(-1);
  } else if(argc==3){
    font_size = atoi(argv[2]);
    if((font_size%2)==0)font_size++;
      height=width= font_size;
  }
  char *stringa=argv[1];
  int idx = 0;
  while(stringa[idx]){
    if(isalpha(stringa[idx]) || ispunct(stringa[idx]) || isspace(stringa[idx])){
     draw_letter(tolower(stringa[idx]),width,height); 
    }
    idx++;
  }
  while(char nch=getch()){ printf("%c",nch);}
  endCurses();
}//:~
