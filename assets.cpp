#include "assets.h"
#include "graphics.h"
#include <cstdio>

namespace primitives
{

/**********************************************ASSETS FOR FOOTBALL PROJECT***************************************************/	
	
	Humanoid genHumanoid(const Point &p)
	{
		//restraints to be included to make sure the object is within the window limits
		Humanoid h1;
		int x, y, r;

		//head
		h1.head.center.x = p.x;
		h1.head.center.y = p.y;
		h1.head.radius = 40;
		circle(h1.head.center.x, h1.head.center.y, h1.head.radius);

		x = h1.head.center.x;
		y = h1.head.center.y;
		r = h1.head.radius;

		//neck
		h1.neck.tL.x = x - (r / 3);
		h1.neck.tL.y = y + r - 4;
		h1.neck.bR.x = x + (r / 3);
		h1.neck.bR.y = y + r + 20 - 4;
		rectangle(h1.neck.tL.x, h1.neck.tL.y, h1.neck.bR.x, h1.neck.bR.y);

		//torso
		h1.torso.tL.x = x - r;
		h1.torso.tL.y = y + r + 20 - 4;
		h1.torso.bR.x = x + r;
		h1.torso.bR.y = y + r + 20 + (2 * r + 20) - 4;
		rectangle(h1.torso.tL.x, h1.torso.tL.y, h1.torso.bR.x, h1.torso.bR.y);

		//rHand;
		//lHand;
		//rLeg;
		//lLeg;

		return h1; // returning reference to the humanoid type object generated by the function
	}
	
	void genFootball(const Circle &ball)
    	{

    		Point point,poly1,poly2,poly3,poly4,poly5,poly6;
        	setcolor(15); // Light Red
		circle(ball.center.x, ball.center.y, ball.radius); //Circle drawn

		poly1.x=ball.center.x-8;
		poly1.y=ball.center.y-(ball.radius-1);
		poly2.x=ball.center.x-4;
		poly2.y=ball.center.y-(ball.radius-8);
		poly3.x=ball.center.x+4;
		poly3.y=ball.center.y-(ball.radius-8);
		poly4.x=ball.center.x+8;
		poly4.y=ball.center.y-(ball.radius-1);
		int polygon2[8]={poly1.x,poly1.y,poly2.x,poly2.y,poly3.x,poly3.y,poly4.x,poly4.y};
		drawpoly(4,polygon2);

		poly1.x=ball.center.x+(ball.radius-1);
		poly1.y=ball.center.y-8;
		poly2.x=ball.center.x+(ball.radius-8);
		poly2.y=ball.center.y-4;
		poly3.x=ball.center.x+(ball.radius-8);
		poly3.y=ball.center.y+4;
		poly4.x=ball.center.x+(ball.radius-1);
		poly4.y=ball.center.y+8;

		int polygon3[8]={poly1.x,poly1.y,poly2.x,poly2.y,poly3.x,poly3.y,poly4.x,poly4.y};
		drawpoly(4,polygon3);


    		poly1.x=ball.center.x-(ball.radius-1);
		poly1.y=ball.center.y-8;
		poly2.x=ball.center.x-(ball.radius-8);
		poly2.y=ball.center.y-4;
		poly3.x=ball.center.x-(ball.radius-8);
		poly3.y=ball.center.y+4;
		poly4.x=ball.center.x-(ball.radius-1);
		poly4.y=ball.center.y+8;

		int polygon4[8]={poly1.x,poly1.y,poly2.x,poly2.y,poly3.x,poly3.y,poly4.x,poly4.y};
		drawpoly(4,polygon4);

    		poly1.x=ball.center.x-8;
		poly1.y=ball.center.y+(ball.radius-1);
		poly2.x=ball.center.x-4;
		poly2.y=ball.center.y+(ball.radius-8);
		poly3.x=ball.center.x+4;
		poly3.y=ball.center.y+(ball.radius-8);
		poly4.x=ball.center.x+8;
		poly4.y=ball.center.y+(ball.radius-1);
		int polygon5[8]={poly1.x,poly1.y,poly2.x,poly2.y,poly3.x,poly3.y,poly4.x,poly4.y};
		drawpoly(4,polygon5);

    		setfillstyle(SOLID_FILL,LIGHTGRAY);
		floodfill(ball.center.x, ball.center.y,15);

    		poly1.x=ball.center.x-4;
		poly1.y=ball.center.y-8;
		poly2.x=ball.center.x+4;
		poly2.y=ball.center.y-8;
		poly3.x=ball.center.x+8;
		poly3.y=ball.center.y;
		poly4.x=ball.center.x+4;
		poly4.y=ball.center.y+8;
		poly5.x=ball.center.x-4;
		poly5.y=ball.center.y+8;
		poly6.x=ball.center.x-8;
		poly6.y=ball.center.y;
		int polygon[14]={poly1.x,poly1.y,poly2.x,poly2.y,poly3.x,poly3.y,poly4.x,poly4.y,poly5.x,poly5.y,poly6.x,poly6.y,poly1.x,poly1.y};
		drawpoly(7,polygon);

	 	setfillstyle(SOLID_FILL,RED);
		floodfill(ball.center.x, ball.center.y,15);

    	}

