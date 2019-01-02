/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_text_analyzer.c                                   */
/* ****************************************************** */

#include "mpsh_text_analyzer.h"


#define MPSH_TOKEN 256
#define MPSH_WHITE " \t\r\n\a"
#define MPSH_BUFFER_SIZE 512


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

char *remove_first_equal(char *word)
{
  if(word[0] == '=')
  {
    char *temp = malloc(sizeof(char)*(strlen(word)));
    memset(&temp[strlen(temp)-1], '\0', 1);
    strcpy(temp, &word[1]);
    if(temp == NULL)
    {
      fprintf(stderr, "%s\n", strerror( errno ) );
      exit(EXIT_FAILURE);
    }
    return temp;
  }
  return word;
}

char *after_equal_signe_from_line(char *line, char *target)
{
  char **line_tokens = mpsh_toknizer(line);
  int i = 0;
  printf("start t \n" );
  while(line_tokens[i])
  {
    if((strstr(line_tokens[i], target)) != NULL)
    {
      printf("token :%s\n", line_tokens[i]);
    }
    i++;
  }
  return NULL;
}

int int_target_from_line(char *line, char *target)
{
  char *temp;
  temp = after_equal_signe_from_line(line, target);
  char *temp_1 = remove_first_equal(temp);
  return atoi(temp_1);
}
