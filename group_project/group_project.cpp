#include<stdio.h>
#include<bangtal.h>

bool landed = false, landed2 = false;  // 각 캐릭터가 땅에 닿았는지
bool right = false, right2 = false;   // 각 캐릭터의 오른쪽 움직임
bool left = false, left2 = false;    //각 캐릭터의 왼쪽 움직임
bool jump = false, jump2 = false;    //각 캐릭터의 점프
bool level1 = true;
bool level2 = false;  //현재 레벨이 2임을 알리는 변수. 오브젝트를 숨겨도 기능이 그대로 남아있어서 이런 기능들을 level2에서만 적용되도록 하기 위해 사용함.
bool level3 = false; //현재 레벨이 3임을 알리는 변수. ~~
float player1X = 45, player1Y = 234, a = 12, b = 0;  //캐릭터1의 위치와 낙하속도
float player2X = 161, player2Y = 234, c = 12, d = 0;  //캐릭터2의 위치와 낙하속도
TimerID timer1;
SceneID scene1;
ObjectID player1, land1, player2, land2, land3, land4, land5;
ObjectID portal1, portal2, but1_on, but1_off, wall1, wall2, wall3, wall4, wall0;
ObjectID but2_on, but2_off, but3_on, but3_off, but4_on, but4_off, spiral, end;  
ObjectID but5_on, but5_off, but6_on, but6_off, but7_on, but7_off, but8_on, but8_off; // level 3 button
ObjectID button1_on, button1_off, button2_on, button2_off;   //level 1 button
int player1X_init = 45, player1Y_init = 234; //player1의 초기위치
int player2X_init = 161, player2Y_init = 234; //player2의 초기위치
int landX[10] = { 34, 805, 1098, 320, 0, 33, 805, 440, 112, 400 }, landY[10] = { 85, 208, 317, 426, 585, 86, 240, 325, 418, 556 }; 
int bottomX[2] = { 22, 21 }, bottomY[2] = { 165, 465 };  //땅의 위치좌표
int portalX[2] = { 40, 0 }, portalY[2] = {85, 585};  
int tpX[4] = { 1006, 1002,1108, 1113 }, tpY[4] = { 165, 465, 165, 465 };  // 포탈 위치 좌표
int buttonX[8] = { 87, 830, 150, 755, 173, 298, 696, 853 }, buttonY[8] = { 575, 426, 575, 426, 150 + 50, 150 + 50, 470 + 200, 470 + 200 };  // 버튼 위치 좌표
int but_X[2] = { 435, 637 }, but_Y[2] = { 165, 165 };
int wall_X = 537, wall_Y = 165;
int wallX[4] = { 948, 1098, 698, 365 }, wallY[4] = { 208, 317, 300, 294 };  // 벽 위치 좌표
int spiralX[6] = { 200, 173, 298, 696, 853, 579 }, spiralY[6] = { 585, 86, 86, 556, 556, 465 }, endX = 320, endY = 426;
int endingX = 1138, endingY = 556;  // level3 성공 위치
int enddingX = 21, enddingY = 465;  // level1 성공 위치

ObjectID CreateObject(const char* image, SceneID scene, int x, int y, bool shown)
{
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) showObject(object);
	return object;
}

