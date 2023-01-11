#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

// #define EOF_TOKEN 0

typedef enum
{
    COMMAND_TOKEN,
    ARGUMENT_TOKEN,
    PIPE_TOKEN,
    BACKGROUND_TOKEN,
    EOF_TOKEN = -1
} TokenType;

typedef struct
{
    TokenType type;
    char *value;
} Token;

Token get_next_token()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        // Ignore leading whitespace
        if (isspace(c))
        {
            continue;
        }

        // Handle tokens
        if (c == '|')
        {
            return (Token){PIPE_TOKEN, "|"};
        }
        else if (c == '&')
        {
            return (Token){BACKGROUND_TOKEN, "&"};
        }
        else if (c == '"')
        {
            // Read until the closing quotation mark
            char *value = malloc(1024);
            int i = 0;
            while ((c = getchar()) != EOF && c != '"')
            {
                value[i++] = c;
            }
            value[i] = '\0';
            return (Token){ARGUMENT_TOKEN, value};
        }
        else
        {
            // Read until whitespace or a special character
            char *value = malloc(1024);
            int i = 0;
            while (!isspace(c) && c != '|' && c != '&' && c != EOF)
            {
                value[i++] = c;
                c = getchar();
            }
            // Put the non-alphanumeric character back in the input stream
            ungetc(c, stdin);
            value[i] = '\0';
            return (Token){COMMAND_TOKEN, value};
        }
    }

    // Return EOF token
    return (Token){EOF_TOKEN, ""};
}

int main()
{
    printf("Enter a command: ");
    Token token = get_next_token();
    while (token.type != EOF_TOKEN)
    {
        if (token.type == COMMAND_TOKEN)
        {
            printf("Command: %s\n", token.value);
        }
        else if (token.type == ARGUMENT_TOKEN)
        {
            printf("Argument: %s\n", token.value);
        }
        else if (token.type == PIPE_TOKEN)
        {
            printf("Pipe\n");
        }
        else if (token.type == BACKGROUND_TOKEN)
        {
            printf("Background\n");
        }
        token = get_next_token();
    }

    return 0;
}