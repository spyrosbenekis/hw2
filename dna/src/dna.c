#include <stdio.h>
#include <stdlib.h>

#define MAX_BASES 100000

int is_ok(char c){
    return c == 'A' || c == 'G' || c == 'T' || c == 'C';
}

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Usage: %s file1.txt file2.txt\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file1, 0, SEEK_END);
    long N = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    fseek(file2, 0, SEEK_END);
    long M = ftell(file2);
    fseek(file2, 0, SEEK_SET);

    if(N == 0 || M == 0)
        return 1;
    else{
        // Διαβάζουμε τα αρχεία
        char *text1 = (char *)malloc(N + 1);
        char *text2 = (char *)malloc(M + 1);

        if (text1 == NULL || text2 == NULL) {
            perror("Memory allocation error");
            return 1;
        }

        int n = fread(text1, 1, N, file1);
        int m = fread(text2, 1, M, file2);

        if(n != N || m != M)
            return 1;

        // Αναζήτηση κοινής ακολουθίας
        int max_common = 0;
        int start1 = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int k = 0;
                while (i + k < N && j + k < M && text1[i + k] == text2[j + k]) {
                    k++;
                }   

                if (k > max_common) {
                    max_common = k;
                    start1 = i;
                }
            }
        }

        if (max_common > 0) {
            int max[MAX_BASES];
            int count = 0;
            for (int i = 0; i < max_common; i++) {
                if(is_ok(text1[start1 + i])){
                    max[count] = text1[start1 + i];
                    count++;
                }
            }
            for (int i = 0; i < count; i++) {
                printf("%c", max[i]);
            }
            printf("\n");
        }


        free(text1);
        free(text2);
    }
    fclose(file1);
    fclose(file2);

    return 0;
}