void landing()  //player1/2가 땅과 닿아있는 상황에서 landed/2를 활성화 시킨다.
{
	if (level1)
	{
		// player1
		if (bottomX[0] - 60 < player1X && player1X < bottomX[0] + 1250 && bottomY[0] - 50 < player1Y && player1Y < bottomY[0])
		{
			landed = true;
		}
		else if (bottomX[1] - 60 < player1X && player1X < bottomX[1] + 1250 && bottomY[1] - 50 < player1Y && player1Y < bottomY[1])
		{
			landed = true;
		}
		//player2
		if (bottomX[0] - 60 < player2X && player2X < bottomX[0] + 1250 && bottomY[0] - 50 < player2Y && player2Y < bottomY[0])
		{
			landed2 = true;
		}
		else if (bottomX[1] - 60 < player2X && player2X < bottomX[1] + 1250 && bottomY[1] - 50 < player2Y && player2Y < bottomY[1])
		{
			landed2 = true;
		}
	}

	else if (level2)  // 스테이지 2 
	{
		//player1
		if (landX[0] - 60 < player1X && player1X < landX[0] + 1200 && landY[0] - 50 < player1Y && player1Y < landY[0])
		{
			landed = true;
		}
		else if (landX[1] - 60 < player1X && player1X < landX[1] + 200 && landY[1] - 50 < player1Y && player1Y < landY[1])
		{
			landed = true;
		}
		else if (landX[2] - 60 < player1X && player1X < landX[2] + 120 && landY[2] - 50 < player1Y && player1Y < landY[2])
		{
			landed = true;
		}
		else if (landX[3] - 60 < player1X && player1X < landX[3] + 660 && landY[3] - 50 < player1Y && player1Y < landY[3])
		{
			landed = true;
		}
		else if (landX[4] - 60 < player1X && player1X < landX[4] + 252 && landY[4] - 50 < player1Y && player1Y < landY[4])
		{
			landed = true;
		}
		else
			if (jump == false)
			{
				landed = false;
			}

		//player2
		if (landX[0] - 60 < player2X && player2X < landX[0] + 1200 && landY[0] - 50 < player2Y && player2Y < landY[0])
		{
			landed2 = true;
		}
		else if (landX[1] - 60 < player2X && player2X < landX[1] + 200 && landY[1] - 50 < player2Y && player2Y < landY[1])
		{
			landed2 = true;
		}
		else if (landX[2] - 60 < player2X && player2X < landX[2] + 120 && landY[2] - 50 < player2Y && player2Y < landY[2])
		{
			landed2 = true;
		}
		else if (landX[3] - 60 < player2X && player2X < landX[3] + 660 && landY[3] - 50 < player2Y && player2Y < landY[3])
		{
			landed2 = true;
		}
		else if (landX[4] - 60 < player2X && player2X < landX[4] + 252 && landY[4] - 50 < player2Y && player2Y < landY[4])
		{
			landed2 = true;
		}
		else
			if (jump2 == false)
			{
				landed2 = false;
			}
	}

	else if (level3)
	{
		//player1
		if (landX[5] - 60 < player1X && player1X < landX[5] + 1200 && landY[5] - 50 < player1Y && player1Y < landY[5])
		{
			landed = true;
		}
		else if (landX[6] - 60 < player1X && player1X < landX[6] + 270 && landY[6] - 50 < player1Y && player1Y < landY[6])
		{
			landed = true;
		}
		else if (landX[7] - 60 < player1X && player1X < landX[7] + 230 && landY[7] - 50 < player1Y && player1Y < landY[7])
		{
			landed = true;
		}
		else if (landX[8] - 60 < player1X && player1X < landX[8] + 220 && landY[8] - 50 < player1Y && player1Y < landY[8])
		{
			landed = true;
		}
		else if (landX[9] - 60 < player1X && player1X < landX[9] + 830 && landY[9] - 50 < player1Y && player1Y < landY[9])
		{
			landed = true;
		}
		else
			if (jump == false)
			{
				landed = false;
			}

		//player2
		if (landX[5] - 60 < player2X && player2X < landX[5] + 1200 && landY[5] - 50 < player2Y && player2Y < landY[5])
		{
			landed2 = true;
		}
		else if (landX[6] - 60 < player2X && player2X < landX[6] + 270 && landY[6] - 50 < player2Y && player2Y < landY[6])
		{
			landed2 = true;
		}
		else if (landX[7] - 60 < player2X && player2X < landX[7] + 230 && landY[7] - 50 < player2Y && player2Y < landY[7])
		{
			landed2 = true;
		}
		else if (landX[8] - 60 < player2X && player2X < landX[8] + 220 && landY[8] - 50 < player2Y && player2Y < landY[8])
		{
			landed2 = true;
		}
		else if (landX[9] - 60 < player2X && player2X < landX[9] + 830 && landY[9] - 50 < player2Y && player2Y < landY[9])
		{
			landed2 = true;
		}
		else
			if (jump2 == false)
			{
				landed2 = false;
			}

	}
}

void gravity() //landed/2가 flase인 동안 b/d의 가속도로 떨어지도록 하는 함수
{
	//player1
	if (landed == false)
	{
		player1Y = player1Y - b;
		locateObject(player1, scene1, int(player1X), int(player1Y));
		if (b <= 20) b = b + 0.5f;  //속도가 20이 될 때 까지 속도를 점차 빠르게 만든다.
	}
	else b = 0;  //땅에 닿으면 속도 초기화

	//player2
	if (landed2 == false)
	{
		player2Y = player2Y - d;
		locateObject(player2, scene1, int(player2X), int(player2Y));
		if (d <= 20) d = d + 0.5f;  //속도가 20이 될 때 까지 속도를 점차 빠르게 만든다.
	}
	else d = 0;  //땅에 닿으면 속도 초기화
}

