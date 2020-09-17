#include<iostream.h>
#include<graphics.h>
#include<dos.h>

void boundaryfill(int x,int y,int f_color,int b_color);
void floodfill(int x,int y,float f_color);

void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
	}
}
void floodFill(int x,int y,int oldcolor,int newcolor)
{
	if(getpixel(x,y) == oldcolor)
	{
		putpixel(x,y,newcolor);
		floodFill(x+1,y,oldcolor,newcolor);
		floodFill(x,y+1,oldcolor,newcolor);
		floodFill(x-1,y,oldcolor,newcolor);
		floodFill(x,y-1,oldcolor,newcolor);
	}
}

int main()
{
	int gm,gd=DETECT,radius;
	int x,y;
	int c=0;
	cout<<"Enter x and y positions for circle\n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>radius;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

circle (x,y,radius);
while(c!=3){
	cout<<" 1:Boundaryfill\n 2:Floodfill\n Enter one option from the above\n";
	cin>>c;

	
    switch (c)
    {
    case 1 :
        boundaryfill(x,y,11,15);
        break;
    
    case 2 :
        floodFill(x,y,15,4);
        break;;
    }
	}
	
	delay(2);
	closegraph();

	return 0;
}
