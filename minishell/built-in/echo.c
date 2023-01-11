#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int j;
    int newline;
    int flag_n;

    j = 1;
    i = 1;
    newline = 1; // assume que será impresso uma quebra de linha no final
    if (argc > 1 && argv[1][0] == '-')
    {
        flag_n = 1;
        while (argv[1][j] != '\0')
        {
            if (argv[1][j] != 'n')
            {
                flag_n = 0;
                break;
            }
            j++;
        }
        if (flag_n)
        {
            newline = 0;
            i = 2;
        }
    }

    // imprime todos os argumentos, com o tratamento adequado de caracteres de escape
    while (i < argc)
    {
        char *arg = argv[i];
        int len = strlen(arg);
        int j = 0;
        while (j < len)
        {
            char c = arg[j];
            if (c == '\"' || c == '\'')
            {
                // trata aspas
                if (arg[j - 1] != '\\')
                {
                    j++;
                    continue;
                }
            }
            if (c == '\\')
            {
                j++;
                c = arg[j];
                // trata caracteres de escape
                if (c == 'a')
                {
                    putchar('\a');
                }
                else if (c == 'b')
                {
                    putchar('\b');
                }
                else if (c == 'c')
                {
                    newline = 0;
                }
                else if (c == 'f')
                {
                    putchar('\f');
                }
                else if (c == 'n')
                {
                    putchar('\n');
                }
                else if (c == 'r')
                {
                    putchar('\r');
                }
                else if (c == 't')
                {
                    putchar('\t');
                }
                else if (c == 'v')
                {
                    putchar('\v');
                }
                else if (c == '\"')
                {
                    putchar('\"');
                }
                else if (c == '\'')
                {
                    putchar('\'');
                }
                else if (c == '\\')
                {
                    putchar('\\');
                }
                else
                {
                    putchar(c);
                }
                j++;
                continue;
            }
            putchar(c);
            j++;
        }
        if (i != argc - 1)
        {
            putchar(' ');
        }
        i++;
    }

    // imprime a quebra de linha, se necessário
    if (newline)
    {
        putchar('\n');
    }
    return 0;
}

/*
Neste exemplo, a função "echo" foi criada a partir do código da main.
Ela recebe uma string como parâmetro e usa uma função auxiliar "makeargv"
para converter essa string em um vetor de argumentos argv, que é então usado
pelo restante do código. A função "echo" não retorna nenhum valor e
imprime a saída como o comando "echo" do shell.
*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// void echo(char *input)
// {
//     int i;
//     int j;
//     int newline;
//     int flag_n;

//     j = 1;
//     i = 1;
//     newline = 1; // assume que será impresso uma quebra de linha no final
//     char *argv[10];
//     int argc = makeargv(input, " \t", &argv);

//     if (argc > 1 && argv[1][0] == '-')
//     {
//         flag_n = 1;
//         while (argv[1][j] != '\0')
//         {
//             if (argv[1][j] != 'n')
//             {
//                 flag_n = 0;
//                 break;
//             }
//             j++;
//         }
//         if (flag_n)
//         {
//             newline = 0;
//             i = 2;
//         }
//     }

//     // imprime todos os argumentos, com o tratamento adequado de caracteres de escape
//     while (i < argc)
//     {
//         char *arg = argv[i];
//         int len = strlen(arg);
//         int j = 0;
//         while (j < len)
//         {
//             char c = arg[j];
//             if (c == '\"' || c == '\'')
//             {
//                 // trata aspas
//                 if (arg[j - 1] != '\\')
//                 {

//                     j++;
//                     continue;
//                 }
//             }
//             if (c == '\\')
//             {
//                 j++;
//                 c = arg[j];
//                 // trata caracteres de escape
//                 if (c == 'a')
//                 {
//                     putchar('\a');
//                 }
//                 else if (c == 'b')
//                 {
//                     putchar('\b');
//                 }
//                 else if (c == 'c')
//                 {
//                     newline = 0;
//                 }
//                 else if (c == 'f')
//                 {
//                     putchar('\f');
//                 }
//                 else if (c == 'n')
//                 {
//                     putchar('\n');
//                 }
//                 else if (c == 'r')
//                 {
//                     putchar('\r');
//                 }
//                 else if (c == 't')
//                 {
//                     putchar('\t');
//                 }
//                 else if (c == 'v')
//                 {
//                     putchar('\v');
//                 }
//                 else if (c == '\"')
//                 {
//                     putchar('\"');
//                 }
//                 else if (c == '\'')
//                 {
//                     putchar('\'');
//                 }
//                 else if (c == '\\')
//                 {
//                     putchar('\\');
//                 }
//                 else
//                 {
//                     putchar(c);
//                 }
//                 j++;
//                 continue;
//             }
//             putchar(c);
//             j++;
//         }
//         if (i != argc - 1)
//         {
//             putchar(' ');
//         }
//         i++;
//     }

//     // imprime a quebra de linha, se necessário
//     if (newline)
//     {
//         putchar('\n');
//     }
// }

// int main(int argc, char const *argv[])
// {
//     echo("-nnnnnnnnn rato \"kiko\"");
//     return 0;
// }
