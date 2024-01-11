/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:15:13 by dapetros          #+#    #+#             */
/*   Updated: 2023/11/01 15:08:27 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <libgen.h>

void	display_file(char *filename, char *program_name);
void	process_stdin(void);

#endif /* CAT_H */
