#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "auto",
        "break",
        "case",
        "char",
        "const",
        "continue",
        "default",
        "do",
        "double",
        "else",
        "enum",
        "extern",
        "float",
        "for",
        "goto",
        "if",
        "int",
        "long",
        "register",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "struct",
        "switch",
        "typedef",
        "union",
        "unsigned",
        "void",
        "volatile",
        "while",
    };

    int i, x = -1;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            x = i;
            break;
        }
    }
    return x;
}

int main(int argc, char *argv[])
{
    char ch, buffer[15], comment[3];
    char operators[] = "+-*/%=!<>&|^,;:.~?";
    char parentheses[] = "()[]{}";
    char parenthesesToken[6][20] = {"LPAREN_TOK", "RPAREN_TOK", "LBRACK_TOK", "RBRACK_TOK", "LCURLY_TOK", "RCURLY_TOK"};
    char operatorsToken[24][20] = {"PLUS_TOK", "MINUS_TOK", "STAR_TOK", "FSLASH_TOK", "PERCENT_TOK", "EQ_TOK", "NOTEQ_TOK",
                                   "LT_TOK", "GT_TOK", "AND_TOK", "OR_TOK", "XOR_TOK", "COMMA_TOK", "SEMICOLON_TOK", "COLON_TOK",
                                   "DOT_TOK", "TILDE_TOK", "QUES_TOK"};
    char keywordsToken[32][20] = {"AUTO_TOK", "BREAK_TOK", "CASE_TOK", "CHAR_TOK", "CONST_TOK", "CONTINUE_TOK", "DEFAULT_TOK",
                                  "DO_TOK", "DOUBLE_TOK", "ELSE_TOK", "ENUM_TOK", "EXTERN_TOK", "FLOAT_TOK", "FOR_TOK", "GOTO_TOK",
                                  "IF_TOK", "INT_TOK", "LONG_TOK", "REGISTER_TOK", "RETURN_TOK", "SHORT_TOK", "SIGNED_TOK",
                                  "SIZEOF_TOK", "STATIC_TOK", "STRUCT_TOK", "SWITCH_TOK", "TYPEDEF_TOK", "UNION_TOK",
                                  "UNSIGNED_TOK", "VOID_TOK", "VOLATILE_TOK", "WHILE_TOK"};
    int keywordsTokenNum[32];
    for (int i = 256; i < 256 + 32; i++)
        keywordsTokenNum[i - 256] = i;

    int parenthesesTokenNum[6] = {'(', ')', '[', ']', '{', '}'};
    int operatorsTokenNum[24] = {'+', '-', '*', '/', '%', '=', '!', '<', '>', '&', '|', '^', ',', ';', ':', '.', '~', '?'};

    FILE *fp;
    int i, j = 0, lc = 1, k = 0;
    if (argc == 2)
        fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }

    printf("Line %d:\n", lc++);
    while ((ch = fgetc(fp)) != EOF)
    {
        int x;

        // ignore if what follows is a single-line comment
        if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
                while ((ch = fgetc(fp)) != '\n')
                    ;
            else
                fseek(fp, -2, SEEK_CUR);
        }

        // ignore if what follows is a pre-process directive
        if (ch == '#')
            while ((ch = fgetc(fp)) != '\n')
                ;

        // check if the character is a single-character lexeme (operator / parentheses)
        for (i = 0; i < 18; ++i)
        {
            if (ch == operators[i])
                printf("%c is operator (%s %d)\n", ch, operatorsToken[i], operatorsTokenNum[i]);
        }

        for (i = 0; i < 6; ++i)
        {
            if (ch == parentheses[i])
                printf("%c is operator (%s %d)\n", ch, parenthesesToken[i], parenthesesTokenNum[i]);
        }

        // check if we are encountering an identifier
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if (j != 0)
        {
            buffer[j] = '\0';
            j = 0;

            if ((x = isKeyword(buffer)) != -1)
                printf("%s is keyword (%s %d)\n", buffer, keywordsToken[x], keywordsTokenNum[x]);
            else
                printf("%s is identifier\n", buffer);
        }
        if (ch == '\n')
            printf("\nLine %d:\n", lc++);
    }
    fclose(fp);
    return 0;
}