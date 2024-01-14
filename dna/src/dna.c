#include <stdio.h>
#include <stdlib.h>

#define MAX_BASES 100000

// Function to check if a character is one of 'A', 'G', 'T', or 'C'
int is_ok(char c){
    return c == 'A' || c == 'G' || c == 'T' || c == 'C';
}

int main(int argc, char *argv[]) {
    
    // Check for the correct number of command-line arguments
    if (argc != 3) {
        printf("%s file1.txt file2.txt\n", argv[0]);
        return 1;
    }

    // Open the two files for reading
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    // Check for errors in file opening
    if (file1 == NULL || file2 == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Calculate the size of each file
    fseek(file1, 0, SEEK_END);
    long N = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    fseek(file2, 0, SEEK_END);
    long M = ftell(file2);
    fseek(file2, 0, SEEK_SET);

    // Check if either file is empty
    if (N == 0 || M == 0)
        return 1;
    else {
        // Allocate memory to store file contents
        char *text1 = (char *)malloc(N + 1);
        char *text2 = (char *)malloc(M + 1);

        // Read the contents of the files into memory
        int n = fread(text1, 1, N, file1);
        int m = fread(text2, 1, M, file2);

        // Check if the expected number of bytes were read
        if (n != N || m != M)
            return 1;

        // Find the longest common sequence
        int max_common = 0;
        int start1 = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int k = 0;
                // Check for a common sequence
                while (i + k < N && j + k < M && text1[i + k] == text2[j + k]) {
                    k++;
                }   

                // Update if a longer common sequence is found
                if (k > max_common) {
                    max_common = k;
                    start1 = i;
                }
            }
        }

        // Print the longest common sequence composed of 'A', 'G', 'T', 'C'
        if (max_common > 0) {
            int max[MAX_BASES];
            int count = 0;
            for (int i = 0; i < max_common; i++) {
                if (is_ok(text1[start1 + i])) {
                    max[count] = text1[start1 + i];
                    count++;
                }
            }
            for (int i = 0; i < count; i++) {
                printf("%c", max[i]);
            }
            printf("\n");
        }

        // Free allocated memory
        free(text1);
        free(text2);
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}