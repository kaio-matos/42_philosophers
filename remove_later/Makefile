define \n


endef
OBJS_DIR = objects
OBJS_DEBUG_DIR = $(OBJS_DIR)_debug

CC					= cc
CFLAGS				= -Wall -Wextra -Werror
NAME				= libft
INCLUDE_PATH		= ./includes
CCF_INCLUDES		= -I $(INCLUDE_PATH)
CFLAGS_DEBUG		= -g3 -D VERBOSE=1

ORIGINAL_LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c\
# ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OTHERS_SRCS = ft_mtxiteri.c ft_mtxdup.c ft_mtxpush.c ft_mtxlen.c ft_strljoin.c ft_atol.c ft_isinteger.c

WRITE_SRCS = $(addprefix write/, ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbase_fd.c ft_putnbase.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putstrn_fd.c ft_putstrn.c)

GET_NEXT_LINE_SRCS = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

FT_PRITF_SRCS = $(addprefix ft_printf/, ft_printf.c deal.c\
				conversions/char.c conversions/string.c conversions/pointer.c conversions/decimal.c conversions/int.c conversions/unsigned.c conversions/hexadecimal.c conversions/percent.c\
				slot/slot.c slot/utils.c)

FILES_SRCS = $(addprefix files/, ft_pread_file.c ft_read_file_fd.c ft_read_file.c)

LOG_SRCS = $(addprefix log/, ft_notify.c ft_printf_mtx.c ft_throw_error.c debug_log.c error/ft_exterr.c error/ft_prterr.c)

MEMORY_SRCS = $(addprefix memory/, ft_free_matrix.c ft_memory_actions.c ft_memory.c ft_palloc.c ft_salloc.c)

C_LINKED_LISTS = $(addprefix linked_list/singly/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstprint.c)
C_DOUBLY_LINKED_LISTS = $(addprefix linked_list/doubly/, ft_dlstnew.c ft_dlstadd_front.c ft_dlstadd_begin.c ft_dlstfirst.c ft_dlstlast.c ft_dlstadd_back.c ft_dlstsize.c ft_dlstdelone.c ft_dlstclear.c ft_dlstmap.c ft_dlstiter.c ft_dlstprint.c)
C_STACK = $(addprefix stack/, ft_stkclear.c ft_stkinit.c ft_stkis_empty.c ft_stknew.c ft_stkpeek.c ft_stkpop.c ft_stkprint.c ft_stkpush.c)
C_DATA_STRUCTURES = $(addprefix data_structures/,$(C_LINKED_LISTS) $(C_DOUBLY_LINKED_LISTS) $(C_STACK))

SRCS = $(ORIGINAL_LIBFT_SRCS) $(OTHERS_SRCS) $(GET_NEXT_LINE_SRCS) $(FT_PRITF_SRCS) $(WRITE_SRCS) $(FILES_SRCS) $(LOG_SRCS) $(MEMORY_SRCS) $(C_DATA_STRUCTURES)
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
RM = rm -rf

all: $(NAME).a

$(NAME).a: $(OBJS)
	ar -rcs $@ $(OBJS)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CCF_INCLUDES) -c $< -o $@

debug: $(NAME)_debug.a

$(NAME)_debug.a:
	$(foreach V,$(SRCS),@mkdir -p $(dir $(OBJS_DEBUG_DIR)/$V)${\n})
	$(foreach V,$(SRCS),$(CC) $(CFLAGS_DEBUG) $(CCF_INCLUDES) -c $V -o $(OBJS_DEBUG_DIR)/$(V:.c=.o)${\n})
	ar -rcs $(NAME)_debug.a $(addprefix $(OBJS_DEBUG_DIR)/,$(SRCS:.c=.o))

norm:
	norminette $(SRCS)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJS_DEBUG_DIR)

fclean: clean
	$(RM) $(NAME).a
	$(RM) $(NAME)_debug.a

re:	fclean all