	void genRods(const int &X, const int &Y)
	{
        	setcolor(15);
    		primitives :: Rectangle rod1,rod2;
    		rod1.tL.x = X;
        	rod1.tL.y = 0;
        	rod1.bR.y = Y;
        	rod1.bR.x = rod1.tL.x+50;
        	rod2.tL.x = rod1.tL.x;
        	rod2.bR.x = rod1.bR.x;
        	rod2.bR.y = getmaxy();
        	rod2.tL.y = rod1.bR.y+100;
        	rectangle(rod1.tL.x,rod1.tL.y,rod1.bR.x,rod1.bR.y);
        	rectangle(rod2.tL.x,rod2.tL.y,rod2.bR.x,rod2.bR.y);
	}

	Rectangle getRectangle(const int &topLeftX, const int &topLeftY, const int &bottomRightX, const int &bottomRightY)
	{
		Rectangle rect;
		rect.tL.x = topLeftX;
		rect.tL.y = topLeftY;
		rect.bR.x = bottomRightX;
		rect.bR.y = bottomRightY;
		rect.center.x = (topLeftX + bottomRightX) / 2; // potential overflow bug
		rect.center.y = (topLeftY + bottomRightY) / 2;
		rect.width = bottomRightX - topLeftX;
		rect.height = bottomRightY - topLeftY;
		return rect;
	}
	
	void genGoalPost()
	{

		primitives::Line top,reaR,bottom,front;
		int maxx=getmaxx();
		int maxy=getmaxy();
		top.src.x=maxx*2/3;
		top.src.y=maxy*1/4;
		top.dst.x=maxx*5/6;
		top.dst.y=maxy*1/4;
		front.src.x=maxx*2/3;
		front.src.y=maxy*1/4;
		front.dst.x=maxx*2/3;
		front.dst.y=maxy;
		reaR.src.x=maxx*5/6;
		reaR.src.y=maxy*1/4;
		reaR.dst.x=maxx;
		reaR.dst.y=maxy*3/4;
		bottom.src.x=maxx*2/3;
		bottom.src.y=maxy;
		bottom.dst.x=maxx;
		bottom.dst.y=maxy;

		setlinestyle(0,0,20);
		line(top.src.x,top.src.y,top.dst.x,top.dst.y);//top bar//
		setlinestyle(0,0,20);
		line(reaR.src.x,reaR.src.y,reaR.dst.x,reaR.dst.y);//rear post//
		setlinestyle(0,0,20);
		line(front.src.x,front.src.y,front.dst.x,front.dst.y);//front post//
		setlinestyle(0,0,20);
		line(bottom.src.x,bottom.src.y,bottom.dst.x,bottom.dst.y);//bottom//
		setfillstyle(HATCH_FILL,WHITE);
		floodfill((maxx*2/3)+30,(maxy*1/4)+20,WHITE);
	}
	
	
/***********************************************ASSETS FOR ARCHERY PROJECT**************************************************/

	
	
