#include <stdio.h>
#include <stdlib.h>
// To use time library of C
#include <time.h>
#include <windows.h>
void delay(int number_of_seconds);
void Select_Ball_Located(int *Locate_PtrX,int *Locate_PtrY,int *Velocity_X,int *Velocity_Y);
void UI_show(int UI_hight, int UI_width );

    int bottom = 25;
    int top = 1;
    int left = 25;
    int right = 1;
    int Velocity_X = (rand() % 10) +1;
    int Velocity_Y =1;
int main()
{

	int line_ball_located_X = 4;
   	int line_ball_located_Y = 7;
    int *Locate_PtrX = &line_ball_located_X;
    int *Locate_PtrY = &line_ball_located_Y;
    int *Velocity_Ptr_X = &Velocity_X;
    int *Velocity_Ptr_Y = &Velocity_Y;

    printf("Locate_PtrX(%d);Locate_PtrY(%d);Velocity_Ptr_X(%d);Velocity_Ptr_Y(%d)",
               *Locate_PtrX,*Locate_PtrY,*Velocity_Ptr_X,*Velocity_Ptr_Y);
delay(3);
    while(1)
    {
        system("cls");
        UI_show(bottom,left);
        printf("Locate_PtrX(%d);Locate_PtrY(%d);Velocity_Ptr_X(%d);Velocity_Ptr_Y(%d)",
               *Locate_PtrX,*Locate_PtrY,*Velocity_Ptr_X,*Velocity_Ptr_Y);

        Select_Ball_Located(Locate_PtrX,Locate_PtrY,Velocity_Ptr_X,Velocity_Ptr_Y);//此部分要改用指標
        delay(1);
    }


    return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 200 * number_of_seconds;

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
}
void Select_Ball_Located(int *Locate_PtrX,int *Locate_PtrY,int *Velocity_X,int *Velocity_Y)
{
    int tmpX,tmpY;
    gotoxy(*Locate_PtrX,*Locate_PtrY);
    printf("o");

    tmpX = *Locate_PtrX;
    *Locate_PtrX = tmpX + *Velocity_X;//更新位置X

    tmpY = *Locate_PtrY;
    *Locate_PtrY = tmpY + *Velocity_Y;//更新位置X

    if(*Locate_PtrX == bottom||*Locate_PtrX == top)
                *Velocity_X = -(*Velocity_X);

    if(*Locate_PtrY == right||*Locate_PtrY == left)
                (*Velocity_Y) = -(*Velocity_Y);
    printf("\n");

}
