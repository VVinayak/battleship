#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<strstream.h>
#include<stdlib.h>
#include<DOS.h>
#define CLIP_ON 1
void battletime();//players tactics manager
void load(); //loading page
void final();//exit screen
void rules();
void gameplay();//main function managing game environment
void nmsc(); //name storage page
void sleep(unsigned seconds);
void comppos();//computers positions & tactics
int flag=0,a,hits=0,loss=0,points=500,level,temp,templ;
char name[30];
int i,j,k,l,m,n,b;
int poly1[8],poly2[8],poly3[8],poly4[8],cheat[4][8],poly[8]; //cheat gives the positions
		 // of the player directly to compiler
int main()
{
restart:
clrscr();
int gdriver = DETECT, gmode;
int midx, midy;
initgraph(&gdriver, &gmode, "");
midx = getmaxx() / 2;
midy = getmaxy() / 2;
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
outtextxy(midx, midy-50, "Battleship");
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(midx-5, midy+50, "....Strategy without tactics is the slowest route to victory.");
outtextxy(midx-5,midy+80," Tactics without strategy is the noise before defeat....");
outtextxy(midx+240,midy+110, "- Sun Tzu");
sleep(4);
cleardevice();
char option;
int choice;
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(midx,80,"...Because wars are fought on the best guesses and strategies...");
outtextxy(midx+2,180,"1. New Battle ");
outtextxy(midx-12,230,"2. Rules   ");
outtextxy(midx,280,"3. Exit      ");
settextstyle(SMALL_FONT,HORIZ_DIR, 5);
outtextxy(midx+150,400,"Designed and developed by Vineet Vinayak");
option=getch();
switch(option)
   {
   case '1':load();
	    nmsc();
	    gameplay();   //takes you to playfield
	    load();
	    if(flag)
	      {
	      flag=0;
	      goto restart;
	      }
	    break;

   case '2':load();
	    rules();
	    if(flag==1)
	      {
	      flag=0;
	      goto restart; //to return the user back to the main page
	      }
	    getch();
	    break;

   case '3':final();
	    if(flag)         //to exit
	      {
	      flag=0;
	      goto restart;
	      }
	    getch();
	    break;

   default:goto restart;
   }
closegraph();
getch();
return 0;
}

void load()
{
clrscr();
int gdriver = DETECT, gmode;
int style, midx, midy;
long int loop;
midx = getmaxx() / 2;
midy = getmaxy() / 2;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLACK);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(midx-50,midy-50,"LOADING");
for(loop=0;loop<200000000;++loop);  //time delay loops
outtextxy(midx-25,midy-25,".");     //printing loading dots
for(loop=0;loop<200000000;++loop);
outtextxy(midx-15,midy-25,".");
for(loop=0;loop<200000000;++loop);
outtextxy(midx-5,midy-25,".");
for(loop=0;loop<200000000;++loop);
outtextxy(midx+5,midy-25,".");
for(loop=0;loop<200000000;++loop);
outtextxy(midx+15,midy-25,".");
sleep(1);
closegraph();
}

void final()
{
char ch;
clrscr();
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLACK);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(getmaxx()/2-153,getmaxy()/2-20,"Would you like to exit the game (y/n)?");
ch=getch();  //so that the comp directly takes him through next action
if(ch=='y'||ch=='Y')       // instead of waiting for him to press enter
  exit(0);     //the user doesnt see his typed stuff on the output screen
else
  flag=1;
closegraph();
}

void rules()
{
clrscr();
char opt;
int gdriver = DETECT, gmode;
int style, midx, midy;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLACK);  //initializing black bground
cout<<"                                 RULES\n";
cout<<"BATTLEFIELD is a basic strategy game which tests the guessing, strategic and    tactical skills of a person. "
    <<"In this game, the player is a navy general whose   sole purpose is to destroy all the enemy's (General Alexander)"
    <<" frigates before the  enemy destroys yours. The more accurate your guesses, the quicker you defeat your enemy "
    <<"and higher is your score. As a player you are given 2 fields, one    showing the position of your troops and the other,"
    <<" the field of General Alexander. Only you don't know where your enemy's frigates lie!! You gotta guess their positions "
    <<"before they guess yours!! \n";
cout<<"\n 1. Your troops are represented by blue blocks. Alexander's hits turn blocks in your field brown. If you hit one of Alexander's frigates', "
    <<"   then that block in the  second field turns red. For every miss, the block turns white.\n"
    <<"\n 2. For every miss you lose 100 points, but for every hit you gain 1000 points. You start with 500 points. So the faster "
    <<"   you get those frigates, the more points you get.\n"
    <<"\n 3. Choose strategic positions for your frigates, that keeps Alexander guessing. But "
    <<"   no 2 frigates can be within a block of each other (that is important while guessing your enemies' frigates "
    <<"   positions'!). \n"
    <<"\n 4. Your turn alternates with that of Alexander's. Each frigate occupies 1 block, so don't waste time searching for a 2nd hit in the immediate "
    <<"   vicinity of a    frigate you just hit! \n";
