/*
TASK: milk2 
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a: b)
#define MIN(a, b) (a < b ? a: b)
#define INTERSECTS(a0, b0, a1, b1) \
    ((a0 >= a1 && a0 <= b1) ||     \
     (b0 >= a1 && b0 <= b1) ||     \
     (a1 >= a0 && a1 <= b0) ||     \
     (b1 >= a0 && b1 <= b0))

#define MAX_N 5000

typedef struct {
    long int s, e;
} milking_period;

int cmp_period(const void *_a, const void *_b) {
    const milking_period *a, *b;
    a = (milking_period*)_a;
    b = (milking_period*)_b;
    return a->s < b->s ? -1 : (a->s == b->s ? 0: 1);
}

int main(void) {
   FILE *in=fopen("milk2.in", "r"), *out=fopen("milk2.out", "w");
   milking_period periods[MAX_N];
   long int longest_ws=0, longest_we=0, longest_wt=0, longest_it=0;
   int i, n;

   fscanf(in, "%d\n", &n);
   for (i=0; i < n; i++) {
       fscanf(in, "%ld %ld\n", &periods[i].s, &periods[i].e);
   }
   qsort(periods, n, sizeof(milking_period), cmp_period);

   for (i=0; i < n; i++) {
       if (INTERSECTS(periods[i].s, periods[i].e, longest_ws, longest_we)) {
           longest_ws = MIN(longest_ws, periods[i].s);
           longest_we = MAX(longest_we, periods[i].e);
       } else {
           if (i)
               longest_it = MAX(longest_it, periods[i].s - longest_we);
           longest_ws = periods[i].s;
           longest_we = periods[i].e;
       }
       longest_wt = MAX(longest_wt, longest_we - longest_ws);
   }

   fprintf(out, "%ld %ld\n", longest_wt, longest_it);
   fclose(in);
   fclose(out);
   return 0;
}
