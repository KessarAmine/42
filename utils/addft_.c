#include<stdio.h>
#include<dirent.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	is;
	int	ia;

	is = 0;
	ia = 0;
	while (dest[is] != '\0')
		is++;
	while (src[ia] != '\0')
	{
		dest[is] = src[ia];
		ia++;
		is++;
	}
	dest[is] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int main()
{
    DIR             *d;
    struct dirent   *dir;
    char            dest[50];
    char            *new;

    d = opendir(".");
    if(d)
    {
        while((dir = readdir(d)) != NULL)
        {
            if(ft_strcmp(dir->d_name,".") != 0 && ft_strcmp(dir->d_name, "..") != 0 && ft_strcmp(dir->d_name, "a.out") != 0 && ft_strcmp(dir->d_name, "addft_.c") != 0)
            {
                ft_strcpy(dest, "ft_");
                new = ft_strcat(dest, dir->d_name);
                rename(dir->d_name, new);
                ft_strcpy(new, "");
            }
        }
        closedir(d);
    }
}