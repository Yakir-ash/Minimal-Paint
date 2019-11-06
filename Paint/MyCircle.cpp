#include "StdAfx.h"
#include "MyCircle.h"

IMPLEMENT_SERIAL(MyCircle, MyShape, 1)

MyCircle::MyCircle(void)
{
}


MyCircle::~MyCircle(void)
{
}

void MyCircle::innerDraw(CDC *dc) {
	// d means minimum value of width and height
	int d,dx,dy;
	if(abs(start.x - end.x) < abs(start.y - end.y)) 

		d = abs(start.x - end.x); 
	else
		d = abs(start.y - end.y);

	dx=dy=d;

	if(start.x > end.x) 
		dx = -d;	//dx means width
	if(start.y > end.y) 
		dy = -d;	//dy means height

	//in a circle, abs(dx) = abs(dy) the change between x and y is the same

	dc->Ellipse(start.x, start.y, start.x + dx, start.y + dy);
}

bool MyCircle::inHit(CPoint point) {

	int minx,maxx,miny,maxy,d;

	if(start.x < end.x)

		minx = start.x; 
	else 
		minx = end.x;

	if(start.x > end.x)

		maxx = start.x; 
	else 
		maxx = end.x;
	if(start.y < end.y)	

		miny = start.y; 
	else 
		miny = end.y;
	if(start.y > end.y)

		maxy = start.y;
	else 
		maxy = end.y;
	
	// d means minimum value of width and height
	if(abs(start.x - end.x) < abs(start.y - end.y)) 
	
		d = abs(start.x - end.x); 
	
	else 
		d = abs(start.y - end.y);
	
	if (point.x < minx || point.y < miny || point.x > minx+d || point.y > miny+d) 
		return false;

	return true;
}