void teleport()   // 포탈에 닿으면 이동하는 함수
{
	if (level1)
	{
		if (tpX[0] - 50 < player1X && player1X < tpX[0] + 20 && tpY[0] - 80 < player1Y && player1Y < tpY[0] + 50)
		{
			player1X = tpX[1] - 100, player1Y = tpY[1] ;
		}
		else if (tpX[1] - 50 < player1X && player1X < tpX[1] + 20 && tpY[1] - 80 < player1Y && player1Y < tpY[1] + 50)
		{
			player1X = tpX[0] - 100, player1Y = tpY[0] ;
		}
		else if (tpX[2] - 50 < player2X && player2X < tpX[2] + 20 && tpY[2] - 80 < player2Y && player2Y < tpY[2] + 50)
		{
			player2X = tpX[3] - 100, player2Y = tpY[3];
		}
		else if (tpX[3] - 50 < player2X && player2X < tpX[3] + 20 && tpY[3] - 80 < player2Y && player2Y < tpY[3] + 50)
		{
			player2X = tpX[2] - 100, player2Y = tpY[2];
		}
	}

	else if (level2)
	{
		if (portalX[0] - 50 < player2X && player2X < portalX[0] + 20 && portalY[0] - 80 < player2Y && player2Y < portalY[0] + 50)
		{
			player2X = portalX[1] + 100, player2Y = portalY[1] + 50;
		}
		else if (portalX[1] - 20 < player2X && player2X < portalX[1] + 20 && portalY[1] - 80 < player2Y && player2Y < portalY[1] + 50)
		{
			player2X = portalX[0] + 100, player2Y = portalY[0] + 50;
		}
	}	
}

