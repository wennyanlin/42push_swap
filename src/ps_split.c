#include "push_swap.h"

int	ps_count_words(char *array, char separator)
{
	char	*array_cpy;
	int		i;
	int		words;

	i = 0;
	words = 0;
	array_cpy = array;
	while (array_cpy[i])
	{
		while (array_cpy[i] && array_cpy[i] == separator)
			i++;
		if (array_cpy[i] && array_cpy[i] != separator)
			words++;
		while (array_cpy[i] && array_cpy[i] != separator)
			i++;
	}
	return (words);
}


char	*get_next_word(char *array, char separator)
{
	char		*next_word;
	static int	i = 0;
	int			j;
	int			len;

	// i = 0;
	len = 0;
	j = 0;
	while (array[i])
	{
		while (array[i] && array[i] == separator)
			i++;
		while (array[i + len] && array[i + len] != separator)
			len++;
		next_word = malloc(sizeof(char) * (len + 1));
		if (!next_word)
			return NULL;
		while (array[i] && array[i] != separator)
			next_word[j++] = array[i++];
		next_word[j] = '\0';
		return (next_word);
	}
	return (NULL);
}

char	**ps_split(char *array, char separator)
{
	char	**result_array;
	int		i;
	int		words;

	i = 0;
	if (!array)
		return (0);
	words = ps_count_words(array, ' ');
	result_array = malloc(sizeof(char*) * (words + 2));
	if (!result_array)
		return (0);
	while (i < (words + 1))
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return NULL;
			result_array[i++][0] = '\0';
		}
		result_array[i++] = get_next_word(array, separator);
	}
	result_array[i] = NULL; //add final Null terminator
	return (result_array);
}

	//allocate space for the big array
		//calculate the lentgh, how many strs there are
		//allocate the mamory space
	//allocate space for the chars
		//find chars
		//calculate the length
		//allocate space

// int	main()
// {
// 	char **word = ps_split("123 456 3 2 45 34", ' ');
// 	int	i = 0;
// 	while (word[i])
// 	{
// 		printf("%s\n", word[i++]);
// 	}

// }
