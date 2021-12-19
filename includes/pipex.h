/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:38:39 by abba          #+#    #+#                 */
/*   Updated: 2021/12/17 15:58:39 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft.h"
# include <errno.h> 

void	ft_child_process(int fd[], int infile, char **argv, char **envp);
void	ft_parent_process(int fd[], int outfile, char **argv, char **envp);
void	ft_esec(char *argv, char **envp);
void	ft_exit(int file, int nb);

#endif