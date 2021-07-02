#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
	fprintf(stderr, "Invalid Call\n");
	return 1;
    }

    FILE *pointer = fopen(argv[1], "r");

    char name;

    do
    {
	name = fgetc(pointer);
	printf("%c", name);
    } while (name != EOF);

    fclose(pointer);

    printf("\n");

    return 0;
}
