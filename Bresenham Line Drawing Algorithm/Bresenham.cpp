#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
void bres(int x1, int y1, int x2, int y2, int choice)
{
	int dx, dy, p;
	int x, y;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	x=x1;
	y=y1;
	putpixel(x,y,WHITE);
	int i;
	for(i=0; i<=dx; i++)
	{
	switch(choice)
	{
		case 1:{
			putpixel(x,y,WHITE);
			break;
		}
		case 2:{
			if(i%2==0)
			{
			putpixel(x,y,WHITE);
			}
			break;
		}
		case 3:
			if(i%7!=0)
			{
				putpixel(x,y,WHITE);
			}
	}
	x=x+1;
	if(p<0)
	{
	y=y;
	p=p+2*dy;	
	}
	else{
		y=y+1;
		p=p+2*dy-2*dx;
	}
  }
}
void main()
{         clrscr();
int gd= DETECT, gm;
int x1,y1,x2,y2,choice;
initgraph( &gd, &gm,"C:\\TURBOC3\\BGI");
cleardevice();
cout<<"\n Bresenham's' Line Generating Algorithm";
cout<<"\n MAIN MENU ";
cout<<"\n 1.Thick Line";
cout<<"\n 2.Dotted Line";
cout<<"\n 3.Dashed Line";
cout<<"\n Enter choice:";
cin>>choice;
cout<<"\n Starting Co-ordinates:";
cin>>x1>>y1;
cout<<"\n Ending Co-ordinates:";
cin>>x2>>y2;
bres(x1,y1,x2,y2,choice);
getch();
closegraph();
}
