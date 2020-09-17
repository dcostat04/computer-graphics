#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#define PI 3.14
#define ORIGX 150
#define ORIGY 150

float pt[3][4] = {200, 250, 250, 200,
		        225, 225, 250, 250,
		        1,   1,   1,   1};
float pre[3][4];

void drawRec(float[3][4]);
void translate(float,float);
void rotate(float);
void scale(float, float);
void mat_mult(float[3][3]);
void setPre();
void drawAxis();
void reflect(int, int);
void shear(int, int);

int main(){
	int gd = DETECT, gm;
	int ch, temp;
	float x, y;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	drawAxis();
	setcolor(RED);
	drawRec(pt);
	do{
		cleardevice();
		cout << "MAIN MENU\n\n1. Translate\n2. Rotate\n3. Scale\n4. Reflect\n5. Shear\n6. Exit\n\n\n- ";
		cin >> ch;
		clrscr();
		cleardevice();
		if(ch == 4 || ch == 5){
			if(ch == 4){
				cout << "Reflect about -\n1. X-axis\n2. Y-axis\n3. Origin\n\n- ";
			} else {
				cout << "Shear -\n1. X direction\n2. Y direction\n\n- ";
			}
			cin >> temp;
			ch *= 10;
			ch += temp;
		}
		clrscr();
		cleardevice();
		drawAxis();
		setcolor(RED);
		drawRec(pt);
		setPre();
		switch(ch){
			case 1: cout << "Enter x parameter - ";
				cin >> x;
				cout << "Enter y parameter - ";
				cin >> y;
				translate(x,y);
				break;
			case 2: cout << "Enter angle - ";
				cin >> x;
				rotate(x);
				break;
			case 3: cout << "Enter x parameter - ";
				cin >> x;
				cout << "Enter y parameter - ";
				cin >> y;
				scale(x,y);
				break;
			case 41:reflect(-1, 1);
				break;
			case 42:reflect(1, -1);
				break;
			case 43:reflect(-1, -1);
				break;
			case 51:cout << "Enter x argument - ";
				cin >> x;
				shear(x, 0);
				break;
			case 52:cout << "Enter y argument - ";
				cin >> y;
				shear(0, y);
				break;
			case 6: cout << "Exiting program...";
				break;
			default: cout << "Error - Invalid choice";
		}
		clrscr();
		cleardevice();
		drawAxis();
		setcolor(YELLOW);
		if(ch != 6) drawRec(pre);
		setcolor(RED);
		drawRec(pt);
		getch();
	}while(ch != 6);

	closegraph();
	clrscr();

	return 0;
}

void drawRec(float rec[3][4]){
	int x1 = rec[0][0], x2 = rec[0][1], x3 = rec[0][2], x4 = rec[0][3];
	int y1 = rec[1][0], y2 = rec[1][1], y3 = rec[1][2], y4 = rec[1][3];
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);
}

void drawAxis(){
	setcolor(WHITE);
	line(ORIGX-300, ORIGY, ORIGX+300, ORIGY);
	line(ORIGX, ORIGY-300, ORIGX, ORIGY+300);
}

void setPre(){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			pre[i][j] = pt[i][j];
		}
	}
}

void translate(float tx, float ty){
	float tMat[3][3] = {1, 0, tx,
			    0, 1, ty,
			    0, 0, 1};
	mat_mult(tMat);
}

void rotate(float x){
	float tx = (pt[0][0]+pt[0][1]+pt[0][2]+pt[0][3])/4;
	float ty = (pt[1][0]+pt[1][1]+pt[1][2]+pt[1][3])/4;
	translate(-tx, -ty);
	float rMat[3][3] = {1, 0, 0,
			    0, 1, 0,
			    0, 0, 1};
	x = x*PI/180;
	rMat[0][0] = cos(x);
	rMat[0][1] = -sin(x);
	rMat[1][0] = sin(x);
	rMat[1][1] = cos(x);

	mat_mult(rMat);

	translate(tx, ty);
}

void scale(float sx, float sy){
	float tx = (pt[0][0]+pt[0][1]+pt[0][2]+pt[0][3])/4;
	float ty = (pt[1][0]+pt[1][1]+pt[1][2]+pt[1][3])/4;
	translate(-tx,-ty);
	float sMat[3][3] = {sx, 0, 0,
			    0, sy, 0,
			    0, 0, 1};
	mat_mult(sMat);
	translate(tx,ty);
}

void reflect(int x, int y){
	float tx = ORIGX;
	float ty = ORIGY;
	translate(-tx,-ty);
	float ref[3][3] = {x, 0, 0,
			   0, y, 0,
			   0, 0, 1};
	mat_mult(ref);
	translate(tx, ty);
}

void shear(int shx, int shy){
	float tx = (pt[0][0]+pt[0][1]+pt[0][2]+pt[0][3])/4;
	float ty = (pt[1][0]+pt[1][1]+pt[1][2]+pt[1][3])/4;
	translate(-tx,-ty);
	float shMat[3][3] = {1,  shx, 0,
			     shy, 1,  0,
			     0,   0,  1};
	mat_mult(shMat);
	translate(tx, ty);
}

void mat_mult(float mat[3][3]){
	float temp[3][4], val;
	int i, j, k;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			temp[i][j] = pt[i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			val = 0;
			for(k = 0; k < 3; k++){
				val += (mat[i][k] * temp[k][j]);
			}
			pt[i][j] = val;
		}
	}
}
