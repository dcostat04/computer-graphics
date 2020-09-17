#include<iostream.h>
#include <conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2)
{
	int i,option,dx,dy,steps;
	float x,y;
	float xinc,yinc;
	dx=(x2-x1);
	dy=(y2-y1);
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;
	xinc=(float)dx/steps;
	yinc=(float)dy/steps;
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	cout<<"\n1)DASHED\n2)DOTTED\n3)THICK";
	cout<<"\nSELECT AN OPTION:\n";
	cin>>option;
	switch(option)
	{
		case 1:
		for(i=1;i<steps;i++)
		{

			x=x+xinc;
			y=y+yinc;
		if(i%13==0)
			{
				continue;
			}
			putpixel(x,y,RED);
		}
		break;
		case 2:
		for(i=1;i<steps;i++)
		{

			x=x+xinc;
			y=y+yinc;
		if(i%2==0)
			{
				continue;
			}
			putpixel(x,y,RED);
		}
		break;
		case 3:
		for(i=1;i<steps;i++)
		{

			x=x+xinc;
			y=y+yinc;

			putpixel(x,y,RED);
		}
		break;

  }

}
int main()
{
	int gd=DETECT,gm;
	int x1,x2,y1,y2;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();
	cout<<"DDA Line generation algorithm";
	cout<<"\n enter the starting co-ordinates for drawing line";
	cin>>x1>>y1;
	cout<<"\n enter the ending co-ordinates";
	cin>>x2>>y2;
	dda(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
}
