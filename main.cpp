#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#pragma warning(disable : 4996)
struct info
{

    char name[30];
    int num_board;
    int **board;
    int score = 0;

} player;

int max = 0;

void random_generation(int **boa, int n)
{
    int freespace = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (boa[i][j] == 0)
            {
                freespace = 1;
                break;
            }
        }
        if (freespace == 1)
        {
            break;
        }
    }
    if (freespace == 0)
    {
        return;
    }
    int rand_num = rand() % 100;
    int numchanged = 0;
    for (;;)
    {

        if (numchanged == 1)
        {
            break;
        }
        int x = rand() % (n - 1 - 0 + 1) + 0;
        int y = rand() % (n - 1 - 0 + 1) + 0;
        if (boa[x][y] != 0)
        {
            continue;
        }
        if (rand_num <= 70)
        {
            boa[x][y] = 2;
        }
        else if (70 < rand_num <= 95)
        {
            boa[x][y] = 4;
        }
        else
        {
            boa[x][y] = 8;
        }
        numchanged = 1;
    }
}

void make_board(int n)
{

    player.board = (int **)malloc(n * sizeof(int *));
    player.num_board = n;
    for (int i = 0; i < n; i++)
    {
        player.board[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            player.board[i][j] = 0;
        }
    }
    random_generation(player.board, n);
    random_generation(player.board, n);
}

void print_table(int **boa, int n)
{
    system("cls||clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("                                                      ");
        for (int k = 0; k < n; k++)
        {
            printf("%s", " \033[1;34m------\033[0m");
        }
        printf("\n");
        printf("                                                      ");
        printf("%s", "\033[1;34m|\033[0m");
        // printf("\e[31m|\e[34m");
        for (int j = 0; j < n; j++)
        {
            if (boa[i][j] == 0)
            {

                printf("      ");
            }
            else
            {
                int count = 0;
                for (int t = boa[i][j]; t > 0; t /= 10)
                {
                    count++;
                }
                if (count == 1)
                {
                    if (boa[i][j] == 2)
                    {
                        printf("  \033[1;34m%d\033[0m   ", boa[i][j]);
                    }
                    if (boa[i][j] == 4)
                    {
                        printf("  \033[1;31m%d\033[0m   ", boa[i][j]);
                    }
                    if (boa[i][j] == 8)
                    {
                        printf("  \033[1;32m%d\033[0m   ", boa[i][j]);
                    }
                }
                if (count == 2)
                {
                    if (boa[i][j] == 16)
                    {
                        printf("  \033[1;35m%d\033[0m  ", boa[i][j]);
                    }
                    if (boa[i][j] == 32)
                    {
                        printf("  \033[1;41m%d\033[0m  ", boa[i][j]);
                    }
                    if (boa[i][j] == 64)
                    {
                        printf("  \033[1;39m%d\033[0m  ", boa[i][j]);
                    }
                }
                if (count == 3)
                {
                    if (boa[i][j] == 128)
                    {
                        printf(" \033[1;30m%d\033[0m  ", boa[i][j]);
                    }
                    if (boa[i][j] == 256)
                    {
                        printf(" \033[1;42m%d\033[0m  ", boa[i][j]);
                    }
                    if (boa[i][j] == 512)
                    {
                        printf(" \033[1;36m%d\033[0m  ", boa[i][j]);
                    }
                }
                if (count == 4)
                {
                    if (boa[i][j] == 1024)
                    {
                        printf(" \033[1;38m%d\033[0m ", boa[i][j]);
                    }
                    if (boa[i][j] == 2048)
                    {
                        printf(" \033[1;33m%d\033[0m ", boa[i][j]);
                    }
                }
            }
            // printf("|");
            printf("%s", "\033[1;34m|\033[0m");
        }
        printf("\n");
    }
    printf("                                                      ");
    for (int k = 0; k < n; k++)
    {
        printf("%s", " \033[1;34m------\033[0m");
    }
    printf("\n\nYOUR SCORE : %d", player.score);
    printf("\nPRESS 0 FOR EXIT !");
    printf("\nPRESS 1 FOR RESET !");
}

void resetGame()
{
    for (int i = 0; i < player.num_board; i++)
    {
        for (int j = 0; j < player.num_board; j++)
        {
            player.board[i][j] = 0;
        }
    }
    player.score = 0;
    random_generation(player.board, player.num_board);
}

