#include <stdio.h>
#include <stdlib.h>

// 50% by Nonthwat zaza @ECP1N Rmuit kkc
// 25 % by Thanapun Thongjurai @ECP1N Rmuit kkc
// 25 % by solution
// Minesweeper Homework code
// 99.46% code
// source code นี้มีจุดประสงค์ให้ใช้เป็นแนวทางในการเขียนโค้ดเท่านั้น แนะนำว่าให้เขียนโค้ดด้วยตัวเองดีกว่า^-^ (ถึงไม่ได้เขียนเองทั้งหมด(ผมก็เหมือนกัน) ก็ไม่เป็นไร ขอให้เข้าใจหลักการของโค้ด เดียวก็จะเขียนได้เอง(ถ้าเขียนเองเวลาอธิบายโค้ดจะง่ายกว่ากันเยอะ^^)  ด้วยความปรารถนาดีจากNonthwat zaza 23/2/2019 11:12 PM


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
    while(Round< Row) // รอบน้อยกว่าแถว
    {
        char Cache [Column+1];
        scanf("%s",Cache);
        for(int i = 0 ; i < Column ; i++)
        {
          RC[Round][i] = Cache[i];  // RC[0][1]= cache[1] >> RC[1][2]= cache[2]
        }
      Round++;
    }
    printf("\n");
    int Draw[Row][Column];
    for(int i = 0;i<Row ;i++)  // ให้ i=0;ถ้าi น้อยกว่า แถว ; i++
      for(int j = 0 ; j < Column ; j++) // ให้ j=0;ถ้าj น้อยคอลัม แถว ; j++
        Draw[i][j] = 0; //ให้ตำแหน่งนั้น=0

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
        if(RC[i][j] == '*') //ถ้าตำแหน่งใดมี *
        {
          printf("%c",RC[i][j]); //แสดงจุดนั้น
        }
        else
          printf("%d",Draw[i][j]); // แสดงตัวเลข
      }
      printf("\n");
    }
}
    return 0;
}
