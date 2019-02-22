#include <stdio.h>
#include <stdlib.h>

// 50% by Nonthwat zaza @ECP1N Rmuit kkc
// 25 % by Thanapun Thongjurai @ECP1N Rmuit kkc
// 25 % by solution
// Minesweeper Homework code
// 98.46% code


int main()
{
    int Row,Column,Round=0;
    printf("Input [Row] [Column]\n"); // แนวนอน-ตั้ง
    scanf("%d %d",&Row,&Column);

    if((Row > 0)&& (Row <= 100) && (Column <= 100) && (Column > 0))
{
    {
        printf("=======================\n");
        printf("Input position of mines\n");
        printf(" * = mines . = safezone\n");
        printf("=======================\n");
    }
        char RC [Row][Column];
    while(Round< Row)
    {
        char Cache [Column+1];
        scanf("%s",Cache);
        for(int i = 0 ; i < Column ; i++)
        {
          RC[Round][i] = Cache[i];
        }
      Round++;
    }
    printf("\n");
    int Draw[Row][Column];
    for(int i = 0;i<Row ;i++)
      for(int j = 0 ; j < Column ; j++)
        Draw[i][j] = 0;

    for(int i = 0;i<Row ;i++)
      for(int j = 0 ; j < Column ; j++){
        if(RC[i][j] == '*'){
          /* upper neighbours */
          if(i -1 != -1 )
          {
            if(j - 1 != -1)
              Draw[i-1][j-1]++;
            Draw[i-1][j]++;
            if(j +1 != Column)
              Draw[i-1][j+1]++;
          }

          /* same level neighbours */
          if(j - 1 > -1)
            Draw[i][j-1]++;
          if(j +1 < Column)
            Draw[i][j+1]++;

          /* lower neighbours */
          if(i +1 < Row)
          {
            if(j - 1 > -1)
              Draw[i+1][j-1]++;
            Draw[i+1][j]++;
            if(j + 1 < Column)
              Draw[i+1][j+1]++;
          }
        }
      }
    for(int i = 0 ; i < Row ; i++)
    {
      for(int j = 0 ; j < Column ; j++)
      {
        if(RC[i][j] == '*')
        {
          printf("%c",RC[i][j]);
        }
        else
          printf("%d",Draw[i][j]);
      }
      printf("\n");
    }
}
    return 0;
}