#include <stdio.h>
#include <string.h>

typedef char bool;
#define true 1
#define false 0

#define LUAH_N		0
#define LUAH_X		1
#define LUAH_O		2

// The most amazing input function in the world
void GetPos(char *x, char *y, char who)
{
	char pos_buff[5]; // "x y" 5 for new line + null terminator

	get_pos_in:
	printf("\nWhere to go master(%c)?", who==1?'X':'O');
	fgets(pos_buff, sizeof (pos_buff), stdin);
	
	// Check for help
	if (!strcmp(pos_buff, "h\n"))
	{
		printf("\nSyntax: 'x y'\nBegin at '0 0'. End at '2 2'\n"
			"Example input: 0 2\n");
		goto get_pos_in;
	}

	*x = pos_buff[0]-'0'; // x part
	*y = pos_buff[2]-'0'; // y part after space

	// Check if user made an error with input, including space!
	if ((*x > 2 || *x < 0) ||
		(*y > 2 || *y < 0) ||
		pos_buff[1] != ' ')
	{
		printf("\nSyntax error use 'h' for help!\n");
		goto get_pos_in;
	}
	
}

// Please enter [3][3]
void DrawLuah(int luah[3][3])
{
	int i, j;
	for(i=0; i<3; i++)
	{
		fputs("|", stdout);
		for(j=0; j<3; j++)
		{
			if(luah[i][j]==0){
				fputs("_|", stdout);
			}
			else if(luah[i][j]==1){
				fputs("X|", stdout);
			}
			else if(luah[i][j]==2){
				fputs("O|", stdout);
			}
		}
		putc('\n', stdout);
	}
}

// X X X X
// function
void TetrisMain(void)
{
	int luah[3][3]; // board
	
	int i, j, turns;
	bool win = 0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			luah[i][j]=0;
		}
	}
	turns=0;
	char who = 1;
	while (!win)
	{
		char pos_x, pos_y;
		DrawLuah(luah);
		GetPos(&pos_x, &pos_y, who);
		luah[pos_y][pos_x]=who;

		// checking
		if (turns == 9){
			break;
		}

		// Row
/*1*/	for (i=0; i<3; i++)
		{
			// IF WINS
			if ((luah[i][0]==luah[i][1])&&(luah[i][0]==luah[i][2])&&(luah[i][0]!=0))
			{
				win=luah[i][0];
			}
		}

		// Column
/*2*/	for (i=0; i<3; i++)
		{
			// IF WINS
			if ((luah[0][i]==luah[1][i])&&(luah[0][i]==luah[2][i])&&(luah[0][i]!=0))
			{
				win=luah[0][i];	
			}
		}

		// Alahnas1-IF WINS
		if ((luah[0][0]==luah[1][1])&&(luah[0][0]==luah[2][2])&&(luah[0][0]!=0))
		{
			win=luah[0][0];
		}
		// Alahnas2-IF WINS
		if ((luah[2][0]==luah[1][1])&&(luah[2][0]==luah[0][2])&&(luah[2][0]!=0))
		{
			win=luah[2][0];
		}
		who = who==1?2:1;
		turns++;
	}
	
	DrawLuah(luah);
	if (win==0)
	{
		puts("It's a tie!");
	}
	else if (win==1)
	{
		puts("X won!");
	}
	else if (win==2)
	{
		puts("O won!");
	}
}