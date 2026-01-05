#include <stdio.h>
#include <stdlib.h>

/* Function to compress a text file using RLE */
void compressFile() {
    FILE *in, *out;
    char ch, prev;
    int count = 1;

    in = fopen("input.txt", "r");
    out = fopen("compressed.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    prev = fgetc(in);

    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }

    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);

    printf("Compression completed successfully.\n");
}

/* Function to decompress an RLE compressed file */
void decompressFile() {
    FILE *in, *out;
    char ch;
    int count, i;

    in = fopen("compressed.txt", "r");
    out = fopen("decompressed.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while ((ch = fgetc(in)) != EOF) {
        fscanf(in, "%d", &count);
        for (i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("Decompression completed successfully.\n");
}

/* Main function */
int main() {
    int choice;

    printf("DATA COMPRESSION TOOL (RLE)\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        compressFile();
    else if (choice == 2)
        decompressFile();
    else
        printf("Invalid choice.\n");

    return 0;
}