cout<<"\n Press W if you are prepared for war, General !!!\n";
opt=getch();
if(opt=='w'||opt=='W')
  flag=1;
closegraph();
}

void nmsc()
{
reenter:
clrscr();
cout<<endl<<endl;
cout<<"Please enter the following details :\n";
cout<<endl;
cout<<"NAME:";              //play loading page
gets(name);
cout<<"\nLEVEL(1-4):";
cin>>level;
if(level>4||level<1)
  {
  cout<<"\nINVALID LEVEL !!!";
  sleep(2);
  goto reenter;
  }
name[0]=toupper(name[0]);
clrscr();
int gdriver = DETECT, gmode;
int style, midx, midy;
initgraph(&gdriver, &gmode, "");
midx = getmaxx() / 2;
midy = getmaxy() / 2;
settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
setbkcolor(BLACK);
outtextxy(midx-150,midy-20,"...Preparing battle armour...");
sleep(4);
outtextxy(midx-130,midy+30," Get Ready General!!! ");
sleep(2);
closegraph();
}

void gameplay()
{
clrscr();
char col1='A',row1='A',dir,temp1[4],temp2[4];
int gdriver = DETECT, gmode;
points=500;
initgraph(&gdriver, &gmode, "");
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
outtextxy(100,60,"General ");
outtextxy(165,60,name);
outtextxy(410,60,"General Alexander ");
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
outtextxy(60,112,"A");
outtextxy(60,137,"B");
outtextxy(60,162,"C");
outtextxy(60,187,"D");      //printing nos. along rows
outtextxy(60,212,"E");
outtextxy(60,237,"F");
outtextxy(60,262,"G");
outtextxy(60,287,"H");
outtextxy(370,112,"A");
outtextxy(370,137,"B");
outtextxy(370,162,"C");
outtextxy(370,187,"D");
outtextxy(370,212,"E");
outtextxy(370,237,"F");
outtextxy(370,262,"G");
outtextxy(370,287,"H");
outtextxy(82,75,"A");
outtextxy(107,75,"B");
outtextxy(132,75,"C");
outtextxy(157,75,"D");      //printing nos. along columns
outtextxy(182,75,"E");
outtextxy(207,75,"F");
outtextxy(232,75,"G");
outtextxy(257,75,"H");
outtextxy(392,75,"A");
outtextxy(417,75,"B");
outtextxy(442,75,"C");
outtextxy(467,75,"D");
outtextxy(492,75,"E");
outtextxy(517,75,"F");
outtextxy(542,75,"G");
outtextxy(567,75,"H");
line (70,100,270,100);
line (380,100,580,100);
line (70,100,70,300);
line(270,100,270,300);
line(70,300,270,300);
line(380,100,380,300);
line(580,100,580,300);
line(380,300,580,300);
line(70,125,270,125);
line(70,150,270,150);
line(70,175,270,175);
line(70,200,270,200);           //drawing matrices
line(70,225,270,225);
line(70,250,270,250);
line(70,275,270,275);
line(95,100,95,300);
line(120,100,120,300);
line(145,100,145,300);
line(170,100,170,300);
line(195,100,195,300);
line(220,100,220,300);
line(245,100,245,300);
line(380,125,580,125);
line(380,150,580,150);
line(380,175,580,175);
line(380,200,580,200);
line(380,225,580,225);
line(380,250,580,250);
line(380,275,580,275);
line(405,100,405,300);
line(430,100,430,300);
line(455,100,455,300);
line(480,100,480,300);
line(505,100,505,300);
line(530,100,530,300);
line(555,100,555,300);
for(a=0;a<4;++a)
 {
  getcolrow:
  setviewport(120,320,getmaxx()-120,getmaxy()-50,CLIP_ON);
  outtextxy(95,0,"Enter the row of the Frigate");
  row1=getch();
  clearviewport();
  row1=toupper(row1);
  setviewport(120,320,getmaxx()-120,getmaxy()-50,CLIP_ON);
  outtextxy(90,0,"Enter the column of the Frigate");
  col1=getch();
  clearviewport();
  col1=toupper(col1);
  temp1[a]=row1;
  temp2[a]=col1;
  if(a!=0)
    {
    for(i=0;i<a;++i)
       {
       if(temp1[i]==temp1[a]||temp1[i]==temp1[a]-1||temp1[i]==temp1[a]+1)
	 {
	 if(temp2[i]==temp2[a]||temp2[i]==temp2[a]-1||temp2[i]==temp2[a]+1)
	   {
	   setviewport(120,320,getmaxx()-100,getmaxy()-50,CLIP_ON);
	   outtextxy(95,0,"Please enter a valid column and row ");
	   sleep(2);
	   clearviewport();               //checking if the inputed block
	   goto getcolrow;               //is within a block of a previously
	   }                            //inputed one
	 }
       else if(temp2[i]==temp2[a]||temp2[i]==temp2[a]+1||temp2[i]==temp2[a]-1)
	    {
	     if(temp1[i]==temp1[a]||temp1[i]==temp1[a]-1||temp1[i]==temp1[a]+1)
	      {
	      setviewport(120,320,getmaxx()-100,getmaxy()-50,CLIP_ON);
	      outtextxy(95,0,"Please enter a valid column and row ");
	      sleep(2);
	      clearviewport();
	      goto getcolrow;
	      }
	    }
       }
    }
  int nur1=row1;
  nur1-=64;
  int nuc1=col1;
  nuc1-=64;
  setviewport(0,0,getmaxx(),getmaxy(),CLIP_ON);
  poly[0] = 70+((nuc1-1)*25);
  poly[1] = 100+((nur1-1)*25);
  poly[2] = poly[0]+25;
  poly[3] = poly[1];
  if(poly[2]>270)
    poly[2]-=50;
  if(poly[2]<70)
    poly[2]+=50;
  if(poly[3]<100)
    poly[3]+=50;
  if(poly[3]>300)
    poly[3]-=50;
  poly[4] = poly[2];
  poly[5] = poly[3]+25;
  if(poly[4]>270)
    poly[4]-=50;
  if(poly[4]<70)
    poly[4]+=50;
  if(poly[5]<100)
    poly[5]+=50;
  if(poly[5]>300)
    poly[5]-=50;
  poly[6] = poly[4]-25;
  poly[7] = poly[5];   //accepting start positions
  if(poly[6]>270)
    poly[6]-=50;
  if(poly[6]<70)
    poly[6]+=50;
  if(poly[7]<100)
    poly[7]+=50;
  if(poly[7]>300)
    poly[7]-=50;
  for(l=0;l<8;++l)
     {
     cheat[a][l]=poly[l];
     }
  setfillstyle(XHATCH_FILL,BLUE);
  fillpoly(4, poly);
  floodfill(poly[0],poly[1],WHITE);
  }

sleep(1);
for(b=1;(hits<4&&loss<4);++b)
   {
   battletime();
   comppos();
   }
settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
setviewport(120,320,getmaxx()-80,getmaxy()-50,CLIP_ON);
if(hits>=4)
  {
  hits=0;
  loss=0;
  outtextxy(24,0,name);
  outtextxy(24,20,"has defeated Alexander the Great!!!");
  }
else if(loss>=4)
  {
  hits=0;
  loss=0;
  outtextxy(24,0,"...Alexander remains the king of the seas...");
  }
outtextxy(24,40,"Points scored:");
gotoxy(35,24);
cout<<points;
sleep(7);
clearviewport();
flag=1;
closegraph();
}

