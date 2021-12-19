/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:37:17 by abba          #+#    #+#                 */
/*   Updated: 2021/12/17 15:59:03 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int file, int nb)
{
	if (nb)
	{
		close(file);
		perror("");
		exit (EXIT_FAILURE);
	}
	else
	{
		perror("");
		exit (EXIT_FAILURE);
	}
}

void	ft_child_process(int fd[], int infile, char **argv, char **envp)
{
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
	{
		perror("");
		exit (EXIT_FAILURE);
	}
	close (fd[0]);
	close (infile);
	ft_esec(argv[2], envp);
}

void	ft_parent_process(int fd[], int outfile, char **argv, char **envp)
{
	waitpid(fd[1], NULL, 0);
	if (dup2(outfile, STDOUT_FILENO) < 0 || dup2(fd[0], STDIN_FILENO) < 0)
	{
		perror("");
		exit (EXIT_FAILURE);
	}
	close (fd[1]);
	close (outfile);
	ft_esec(argv[3], envp);
}
