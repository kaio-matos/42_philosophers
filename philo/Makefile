OBJS_DIR			= objects
SRC_DIR				= .
BONUS_DIR			= bonus

CC					= cc
CCF_STRICT			= -Wall -Wextra -Werror
CCF_DEBUG			= -g3 -D VERBOSE=1
LIBS				= -pthread

RM					= rm -rf

ifdef VERBOSE
	CCF_STRICT += $CCF_DEBUG
endif

################################################################################
# MANDATORY
################################################################################

NAME				= philo
CCF_INCL_MANDATORY	= -I ./$(SRC_DIR)/includes

C_THREADS_FILES		= $(addprefix threads/, th__observer.c th__philosophers.c)
C_ACTIONS_FILES		= $(addprefix actions/, a__eat.c a__sleep.c a__take_fork.c a__think.c)
C_TIME_FILES		= $(addprefix time/, time.c mssleep.c)
C_LOG_FILES			= $(addprefix log/, log.c)
C_ENTITIES_FILES	= $(addprefix entities/, fork/fork.c fork/forks_list.c philosopher/philosopher.c philosopher/philosophers_list.c simulation/simulation.c)
C_UTILS_FILES		= $(addprefix utils/, ft_atoi.c ft_isdigit.c ft_isstrdigit.c ft_salloc.c ft_atol.c)
C_PARSER_FILES		= $(addprefix parser/, p__arguments.c)
C_VALIDATION_FILES	= $(addprefix validation/, v__arguments.c)
C_LINKED_LISTS		= $(addprefix linked_list/, $(addprefix singly/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c) $(addprefix doubly/, ft_dlstnew.c ft_dlstadd_front.c ft_dlstadd_begin.c ft_dlstfirst.c ft_dlstlast.c ft_dlstadd_back.c ft_dlstsize.c ft_dlstdelone.c ft_dlstclear.c ft_dlstmap.c ft_dlstiter.c))

C_FILES_MANDATORY	= main.c philosophers.c $(C_VALIDATION_FILES) $(C_PARSER_FILES) $(C_UTILS_FILES) $(C_LINKED_LISTS) $(C_ENTITIES_FILES) $(C_LOG_FILES) $(C_TIME_FILES) $(C_ACTIONS_FILES) $(C_THREADS_FILES)
FILES_MANDATORY		= $(C_FILES_MANDATORY)
SRCS_MANDATORY		= $(addprefix $(SRC_DIR)/,$(FILES_MANDATORY))
OBJS_MANDATORY		= $(addprefix $(OBJS_DIR)/,$(FILES_MANDATORY:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_MANDATORY)
	$(CC) $(OBJS_MANDATORY) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCF_STRICT) $(CCF_INCL_MANDATORY) -c $< -o $@

debug:
	@echo "Compiling..."
	@$(CC) $(CCF_DEBUG) $(CCF_INCL_MANDATORY) $(SRCS_MANDATORY) -o $(NAME)

rebuild:
	@$(CC) $(CCF_STRICT) $(CCF_INCL_MANDATORY) $(SRCS_MANDATORY) $(LIBS) -o $(NAME)

inspect:
	@echo "Compiling..."
	@$(CC) $(CCF_DEBUG) $(CCF_INCL_MANDATORY) $(SRCS_MANDATORY) $(LIBS) -o $(NAME)
	valgrind --tool=helgrind ./$(NAME) 4 410 200 200

################################################################################
# CLEAN UP
################################################################################

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME_B)
	$(RM) $(NAME)

re:	fclean all

################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re rebuild debug inspect

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
