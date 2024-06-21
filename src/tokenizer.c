#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
    if (c == ' ' || c == '\t') { 
        return 1;
    }
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
    return !space_char(c);
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str) {
    while (*str && space_char(*str)) {
        str++;
    }
    if (*str == '\0') { return NULL; }
    return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {
    while (*token && non_space_char(*token)) {
        token++;
    }
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
    int count = 0;
    char *start = token_start(str);
    while (start != NULL) {
        count++;
        start = token_start(token_terminator(start));
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    char *new = (char *)malloc(len + 1);
    if (new == NULL) { return NULL; }
    strncpy(new, inStr, len);
    new[len] = '\0';
    return new;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
    int token_count = count_tokens(str);
    char **tokens = (char **)malloc((token_count + 1) * sizeof(char *));
    if (tokens == NULL) return NULL;

    int idx = 0;
    char *start = token_start(str);
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
    int i = 0;
    while (tokens[i] != NULL) {
        printf("tokens[%d] = \"%s\"\n", i, tokens[i]);
        i++;
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
    int i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}