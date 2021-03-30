#include <stdio.h>
#include <stdlib.h>

int BLUE=-1,GREEN=-1,RED=-1,YELLOW=-1;  //tokens

int H[] = {17,54,64,62,87,93,95};    //snake's head
int T[] = {7,26,41,19,36,5,75};   //snake's tail

int B[] = {4,8,9,21,47,72,80};   //ladder's bottom
int Tp[] = {37,14,31,42,84,91,99};   //ladder's top


void gameBoard() // it will show every gameboard 
{ //show the game board (snake and ladders)
	int i,j,k=100;
	printf("\n");
	for(i=0;i<10;i++) 
	{
		for(j=0;j<10;j++)
			printf(" -----");
			printf("\n");
		for(j=0;j<10;j++) 
		{
			printf("|");
			if(BLUE == k) 
			{
				printf("  B  ");
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(GREEN == k)
			{
				printf("  G  ");
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(RED == k)
			{
				printf("  R  ");
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(YELLOW == k)
			{
				printf("  Y  ");
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(checkSnake(k) != -1) 
			{
				printf(" SH%d ",checkSnake(k));
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(checkLadder(k) != -1)
			{
				printf(" LB%d ",checkLadder(k));
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(snakeTail(k) != -1)
			{
				printf("  S%d ",snakeTail(k));
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(ladderTop(k) != -1)
			{
				printf("  L%d ",ladderTop(k));
				if(i%2==0)
				{
					if(k%10 == 1)
						k -= 10;
					else
						k--;
				}
				else 
				{
					if(k%10 == 0)
						k -= 10;
					else
						k++;
				}
			}
			else if(k==100) //all above condition fail
			{
				printf(" WIN ");
				k--; 
			}
			else if(i%2==0) 
			{
				printf(" %d  ",k);
				if(k%10 == 1)
					k -= 10;
				else
					k--;
			}
			else 
			{
				if(i==9&&j<9) //board setting
					printf("  %d  ",k);
				else
					printf(" %d  ",k);
				if(k%10 == 0)
					k -= 10;
				else
					k++;
			}
		}
		printf("|\n");
	}
	for(i=0;i<10;i++)
		printf(" -----");
}
int checkSnake(int position) 
{ //check for snakes
	int i;
	for(i=0;i<7;i++) // linear searching
	{
		if(position == H[i]) //"
		{
			return i;  //"
		}
	}
	return -1; //ladder bottom not found
}
int checkLadder(int position) 
{ //check for ladder
	int i;
	for(i=0;i<7;i++) 
	{
		if(position == B[i])
		{
			return i;
		}
	}
	return -1;
}
int snakeTail(int position) 
{
	int i;
	for(i=0;i<7;i++) 
	{
		if(position == T[i])
		{
			return i;
		}
	}
	return -1;
}
int ladderTop(int position) 
{
	int i;
	for(i=0;i<7;i++) 
	{
		if(position == Tp[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{

	printf("\n->SH is used for Snake's Head");
	printf("\n->S is used for Snake's Tail");
	printf("\n->LB is used for Ladder's Bottom");
	printf("\n->L for Ladder's Top\n\n\n");
	gameBoard();
	printf("\n");
	printf("Welcome to SNAKES AND LADDERS!!");
	printf("\nEnter the number of Players: ");
	
	return 0;
}