	Bow genInitBow()
	{
                                                //https://www.cs.colorado.edu/~main/bgi/doc/arc.html
                                                //https://www.cs.colorado.edu/~main/bgi/doc/getarccoords.html
		Bow bow;
		int xmax = getmaxx();
		int ymax = getmaxy();
		
		bow.radius = xmax / 16; 
		bow.center.x = bow.radius / 3;
 		bow.center.y = ymax / 2;
        setcolor(WHITE);
        struct arccoordstype arcinfo;
        setlinestyle(0 , 0 , 7);             //set line style function is not for arcs but the thickness parameter works successfully
		arc(bow.center.x , bow.center.y , 290 , 70 , bow.radius);
 		getarccoords(&arcinfo);              //fetching the endpoints of the last drawn arc
        bow.midy = ( arcinfo.ystart + 5 + arcinfo.yend - 5 ) / 2;

        /*co-ordinates for upper part of the string*/

        	bow.uString.src.x = arcinfo.xstart;
        	bow.uString.src.y = arcinfo.ystart+5;
        	bow.uString.dst.x = arcinfo.xstart;
        	bow.uString.dst.y = bow.midy;

       	//co-ordinates for lower part of the string
        	bow.lString.src.x = arcinfo.xend;
        	bow.lString.src.y = bow.midy+1;
        	bow.lString.dst.x = arcinfo.xend;
        	bow.lString.dst.y = arcinfo.yend-4;
 		return bow;                          // returning reference to the Bow type object generated by the function
	}

	Bow genBow(Bow &bow)
	{
		//https://www.cs.colorado.edu/~main/bgi/doc/arc.html
		//https://www.cs.colorado.edu/~main/bgi/doc/getarccoords.html
		               // this needs to be a parameter - this still needs to be decoupled from system resolution. Please consider sending it as an artist controllable parameter
		setcolor(WHITE);
		struct arccoordstype arcinfo;
		setlinestyle(0, 0, 7);             //set line style function is not for arcs but the thickness parameter works successfully
		arc(bow.center.x, bow.center.y, 290, 70, bow.radius);
		getarccoords(&arcinfo);              //fetching the endpoints of the last drawn arc
		bow.midy = (arcinfo.ystart + 5 + arcinfo.yend - 5) / 2;

		/*co-ordinates for upper part of the string*/

		bow.uString.src.x = arcinfo.xstart;
		bow.uString.src.y = arcinfo.ystart + 5;
		bow.uString.dst.x = arcinfo.xstart;
		bow.uString.dst.y = bow.midy;

		//co-ordinates for lower part of the string
		bow.lString.src.x = arcinfo.xend;
		bow.lString.src.y = bow.midy;
		bow.lString.dst.x = arcinfo.xend;
		bow.lString.dst.y = arcinfo.yend - 4;
		return bow;                          // returning reference to the Bow type object generated by the function
	}
	void drawInitBow(Bow &bow) // pass by reference please
	{

        	setcolor(BLUE);
        	setlinestyle(0 , 0 , 8);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius - 1);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius - 2);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius - 3);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius + 3);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius + 2);
        	arc(bow.center.x , bow.center.y , 350 , 10 , bow.radius + 1);

        	setlinestyle(0 , 0 , 1);
			int trans = (bow.radius / 3) * (-1);
        	/*Function call for a stretched bow.*/
        	translatePoint(bow.uString.dst , trans , 0);
        	translatePoint(bow.lString.src , trans , 0);


        	line(bow.uString.src.x , bow.uString.src.y , bow.uString.dst.x , bow.uString.dst.y);
        	line(bow.lString.src.x , bow.lString.src.y , bow.lString.dst.x , bow.lString.dst.y);
	}
	void drawBow(Bow &bow) // pass by reference please
	{

		setcolor(BLUE);
		setlinestyle(0, 0, 8);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius - 1);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius - 2);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius - 3);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius + 3);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius + 2);
		arc(bow.center.x, bow.center.y, 350, 10, bow.radius + 1);

		setlinestyle(0, 0, 1);

		line(bow.uString.src.x, bow.uString.src.y, bow.uString.dst.x, bow.uString.dst.y);
		line(bow.lString.src.x, bow.lString.src.y, bow.lString.dst.x, bow.lString.dst.y);
	}
	Arrow genArrow(const Point &p,int &bowRadius)  //body to size ratio is 10:1
	{
                                    	     //restraints to be included to make sure the object is within the window limits
        	Arrow aro;
        	aro.p = p;
        	aro.size = bowRadius * 3 / 20;
        	return aro;                 //returning reference to the Arrow type object generated by the function
	}
	void drawArrow(Arrow &arrow)
	{
        	setlinestyle(0 , 0 , 1);
        	setcolor(WHITE);
        	moveto(arrow.p.x , arrow.p.y);                                   //https://www.cs.colorado.edu/~main/bgi/doc/moveto.html
        	linerel(10 * arrow.size, 0);     //linerel(int dx,int dy)      //https://www.cs.colorado.edu/~main/bgi/doc/linerel.html

        	//head part of the arrow

        	linerel(-2 * arrow.size , -1 * arrow.size + 1);
        	linerel(0 , 2 * arrow.size - 1);
        	linerel(2 * arrow.size , -1 * arrow.size);

        	//tail part of the arrow

        	moveto(arrow.p.x + 15 , arrow.p.y);
        	arrow.size = arrow.size - 3;

        	linerel(-2 * arrow.size , -1 * arrow.size + 1);
        	linerel(0 , 2 * arrow.size - 1);
        	linerel(2 * arrow.size , -1 * arrow.size);
    	}
	void drawInitArrow(const Point bowCenter, Arrow &arrow)                     //handle to the existing arrow and the center of the bow                                    
	{
		setlinestyle(0, 0, 1);
		setcolor(WHITE);
		moveto(bowCenter.x, bowCenter.y);                                   //https://www.cs.colorado.edu/~main/bgi/doc/moveto.html
		linerel(10 * arrow.size, 0);     //linerel(int dx,int dy)     //https://www.cs.colorado.edu/~main/bgi/doc/linerel.html

									   //head part of the arrow

		linerel(-2 * arrow.size, -1 * arrow.size + 1);
		linerel(0, 2 * arrow.size - 1);
		linerel(2 * arrow.size, -1 * arrow.size);

		//tail part of the arrow

		moveto(bowCenter.x + 3, bowCenter.y);
		arrow.size = arrow.size - 3;

		linerel(-2 * arrow.size, -1 * arrow.size + 1);
		linerel(0, 2 * arrow.size - 1);
		linerel(2 * arrow.size, -1 * arrow.size);
	}
	Target genTarget(const Point &p)
    	{
        	Target targ;
        	targ.vert.src.x = p.x;
        	targ.vert.src.y = p.y;
        	targ.vert.dst.x = p.x;
        	targ.vert.dst.y = p.y + 125;
        	targ.horiz.src.x = (targ.vert.src.x + targ.vert.dst.x)/2;
        	targ.horiz.src.y = (targ.vert.src.y + targ.vert.dst.y)/2;
        	targ.horiz.dst.x = targ.horiz.src.x + 80;
        	targ.horiz.dst.y = targ.horiz.src.y;
        	return targ;
    	}
    	void drawTarget(Target targ) // consider sending as const reference if this function isn't a mutator
    	{
        	setlinestyle(0,0,5);
        	line(targ.vert.src.x,targ.vert.src.y,targ.vert.dst.x,targ.vert.dst.y);
        	setlinestyle(0,0,5);
        	line(targ.horiz.src.x,targ.horiz.src.y,targ.horiz.dst.x,targ.horiz.dst.y);
        	setlinestyle(0,0,3);
        	arc(targ.horiz.src.x,targ.horiz.src.y,90,270,12);
    	}


}

