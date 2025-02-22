#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>


#define MAX_FILE_NAME 100
#define MAX_WORD_SIZE 50

int main() {
    char file_name[MAX_FILE_NAME];
    FILE *fp;
    char ch;
    int num_chars = 0, num_words = 0, num_lines = 0;
    int in_word = 0;
    char word[MAX_WORD_SIZE];

    printf("Enter file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Could not open file %s", file_name);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        num_chars++;

        if (ch == '\n') {
            num_lines++;
        }

        if (isspace(ch)) {
            if (in_word) {
                in_word = 0;
                num_words++;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                word[0] = ch;
                word[1] = '\0';
            } else {
                int word_len = strlen(word);
                if (word_len < MAX_WORD_SIZE - 1) {
                    word[word_len] = ch;
                    word[word_len + 1] = '\0';
                }
            }
        }
    }

    if (in_word) {
        num_words++;
    }

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    fclose(fp);

    return 0;
}

