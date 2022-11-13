/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:10 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 12:47:12 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H

# define KEYCODE_H

# if defined(linux) || defined(__linux)
#  define KEY_Q 113
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_LEFT 65361
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_A 97
#  define KEY_Q 113
#  define KEY_E 101
# else
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
# endif

#endif
