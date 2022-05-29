#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4

#include <stdio.h>

// workshop 3 home session
int main() {
   int i, high, low, c_high = 0, c_low = 0, i_high=0, i_low=0;
   double total_h = 0, total_l = 0, ave_h, ave_l, total, ave;

   printf("---===IPC Temperature Analyzer===---\n");
   for (i = 0; i < NUMS; i++) {
      int flag = 0;
      do {
      printf("Enter the high value for day %d: ", i + 1);
      scanf("%d", &high);
      
      printf("Enter the low value for day %d: ", i + 1);
      scanf("%d", &low);
     
         if (high < 41 && low > -41 && high > low) {
            total_h += high;
            total_l += low;
            total = total_h + total_l;
            flag++;
         }
         else {
            printf("Incorrect value, temperqatures must be in the range -40 to 40, high must be"
               "greater than low.\n");
         }

      } while (!flag);

      if (high > c_high) {
         c_high = high;
         i_high = i+1;
      }
      if (low < c_low) {
         c_low = low;
         i_low = i + 1;
      }
   }

   ave_h = total_h / NUMS;
   ave_l = total_l / NUMS;
   ave = total / NUMS/2;
   printf("The average (mean) Low temperature was: %.2lf\n", ave_l);
   printf("The average (mean) high temperature was: %.2lf\n", ave_h);
   printf("The average (mean) temperature was: %.2lf\n", ave);
   printf("The highest temperature was %d, on day %d\n", c_high, i_high);
   printf("The lowest temperature was %d, on day %d\n", c_low, i_low);

   return 0;
}