void right(int **boa, int n, char mov)
{
    for (int i = 0; i < n; i++)
    { // sotoon//

        for (;;)
        {
            int end = 0;

            for (int z = n - 1; z >= 1; z--)
            {
                if (boa[i][z] == 0 && boa[i][z - 1] == 0)
                {
                    continue;
                }
                if (boa[i][z] == boa[i][z - 1] || boa[i][z] == 0)
                {
                    if (boa[i][z] == boa[i][z - 1])
                    {
                        player.score += boa[i][z - 1] + boa[i][z];
                    }
                    boa[i][z] = boa[i][z - 1] + boa[i][z];
                    if (boa[i][z] > max)
                    {
                        max = boa[i][z];
                    }
                    boa[i][z - 1] = 0;
                    end = 1;
                }
            }

            if (end != 1)
            {
                break;
            }
        }
    }
}
void left(int **boa, int n, char mov)
{
    for (int i = 0; i < n; i++) // sotoon
    {

        for (;;)
        {
            int end = 0;
            for (int z = 0; z < n - 1; z++)
            {

                if (boa[i][z] == 0 && boa[i][z + 1] == 0)
                {
                    continue;
                }

                if (boa[i][z] == boa[i][z + 1] || boa[i][z] == 0)
                {
                    if (boa[i][z] == boa[i][z + 1])
                    {
                        player.score += boa[i][z + 1] + boa[i][z];
                    }
                    boa[i][z] = boa[i][z + 1] + boa[i][z];
                    if (boa[i][z] > max)
                    {
                        max = boa[i][z];
                    }
                    boa[i][z + 1] = 0;
                    end = 1;
                }
            }
            if (end != 1)
            {
                break;
            }
        }
    }
}
void down(int **boa, int n, char mov)
{
    for (int i = 0; i < n; i++) // satr
    {

        for (;;)
        {

            int end = 0;
            for (int z = n - 1; z >= 1; z--)
            {

                if (boa[z][i] == 0 && boa[z - 1][i] == 0)
                {
                    continue;
                }
                if (boa[z][i] == boa[z - 1][i] || boa[z][i] == 0)
                {
                    if (boa[z][i] == boa[z - 1][i])
                    {
                        player.score += boa[z - 1][i] + boa[z][i];
                    }
                    boa[z][i] = boa[z - 1][i] + boa[z][i];
                    if (boa[i][z] > max)
                    {
                        max = boa[i][z];
                    }
                    boa[z - 1][i] = 0;
                    end = 1;
                }
            }
            if (end != 1)
            {
                break;
            }
        }
    }
}
void up(int **boa, int n, char mov)
{

    for (int i = 0; i < n; i++) // satr
    {
        for (;;)
        {
            int end = 0;
            for (int z = 0; z < n - 1; z++)
            {
                if (boa[z][i] == 0 && boa[z + 1][i] == 0)
                {
                    continue;
                }

                if (boa[z][i] == boa[z + 1][i] || boa[z][i] == 0)
                {
                    if (boa[z][i] == boa[z + 1][i])
                    {
                        player.score += boa[z + 1][i] + boa[z][i];
                    }
                    boa[z][i] = boa[z + 1][i] + boa[z][i];
                    if (boa[i][z] > max)
                    {
                        max = boa[i][z];
                    }
                    boa[z + 1][i] = 0;
                    end = 1;
                }
            }
            if (end != 1)
            {
                break;
            }
        }
    }
}

