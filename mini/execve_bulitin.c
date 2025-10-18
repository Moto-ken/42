
#include "builtin.h"

void	run_builtin(char **cmd, char **envp)
{
	if (!cmd || !envp)
		exit(1);
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
		echo_cmd(cmd);
	// else if (ft_strncmp(cmd[0], "cd", 2) == 0)
	// 	cd_cmd(cmd);
	// else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
	// 	pwd_cmd(cmd);
	// else if (ft_strncmp(cmd[0], "export", 7) == 0)
	// 	export_cmd(cmd);
	// else if (ft_strncmp(cmd[0], "unset", 6) == 0)
	// 	unset_cmd(cmd);
	if (ft_strncmp(cmd[0], "env", 4) == 0)
	{
		if (cmd[1] != NULL)
		{
			write(2, "env: '", 6);
			write(2, cmd[1], strlen(cmd[1]));
			write(2, "': No such file or directory\n", 30);
			exit(1);
		}
		env_cmd(envp);
	}
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		exit_cmd(cmd);
}