void buttonPress()  
{
	if(level1)
	{
		if (but_X[0] - 40 < player1X && player1X < but_X[0] + 20 && but_Y[0] - 20 < player1Y && player1Y < but_Y[0] + 10 )
		{
			hideObject(button1_off);
			showObject(button1_on);
			hideObject(wall0);
			wall_X = 1280, wall_Y = 720;
		}
		else
		{
			hideObject(button1_on);
			showObject(button1_off);
			showObject(wall0);
			wall_X = 537, wall_Y = 165;
		}

		if ( but_X[1] - 40 < player2X && player2X < but_X[1] + 20 && but_Y[1] - 20 < player2Y && player2Y < but_Y[1] + 10)
		{
			hideObject(button2_off);
			showObject(button2_on);
			hideObject(wall0);
			wall_X = 1280, wall_Y = 720;
		}
		else
		{
			hideObject(button2_on);
			showObject(button2_off);
		}
	}

	else if (level2)
	{
		//버튼1: player2가 wall1을 동작, 버튼2: player1이 wall1을 동작
		if (buttonX[0] - 40 < player2X && player2X < buttonX[0] + 20 && buttonY[0] - 20 < player2Y && player2Y < buttonY[0] + 10)
		{
			showObject(but1_on);
			hideObject(but1_off);
			hideObject(wall1);
			wallX[0] = 1280, wallY[0] = 720;
		}
		else if (buttonX[1] - 40 < player1X && player1X < buttonX[1] + 20 && buttonY[1] - 20 < player1Y && player1Y < buttonY[1] + 10)
		{

		}
		else
		{
			showObject(but1_off);
			hideObject(but1_on);
			showObject(wall1);
			wallX[0] = 948, wallY[0] = 208;
		}
		if (buttonX[1] - 40 < player1X && player1X < buttonX[1] + 20 && buttonY[1] - 20 < player1Y && player1Y < buttonY[1] + 10)
		{
			showObject(but2_on);
			hideObject(but2_off);
			hideObject(wall1);
			wallX[0] = 1280, wallY[0] = 720;
		}
		else if (buttonX[0] - 40 < player2X && player2X < buttonX[0] + 20 && buttonY[0] - 20 < player2Y && player2Y < buttonY[0] + 10)
		{

		}
		else
		{
			showObject(but2_off);
			hideObject(but2_on);
			showObject(wall1);
			wallX[0] = 948, wallY[0] = 208;
		}

		//버튼3: player2가 wall2를 동작, 버튼4: player1이 wall2를 동작
		if (buttonX[2] - 40 < player2X && player2X < buttonX[2] + 20 && buttonY[2] - 20 < player2Y && player2Y < buttonY[2] + 10)
		{
			showObject(but3_on);
			hideObject(but3_off);
			hideObject(wall2);
			wallX[1] = 1280, wallY[1] = 720;
		}
		else if (buttonX[3] - 40 < player1X && player1X < buttonX[3] + 20 && buttonY[3] - 20 < player1Y && player1Y < buttonY[3] + 10)
		{

		}
		else
		{
			showObject(but3_off);
			hideObject(but3_on);
			showObject(wall2);
			wallX[1] = 1098, wallY[1] = 317;
		}
		if (buttonX[3] - 40 < player1X && player1X < buttonX[3] + 20 && buttonY[3] - 20 < player1Y && player1Y < buttonY[3] + 10)
		{
			showObject(but4_on);
			hideObject(but4_off);
			hideObject(wall2);
			wallX[1] = 1280, wallY[1] = 720;
		}
		else if (buttonX[2] - 40 < player2X && player2X < buttonX[2] + 20 && buttonY[2] - 20 < player2Y && player2Y < buttonY[2] + 10)
		{

		}
		else
		{
			showObject(but4_off);
			hideObject(but4_on);
			showObject(wall2);
			wallX[1] = 1098, wallY[1] = 317;
		}
	}

	else if (level3) 
	{
		// 버튼5: player1이 wall3 동작, 버튼7: player2가 wall3 동작
		if (buttonX[4] - 50 < player1X && player1X < buttonX[4] + 30 && buttonY[4] - 50 < player1Y && player1Y < buttonY[4] + 40)
		{
			showObject(but5_on);
			hideObject(but5_off);
			hideObject(wall3);
			wallX[2] = 1280, wallY[2] = 720;
		}
		else if (buttonX[6] - 50 < player2X && player2X < buttonX[6] + 30 && buttonY[6] < player2Y && player2Y < buttonY[6] + 90)
		{

		}
		else
		{
			showObject(but5_off);
			hideObject(but5_on);
			showObject(wall3);
			wallX[2] = 698, wallY[2] = 300;
		}

		if (buttonX[6] - 50 < player2X && player2X < buttonX[6] + 30 && buttonY[6] < player2Y && player2Y < buttonY[6] + 90)
		{
			showObject(but7_on);
			hideObject(but7_off);
			hideObject(wall3);
			wallX[2] = 1280, wallY[2] = 720;
		}
		else if (buttonX[4] - 50 < player1X && player1X < buttonX[4] + 30 && buttonY[4] - 50 < player1Y && player1Y < buttonY[4] + 40)
		{

		}
		else
		{
			showObject(but7_off);
			hideObject(but7_on);
			showObject(wall3);
			wallX[2] = 698, wallY[2] = 300;
		}

		// 버튼6: player1이 wall4 동작, 버튼8: player2가 wall4 동작
		if (buttonX[5] - 50 < player1X && player1X < buttonX[5] + 30 && buttonY[5] - 50 < player1Y && player1Y < buttonY[5] + 40)
		{
			showObject(but6_on);
			hideObject(but6_off);
			hideObject(wall4);
			wallX[3] = 1280, wallY[3] = 720;
		}
		else if (buttonX[7] - 50 < player2X && player2X < buttonX[7] + 30 && buttonY[7] < player2Y && player2Y < buttonY[7] + 90)
		{

		}
		else
		{
			showObject(but6_off);
			hideObject(but6_on);
			showObject(wall4);
			wallX[3] = 365, wallY[3] = 294;
		}

		if (buttonX[7] - 50 < player2X && player2X < buttonX[7] + 30 && buttonY[7] < player2Y && player2Y < buttonY[7] + 90)
		{
			showObject(but8_on);
			hideObject(but8_off);
			hideObject(wall4);
			wallX[3] = 1280, wallY[3] = 720;
		}
		else if (buttonX[5] - 50 < player1X && player1X < buttonX[5] + 30 && buttonY[5] - 50 < player1Y && player1Y < buttonY[5] + 40)
		{

		}
		else
		{
			showObject(but8_off);
			hideObject(but8_on);
			showObject(wall4);
			wallX[3] = 365, wallY[3] = 294;
		}
	}
}

