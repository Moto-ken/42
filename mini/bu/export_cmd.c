/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:22 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/18 22:58:15 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_token(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

static int	is_valid_varname(const char *var)
{
	int	i;

	i = 0;
	if (!var || !(isalpha(var[0]) || var[0] == '_'))
		return (0); // 変数名は英字または _ で始まる必要がある
	while (var[i])
	{
		if (var[i] == '=')
			break ;
		if (!(isalnum(var[i]) || var[i] == '_'))
			return (0); // 英数字かアンダースコア以外はNG
		i++;
	}
	return (1);
}

void	jugde_token(char *cmd)
{
	if (!is_valid_varname(cmd))
		exit(1);
}

void	export_cmd(char **cmd, char **envp)
{
	int	token;
	int	i;

	i = 1;
	token = count_token(cmd);
	while (token <= i)
	{
		jugde_token(cmd[i]);
		i++;
	}
}
