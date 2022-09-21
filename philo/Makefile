CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
SRCS = main.c ./utils/philo_lunch.c ./utils/philo_inits.c ./utils/atoi.c ./utils/actions.c ./utils/ft_sleep.c
NAME = philo.a
NAME_BONUS = philo_bonus.a 
OBJS = $(SRCS:.c=.o)
AR = ar rc
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

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@rm -rf philo

re : fclean all

.PHONY: re fclean all clean bonus