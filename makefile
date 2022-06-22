CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c ./utils/philo_lunch.c ./utils/philo_inits.c ./utils/atoi.c ./utils/actions.c ./utils/ft_sleep.c
# FUNC_BONUS = checker.c ./push_swap_utils/get_next_line.c ./push_swap_utils/ft_check_args.c ./push_swap_utils/error_handler.c \
# 			 ./push_swap_utils/operations.c ./push_swap_utils/operations1.c ./push_swap_utils/libft/libft.a
NAME = philo.a
NAME_BONUS = philo_bonus.a 
OBJS = $(SRCS:.c=.o)
AR = ar rc
B_SRCS = ./pipx_bonus/pipex_bonus.c ./pipx_bonus/process.c ./utils/parsing.c ./utils/ft_substr.c ./utils/ft_strtrim.c ./utils/ft_strncmp.c ./utils/ft_strlen.c ./utils/ft_strjoin.c ./utils/ft_strchr.c ./utils/ft_split.c ./utils/error.c ./utils/get_next_line_utils.c .//pipx_bonus/get_next_line.c

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
	@$(CC) $(CFLAGS) $(NAME) -o philo
	@echo  $(GREEN) "DONE!"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJS)
	@rm -rf $(NAME)
	@echo  $(CURSIVE)$(GRAY) "-MAKING BONUS..." $(NONE)
	@$(AR) $(NAME_BONUS) $(B_OBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o pipex
	@echo  $(GREEN) "DONE!"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf philo

re : fclean all

.PHONY: re fclean all clean bonus