void blockwall()  // 벽에 막혀서 지나가지 못하게 하는 함수
{
	if (level1)
	{
		if (wall_X - 60 < player1X && player1X < wall_X + 50 && wall_Y - 80 < player1Y && player1Y < wall_Y + 110)
		{
			player1X = wall_X - 70;
		}
		else if (wall_X - 60 < player2X && player2X < wall_X + 50 && wall_Y - 80 < player2Y && player2Y < wall_Y + 110)
		{
			player2X = wall_X - 70;
		}
	}

	else if (level2)
	{
		if (wallX[0] - 60 < player1X && player1X < wallX[0] + 50 && wallY[0] - 80 < player1Y && player1Y < wallY[0] + 150)
		{
			player1X = wallX[0] - 70;
		}
		else if (wallX[0] - 60 < player2X && player2X < wallX[0] + 50 && wallY[0] - 80 < player2Y && player2Y < wallY[0] + 150)
		{
			player2X = wallX[0] - 70;
		}
		if (wallX[1] - 60 < player1X && player1X < wallX[1] + 50 && wallY[1] - 80 < player1Y && player1Y < wallY[1] + 150)
		{
			player1X = wallX[1] - 70;
		}
		else if (wallX[1] - 60 < player2X && player2X < wallX[1] + 50 && wallY[1] - 80 < player2Y && player2Y < wallY[1] + 150)
		{
			player2X = wallX[1] - 70;
		}
	}

	else if (level3)
	{
		if (wallX[2] - 40 < player1X && player1X < wallX[2] + 30 && wallY[2] - 60 < player1Y && player1Y < wallY[2] + 150)
		{
			player1X = wallX[2] + 30;
		}
		else if (wallX[2] - 40 < player2X && player2X < wallX[2] + 30 && wallY[2] - 60 < player2Y && player2Y < wallY[2] + 150)
		{
			player2X = wallX[2] + 30;
		}

		if (wallX[3] - 40 < player1X && player1X < wallX[3] + 30 && wallY[3] - 60 < player1Y && player1Y < wallY[3] + 150)
		{
			player1X = wallX[3] + 30;
		}
		else if (wallX[3] - 40 < player2X && player2X < wallX[3] + 30 && wallY[3] - 60 < player2Y && player2Y < wallY[3] + 150)
		{
			player2X = wallX[3] + 30;
		}
	}
}

void spiral_event()
{
	if (level1) //레벨 1 가시
	{
		if (spiralX[5] - 47 < player1X && player1X < spiralX[5] + 65 && spiralY[5] - 20 < player1Y && player1Y < spiralY[5] + 30)
		{
			showMessage("가시에 부딪혀 재시작합니다.");
			player1X = 45; player1Y = 215;
			player2X = 161; player2Y = 215;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall0);
		}
		else if (spiralX[5] - 47 < player2X && player2X < spiralX[5] + 65 && spiralY[5] - 20 < player2Y && player2Y < spiralY[5] + 30)
		{
			showMessage("가시에 부딪혀 재시작합니다.");
			player1X = 45; player1Y = 215;
			player2X = 161; player2Y = 215;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall0);
		}
	}

	else if (level2)  // 레벨 2 가시 
	{
		if (spiralX[0] - 47 < player2X && player2X < spiralX[0] + 37 && spiralY[0] - 20 < player2Y && player2Y < spiralY[0] + 100)
		{
			showMessage("가시에 부딪혀 재시작합니다.");
			player1X = player1X_init; player1Y = player1Y_init;
			player2X = player2X_init; player2Y = player2Y_init;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall1);
			showObject(wall2);
		}
	}
	else if (level3)  //레벨 3 가시
	{
		for (int i = 1; i < 5; i++)
		{
			if (spiralX[i] - 47 < player1X && player1X < spiralX[i] +15 && spiralY[i] - 20 < player1Y && player1Y < spiralY[i] + 20)
			{
				showMessage("가시에 부딪혀 재시작합니다.");
				player1X = 40, player1Y = 166;
				player2X = 100, player2Y = 166;
				locateObject(player1, scene1, int(player1X), int(player1Y));
				locateObject(player2, scene1, int(player2X), int(player2Y));
				a = 12; b = 0; c = 12; d = 0;
				showObject(wall3); showObject(wall4);
			}

			else if (spiralX[i] - 47 < player2X && player2X < spiralX[i] + 15 && spiralY[i] - 20 < player2Y && player2Y < spiralY[i] + 20)
			{
				showMessage("가시에 부딪혀 재시작합니다.");
				player1X = 40, player1Y = 166;
				player2X = 100, player2Y = 166;
				locateObject(player1, scene1, int(player1X), int(player1Y));
				locateObject(player2, scene1, int(player2X), int(player2Y));
				a = 12; b = 0; c = 12; d = 0;
				showObject(wall3); showObject(wall4);
			}
		}
	}
}

