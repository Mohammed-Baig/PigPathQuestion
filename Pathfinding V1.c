#include <stdio.h>
char farm[10][10];

int main(void) {
  int i, j;
  int barn_x, barn_y, obstacle_x, obstacle_y, water_x, water_y;
  int pig_number=0;

  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      farm[i][j]='.';
    }
  }

printf("Enter the X and Y values of the barn(B):\n");
scanf("%d%d",&i,&j);
farm[i-1][j-1]='B';
barn_x=j-1;
barn_y=i-1;

printf("Enter the X and Y values of the obstacle(R):\n");
scanf("%d%d",&i,&j);
farm[i-1][j-1]='R';
obstacle_x=j-1;
obstacle_y=i-1;

printf("Enter the X and Y values of the water(L):\n");
scanf("%d%d",&i,&j);
farm[i-1][j-1]='L';
water_x=j-1;
water_y=i-1;


/*--------------------------------------------*/
if (water_x > barn_x){
water_x--;
  while (water_x > barn_x){
    if (farm[water_x][water_y] == 'R'){
      water_x++;
      if (water_y > barn_y ){
        while(water_y> barn_y){
          water_y--;
          pig_number++;
          farm[water_x][water_y] = 'P';
        }
        pig_number--;
      }
      else if(water_y < barn_y){
        while (water_y < barn_y){
        water_y++;
        pig_number++;
        farm[water_x][water_y]='P';
        }
        pig_number--;
      }
      else{
        water_y--;
        pig_number++;
        farm[water_x][water_y]='P';
      }
    }
    farm[water_x][water_y] = 'P';
    pig_number++;
    water_x--;    
  }
  if(water_y > barn_y){
    water_x++;
    while (water_y > barn_y){
      water_y--;
      pig_number++;
      farm[water_x][water_y]='P';
    }
  }
}


/*--------------------------------------------*/

else if (water_x < barn_x){
  water_x++;
  while (water_x < barn_x){
    if (farm[water_x][water_y]=='R'){
      water_x--;
      if (water_y > barn_y){
        while(water_y > barn_y){
          water_y--;
          pig_number++;
          farm[water_x][water_y]='P';
        }
        pig_number--;
      }
      else if(water_y < barn_y){
        while (water_y < barn_y){
        water_y++;
        pig_number++;
        farm[water_x][water_y]='P';
        }
        pig_number--;
      }
      else {
        water_y--;
        pig_number++;
        farm[water_x][water_y]='P';
      }
    }
    farm[water_x][water_y] = 'P';
    pig_number++;
    water_x++;
  }
  if (water_y > barn_y){
    water_x++;
    while (water_y > barn_y){
      water_y--;
      pig_number++;
      farm[water_x][water_y] = 'P';
    }
  }
  else if (water_y < barn_y){
    water_x++;
    while (water_y < barn_y){
      water_y++;
      pig_number++;
      farm[water_x][water_y] = 'P';
    }
  }
}

/*---------------------------------------------*/
else if (water_x==barn_x){
  if (water_y > barn_y){
    water_y--;
    while(water_y > barn_y){
      if(farm[water_x][water_y] == 'R'){
        water_x--;
        water_y++;
        if(water_y > barn_y){
          while(water_y >= barn_y){
            pig_number++;
            farm[water_x][water_y] = 'P';
            water_y--;
          }
        }
      }
      else{
        pig_number++;
        farm[water_x][water_y] = 'P';
        water_y--;
      }
    }
  }
  
  if(water_y < barn_y){
    water_y++;
    while(water_y < barn_y){
      if(farm[water_x][water_y] == 'R'){
        water_x--;
        water_y--;
        if(water_y < barn_y){
          while(water_y <= barn_y){
            pig_number++;
            farm[water_x][water_y] = 'P';
            water_y++;
          }
        }
      }
      else {
        pig_number++;
        farm[water_x][water_y] = 'P';
        water_y++;
      }
    }
  }
}

printf("\n \n");
for (i = 0; i < 10; i++) {
  for (j = 0; j < 10; j++) {
      printf("%C", farm[i][j]);
      if (j == 9)
        printf("\n");
  }   
}
printf("\n \n Number of pigs %d", pig_number);
  return 0;
}
