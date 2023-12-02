#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: numbers of letters to be read
 * Return: w- actual number of bytes read and printed
 * 0 when functions fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t n_read, n_written;
char *buffer;
int file;

if (filename == NULL)
return (0);

file = open(filename, O_RDONLY);
if (file == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(file);
return (0);
}

n_read = read(file, buffer, letters);
n_written = write(STDOUT_FILENO, buffer, n_read);

free(buffer);
close(file);

if (n_written != n_read)
return (0);

return (n_written);
}
