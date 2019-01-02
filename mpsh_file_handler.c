/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_file_handler.c                                    */
/* ****************************************************** */

#include "mpsh_file_handler.h"


void append_line_to_file(char *file_dir, char *line)
{
  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "%s\n", line);
    // Close the file
    fclose(file_pointer);
  }
  else // file is exist
  {
  FILE *file_pointer;
  file_pointer = fopen (file_dir, "a+");
  if (file_pointer == NULL) // fail of opening file
  {
    perror("error opening file.\n");
    //exit(EXIT_FAILURE);
  }
  fprintf(file_pointer, "%s\n", line);
  fclose(file_pointer); // close file
  }
}

int file_length(char *file_dir)
{
  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
    return 0;
  }
  else // file is exist
  {
    int c = 0;
    int i = 1;
    FILE *file_pointer;
    file_pointer = fopen (file_dir, "r");
    if (file_pointer == NULL) // fail of opening file
    {
      perror("error opening file.\n");
      exit(EXIT_FAILURE);
    }
    while (c != EOF)
    {
      c = getc(file_pointer);
      if (c == '\n')
      {
        i++;
      }
    }
    fclose(file_pointer); // close file
    return i;
  }
}

char *temp_dir_from_dir(char *path, char *temp)
{
  char *dir_temp = malloc(sizeof(char)*(strlen(path)+strlen(temp)+1));; // 1 + 4 len("temp")
  memset(&dir_temp[strlen(dir_temp)-1], '\0', 1);
  strcpy(dir_temp,path);
  if(dir_temp == NULL)
  {
    fprintf(stderr, "%s\n", strerror( errno ) );
    exit(EXIT_FAILURE);
  }

  int len = (int)strlen(dir_temp);
  int i = 0;
  for( ; (i < len && dir_temp[len-i] != '/' );i++){}
  memset(&dir_temp[strlen(dir_temp)-i+1], '\0', 1);
  strcat(dir_temp, temp);
  return dir_temp;
}


void remove_first_n_line(char *file_dir, int n)
{
  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
  }
  else // file is exist
  {
    int c =0;
    char *dir_temp;
    FILE *file_pointer;
    FILE *temp;
    file_pointer = fopen (file_dir, "r");
    if (file_pointer == NULL) // fail of opening file
    {
      perror("error opening file.\n");
      exit(EXIT_FAILURE);
    }
    while (c != EOF && n > 0)
    {
      c = getc(file_pointer);
      if (c == '\n')
      {
        n--;
      }
    }
    dir_temp = temp_dir_from_dir(file_dir, "mpsh_temp");
    temp = fopen (dir_temp, "w");
    c = fgetc(file_pointer);
    while (c != EOF)
    {
        fputc(c, temp);
        c = fgetc(file_pointer);
    }
    fclose(file_pointer); // close file
    fclose(temp); // close file
    remove(file_dir); // remove the original file
    rename(dir_temp, file_dir); 	// rename the temporary file to original name
  }
}

void limited_append_line(char *file_dir, char *line, int max)
{
  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
  }
  else // file is exist
  {
    FILE *file_pointer;
    file_pointer = fopen(file_dir, "r+");
    int d = max - file_length(file_dir);
    if(!(d > 0))
    {
      remove_first_n_line(file_dir, (-1*d)+1);
    }
      append_line_to_file(file_dir, line);
  }
}

char *find_line_in_file(char *file_dir, char *word)
{
  if(access(file_dir, F_OK)) // .file is not exist
  {
    return NULL;
  }
  else // file is exist
  {

    FILE *file_pointer;
    char c[513];
    //int len = strlen(word);
    file_pointer = fopen(file_dir, "r");
    while(fgets(c, 512, file_pointer) != NULL)
    {
      if((strstr(c, word)) != NULL)
      {
        //fgets(c, 512, file_pointer);
        char *line = malloc(sizeof(char)*(512+1));
        memset(&line[strlen(line)-1], '\0', 1);
        strcpy(line, c);
        if(!line)
        {
          fprintf(stderr, "%s\n", strerror( errno ) );

        }
        printf("start find .. %s \n", line );
        return line;
      }
    }
    return NULL;
  }
}


void remove_last_n_line(char *file_dir, int n)
{

  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
  }
  else // file is exist
  {
    int c =0;
    char *dir_temp;
    FILE *file_pointer;
    FILE *temp;
    int len = file_length(file_dir);
    int deff = len - n;
    if(deff > 0)
    {
      file_pointer = fopen (file_dir, "r");
      if (file_pointer == NULL) // fail of opening file
      {
        perror("error opening file.\n");
        exit(EXIT_FAILURE);
      }

      dir_temp = temp_dir_from_dir(file_dir, "mpsh_temp");
      temp = fopen (dir_temp, "w");
      c = getc(file_pointer);
      while (c != EOF && deff > 0)
      {
        fputc(c, temp);
        c = fgetc(file_pointer);
        if (c == '\n')
        {
          deff--;
        }
      }
      fclose(file_pointer); // close file
      fclose(temp); // close file
      remove(file_dir); // remove the original file
      rename(dir_temp, file_dir); 	// rename the temporary file to original name
    }
    else
    {
      remove(file_dir);
      FILE *file_pointer;
      // open the file "dir/.../name_of_file.txt" for writing
      file_pointer = fopen(file_dir, "ab");
      // Write to the file
      fprintf(file_pointer, "");
      // Close the file
      fclose(file_pointer);
    }

  }
}

void limited_append_table(char *file_dir, table table , int max)
{
  int table_len = table_length(table);
  if(access(file_dir, F_OK)) // .file is not exist
  {
    FILE *file_pointer;
    // open the file "dir/.../name_of_file.txt" for writing
    file_pointer = fopen(file_dir, "ab");
    // Write to the file
    fprintf(file_pointer, "");
    // Close the file
    fclose(file_pointer);
    if(HISTFILESIZE > table_len)
      {
        for(int i = 0; i < table_len; i++)
        {
          limited_append_line(file_dir, n_row_text(table, i), HISTFILESIZE);
        }
      }
      else
      {
        for(int i = table_len - HISTFILESIZE; i <= table_len; i++)
        {
          limited_append_line(file_dir, n_row_text(table, i), HISTFILESIZE);
        }
      }
  }
  else // file is exist
  {
    int file_len = file_length(file_dir);
    int empty = HISTFILESIZE - file_len;
    if(history_init_len < table_len)
    {
      int lines_to_add = table_len - history_init_len;
      if(empty < lines_to_add)
      {
        remove_first_n_line(file_dir, lines_to_add - empty);
      }
      for(int i = table_len - history_init_len; i <= table_len; i++)
      {
        limited_append_line(file_dir, n_row_text(table, i), HISTFILESIZE);
      }
    }
    else
    {
      remove_last_n_line(file_dir, table_len);
      for(int i = 0; i < table_len; i++)
      {
        limited_append_line(file_dir, n_row_text(table, i), HISTFILESIZE);
      }
    }
  }
}
