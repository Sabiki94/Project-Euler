/* Problem_96.c */
/* 2012-06-30 */
/* UNDONE */

#include <stdio.h>

int DrawSudokuTable();
const int data[9][9] = {
    { 0, 0, 3, 0, 2, 0, 6, 0, 0 },
    { 9, 0, 0, 3, 0, 5, 0, 0, 1 },
    { 0, 0, 1, 8, 0, 6, 4, 0, 0 },
    { 0, 0, 8, 1, 0, 2, 9, 0, 0 },
    { 7, 0, 0, 0, 0, 0, 0, 0, 8 },
    { 0, 0, 6, 7, 0, 8, 2, 0, 0 },
    { 0, 0, 2, 6, 0, 9, 5, 0, 0 },
    { 8, 0, 0, 2, 0, 3, 0, 0, 9 },
    { 0, 0, 5, 0, 1, 0, 3, 0, 0 }
};

int main(void)
{
    DrawSudokuTable();

    return(0);
}

int DrawSudokuTable()
{
    int x = 0, y = 0;

    printf(" ÅQÅQÅQÅQÅQÅQÅQÅQÅQ\n");
    for (y = 0; y < 3; y++){
        for (x = 0; x < 9; x += 3){
            printf("|%d %d %d",
                data[y][x], data[y][x + 1], data[y][x + 2]);
        }
        printf("|\n");
    }
    printf(" ÅPÅPÅPÅPÅPÅPÅPÅPÅP\n");

    return 0;
}
