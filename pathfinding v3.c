#include <stdio.h>
char farm[10][10];

int main()
{
	int i, j;
	int barn_r, barn_c, obstacle_r, obstacle_c, water_r, water_c;
	int pig_number = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			farm[i][j] = '.';
		}
	}
	printf("Enter Row position of Barn: ");
	scanf("%d", &i);
	printf("Enter Column position of Barn: ");
	scanf("%d", &j);
	farm[i][j] = 'B';
	barn_r = i;
	barn_c = j;

	printf("Enter x position of Obstacle: ");
	scanf("%d", &i);
	printf("Enter y position of Obstacle: ");
	scanf("%d", &j);
	farm[i][j] = 'R';
	obstacle_r = i;
	obstacle_c = j;

	printf("Enter x position of Water: ");
	scanf("%d", &i);
	printf("Enter y position of Water: ");
	scanf("%d", &j);
	farm[i][j] = 'L';
	water_r = i;
	water_c = j;

	printf("\n \n Barn (x,y)%d %d \n ", barn_r, barn_c);
	printf("Obstacle (x,y) %d %d \n ", obstacle_r, obstacle_c);
	printf("Water (x,y)    %d %d \n ", water_r, water_c);

	/*---When the water is below the the barn---*/

	if (water_r > barn_r)
	{
		printf("The Water is below the level of Barn");
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

				if (farm[water_r][water_c] != 'B')
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
				if (farm[water_r][water_c] != 'B')
				{
					farm[water_r][water_c] = 'P';
				}
				pig_number++;				
			}

		}
        
	}

	/*---When the water is above the the barn---*/
	else if (water_r < barn_r)
	{
		printf("The Water is above the level of Barn");
		water_r++;
		while (water_r < barn_r)
		{
			if (farm[water_r][water_c] == 'R')
			{
				water_r--;
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
			water_r++;

		}

		if (water_c > barn_c)
		{
			water_r--;
			while (water_c > barn_c)
			{
				water_c--;
				if (farm[water_r][water_c] == 'R')
				{
					water_c++;
					water_r--;
					pig_number--;
				}

				if (farm[water_r][water_c] != 'B')
				{
					farm[water_r][water_c] = 'P';
				}
				pig_number++;
			}
		}

		else if (water_c < barn_c)
		{
			water_r--;
			while (water_c < barn_c)
			{
				water_c++;
				if (farm[water_r][water_c] == 'R')
				{
					water_c--;
					water_r--;
					pig_number--;
				}
				if (farm[water_r][water_c] != 'B')
				{
					farm[water_r][water_c] = 'P';
				}
				pig_number++;
			}
		}

	}
	
	/*---When the water is same level as the barn---*/
	else if (water_r == barn_r)
	{
	    printf("The Water is at same level as the Barn");
		if (water_c > barn_c)
		{
			water_c--;
			while (water_c > barn_c)
			{
				if (farm[water_r][water_c] == 'R')
				{
					water_r--;
					water_c++;
					if (water_c > barn_c)
					{
						while (water_c >= barn_c)
						{
							pig_number++;
							farm[water_r][water_c] = 'P';
							water_c--;
						}
					}
				}
				else
				{
					pig_number++;
					farm[water_r][water_c] = 'P';
					water_c--;
				}

			}
		}

		if (water_c < barn_c)
		{
			water_c++;
			while (water_c < barn_c)
			{
				if (farm[water_r][water_c] == 'R')
				{
					water_r--;
					water_c--;
					if (water_c < barn_c)
					{
						while (water_c <= barn_c)
						{
							pig_number++;
							farm[water_r][water_c] = 'P';
							water_c++;
						}
					}
				}
				else
				{
					pig_number++;
					farm[water_r][water_c] = 'P';
					water_c++;
				}

			}
		}

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