void comppos()
{
templ=loss;
setviewport(0,0,getmaxx(),getmaxy(),CLIP_ON);
static int mood=0;
mood+=25;
if((mood/5)==90)
  {
  setfillstyle(XHATCH_FILL,BROWN);
  fillpoly(4, cheat[0]);
  floodfill(cheat[0][0],cheat[0][1],WHITE);
  ++loss;
  }
else if((mood/5)==75)
  {
  setfillstyle(XHATCH_FILL,BROWN);
  fillpoly(4, cheat[1]);
  floodfill(cheat[1][0],cheat[1][1],WHITE);
  ++loss;
  }
else if((mood/5)==50)
  {
  setfillstyle(XHATCH_FILL,BROWN);
  fillpoly(4, cheat[2]);
  floodfill(cheat[2][0],cheat[2][1],WHITE);
  ++loss;
  }
else if((mood/5)==20)
  {
  setfillstyle(XHATCH_FILL,BROWN);
  fillpoly(4, cheat[3]);
  floodfill(cheat[3][0],cheat[3][1],WHITE);
  ++loss;
  }
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setviewport(120,320,getmaxx()-80,getmaxy()-50,CLIP_ON);
if(templ==loss-1)
  outtextxy(115,0,"ALEXANDER STRIKES!!!");
else
  outtextxy(120,0,"ALEXANDER MISSES...");
sleep(2);
clearviewport();
}