void level_clear()
{
	if (level1)
	{
		if (enddingX - 50 < player1X && player1X < enddingX + 50 && enddingY - 30 < player1Y && player1Y < enddingY + 100 && enddingX - 50 < player2X && player2X < enddingX + 50 && enddingY - 30 < player2Y && player2Y < enddingY + 100)
		{
			player1X = 147, player1Y = 170;
			player2X = 292, player2Y = 170;
			setSceneImage(scene1, "level2.png");
			locateObject(player1, scene1, 147, 170);
			locateObject(player2, scene1, 292, 170);
			hideObject(button1_off); hideObject(button1_on); hideObject(button2_off); hideObject(button2_on);
			hideObject(wall0); // level1에서 쓰인 오브젝트 전부 숨기기

			/*showObject(but1_on);*/ showObject(but1_off); /*showObject(but2_on);*/ showObject(but2_off);
			/*showObject(but3_on);*/ showObject(but3_off); /*showObject(but4_on);*/ showObject(but4_off);
			showObject(wall1); showObject(wall2);  //level2에서 쓰일 오브젝트 전부 보이기
			level1 = false; level2 = true;  // 레벨 1 클리어 후에 레벨 2로 바뀜
			startTimer(timer1);
		}
	}

	else if (level2)
	{
		if (endX - 50 < player1X && player1X < endX + 50 && endY - 30 < player1Y && player1Y < endY + 100 && endX - 50 < player2X && player2X < endX + 50 && endY - 30 < player2Y && player2Y < endY + 100)
		{
			player1X = 40; player1Y = 166;
			player2X = 100; player2Y = 166;
			setSceneImage(scene1, "level3.png");  //문자열에 다음 레벨의 이미지를 넣으세요
			locateObject(player1, scene1, 40, 166); // 다음 레벨의 player1의 위치를 넣으세요
			locateObject(player2, scene1, 100, 166); // 다음 레벨의 player2의 위치를 넣으세요
			hideObject(but1_on); hideObject(but2_on); hideObject(but3_on); hideObject(but4_on);
			hideObject(but1_off); hideObject(but2_off); hideObject(but3_off); hideObject(but4_off);
			hideObject(wall1); hideObject(wall2);  //level2에서 쓰인 오브젝트 전부 숨기기

			showObject(but5_on); showObject(but5_off); showObject(but6_on); showObject(but6_off);
			showObject(but7_on); showObject(but7_off); showObject(but8_on); showObject(but8_off);
			showObject(wall3); showObject(wall4);  // level3에서 쓰이는 오브젝트 전부 보이기
			land1 = false; land2 = false;
			level2 = false; // 현재 레벨이 2가 아님을 알리기 위해 사용.현재 버튼, 벽, 가시에 사용되었음.그 밖에도 필요하면 사용 바람
			level3 = true;  // 레벨 2 클리어 후에 레벨 3로 바뀜.
			startTimer(timer1);
		}
	}

	else if (level3)  // level 3 성공
	{
		if (endingX - 50 < player1X && player1X < endingX + 50 && endingY - 30 < player1Y && player1Y < endingY + 100 && endingX - 50 < player2X && player2X < endingX + 50 && endingY - 30 < player2Y && player2Y < endingY + 100)
		{
			setSceneImage(scene1, "white.png");
			hideObject(but5_on); hideObject(but5_off); hideObject(but6_on); hideObject(but6_off);
			hideObject(but7_on); hideObject(but7_off); hideObject(but8_on); hideObject(but8_off);
			hideObject(wall3); hideObject(wall4);
			hideObject(player1); hideObject(player2);
			showMessage("플레이 해 주셔서 감사합니다!!");
		}
	}
	
}

