

#define MAX_WIDTH 100

typedef struct s_list {
	char 			*line;
	struct s_list 	*next;
}	t_list;

t_list	*create_new_pearl(void *line_text)
{
	t_list	*new_pearl;

	new_pearl = (t_list *)malloc(sizeof(t_list));
	if (new_pearl == NULL)
		return (NULL);
	new_pearl->line = line_text;
	new_pearl->next = NULL;
	return (new_pearl);
}
void attach_pearl_at_end(t_list **necklace, t_list *new_pearl)
{
	if (!*necklace)
		*necklace = new_pearl;
	else
	{
		t_list *current = *necklace;
		while (current->next)
			current = current->next;
		current->next = new_pearl;
	}
}
void free_necklace(t_list *necklace)
{
	t_list	*temp;

	while (necklace)
	{
		temp = necklace;
		necklace = necklace->next;
		free(temp->line);
		free(temp);
	}
}

t_list *string_lines_to_necklace(char *filename)
{
	t_list	*necklace;
	char	*line;
	int		fd;
	t_list	*pearl;
	t_game	game;
	int		len;

	necklace = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return NULL;
	}
	line = get_next_line(fd);
	while (line)
	{
		game.line = malloc(ft_strlen(line) + 1);
		if (!game.line)
		{
			free_necklace(necklace);
			close(fd);
			return (NULL);
		}
		len = ft_strlen(line);
		ft_strlcpy(game.line, line, len + 1);
		line = create_new_pearl(line);
		if (!line)
		{
			free_necklace(necklace);
			close(fd);
			return NULL;
		}
		attach_pearl_at_end(&necklace, line);
		line = get_next_line(fd);
	}
	close(fd);
	return necklace;
}

int main(int argc, char **argv)
{
	t_list	*current;
	t_list	*necklace;

	necklace = string_lines_to_necklace(argv[1]);
	if (argc < 2)
	{
		ft_printf("Error\nNo argument\n");
		return EXIT_FAILURE;
	}
	if (argc > 2)
	{
		ft_printf("Error\nToo much arguments\n");
		return EXIT_FAILURE;
	}
	if (!necklace)
	{
		ft_printf("Error\nNo data loaded from file\n");
		return EXIT_FAILURE;
	}
	t_list *current = necklace;
	while (current != NULL)
	{
		ft_printf("%s", current->line);
		current = current->next;
	}
	ft_ismaprectangular(game.line);
	free_necklace(necklace);
	return EXIT_SUCCESS;
}
