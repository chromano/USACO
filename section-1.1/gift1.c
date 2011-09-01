/*
TASK: gift1
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_SIZE 14

struct person {
    char name[MAX_NAME_SIZE + 1];
    int initial_amount;
    int n_recipients;
    int amount_received;
    int amount_given;
};

int np;
struct person people[10];

int main(void)
    {
        char giver_name[MAX_NAME_SIZE + 1];
        char recipient_name[MAX_NAME_SIZE + 1];
        int i, j, amount_to_give, person_idx;
        struct person *giver, *recipient;
        FILE *in, *out;

        in = fopen("gift1.in", "r");
        fscanf(in, "%d\n", &np);
        for (i = 0; i < np; i++)
            {
                fscanf(in, "%s\n", people[i].name);
                people[i].amount_received = 0;
            }
        for (i = 0; i < np; i++)
            {
                fscanf(in, "%s\n", giver_name);
                for (person_idx = 0; person_idx < np; person_idx++)
                    if (!strcmp(people[person_idx].name, giver_name))
                        break;
                giver = &people[person_idx];
                fscanf(in, "%d\n%d\n", &giver->initial_amount, &giver->n_recipients);
                if (giver->n_recipients)
                    amount_to_give = (int)ceil(giver->initial_amount / giver->n_recipients);
                else
                    amount_to_give = 0;
                for (j = 0; j < giver->n_recipients; j++)
                    {
                        fscanf(in, "%s\n", recipient_name);
                        for (person_idx = 0; person_idx < np; person_idx++)
                            if (!strcmp(people[person_idx].name, recipient_name))
                                break;
                        people[person_idx].amount_received += amount_to_give;
                        giver->amount_given += amount_to_give;
                    }
            }
        fclose(in);
        out = fopen("gift1.out", "w");
        for (i = 0; i < np; i++)
            fprintf(out, "%s %d\n", people[i].name,
                    people[i].amount_received - people[i].amount_given);
        fclose(out);
        return 0;
    }

