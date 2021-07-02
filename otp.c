/*
 * otp
 *
 * 29.06.2021
 * Denis Bolintineanu and Georgios Gerontidis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // read in File
    FILE *pointer = fopen(argv[1], "r");

    if (argc != 4)
    {
	fprintf(stderr, "Invalid Call\n");
	return 1;
    }

    int n = 0;
    while (fgetc(pointer) != EOF)
    n++;

    pointer = fopen(argv[1], "r");

    char *file = (char*) malloc(sizeof (char) * n);
    for (int i = 0; i < n; i++)
    {
	file[i] = fgetc(pointer);
    }

    fclose(pointer);

    // read in Key
    pointer = fopen(argv[2], "r");

    int m = 0;
    while (fgetc(pointer) != EOF)
	m++;

    // Error handling
    if (n > m)
    {
	fprintf(stderr, "Error\n");
	return 1;
    }

    pointer = fopen(argv[2], "r");

    char *key = (char*) malloc(sizeof (char) * m);
    if (key == NULL)
    {
	fprintf(stderr, "Memory allocation fault\n");
	return 1;
    }

    for (int i = 0; i < m; i++)
    {
	key[i] = fgetc(pointer);
    }

    fclose(pointer);

    // Decoding with XOR
    for (int i = 0; i < n; i++)
    {
	file[i] = file[i]^key[i];
    }

    free(key);

    // write encrypted File
    pointer = fopen(argv[3], "w");

    for (int i = 0; i < n; i++)
    {
        fputc(file[i] ,pointer);
    }

    fclose(pointer);

    free(file);

    return 0;
}
