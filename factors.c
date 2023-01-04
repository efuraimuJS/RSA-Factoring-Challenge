#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: factors <file>\n");
    return 1;
  }

  // Open the file for reading
  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: unable to open file '%s' for reading\n", argv[1]);
    return 1;
  }
  // Read the numbers from the file and factorize them
  long double n;
  while (fscanf(file, "%Lf", &n) == 1) {
    // Find the smallest factor of n
    long double factor = 2;
    long double result = fmod(n, factor);
    while (result != 0) {
      factor++;
    }

    // Print the factorization of n
    printf("%0.0Lf=%0.0Lf*%0.0Lf\n", n, n / factor, factor);
  }

  // Close the file
  fclose(file);
  return 0;
}