void timerCallback(TimerID timer)
{
	//player1 움직임 코드
	if (right && jump == false) //점프하지 않고 오른쪽 이동
	{
		player1X = player1X + 4;
		locateObject(player1, scene1, int(player1X), int(player1Y));
	}
	else if (left && jump == false) //점프하지 않고 왼쪽 이동
	{
		player1X = player1X - 4;
		locateObject(player1, scene1, int(player1X), int(player1Y));
	}
	else if (jump && right == false && left == false) //좌우 이동 없이 점프
	{
		if (landed)
		{
			player1Y = player1Y + a;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			a = a - 0.5f;  //올라가는 속도를 점점 낮춤
			if (a == 0)
			{
				jump = false;
				a = 12;
				landed = false; //올라가는 속도가 0이 되면 jump를 끄고 속도 초기화. landed를 flase로 바꿔 중력을 작용시켜 떨어뜨림.
			}
		}
	}
	else if (jump && right)  //점프하면서 오른쪽으로 이동
	{
		if (landed)
		{
			player1X = player1X + 4;
			player1Y = player1Y + a;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			a = a - 0.5f;
			if (a == 0)
			{
				jump = false;
				a = 12;
				landed = false;
			}
		}
	}
	else if (jump && left)  //점프하면서 왼쪽으로 이동
	{
		if (landed)
		{
			player1X = player1X - 4;
			player1Y = player1Y + a;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			a = a - 0.5f;
			if (a == 0)
			{
				jump = false;
				a = 12;
				landed = false;
			}
		}
	}

	//player2 움직임 코드.  세부 내용은 위와 동일
	if (right2 && jump2 == false)
	{
		player2X = player2X + 4;
		locateObject(player2, scene1, int(player2X), int(player2Y));
	}
	else if (left2 && jump2 == false)
	{
		player2X = player2X - 4;
		locateObject(player2, scene1, int(player2X), int(player2Y));
	}
	else if (jump2 && right2 == false && left2 == false)
	{
		if (landed2)
		{
			player2Y = player2Y + c;
			locateObject(player2, scene1, int(player2X), int(player2Y));
			c = c - 0.5f;
			if (c == 0)
			{
				jump2 = false;
				c = 12;
				landed2 = false;
			}
		}
	}
	else if (jump2 && right2)
	{
		if (landed2)
		{
			player2X = player2X + 4;
			player2Y = player2Y + c;
			locateObject(player2, scene1, int(player2X), int(player2Y));
			c = c - 0.5f;
			if (c == 0)
			{
				jump2 = false;
				c = 12;
				landed2 = false;
			}
		}
	}
	else if (jump2 && left2)
	{
		if (landed2)
		{
			player2X = player2X - 4;
			player2Y = player2Y + c;
			locateObject(player2, scene1, int(player2X), int(player2Y));
			c = c - 0.5f;
			if (c == 0)
			{
				jump2 = false;
				c = 12;
				landed2 = false;
			}
		}
	}

	landing();
	gravity();
	teleport();
	buttonPress();
	blockwall();
	spiral_event();
	level_clear();
	setTimer(timer1, 0.01f);
	startTimer(timer1);
}

