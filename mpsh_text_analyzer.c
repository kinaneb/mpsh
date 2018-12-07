/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_text_analyzer.c                                   */
/* ****************************************************** */

#include "mpsh_text_analyzer.h"


#define MPSH_TOKEN 256
#define MPSH_WHITE " \t\r\n\a"
#define MPSH_BUFFER_SIZE 1024


char *mpsh_read_line(void)
{
  int buffer_size = MPSH_BUFFER_SIZE;
  int i = 0;
  char *buffer = malloc(sizeof(char) * buffer_size);
  int c;

  if (!buffer) {
    fprintf(stderr, "error malloc mpsh_read_line!\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[i] = '\0';
      return buffer;
    } else {
      buffer[i] = c;
    }
    i++;

    if (i >= buffer_size) {
      buffer_size += MPSH_BUFFER_SIZE;
      buffer = realloc(buffer, buffer_size);
      if (!buffer) {
        fprintf(stderr, "error realloc mpsh_read_line!\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


char **mpsh_toknizer(char *line)
{
  int buffer_size = MPSH_TOKEN, i = 0;
  char **line_tokens = malloc(buffer_size * sizeof(char*));
  char *token;

  if (!line_tokens) {
    fprintf(stderr, "%s\n", strerror( errno ) );
    exit(EXIT_FAILURE);
  }

  token = strtok(line, MPSH_WHITE);
  while (token != NULL) {
    line_tokens[i] = token;
    i++;

    if (i >= buffer_size) {
      buffer_size += MPSH_TOKEN;
      line_tokens = realloc(line_tokens, buffer_size * sizeof(char*));
      if (!line_tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, MPSH_WHITE);
  }
  line_tokens[i] = NULL;
  return line_tokens;
}
