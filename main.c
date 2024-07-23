#include <primes.h>
#include <string.h>
#define queue_size 100

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {   
        u64 total = strtoull(argv[1], NULL, 10);
        long long input = strtoll(argv[1],  NULL, 10);
        if (input <= 0) //Check if input is in the correct format
        {
            fprintf(stderr, "Number is 0, negative or in the wrong format (-1)\n");
            exit(-1); 
        }
        if (total == 0xFFFFFFFFFFFFFFFF && (strcmp(argv[1], "18446744073709551615") != 0))
        {
            fprintf(stderr, "Number is too big (-2)\n");
            exit(-2);
        }
        if (total == 1)
        {
            fprintf(stderr, "Number is 1 (-3)\n");
            exit(-3);
        }
        if (is_prime(total)) 
        {
            fprintf(stderr, "Number is prime (-4)\n"); 
            exit(-4);
        }
        u64* queue=get_prime_fact_ull(total, queue_size);
        if (*queue == 0 || queue == NULL)
        {
            fprintf(stderr, "Error while parsing number (-6).\n");
            exit(-6);
        }
        printf("{ ");
        u64 acc = 1;
        for (int i = 0; i<queue_size; i++) //Print the prime factors in a tidier way;
        {
            if (queue[i]!=0)
            {
                if (queue[i]==queue[i-1])
                    acc++;
                else
                {
                    if (i>0)
                        printf(" × ");
                    printf("%llu", queue[i]);
                }
                if (queue[i]!=queue[i+1] && acc>1)
                {
                    printf("^%llu", acc);
                    acc = 1;
                }
            }
            else
                break;
        }
        printf(" } = ");
        /* > Uncomment to enable further checking
        acc = 1;
        for (int i = 0; i < queue_size && queue[i] != 0; i++)
            acc *= queue[i];
        
        printf("%llu == %llu\n", acc, input, total);
        */
        free(queue);
        exit(0);
    }
    else
    {
        fprintf(stderr, "No number provided (-5)\n");
        exit(-5);
    }
}