void movement(int **boa, int n, char mov)
{

    if (mov == 77) // rast
    {
        right(player.board, player.num_board, mov);
    }

    if (mov == 75) // chap
    {
        left(player.board, player.num_board, mov);
    }
    if (mov == 80) // payiin
    {
        down(player.board, player.num_board, mov);
    }
    if (mov == 72) // bala
    {
        up(player.board, player.num_board, mov);
    }
}
int check_lose(int **boa, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                        return 1; // rast
                    if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                        return 1; // payin
                    continue;
                }
                if (j == n - 1)
                {
                    if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                        return 1; // chap
                    if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                        return 1; // payin
                    continue;
                }

                if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                    return 1; // chap
                if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                    return 1; // payin
                if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                    return 1; // rast
                continue;
            }
            if (i == n - 1)
            {
                if (j == 0)
                {
                    if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                        return 1; // bala
                    if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                        return 1; // rast
                    continue;
                }
                if (j == n - 1)
                {
                    if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                        return 1; // bala
                    if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                        return 1; // chap
                    continue;
                }
                if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                    return 1; // chap
                if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                    return 1; // bala
                if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                    return 1; // rast
                continue;
            }
            if (j == 0)
            {
                if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                    return 1; // rast
                if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                    return 1; // bala
                if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                    return 1; // payin
                continue;
            }
            if (j == n - 1)
            {

                if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                    return 1; // chap
                if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                    return 1; // bala
                if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                    return 1; // payin
                continue;
            }
            // vasat morab
            if (boa[i][j] == boa[i][j + 1] || boa[i][j + 1] == 0)
                return 1; // rast
            if (boa[i][j] == boa[i][j - 1] || boa[i][j - 1] == 0)
                return 1; // chap
            if (boa[i][j] == boa[i + 1][j] || boa[i + 1][j] == 0)
                return 1; // payin
            if (boa[i][j] == boa[i - 1][j] || boa[i - 1][j] == 0)
                return 1; // bala
        }
    }

    return 0;
}

void destroy_map(int **boa, int n)
{

    for (int i = 0; i < n; i++)
    {
        free(boa[i]);
    }
    free(boa);
}

int game()
{

    print_table(player.board, player.num_board);
    getchar();
    for (;;)
    {

        printf("\n");
        char mov = _getch();
        if (mov == -32)
        {
            mov = _getch();
        }
        if ((mov == '0') || (mov == '1') || (mov == 77 || mov == 75 || mov == 72 || mov == 80))
        {
            if (mov == '0') // khorooj
            {
                system("cls||clear");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
                printf("GOOD BYE !");
                _sleep(2000);
                return 0;
            }
            if (mov == '1')
            { // reset
                printf("YOU WANT PLAY AGAIN :)");
                _sleep(2000);
                resetGame();
            }
            if (mov == 77 || mov == 75 || mov == 72 || mov == 80)
            {

                movement(player.board, player.num_board, mov);
            }
        }
        else
        {
            printf("your choose is wrong !");
            _sleep(2000);
            continue;
        }
        if (max == 2048)
        {
            system("cls||clear");
            print_table(player.board, player.num_board);
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t");
            printf("%s won the game !!!!\n\n\n", player.name);
            printf("Press any key");
            _getch();
            destroy_map(player.board, player.num_board);
            return 0;
        }
        int check = check_lose(player.board, player.num_board);
        if (check == 0)
        {

            printf("\n\n\n");
            printf("%s lose the game !!!!\n\n", player.name);
            printf("Press any key");
            _getch();
            destroy_map(player.board, player.num_board);
            return 0;
        }
        random_generation(player.board, player.num_board);

        print_table(player.board, player.num_board);
    }
}

int menu()
{

    system("cls||clear");
    printf("\nchoose your favorite board :\n");
    printf("\n1.easy(6*6)\n");
    printf("\n2.average (5*5)\n");
    printf("\n3.hard(4*4)\n");
    printf("\n4.your favorite length\n");
    printf("\n5.Exit :(\n");
    int choose;
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        make_board(6);
        break;
    case 2:
        make_board(5);
        break;
    case 3:
        make_board(4);
        break;
    case 4:
        printf("enter your favorite length :\n");
        scanf("%d", &player.num_board);
        make_board(player.num_board);
        break;
    case 5:
        return 0;
    default:
        system("cls||clear");
        printf("\n\n\n\t\t\twrong input!!\n");
        printf("Press any key");
        _getch();
        system("cls||clear");
        return 2;
    }
    return 1;
}
int main()
{
    printf("enter your username :");
    scanf("%s", player.name);
    srand(time(0));
    for (;;)
    {
        int choose = menu();
        if (choose == 0)
        {
            system("cls||clear");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
            printf("GOOD BYE !!!");
            _sleep(2000);
            return 0;
        }
        if (choose == 1)
        {
            game();
            player.score = 0;
        }
        if (choose == 2)
        {
            continue;
        }
    }
    return 0;
}