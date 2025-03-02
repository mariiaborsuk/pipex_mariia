#include "pipex.h"
static void	*free_fn(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

static int	ft_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int start, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **strs, int count)
{
	int	i;
	int	word;
	int	start;

	i = 0;
	word = 0;
	while (word < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		strs[word] = malloc(sizeof(char) * (i - start + 1));
		if (!strs[word])
			return (free_fn(strs, word - 1));
		ft_putword(strs[word++], s, start, i - start);
	}
	strs[word] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	return (ft_split_words(s, c, strs, count));
}
// int main() {
//  printf("%d\n", ft_get_number_of_substrings("  Mariia  Borusk", ' '));
// int * substring_lengths = ft_get_substring_lengths(" Mariia Borsuk",'',4);
//  char **result = ft_split("Panpara papa",'p');

//     int i = 0;
//     while (result[i] != NULL) {
//         printf("%s\n", result[i]);
//         i++;
//     }

//     free(result);

//     return (0);
// }
// }
