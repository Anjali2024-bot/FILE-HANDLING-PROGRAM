#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fptr;
  char filename[] = "my_file.txt";
  char data[100];

  // Create and Write to file
  fptr = fopen(filename, "w");
  if (fptr == NULL) {
    printf("Error creating file.\n");
    return 1;
  }
  printf("Enter data to write to the file: ");
  fgets(data, sizeof(data), stdin);
  fprintf(fptr, "%s", data);
  fclose(fptr);

  // Read from file
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("Error opening file for reading.\n");
    return 1;
  }
  printf("\nData read from the file:\n");
  while (fgets(data, sizeof(data), fptr) != NULL) {
    printf("%s", data);
  }
  fclose(fptr);

  // Append to file
  fptr = fopen(filename, "a");
  if (fptr == NULL) {
      printf("Error opening file for appending.\n");
      return 1;
  }
  printf("\nEnter data to append to the file: ");
  fgets(data, sizeof(data), stdin);
  fprintf(fptr, "%s", data);
  fclose(fptr);

  // Read and display the content after appending
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("Error opening file for reading after appending.\n");
    return 1;
  }
  printf("\nData in the file after appending:\n");
  while (fgets(data, sizeof(data), fptr) != NULL) {
    printf("%s", data);
  }
  fclose(fptr);
  return 0;
}
