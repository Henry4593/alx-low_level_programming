#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the
 * POSIX standard output.
 * @filename: a pointer to the file to be processed
 * @letters: The number of characters to be read and printed
 *
 * Return: 0 on failure.filename is NULL or failed memory allocation
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t open_fd, read_bytes, write_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	open_fd = open(filename, O_RDONLY);
	read_bytes = read(open_fd, buffer, letters);
	write_bytes = write(STDOUT_FILENO, buffer, read_bytes);

	if (open_fd == -1 || read_bytes == -1 || write_bytes == -1 ||
			write_bytes != read_bytes)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(open_fd);

	return (write_bytes);
}
