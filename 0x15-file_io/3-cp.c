#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_buffer - Allocates memory 1024 bytes..
 * @file: filename for which buffer is storing chars for.
 *
 * Return: pointer to the newly-created buffer.
 */

char *new_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_fd - close file descriptors
 * @fd: file descriptor to be closed
 */

void close_fd(int fd)
{
	int closed;

	closed = close(fd);

	if (closed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: counts of arguments passed to the program
 * @argv: array of pointer(s) to the arguments
 *
 * Return: 0 on success.
 *
 * Description: incorrect argument counts - exit code 97.
 *              file non-existent or non-readable - exit code 98.
 *              file_to cannot be created or written - exit code 99.
 *              file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = new_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	read_bytes = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(file_to, buffer, read_bytes);
		if (file_to == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);
	free(buffer);
	close_fd(file_from);
	close_fd(file_to);
	return (0);
}
