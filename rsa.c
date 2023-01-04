#include <stdio.h>
#include <math.h>

#define MAX_NUM 100000

// Function to check if a number is prime
int is_prime(int num) {
  if (num < 2) return 0;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

int main(int argc, char* argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    printf("Error: No filename provided.\n");
    return 1;
  }

  // Open the file
  FILE* file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: Unable to open file.\n");
    return 1;
  }

  // Read in the numbers from the file and factorize them
  int num;
  while (fscanf(file, "%d", &num) == 1) {
    if (num > MAX_NUM) {
      printf("Error: Number %d is too large to factorize.\n", num);
      continue;
    }

    printf("%d=", num);
    int p, q;
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0 && is_prime(i) && is_prime(num / i)) {
	p = i;
	q = num / i;
	break;
      }
    }

    if (p && q) {
      printf("%d*%d\n", p, q);
    } else {
      printf("Unable to factorize.\n");
    }
  }

  // Close the file
  fclose(file);

  return 0;
}
