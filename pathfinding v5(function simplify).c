#include <stdio.h>
char farm[10][10];
int pig_number = 0;
int calculatepath(int barn_r, int barn_c, int water_r, int water_c);

int main()
{
	int i, j;
	int barn_r, barn_c, obstacle_r, obstacle_c, water_r, water_c;

	for (i = 1; i < 11; i++)
	{
		for (j = 1; j < 11; j++)
		{
			farm[i][j] = '.';
		}
	}
	printf("Enter Column(x) and Row(y) of the barn between 1 and 10:\n");
	scanf("%d%d", &barn_c,&barn_r);
	farm[barn_r][barn_c] = 'B';
	
  printf("Enter Column(x) and Row(y) of the obstacle between 1 and 10:\n");
	scanf("%d%d", &obstacle_c,&obstacle_r);
	farm[obstacle_r][obstacle_c] = 'R';
	
	printf("Enter Column(x) and Row(y) of the water between 1 and 10:\n");
	scanf("%d%d", &water_c,&water_r);
	farm[water_r][water_c] = 'L';

	printf("\n \n Barn (x,y)     %d %d \n ", barn_c, barn_r);
	printf("Obstacle (x,y) %d %d \n ", obstacle_c, obstacle_r);
	printf("Water (x,y)    %d %d \n ", water_c, water_r);

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
		pig_number++;

	}
	

	printf("\n \n");
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j < 11; j++)
		{
			printf("%C", farm[i][j]);
			if (j == 10)
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
				while (water_c > barn_c)
				{
					water_c--;
					farm[water_r][water_c] = 'P';
					pig_number++;

				}
				pig_number--;
			}
			else if (water_c < barn_c)
			{
				while (water_c < barn_c)
				{
					water_c++;
					farm[water_r][water_c] = 'P';
					pig_number++;
				}
				pig_number--;
			}
			else if (water_c == barn_c)
			{
				water_c--;
				farm[water_r][water_c] = 'P';
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
				water_r--;
				pig_number--;
			}

			if (farm[water_r][water_c] != 'B' && farm[water_r][water_c] != 'L')
			{
				farm[water_r][water_c] = 'P';
			}
			pig_number++;
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
				water_r--;
				pig_number--;
			}
			if (farm[water_r][water_c] != 'B' && farm[water_r][water_c] != 'L')
			{
				farm[water_r][water_c] = 'P';
			}
			pig_number++;
		}

	}
	
	return pig_number;
}
