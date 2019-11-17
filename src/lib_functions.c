#include "../includes/snake.h"

char			*ft_itoa_base_uns(unsigned long long nb, int base)
{
	long long	rest;
	char		*ans;
	int			i;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(ans = (char*)malloc(sizeof(char) * 65)))
		return (NULL);
	while (nb != 0)
	{
		rest = nb % base;
		ans[i++] = rest > 9 ? rest - 10 + 'a' : rest + '0';
		nb /= base;
	}
	ans[i] = '\0';
	return (ft_strrev(ans));
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	if (str == NULL)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	int		len_less;
	char	tmp;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	len_less = len - 1;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len_less];
		str[len_less] = tmp;
		i++;
		len_less--;
	}
	return (str);
}
