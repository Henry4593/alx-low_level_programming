#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: -1 function fails or filename is NULL,file does not exist, the user
 * lacks write permissions. 1 on success
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int open_fd, write_bytes, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	open_fd = open(filename, O_WRONLY | O_APPEND);
	write_bytes = write(open_fd, text_content, len);

	if (open_fd == -1 || write_bytes == -1)
		return (-1);

	close(open_fd);

	return (1);
}
