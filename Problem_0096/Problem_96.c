/* Problem_96.c */
/* 2012-06-30 */
/* UNDONE */

#include <stdio.h>
#include <string.h>

int DrawSudokuTable(const int [][9]);
int CalcBlock(int no);
int ValidityCheck(const int [][9]);
int CalcX();
int CalcY();

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
    int i, j, k;
    int assume[9][9];
    DrawSudokuTable(data);

    memcpy(assume, data, sizeof(int)* 9 * 9);

    for (i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
        {
            int valid = 0, last_k;

            if (assume[i][j] != 0) continue;
            for (k = 1; k <= 9; k++)
            {
                assume[i][j] = k;
                if (ValidityCheck(assume) == 1)
                {
                    last_k = k;
                    valid++;
                }
                assume[i][j] = 0;
            }
            if (valid == 1)
            {
                assume[i][j] = last_k;
                i = 0;
                j = -1;
                continue;
            }
        }

    DrawSudokuTable(assume);
    printf("%d\n", ValidityCheck(assume));

    return(0);
}

int CalcBlock(int no)
{
    int i0, j0;
    int i, j;
    int sum = 0;

    if (no < 0 || 9 < no)
        return -1;

    i0 = (no / 3) * 3;
    j0 = (no % 3) * 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            sum += data[i0 + i][j0 + j];

    return sum;
}

int ValidityCheck(const int data[][9])
{
    int j0, k0;
    int i, j, k, direction;
    int used_flag, pused_flag;

    // 縦横の検証
    for (direction = 0; direction < 2; direction++)
        for (i = 0; i < 9; i++)
        {
            pused_flag = used_flag = 0;
            for (j = 0; j < 9; j++)
            {
                int num = direction ? data[i][j] : data[j][i];
                pused_flag = used_flag;
                if (num == 0)
                    continue;
                used_flag ^= 1 << (num - 1);
                if (pused_flag > used_flag) // 重複があるとused_flagの値が減少
                    return 0;
            }
        }

    // ブロックの検証
    for (i = 0; i < 9; i++)
    {
        j0 = (i / 3) * 3;
        k0 = (i % 3) * 3;
        pused_flag = used_flag = 0;
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
            {
                pused_flag = used_flag;
                if (data[j0 + j][k0 + k] == 0)
                    continue;
                used_flag ^= 1 << (data[j0 + j][k0 + k] - 1);
                if (pused_flag > used_flag) // 重複があるとused_flagの値が減少
                    return 0;
            }
    }

    return 1;   // pass
}

int DrawSudokuTable(const int data[][9])
{
    int x = 0, y = 0;

    printf("┌───┬───┬───┐\n");
    for (y = 0; y < 9; y++)
    {
        for (x = 0; x < 9; x += 3)
            printf("│ %d %d %d",
                   data[y][x], data[y][x + 1], data[y][x + 2]);
        printf("│\n");
        if (y == 2 || y == 5)
            printf("├───┼───┼───┤\n");
    }
    printf("└───┴───┴───┘\n");

    return 0;
}
