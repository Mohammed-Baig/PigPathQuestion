#include <stdio.h>
char farm[10][10];

int main(void) 
{
  int i, j;
  int barn_r, barn_c, obstacle_r, obstacle_c, water_r, water_c;
  int pig_number=0;

  for (i=0; i<10; i++)
  {
    for (j=0; j<10; j++)
    {
      farm[i][j]='.';
    }
  }

  printf("Enter the Row and Column values of the barn(Y and X values respectively):\n");
  scanf("%d%d",&i,&j);
  farm[i][j]='B';
  barn_r=i;
  barn_c=j;

  printf("Enter the Row and Column values of the obstacle(Y and X value respectively):\n");
  scanf("%d%d",&i,&j);
  farm[i][j]='R';
  obstacle_r=i;
  obstacle_c=j;

  printf("Enter the X and Y values of the water(Y and X values respectively):\n");
  scanf("%d%d",&i,&j);
  farm[i][j]='L';
  water_r=i;
  water_c=j;

  printf("\n Barn is at (x,y) (%d,%d)",barn_r,barn_c);
  printf("\n Obstacle is at (x,y) (%d,%d)",obstacle_r,obstacle_c);
  printf("\n Water is at (x,y) (%d,%d)",water_r,water_c);


/*---------When the water is below the barn----------*/
if(water_r > barn_r)
{
  printf("\n \n Water is below the barn");
  water_r--;
  while (water_r > barn_r)
  {
    if (farm[water_r][water_c] == 'R')
    {
      water_r++;
      if (water_c > barn_c)
      {
        while(water_c >= barn_c)
        {
          pig_number++;
          farm[water_r][water_c] = 'P';
          water_c--;
        }
        pig_number--;
      }
      else if(water_c < barn_c)
      {
        while (water_c <= barn_c)
        {
           pig_number++;
           farm[water_r][water_c]='P';
           water_c++;
        }
        pig_number--;
      }
      else if(water_c == barn_c)
        water_c--;
        while (water_r <= barn_r)
        {
           pig_number++;
           farm[water_r][water_c]='P';
           water_r--;
        }
         
    }
    farm[water_r][water_c] = 'P';
    pig_number++;
    water_r--;  
  }
  if(water_c > barn_c)
  {
    while (water_c > barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c--;
    }
  }

  else if(water_c < barn_c)
  {
    while (water_c < barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c++;
    }
  }
}

/*---------When the water is above the barn-----------*/
if(water_r < barn_r)
{
  printf("\n \n Water is above the barn");
  water_r++;
  while (water_r < barn_r)
  {
    if (farm[water_r][water_c] == 'R')
    {
      water_r--;
      if (water_c > barn_c)
      {
        while(water_c > barn_c)
        {
          pig_number++;
          farm[water_r][water_c] = 'P';
          water_c--;
        }
        pig_number--;
      }
      else if(water_c < barn_c)
      {
        while (water_c < barn_c)
        {
           pig_number++;
           farm[water_r][water_c]='P';
           water_c++;
        }
        pig_number--;
      }
      else if(water_c == barn_c)
      {
        water_c--;
        farm[water_r][water_c]='P';
      }
    }
    farm[water_r][water_c] = 'P';
    pig_number++;
    water_r++;  
  }
  if(water_c > barn_c)
  {
    while (water_c > barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c--;
    }
  }

  else if(water_c < barn_c)
  {
    while (water_c < barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c++;
    }
  }
}
    

/*---When the water is at the same level as the barn---*/
if(water_r < barn_r)
{
  printf("\n \n Water is above the barn");
  water_r--;
  while (water_r < barn_r)
  {
    if (farm[water_r][water_c] == 'R')
    {
      water_r++;
      if (water_c > barn_c)
      {
        while(water_c >= barn_c)
        {
          pig_number++;
          farm[water_r][water_c] = 'P';
          water_c--;
        }
        pig_number--;
      }
      else if(water_c < barn_c)
      {
        while (water_c <= barn_c)
        {
           pig_number++;
           farm[water_r][water_c]='P';
           water_c++;
        }
        pig_number--;
      }
      else if(water_c == barn_c)
        water_c--;
        while (water_r <= barn_r)
        {
           pig_number++;
           farm[water_r][water_c]='P';
           water_r--;
        }
         
    }
    farm[water_r][water_c] = 'P';
    pig_number++;
    water_r--;  
  }
  if(water_c > barn_c)
  {
    while (water_c > barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c--;
    }
  }

  else if(water_c < barn_c)
  {
    while (water_c < barn_c)
    {
      pig_number++;
      farm[water_r][water_c]='P';
      water_c++;
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
