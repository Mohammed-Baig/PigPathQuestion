#include <stdio.h>
char farm[10][10];
int pig_number = 0;
int calculatepath(int barn_r, int barn_c, int water_r, int water_c);

int main()
{
	int i, j;
	int barn_r, barn_c, obstacle_r, obstacle_c, water_r, water_c;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			farm[i][j] = '.';
		}
	}
	printf("Enter Row position of Barn: ");
	scanf("%d", &barn_r);
	printf("Enter Column position of Barn: ");
	scanf("%d", &barn_c);
	farm[barn_r][barn_c] = 'B';
	
	printf("Enter x position of Obstacle: ");
	scanf("%d", &obstacle_r);
	printf("Enter y position of Obstacle: ");
	scanf("%d", &obstacle_c);
	farm[obstacle_r][obstacle_c] = 'R';
	
	printf("Enter x position of Water: ");
	scanf("%d", &water_r);
	printf("Enter y position of Water: ");
	scanf("%d", &water_c);
	farm[water_r][water_c] = 'L';

	printf("\n \n Barn (x,y)     %d %d \n ", barn_r, barn_c);
	printf("Obstacle (x,y) %d %d \n ", obstacle_r, obstacle_c);
	printf("Water (x,y)    %d %d \n ", water_r, water_c);

	/*---When the water is below the the barn---*/
	if (water_r > barn_r)
	{
		printf("\n The Water is below the level of Barn");
		pig_number = calculatepath(barn_r, barn_c, water_r, water_c);
   	}

	/*---When the water is above the the barn---*/
	else if (water_r < barn_r)
	{
		printf("\n The Water is above the level of Barn");
		pig_number = calculatepath(water_r, water_c, barn_r, barn_c);
	}
	
	/*---When the water is same level as the barn---*/
	else if (water_r == barn_r)
	{
	    printf("\n The Water is at same level as the Barn");
		pig_number = calculatepath(barn_r, barn_c, water_r, water_c);

	}
	
	printf("\n \n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%C", farm[i][j]);
			if (j == 9)
				printf("\n");
		}
	}
	printf("\n \n Number of pigs %d", pig_number);

	return 0;
}

int calculatepath(int barn_r, int barn_c, int water_r, int water_c)
{
	water_r--;
	while (water_r > barn_r)
	{
		if (farm[water_r][water_c] == 'R')
		{
			water_r++;
			if (water_c > barn_c)
			{
				water_c--;
			}
			else if (water_c < barn_c)
			{
				water_c++;
			}
			else if (water_c == barn_c)
			{
				if (water_c == 0)
				{
					water_c++;
				}
				else if (water_c == 9)
				{
					water_c--;
				}
			}
		}
		farm[water_r][water_c] = 'P';
		pig_number++;
		water_r--;
	}

	if (water_c > barn_c)
	{
		water_r++;
		while (water_c > barn_c)
		{
			water_c--;
			if (farm[water_r][water_c] == 'R')
			{
				water_c++;
				if (water_r != 0)
				{
					water_r--;
				}
				else
				{
					water_r++;
				}
			}

			if (farm[water_r][water_c] != 'B' && farm[water_r][water_c] != 'L')
			{
				farm[water_r][water_c] = 'P';
				pig_number++;
			}
		}
	}
		
	else if (water_c < barn_c)
	{
		water_r++;
		while (water_c < barn_c)
		{
			water_c++;
			if (farm[water_r][water_c] == 'R')
			{
				water_c--;
				if (water_r != 0)
				{
					water_r--;
				}
				else
				{
					water_r++;
				}
			}
			if (farm[water_r][water_c] != 'B' && farm[water_r][water_c] != 'L')
			{
				farm[water_r][water_c] = 'P';
				pig_number++;
			}
		}

	}
	return pig_number;
}