/* int main()                  // test football
{
    initwindow(480,480);
    primitives::Circle ball;
    std::cout << "Please enter the coordinates for the initial position of the ball (x,y)." << std::endl;
	std::cin >> ball.center.x >> ball.center.y;
	std::cout << "Please enter the radius of the ball." << std::endl;
	std::cin >> ball.radius;
    football(ball);
	system("pause");
}
/*int main()                    //test humanoid
{
    initwindow(480,480);
    primitives::Humanoid h1;
    primitives::Point temp;
    printf(" enter x,y \n");
    scanf("%d%d",&temp.x,&temp.y);
    h1 = primitives::genHumanoid(temp);
    getch();
}*/

/*int main()                    //Test Target
{
    initwindow(800,480);
    primitives::Point tar;
    primitives::Target targ1;
    tar.x = 710;
    tar.y = 40;
    targ1 = genTarget(tar);
    drawTarget(targ1);
}
*/

/*int main()                    //Test Arrow and Bow
{
    initwindow(800,480);
    primitives::Point p;
    primitives::Arrow arrow;
    primitives::Bow bow;
    p.x = 24;
    p.y = 100;
    int size = 15;
    arrow = genArrow(p,size);
    bow = primitives::genBow();        //By default a stretched bow.
    primitives::drawTransBow(bow);
	primitives::drawInitArrow(bow.center,arrow);
    getch();
}


*/