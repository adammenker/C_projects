#include <stdio.h>

int artist_num, album_num, continue_value, x;// initializing variables

//prototypes for my functions
int artist_selection(void);
int artist_one_albums(void);
int artist_two_albums(void);
int artist_three_albums(void);
int artist_four_albums(void);
int artist_five_albums(void);
int continueon(void);

int main ( void )// start of program
{
  x = 1;
  while(x == 1){
    artist_selection();//routing artist number input in to certain artist album list
    switch(artist_num){
      case 1:
        artist_one_albums();
        continueon();
        break;
      case 2:
        artist_two_albums();
        continueon();
        break;
      case 3:
        artist_three_albums();
        continueon();
        break;
      case 4:
        artist_four_albums();
        continueon();
        break;
      case 5:
        artist_five_albums();
        continueon();
        break;
    }
  }
}

int artist_selection(void){//artist selection function block that collects input of which artist user chooses
  printf( "\n** Digital Music Info **\n\nSelect an artist:\n" );
  printf( "1. Bruce Springsteen\n2. Steve Earle\n3. The Clash\n4. The Sex Pistols\n5. P.J. Harvey\n" );
  scanf( "%d", &artist_num );
  while(artist_num < 1 || artist_num > 5){
    puts( "** Please enter a selection from 1 to 5 **" );
    scanf( "%d", &artist_num );
  }
    return artist_num;
}

// Artist one album list and star output switch statement
int artist_one_albums(void){
  printf( "Select an album:\n");
  printf( "1. Greetings From Asbury Park\n2. The Wild, The Innocent, and The "
            "E-Street Shuffle\n3. Born To Run\n4. Darkness On The Edge Of Town"
            "\n5. The River\n6. Nebraska\n7. All Albums by this Artist\n");
  scanf( "%d", &album_num );
  while(album_num < 1 || album_num > 7){// checks to see if user inputs invalid album number
    puts("** Please enter a selection from 1 to 7 **");
    scanf( "%d", &album_num );
  }
  switch(album_num){//prints star value based on input
    case 1:
      puts("*** stars = 3 ***\n");
      break;
    case 2:
      puts("*** stars = 3.5 ***\n");
      break;
    case 3:
      puts("*** stars = 4.5 ***\n");
      break;
    case 4:
      puts("*** stars = 5 ***\n");
      break;
    case 5:
      puts("*** stars = 4.5 ***\n");
      break;
    case 6:
      puts("*** stars = 5 ***\n");
      break;
    case 7:
      printf("*** stars = %.1f ***\n\n", 4.3);
      break;
  }
  return 0;
}

// Artist two album list and star output switch statement
int artist_two_albums(void){
  printf( "Select an album:\n");
  printf( "1. Copperhead Road\n2. I Feel Alright\n3. El Corazon\n4. Transcendental"
          " Blues\n5. All Albums by this Artist\n");
  scanf( "%d", &album_num );
  while(album_num < 1 || album_num > 5){
    puts("** Please enter a selection from 1 to 5 **");
    scanf( "%d", &album_num );
  }
  switch(album_num){
    case 1:
      puts("*** stars = 4 ***\n");
      break;
    case 2:
      puts("*** stars = 5 ***\n");
      break;
    case 3:
      puts("*** stars = 4.5 ***\n");
      break;
    case 4:
      puts("*** stars = 4 ***\n");
      break;
    case 5:
      printf("*** stars = %.1f ***\n\n", 4.4);
      break;
  }
  return 0;
}

// Artist three album list and star output switch statement
int artist_three_albums(void){
  printf( "Select an album:\n");
  printf( "1. The Clash\n2. London Calling\n3. Sandinista\n4. Combat Rock\n5. All Albums by this Artist\n");
  scanf( "%d", &album_num );
  while(album_num < 1 || album_num > 5){
    puts("** Please enter a selection from 1 to 5 **");
    scanf( "%d", &album_num );
  }
  switch(album_num){
    case 1:
      puts("*** stars = 5 ***\n");
      break;
    case 2:
      puts("*** stars = 5 ***\n");
      break;
    case 3:
      puts("*** stars = 4 ***\n");
      break;
    case 4:
      puts("*** stars = 3.5 ***\n");
      break;
    case 5:
      printf("*** stars = %.1f ***\n\n", 4.4);
      break;
  }
  return 0;
}

// Artist four album list and star output switch statement
int artist_four_albums(void){
  printf("Select an album:\n");
  printf( "1. Never Mind The Bollocks, Here's The Sex Pistols\n2. All Albums by this Artist\n");
  scanf( "%d", &album_num );
  while(album_num < 1 || album_num > 2){
    puts("** Please enter a selection from 1 to 2 **");
    scanf( "%d", &album_num );
  }
  switch(album_num){
    case 1:
      puts("*** stars = 5 ***\n");
      break;
    case 2:
      puts("*** stars = 5.0 ***\n");
      break;
  }
  return 0;
}

// Artist five album list and star output switch statement
int artist_five_albums(void){
  printf( "Select an album:\n");
  printf( "1. Dry\n2. Rid of Me\n3. Stories From the City, Stories From the Sea\n4. All Albums by this Artist\n");
  scanf( "%d", &album_num );
  while(album_num < 1 || album_num > 4){
    puts("** Please enter a selection from 1 to 4 **");
    scanf( "%d", &album_num );
  }
  switch(album_num){
    case 1:
      puts("*** stars = 3 ***\n");
      break;
    case 2:
      puts("*** stars = 3 ***\n");
      break;
    case 3:
      puts("*** stars = 5 ***\n");
      break;
    case 4:
      printf("*** stars = %.1f ***\n\n", 3.7);
      break;
  }
  return 0;
}

//checks to see if user want to continue
int continueon(void){
  printf("Enter 0 to exit or any other number to continue...\n");
  scanf("%d", &continue_value);
  if(continue_value == 0){
    return(x = 0);
  }
  return 0;
}

