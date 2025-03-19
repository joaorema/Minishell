#include "../inc/minishell.h"



/*
char	*find_dir(char *cmd, char *envp[])
{
	char	*half_path;
	char	**full_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	full_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		half_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK | X_OK) == 0)
			return (free_stuff(full_path), path);
		free(path);
		i++;
	}
	return (free_stuff(full_path), NULL);
}

void	ft_cmd(s_minishell *mini, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = NULL;
	cmd[0] = mini->tokens->type;
	path = find_dir(cmd[0], envp);
	if (!path)
	{
		free_stuff(cmd);
		ft_printf("not a valid path!");
		exit(1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_stuff(cmd);
		exit(1);
	}
}




/*
void echo_cmd(s_minishell *mini, s_token *tokens) {
    int i = 1;
    int no_newline = 0;

    // Check for -n flag in echo
    if (tokens->next && strcmp(tokens->next->value, "-n") == 0) {
        no_newline = 1;
        i++;  // Skip over -n flag
    }

    // Print the arguments
    while (tokens->next && tokens->next->next) {
        printf("%s ", tokens->next->value);
        tokens = tokens->next;
    }
    if (!no_newline) {
        printf("\n");
    }
}
*/

