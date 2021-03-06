#include <iostream>
#include <windows.h>
#include <string>
#include "graphics.h"
#include "primitives.h"
#include "assets.h"
#include "fx.h"
#include "Mmsystem.h"

#define TRUE 1
#define FALSE 0

int main()                    
{
	int xmax = 0, ymax = 0;
	std::cout << "Please enter the desired resolution." << std::endl;
	std::cout << "Please enter the width, followed by the height in pixels." << std::endl;
	std::cin >> xmax >> ymax;
	initwindow(xmax, ymax, "Archery");
	xmax = getmaxx();
    ymax = getmaxy();
	int y_inc = 1, lives = 5;
	int score = 0, addScore = 0, lastScore = 0;	// Variable for scoring
	int division = 0;					// Variable to divide the target into fixed no. of zones.
	bool flag = false;
	std::string points;					// for displaying the score
	std::string earnedPoint;			// for displaying the current earned point
	std::string livesStr;
	primitives::Point arrowHitPos;		//Point Variable to store the arrow position.

	/**object declarations**/
	primitives::Bow bow;                             
	primitives::Arrow arrow;       
	primitives::Target target;

	
    
	while (1) // Main game loop
	{
		cleardevice();
		score = 0, addScore = 0, lastScore = 0, division = 0, lives = 3;
		flag = false;

		bow = primitives::genInitBow();                             //By default a stretched bow.
        arrow = primitives::genArrow(bow.radius, bow.center);        //scaled in accordance to bow radius origin at bow.center
		target = primitives::genTarget(bow.center);

		drawBow(bow, TRUE);
		drawArrow(arrow.size, bow.center);
		drawTarget(target);
		outtextxy(xmax / 2 - 75, ymax / 2, "Press Space to Play!");
		outtextxy(xmax / 2 - 75, ymax / 2 + 25, "Left click mouse to shoot arrows.");
		if (GetAsyncKeyState(VK_SPACE))
		{
			PlaySound(TEXT("whistle.wav"), NULL, SND_ASYNC);
			delay(1000);
			flag = true;
		}
		while (flag && lives != 0)                 // gameplay loop
		{
			cleardevice();
			if ((bow.center.y - (bow.radius + 10)) <= 5)                  //bound checking for bow  (upper screen) 
				y_inc = 1;
			if ((bow.center.y + bow.radius + 10) >= (ymax - 5))           //bound checking for bow  (lower screen)
				y_inc = -1;

			bow.center.y += y_inc;            //bow translation by modifying bow center
			genBow(bow);                      // regenerating the co-ordinates in response to modified Bow center
			drawBow(bow, TRUE);
			drawArrow(arrow.size, bow.center);
			drawTarget(target);

			/**Score Display**/
			points = std::to_string(score);
			const char *pstr = points.c_str();
			livesStr = std::to_string(lives);
			const char *plives = livesStr.c_str();
			outtextxy(xmax - 170, 50, "Points: ");
			outtextxy(xmax - 100, 50, (char*)pstr); // displays the current score 

			earnedPoint = std::to_string(lastScore);
			const char *pstrAdd = earnedPoint.c_str();
			outtextxy(xmax - 248, 70, "Last Point Earned :");
			outtextxy(xmax - 100, 70, (char*)pstrAdd); // displays the current earned score

			outtextxy(xmax - 168, 90, "Lives :");
			outtextxy(xmax - 100, 90, (char*)plives);

			arrow.arrowLocus.x = bow.center.x;
			arrow.arrowLocus.y = bow.center.y;



			if (ismouseclick(WM_LBUTTONDOWN))                    //occurrence of event is checked
			{
				PlaySound(TEXT("arrow_release.wav"), NULL, SND_ASYNC);
				while (arrow.arrowLocus.x + (8 * arrow.size) <= target.vert.src.x)
				{
					cleardevice();
					arrow.arrowLocus.x = arrow.arrowLocus.x + 5;
					genBow(bow);
					drawBow(bow, FALSE);
					drawArrow(arrow.size, arrow.arrowLocus);
					drawTarget(target);
					points = std::to_string(score);
					const char *pstr = points.c_str();
					outtextxy(xmax - 170, 50, "Points: ");
					outtextxy(xmax - 100, 50, (char*)pstr); // displays the current score 

					earnedPoint = std::to_string(lastScore);
					const char *pstrAdd = earnedPoint.c_str();
					outtextxy(xmax - 248, 70, "Last Point Earned :");
					outtextxy(xmax - 100, 70, (char*)pstrAdd); // displays the current earned score

					outtextxy(xmax - 168, 90, "Lives :");
					outtextxy(xmax - 100, 90, (char*)plives); // displays the no. of lives left
					swapbuffers();
				}
				clearmouseclick(WM_LBUTTONDOWN);    //event is released

				PlaySound(TEXT("target_hit.wav"), NULL, SND_ASYNC);
				arrowHitPos = arrow.arrowLocus;		//Stores the final position of the array
				division = (target.horiz.src.y - target.vert.src.y) / 4;  //Divide the target into 4 zones for scoring

				if (arrowHitPos.y < target.vert.src.y || arrowHitPos.y > target.vert.dst.y)		//If arrow doesn't hit the target
				{
					lastScore = 0;
					--lives;
				}
				else
				{
					if (arrowHitPos.y > target.vert.src.y && arrowHitPos.y < (target.vert.src.y + division))		//If the arrow hits the upper first divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+1");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 1;
						--lives;
					}
					else if (arrowHitPos.y < target.vert.dst.y && arrowHitPos.y >(target.vert.dst.y - division))		//If the arrow hits the lower first divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+1");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 1;
						--lives;
					}
					else if (arrowHitPos.y > target.vert.src.y && arrowHitPos.y < (target.vert.src.y + 2 * division))//If the arrow hits the upper second divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+3");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 3;
						--lives;
					}
					else if (arrowHitPos.y < target.vert.dst.y && arrowHitPos.y >(target.vert.dst.y - 2 * division))	//If the arrow hits the lower second divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+3");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 3;
						--lives;
					}
					else if (arrowHitPos.y > target.vert.src.y && arrowHitPos.y < (target.vert.src.y + 3 * division))//If the arrow hits the upper third divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+5");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 5;
						--lives;
					}
					else if (arrowHitPos.y < target.vert.dst.y && arrowHitPos.y >(target.vert.dst.y - 3 * division))	//If the arrow hits the lower third divided zone of the target
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+5");
						arrowHitPos.x += 9 * arrow.size;
						shockWave(arrowHitPos, 20, 50);
						swapbuffers();
						lastScore = addScore = 5;
						--lives;
					}
					else //If the arrow hits the center
					{
						outtextxy(arrowHitPos.x, arrowHitPos.y + 20, "+7");
						outtextxy(arrowHitPos.x - 50, arrowHitPos.y, "BULLSEYE !!");
						shockWave(target.horiz.src, 20, 50);
						swapbuffers();
						lastScore = addScore = 7;
						++lives;
					}
				}
				score += addScore;
				addScore = 0;
				target.horiz.src.y = rand() % (ymax - 75 - static_cast<int>(ymax / 8)) + static_cast<int>(ymax / 8);
				target = primitives::genTarget(target.horiz.src);
				delay(700);
			}
			swapbuffers();
		}
		if (lives == 0)
		{
			outtextxy(xmax / 2 - 75, ymax / 2, "Game Over!");
			swapbuffers();
			delay(3000);
		}
		swapbuffers();
	}
	closegraph();
	return 0;
}