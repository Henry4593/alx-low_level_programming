#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: pointer to the file to be created
 * @text_content: pointer to the string to write to the file.
 *
 * Return: function failure -1, 1 on success
 */

int create_file(const char *filename, char *text_content)
{
	int open_fd, write_bytes, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	open_fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_bytes = write(open_fd, text_content, len);

	if (open_fd == -1 || write_bytes == -1)
		return (-1);

	close(open_fd);

	return (1);
}
