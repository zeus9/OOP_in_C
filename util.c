#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int strcmpi(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    int c1 = tolower(*s1++);
    int c2 = tolower(*s2++);
    if (c1 != c2) {
      return c1 - c2;
    }
  }
  return *s1 - *s2;
}

void print(char* name, char** arr, int rows){
  printf("\n %s", name);
  for (int i = 0; i < rows; i++) {
      printf("\n%s ", arr[i]);
  }
  printf("\n");
}

void printi(char* name, int* arr, int n){
  printf("\n %s", name);
  for (int i = 0; i < n; i++) {
      printf("\n%d ", arr[i]);
  }
  printf("\n");
}

void printfl(char* name, float* arr, int n){
  printf("\n %s", name);
  for (int i = 0; i < n; i++) {
      printf("\n%f ", arr[i]);
  }
  printf("\n");
}

int random_no(int limit){
    srand(time(NULL));
    // Generate a random number within the specified range
    return rand() % limit;
}

// int weighted_random(float *weights, int n) {
//     float sum = 0;
//      int i;
//     for (i = 0; i < n; i++) {
//         sum += weights[i];
//     }

//     srand(time(NULL));

//     int random_num = rand() % sum;
//     for (i = 0; i < n; i++) {
//         if (random_num < weights[i]) {
//             return i;
//         }
//         random_num -= weights[i];
//     }
//     return n - 1;
// }

int random_weighted_index(float *weights, int num_weights) {
  int i;
  float sum = 0;
  srand(time(NULL));

  float rnd = (float)rand() / RAND_MAX;

  for (i = 0; i < num_weights; i++) {
    sum += weights[i];
    if (rnd < sum) {
      return i;
    }
  }

  return num_weights - 1;
}

float random_decimal() {
    float random_value;
    srand(time(NULL));
    random_value = ((float)rand() / RAND_MAX);
    return random_value;
}

