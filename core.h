#ifndef CORE_H
#define CORE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern const size_t primes_size;
extern const size_t queue_size;
bool is_prime(long long number);
int* init_primes(void);
int* init_queue(void);

#endif //CORE_H