void battletime()
{
char rowat,colat;
int polyattack[8];
int nurat,nucat;
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
setviewport(120,320,getmaxx()-80,getmaxy()-50,CLIP_ON);
outtextxy(72,0,"Enter the row you want to attack ");
rowat=getch();
clearviewport();
rowat=toupper(rowat);
setviewport(120,320,getmaxx()-80,getmaxy()-50,CLIP_ON);
outtextxy(64,0,"Enter the column you want to attack ");
colat=getch();
clearviewport();
colat=toupper(colat);
nurat=rowat;
nurat-=64;
nucat=colat;
nucat-=64;
setviewport(0,0,getmaxx(),getmaxy(),CLIP_ON);
polyattack[0]=380+((nucat-1)*25);
polyattack[1]=100+((nurat-1)*25);
polyattack[2] = polyattack[0]+25;
polyattack[3] = polyattack[1];
polyattack[4] = polyattack[2];
polyattack[5] = polyattack[3]+25;
polyattack[6] = polyattack[4]-25;
polyattack[7] = polyattack[5];   //accepting start positions
temp=hits;
switch(level)
      {
      case 2:poly1[0] = 405;
	     poly1[1] = 125;
	     poly2[0] = 430;
	     poly2[1] = 225;
	     poly3[0] = 505;
	     poly3[1] = 225;
	     poly4[0] = 530;
	     poly4[1] = 125;
	     break;

      case 1:poly1[0] = 380;
	     poly1[1] = 100;
	     poly2[0] = 555;
	     poly2[1] = 100;
	     poly3[0] = 480;
	     poly3[1] = 175;
	     poly4[0] = 455;
	     poly4[1] = 275;
	     break;

      case 3:poly1[0] = 430;
	     poly1[1] = 125;
	     poly2[0] = 405;
	     poly2[1] = 225;
	     poly3[0] = 455;
	     poly3[1] = 250;
	     poly4[0] = 530;
	     poly4[1] = 275;
	     break;

      case 4:poly1[0] = 455;
	     poly1[1] = 125;
	     poly2[0] = 530;
	     poly2[1] = 150;
	     poly3[0] = 480;
	     poly3[1] = 200;
	     poly4[0] = 430;
	     poly4[1] = 250;
	     break;

      }
poly1[2] = poly1[0]+25;
poly1[3] = poly1[1];
poly1[4] = poly1[2];
poly1[5] = poly1[3]+25;
poly1[6] = poly1[4]-25;
poly1[7] = poly1[5];
poly2[2] = poly2[0]+25;
poly2[3] = poly2[1];
poly2[4] = poly2[2];
poly2[5] = poly2[3]+25;
poly2[6] = poly2[4]-25;
poly2[7] = poly2[5];
poly3[2] = poly3[0]+25;
poly3[3] = poly3[1];
poly3[4] = poly3[2];
poly3[5] = poly3[3]+25;
poly3[6] = poly3[4]-25;
poly3[7] = poly3[5];
poly4[2] = poly4[0]+25;
poly4[3] = poly4[1];
poly4[4] = poly4[2];
poly4[5] = poly4[3]+25;
poly4[6] = poly4[4]-25;
poly4[7] = poly4[5];
if(polyattack[1]==poly1[1]&&polyattack[0]==poly1[0])
  {
     setfillstyle(XHATCH_FILL,RED);
     fillpoly(4, poly1);
     floodfill(poly1[0],poly1[1],WHITE);
     ++hits;
  }
else if(polyattack[1]==poly2[1]&&polyattack[0]==poly2[0])
  {
     setfillstyle(XHATCH_FILL,RED);
     fillpoly(4, poly2);
     floodfill(poly2[0],poly2[1],WHITE);
     ++hits;
  }
else if(polyattack[1]==poly3[1]&&polyattack[0]==poly3[0])
  {
     setfillstyle(XHATCH_FILL,RED);
     fillpoly(4, poly3);
     floodfill(poly3[0],poly3[1],WHITE);
     ++hits;
  }
else if(polyattack[1]==poly4[1]&&polyattack[0]==poly4[0])
  {
     setfillstyle(XHATCH_FILL,RED);
     fillpoly(4, poly4);
     floodfill(poly4[0],poly4[1],WHITE);
     ++hits;
  }
else
  {
     setfillstyle(XHATCH_FILL,WHITE);
     fillpoly(4, polyattack);
     floodfill(polyattack[0],polyattack[1],WHITE);
  }
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setviewport(120,320,getmaxx()-80,getmaxy()-50,CLIP_ON);
if(temp==hits-1)
  {
  outtextxy(180,0,"HIT!!!");
  points+=1000;
  }
else if(temp==hits)
  {
  outtextxy(180,0,"MISS...");
  points-=100;
  }
sleep(2);
clearviewport();
}
