#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	if (!dest_str && !src_str)
	{
		return (NULL);
	}
	p_dest = (unsigned char *) dest_str;
	p_src = (unsigned char *) src_str;
	i = 0;
	if (dest_str != src_str)
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			dest_str++;
			src_str++;
			i++;
		}
	}
	return (p_dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		num;
	char	*new_s;

	num = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(num * sizeof(char) + 1);
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_memcpy(new_s, s1, ft_strlen(s1));
	ft_memcpy(new_s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new_s);
}
