#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include <dos.h>

void sad()
{
	arc(300,300,0,180,40);

	setfillstyle(SOLID_FILL,WHITE );
	circle(250,210,15);
	floodfill(250,210,WHITE);

	setfillstyle(SOLID_FILL,WHITE );
	circle(350,210,15);
	floodfill(350,210,WHITE);
}

void happy()
{
	arc(300,260,180,360,40);
	
	setfillstyle(SOLID_FILL,LIGHTRED);
	circle(250,210,15);
	floodfill(250,210,WHITE);

	setfillstyle(SOLID_FILL,LIGHTRED);
	circle(350,210,15);
	floodfill(350,210,WHITE);
}
void main()
{
	int gd=DETECT,gm,i;
 	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(i!=3){
		cout<<" 1:Happy\n 2:Sad\n 3: exit\n Enter one option from the above\n";
		cin>>i;
		setfillstyle(SOLID_FILL,YELLOW );
	 	circle(300,230,100);
	 	floodfill(300,230,WHITE);
	 	
	 	line(300,215,300,240);

		
	    switch (i)
	    {
	    case 1 :
	        happy();
	        break;
	    
	    case 2 :
	        sad();
	        break;
	    }
	    delay(2500);
	    cleardevice();
	}
	
	 getch();
	closegraph();


}