void keyboardCallback(KeyCode key, KeyState state)
{
	//player1 키보드 조작. wasd 조작
	if (key == KeyCode::KEY_D && state == KeyState::KEY_PRESSED)
	{
		right = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_D && state == KeyState::KEY_RELEASED)
	{
		right = false;
	}
	else if (key == KeyCode::KEY_A && state == KeyState::KEY_PRESSED)
	{
		left = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_A && state == KeyState::KEY_RELEASED)
	{
		left = false;
	}
	else if (key == KeyCode::KEY_W && state == KeyState::KEY_PRESSED)
	{
		jump = true;
	}
	//player2 키보드 조작.  방향키로 조작
	else if (key == KeyCode::KEY_RIGHT_ARROW && state == KeyState::KEY_PRESSED)
	{
		right2 = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_RIGHT_ARROW && state == KeyState::KEY_RELEASED)
	{
		right2 = false;
	}
	else if (key == KeyCode::KEY_LEFT_ARROW && state == KeyState::KEY_PRESSED)
	{
		left2 = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_LEFT_ARROW && state == KeyState::KEY_RELEASED)
	{
		left2 = false;
	}
	else if (key == KeyCode::KEY_UP_ARROW && state == KeyState::KEY_PRESSED)
	{
		jump2 = true;
	}
	else if (key == KeyCode::KEY_R && state == KeyState::KEY_PRESSED)  //r키를 누르면 모든 속도를 초기화 하고, player1/2를 초기 위치로 되돌림
	{
		if (level1)
		{
			showMessage("재시작합니다.");
			player1X = player1X_init; player1Y = player1Y_init;
			player2X = player2X_init; player2Y = player2Y_init;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall0);
		}
		else if (level2)
		{
			showMessage("재시작합니다.");
			player1X = 147, player1Y = 170;
			player2X = 292, player2Y = 170;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall1); showObject(wall2);
		}
		else if (level3)
		{
			showMessage("재시작합니다.");
			player1X = 40, player1Y = 166;
			player2X = 100, player2Y = 166;
			locateObject(player1, scene1, int(player1X), int(player1Y));
			locateObject(player2, scene1, int(player2X), int(player2Y));
			a = 12; b = 0; c = 12; d = 0;
			showObject(wall3); showObject(wall4);
		}
		
	}
}


int main()
{
	setTimerCallback(timerCallback);
	setKeyboardCallback(keyboardCallback);
	scene1 = createScene("map1", "level1.png");
	button1_off = CreateObject("standard_button.png", scene1, but_X[0], but_Y[0], true);
	button1_on = CreateObject("pressed_button.png", scene1, but_X[0], but_Y[0], false);
	button2_off = CreateObject("standard_button.png", scene1, but_X[1], but_Y[1], true);
	button2_on = CreateObject("pressed_button.png", scene1, but_X[1], but_Y[1], false);

	but1_off = CreateObject("standard_button.png", scene1, buttonX[0], buttonY[0], false);
	but1_on = CreateObject("pressed_button.png", scene1, buttonX[0], buttonY[0], false);
	but2_off = CreateObject("standard_button.png", scene1, buttonX[1], buttonY[1], false);
	but2_on = CreateObject("pressed_button.png", scene1, buttonX[1], buttonY[1], false);
	but3_off = CreateObject("standard_button.png", scene1, buttonX[2], buttonY[2], false);
	but3_on = CreateObject("pressed_button.png", scene1, buttonX[2], buttonY[2], false);
	but4_off = CreateObject("standard_button.png", scene1, buttonX[3], buttonY[3], false);
	but4_on = CreateObject("pressed_button.png", scene1, buttonX[3], buttonY[3], false);

	but5_off = CreateObject("standard_button.png", scene1, buttonX[4], buttonY[4], false);
	but5_on = CreateObject("pressed_button.png", scene1, buttonX[4], buttonY[4], false);
	but6_off = CreateObject("standard_button.png", scene1, buttonX[5], buttonY[5], false);
	but6_on = CreateObject("pressed_button.png", scene1, buttonX[5], buttonY[5], false);
	but7_off = CreateObject("standard_button.png", scene1, buttonX[6], buttonY[6], false);
	but7_on = CreateObject("pressed_button.png", scene1, buttonX[6], buttonY[6], false);
	but8_off = CreateObject("standard_button.png", scene1, buttonX[7], buttonY[7], false);
	but8_on = CreateObject("pressed_button.png", scene1, buttonX[7], buttonY[7], false);

	player1 = CreateObject("1player.png", scene1, int(player1X), int(player1Y), true);
	player2 = CreateObject("2player.png", scene1, int(player2X), int(player2Y), true);
	wall0 = CreateObject("wall.png", scene1, wall_X, wall_Y, true);
	wall1 = CreateObject("wall.png", scene1, wallX[0], wallY[0], false);
	wall2 = CreateObject("wall.png", scene1, wallX[1], wallY[1], false);
	wall3 = CreateObject("wall.png", scene1, wallX[2], wallY[2], false);
	wall4 = CreateObject("wall.png", scene1, wallX[3], wallY[3], false);

	timer1 = createTimer(0.01f);
	showMessage("검정 캐릭터는 wasd, 하얀 캐릭터는 방향키로 움직입니다. 재시작은 r키입니다.");
	startTimer(timer1);
	startGame(scene1);
	
	return 0;
}