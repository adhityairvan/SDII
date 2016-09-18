#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	int i,a,b,c;
	int x,y;
	int tailx=0;int taily=0;
	int bodyx=0;int bodyy=1;
	int headx=0;int heady=2;
	printf("Masukan ukuran maze.. ");
	scanf("%d%d",&x,&y);
	int maze[x][y];
	printf("Masukkan bentuk Maze (0 untuk jalan dan 1 untuk penghalang)\n");
	for(i=0;i<x;i++){
		for(a=0;a<y;a++){
			scanf("%d",&maze[i][a]);
		}
	}
	
	gotoxy(0,30);
	maze[0][0]=219;maze[0][1]=219;maze[0][2]=219;
	
	for(i=0;i<x;i++){
		for(a=0;a<y;a++){
			if(maze[i][a]==219){
				printf("%c",maze[i][a]);
			}
			else printf("%d",maze[i][a]);
		}
		printf("\n");
	}
	
	while(1)
	{
		gotoxy(0,30+x+2);
		for(i=0;i<x;i++){
			for(a=0;a<y;a++){
				if(maze[i][a]==219){
					printf("%c",maze[i][a]);
				}
				else printf("%d",maze[i][a]);
			}
			printf("\n");
		}
		system("pause");
		
		if(maze[headx][heady+1]==0&&heady<y-1){
			maze[tailx][taily]=1;
			tailx=bodyx;taily=bodyy;
			bodyx=headx;bodyy=heady;
//			printf("headx : %d dan heady : %d\n",headx,heady);
			heady++;
			maze[headx][heady]=219;
		}
		
		else if(maze[headx+1][heady]==0&&headx<x-1){
			maze[tailx][taily]=1;
			tailx=bodyx;taily=bodyy;
			bodyx=headx;bodyy=heady;
			headx++;
//			printf("headx : %d dan heady : %d\n",headx,heady);
			maze[headx][heady]=219;
		}
		
		else if(maze[headx][heady-1]==0&&heady>0){
			maze[tailx][taily]=1;
			tailx=bodyx;taily=bodyy;
			bodyx=headx;bodyy=heady;
			heady--;
//			printf("headx : %d dan heady : %d\n",headx,heady);
			maze[headx][heady]=219;
		}
		else if(maze[headx-1][heady]==0&&headx>0){
			maze[tailx][taily]=1;
			tailx=bodyx;taily=bodyy;
			bodyx=headx;bodyy=heady;
			headx--;
//			printf("headx : %d dan heady : %d\n",headx,heady);
			maze[headx][heady]=219;
		}
		else break;
	}
	printf("End of game,Thanks for playing ^_^\n");
	return 0;
}

