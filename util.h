#ifndef UTIL_H
#define UTIL_H

int strcmpi(const char *s1, const char *s2);
void print(char* name, char** arr, int rows);
void printi(char* name, int* arr, int n);
void printfl(char* name, float* arr, int n);
int random_no(int limit);
int random_weighted_index(float *weights, int num_weights);
float random_decimal();

#endif // UTIL_H