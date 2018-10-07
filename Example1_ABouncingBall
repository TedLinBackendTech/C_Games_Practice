#include <stdio.h>
#include <stdlib.h>
// To use time library of C
#include <time.h>
#include <windows.h>
void delay(int number_of_seconds);
int main()
{
    int i,j;
    int x0 = 0;
    int Velocity_X =1;
    int Velocity_Y =1;
	  int y = 10;
	  int line_ball_located_X = 5;
   	int line_ball_located_Y = 8;

    int bottom = 25;
    int top = 0;
    int left = 25;
    int right = 0;


    while(1)
    {
        system("cls");


        line_ball_located_X = line_ball_located_X + Velocity_X;//更新位置X
        line_ball_located_Y = line_ball_located_Y + Velocity_Y;//更新位置X
        printf("line_ball_located_X(%d);line_ball_located_Y(%d)",line_ball_located_X,line_ball_located_Y);
        UI_show(bottom,left);
        gotoxy(1,1);
        /*垂直是行 左右是空白*/
        for (i=1;i<line_ball_located_X;i = i + 1)
                printf("\n");/*第幾次就印幾行空白*/


        printf("|");
        for (j=1;j<line_ball_located_Y;j++)
                printf(" ");

        printf("o");
        printf("\n");

        if(line_ball_located_X == bottom||line_ball_located_X == top)
                Velocity_X = -Velocity_X;

        if(line_ball_located_Y == right||line_ball_located_Y == left)
                Velocity_Y = -Velocity_Y;
        //delay(1);
    }


    return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 500 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;

}

void UI_show(int UI_hight, int UI_width )
{
    int i,j,k;

    /*從第1行開始畫，遇到頭跟尾就補橫槓 其餘放空白 */
    printf("\n");
    for(j = 0;j<=UI_width;j++)
    {
        printf("|");

        if(j == 0|| j == UI_width)
        {
            for(i = 0;i<=UI_hight;i++)
            {
                printf("-");
            }
        }
        else
        {
            for(k=0;k<=UI_width;k++)
                printf(" ");
        }
        printf("|\n");
    }


}

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
} //接著輸入這個函式,這樣就可以在其他函式使用了
