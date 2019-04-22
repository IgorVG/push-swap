# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 16:59:10 by igarbuz           #+#    #+#              #
#    Updated: 2019/04/09 15:44:05 by igarbuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS		=	push_swap
NAME_CH		=	checker	

SRC_NAME_PS	=	push_swap.c \
				ft_in_check.c \
				ops_1.c \
				ops_2.c \
				ops_write_1.c \
				ops_write_2.c \
				ops_write_3.c \
				print_ops.c \
				stack_init.c \
				ft_read.c \
				ft_error.c \
				math_lib.c \
				ft_median.c \
				ft_median_k.c \
				sub_sort.c \
				sort.c \
				stack_ops.c \
				optimiser.c \
				check_sorted.c \
				sort_small.c \

SRC_NAME_CH	=	checker.c \
				stack_init.c \
				ft_read.c \
				ft_in_check.c \
				ft_error.c \
				ft_median.c \
				ft_median_k.c \
				ops_1.c \
				ops_2.c \
				stack_ops.c \

HEAD_NAME	= 	ft_push_swap.h

LIB_NAME	=	libft.a

OBJ_NAME_PS	=	$(SRC_NAME_PS:.c=.o)

OBJ_NAME_CH	=	$(SRC_NAME_CH:.c=.o)

SRC_PATH	=	./srcs

HEAD_PATH	=	./includes

LIB_PATH	=	./libft

OBJ_PATH	=	./obj

SRC_PS		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME_PS))

SRC_CH		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME_CH))

OBJ_PS		=	$(addprefix $(OBJ_PATH)/, $(SRC_NAME_PS:.c=.o))

OBJ_CH		=	$(addprefix $(OBJ_PATH)/, $(SRC_NAME_CH:.c=.o))

HEAD		=	$(addprefix $(HEAD_PATH)/, $(HEAD_NAME))

LIBFT		=	$(LIB_PATH)/$(LIB_NAME)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -O3

LIBRAIRIES	=	-lft -L$(LIB_PATH)

CPPFLAGS	=	-I$(HEAD_PATH) -I$(LIB_PATH)

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): obj $(OBJ_PS) $(LIBFT)
		$(CC) $(CFLAGS) $(LIBRAIRIES) $(CPPFLAGS) $(OBJ_PS) -o $(NAME_PS)

$(NAME_CH):	obj $(OBJ_CH) $(LIBFT)
		$(CC) $(CFLAGS) $(LIBRAIRIES) $(CPPFLAGS) $(OBJ_CH) -o $(NAME_CH)

obj:
	@$(MAKE) -sC $(LIB_PATH)
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEAD)
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
$(LIBFT):
	@$(MAKE) -sC $(LIB_PATH)

norm:
	norminette $(SRC) $(HEAD) | grep -B1 $(RED)"Error*"$(RESET)

clean:
	@$(MAKE) -sC $(LIB_PATH) clean
	rm -f $(OBJ_PS) $@
	rm -f $(OBJ_CH) $@
	rm -rf $(OBJ_PATH) $@

fclean: clean
	@$(MAKE) -sC $(LIB_PATH) fclean
	rm -f $(NAME_PS) $@
	rm -f $(NAME_CH) $@

debug: CFLAGS += -g
debug: re

re: fclean all

.PHONY: all clean fclean re norm debug
