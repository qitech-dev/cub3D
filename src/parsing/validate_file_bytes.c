#include "cub3d.h"

int validate_file_bytes(char *filename)
{
    int		fd;
    int		bytes_read;
    int		i;
    char	buffer[1024];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (parser_error("Cannot open file"));
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\0')
			{
				close(fd);
				return (parser_error("NUL byte in scene file"));
			}
			i++;
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
	{
		close(fd);
		return (parser_error("Failed to read file"));
	}
	close(fd);
	return (0);
}
