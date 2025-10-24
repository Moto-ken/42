
#include "../builtin.h"

int count_token(char **envp)
{
	int i;
	
	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

t_env *find_env(t_env *env_list, const char *key)
{
    t_env *current;

    current = env_list;
    while (current)
    {
        if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
            return (current);
        current = current->next;
    }
    return (NULL);
}

char *extract_key(const char *cmd)
{
	int len = 0;
	char *key;

	while (cmd[len] && cmd[len] != '=')
		len++;
	key = malloc(len + 1);
	if (!key)
		return (NULL);
	strncpy(key, cmd, len);
	key[len] = '\0';
	return (key);
}

char *extract_value(const char *str)
{
    char *equal_sign;

    equal_sign = ft_strchr(str, '=');
    if (!equal_sign)
        return (NULL);
    return (ft_strdup(equal_sign + 1));
}

void set_variable(t_shell *shell, char *key, char *value, int exported)
{
    t_env *current = shell->env_list;

    while (current)
    {
        if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
        {
            free(current->value);
            current->value = ft_strdup(value);
            if (exported)
                current->exported = 1;
            return;
        }
        current = current->next;
    }
    t_env *new = malloc(sizeof(t_env));
    if (!new)
        return;
    new->key = ft_strdup(key);
    new->value = ft_strdup(value);
    new->exported = exported;
    new->next = shell->env_list;
    shell->env_list = new;
}
