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
  int n;
  while (fscanf(file, "%d", &n) == 1) {
    // Find the smallest factor of n
    int factor = 2;
    while (n % factor != 0) {
      factor++;
    }

    // Print the factorization of n
    printf("%d=%d*%d\n", n, n / factor, factor);
  }

  // Close the file
  fclose(file);
  return 0;
}
