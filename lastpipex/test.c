#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// Fonction pour vérifier si la variable PATH existe dans l'environnement
int check_path_in_env(char **env) 
{
    int i = 0;
    while (env[i] != NULL)
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0) 
            return 1; // La variable PATH a été trouvée
        i++;
    }
    return 0;
}

int main(int argc, char *argv[], char *envp[]) {
    if (check_path_in_env(envp)) {
        printf("La variable PATH existe dans l'environnement.\n");
    } else {
        printf("La variable PATH n'existe pas dans l'environnement.\n");
    }
    return 0;
}
