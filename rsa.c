#include <stdio.h>
#include <math.h>

#define MAX_NUM pow(2, 216384)

// Function to check if a number is prime
long double is_prime(long double num) {
  if (num < 2) return 0;
  for (long double i = 2; i <= sqrt(num); i++) {
    if (fmod(num, i) == 0) return 0;
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
  long double num;
  while (fscanf(file, "%Lf", &num) == 1) {
    if (num > MAX_NUM) {
      printf("Error: Number %Lf is too large to factorize.\n", num);
      continue;
    }

    printf("%0.0Lf=", num);
    long double p, q;
    for (long double i = 2; i <= sqrt(num); i++) {
      if (fmod(num, i) == 0 && is_prime(i) && is_prime(num / i)) {
	p = i;
	q = num / i;
	break;
      }
    }

    if (p && q) {
      printf("%0.0Lf*%0.0Lf\n", q, p);
    } else {
      printf("Unable to factorize.\n");
    }
  }

  // Close the file
  fclose(file);

  return 0;
}
