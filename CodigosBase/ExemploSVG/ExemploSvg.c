#include <stdio.h>

int main()
{
    FILE *file = fopen("name.svg", "w");

    /*for (int a = 0; a < 10000; a++)
        fprintf(file, "The quick brown foz jumps over the lazy dog. ");*/

    fprintf(file, "<svg xmlns='http://www.w3.org/2000/svg'><rect x='3' y='3' width='200' height='100' stroke='green' stroke-width='4' fill='yellow'/></svg>");

    fclose(file);

    return 0;
}