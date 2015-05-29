#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int	len;
	int	i;

	if (!src)
	return (NULL);
	len = ft_strlen(src);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
	return (NULL);
	i = -1;
	while (++i < len)
	new[i] = src[i];
	new[i] = '\0';
	return (new);
}
