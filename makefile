CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address
SRCS = ./philo/main.c ./philo/utils/philo_lunch.c ./philo/utils/philo_inits.c ./philo/utils/atoi.c ./philo/utils/actions.c ./philo/utils/ft_sleep.c
# FUNC_BONUS = checker.c ./push_swap_utils/get_next_line.c ./push_swap_utils/ft_check_args.c ./push_swap_utils/error_handler.c \
# 			 ./push_swap_utils/operations.c ./push_swap_utils/operations1.c ./push_swap_utils/libft/libft.a
NAME = ./philo/philo.a
NAME_BONUS = philo_bonus.a 
OBJS = $(SRCS:.c=.o)
AR = ar rc
B_SRCS = ./philo_bonus/main.c ./philo_bonus/utils/philo_inits.c ./philo_bonus/utils/atoi.c ./philo_bonus/utils/actions.c ./philo_bonus/utils/ft_sleep.c ./philo_bonus/utils/philo_lunch.c 

B_OBJS = $(B_SRCS:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME_BONUS)
	@echo $(CURSIVE)$(GRAY) "-MAKING philo..." $(NONE)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o philo.out
	@echo  $(GREEN) "DONE!"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJS)
	@rm -rf $(NAME)
	@echo  $(CURSIVE)$(GRAY) "-MAKING BONUS..." $(NONE)
	@$(AR) $(NAME_BONUS) $(B_OBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o philo.out
	@echo  $(GREEN) "DONE!"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf philo.out

re : fclean all

.PHONY: re fclean all clean bonus