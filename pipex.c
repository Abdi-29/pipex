/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:36:32 by abba          #+#    #+#                 */
/*   Updated: 2021/12/17 15:58:09 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int			i;
	const char	str[5] = "PATH=";

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(str, envp[i], 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		exit (1);
	return (envp[i]);
}

static int	ft_size(char **s_path)
{
	int	i;

	i = 0;
	while (*s_path)
	{
		i++;
		s_path++;
	}
	return (i);
}

static void	ft_final(char **ss_path, char **s_path, char **cmd, char **envp)
{
	int	i;

	i = 1;
	while (s_path[i])
	{
		ss_path[i] = ft_strjoin(ft_strjoin(s_path[i], "/"), cmd[0]);
		free(s_path[i]);
		i++;
	}
	free(s_path);
	ss_path[i] = NULL;
	i = -1;
	while (ss_path[i + 1])
	{
		i++;
		execve(ss_path[i], cmd, envp);
		free(ss_path[i]);
	}
	free(ss_path);
}

void	ft_esec(char *argv, char **envp)
{
	char	**cmd_split;
	char	**s_path;
	char	*path;
	int		i;
	char	**ss_path;

	path = ft_strdup(get_path(envp));
	if (!path)
		exit (EXIT_FAILURE);
	s_path = ft_split(path, ':');
	i = 1;
	cmd_split = ft_split(argv, ' ');
	free(path);
	path = ft_strjoin(ft_strjoin(s_path[0], "/"), cmd_split[0]);
	if (!path)
		exit (1);
	ss_path = malloc(sizeof(char *) * ft_size(s_path) + 1);
	if (!ss_path)
		exit(1);
	ss_path[0] = ft_substr(path, 5, ft_strlen(path));
	free(path);
	ft_final(ss_path, s_path, cmd_split, envp);
	write(2, argv, ft_strlen(argv));
	ft_putendl_fd(": command not found", 2);
	exit (127);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	id_1;
	int		infile;
	int		outfile;

	(void)argc;
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (infile < 0 || outfile < 0)
		ft_exit(outfile, 1);
	pipe(fd);
	id_1 = fork();
	if (id_1 < 0)
		ft_exit(infile, 0);
	if (id_1 == 0)
		ft_child_process(fd, infile, argv, envp);
	else
		ft_parent_process(fd, outfile, argv, envp);
	exit (0);
}
