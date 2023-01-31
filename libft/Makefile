# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liperman <liperman@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 10:52:20 by liperman          #+#    #+#              #
#    Updated: 2022/08/26 06:36:57 by liperman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_strjoin.c ft_strtrim.c ft_split.c ft_printf_utils_hexa.c ft_printf_utils.c ft_printf.c
OBJS = ${SCRS:.c=.o}
CC = cc
RM = rm -f
CCFLAGS = -Wall -Werror -Wextra
NAME = libft.a

.c.o:
	$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
