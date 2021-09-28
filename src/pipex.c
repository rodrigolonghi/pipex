/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:59:26 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/27 22:48:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	throw_error(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(msg, 1);
	exit(0);
}

static char	*get_path(char *command, char **envp)
{
	char	**env_path;
	char	*temp_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	env_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		temp_path = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(temp_path, command);
		free(temp_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

static void	second_command(char **argv, char **envp, int *fd)
{
	char	**command;
	int		out;

	command = check_arguments(argv[3]);
	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
		throw_error("Unable to open file!");
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	if (execve(get_path(command[0], envp), command, envp) == -1)
		throw_error(ft_strjoin("Could not execute command ", command[0]));
}

static void	first_command(char **argv, char **envp, int *fd)
{
	char	**command;
	int		in;

	command = check_arguments(argv[2]);
	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		throw_error("Unable to open file!");
	dup2(fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
	if (execve(get_path(command[0], envp), command, envp) == -1)
		throw_error(ft_strjoin("Could not execute command ", command[0]));
}

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
			first_command(argv, envp, fd);
		waitpid(pid, NULL, 0);
		if (pid > 0)
			second_command(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		throw_error("Invalid number of arguments!");
	return (0);
}
