#include "core.h"

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {   long long input = strtoll(argv[1],  NULL, 10);
        int* primes = (int*)init_primes();
        
        if (is_prime(input, primes)) //Check if input is in the correct format
        {
            fprintf(stderr, "Number is prime (-1)\n");
            free(primes); 
            exit(-1);
        }
        if (input <= 0) 
        {
            fprintf(stderr, "Number is 0, negative or in the wrong format (-2)\n");
            free(primes); 
            exit(-2); 
        }
        if (input == 1)
        {
            fprintf(stderr, "Number is 1 (-3)\n");
            free(primes);
            exit(-3);
        }
        int* queue = (int*)init_queue();
        int counter = 0;
        unsigned long long result = input;
        for(int i = 0; i<primes_size; ++i) //Stack every prime number that is divisible for the result of the last division;
        {
            if (result == 1)
                break;
            if (result % primes[i] == 0)
            {
                queue[counter] = primes[i];
                counter++; 
                result /= primes[i];
                i=-1;
            }
        }
        printf("{ ");
        int acc = 1;
        for(int i = 0; i<queue_size; i++) //Print the prime factors in a tidier way;
        {
            if (queue[i]!=-99)
            {
                if (queue[i]==queue[i-1])
                    acc++;
                else
                {
                    if (i>0)
                        printf(" × ");
                    printf("%d", queue[i]);
                }
                if (queue[i]!=queue[i+1] && acc>1)
                {
                    printf("^%d", acc);
                    acc = 1;
                }
            }
            else
                break;
        }
        printf(" }\n");
        free(queue);
        free(primes);
        exit(0);
    }
    else
    {
        fprintf(stderr, "No number provided (-4)\n");
        exit(-4);
    }
}