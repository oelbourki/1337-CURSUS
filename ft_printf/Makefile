NAME = libftprintf.a
flags = -Werror -Wall -Wextra
srcs = hexa.c numberpos.c numberneg.c string.c pointer.c char.c \
libftprint.c itoa_base.c  ft_printf.c modulo.c unsigned.c \
itoa_base10.c ft_strlen.c ft_calloc.c ft_bzero.c what.c isin.c \
ft_isdigit.c whatl.c hexal.c charl.c stringl.c hexall.c whatll.c \
unsignedll.c whath.c extra.c ft_atoi.c
object = hexa.o numberpos.o numberneg.o string.o pointer.o char.o \
libftprint.o itoa_base.o  ft_printf.o modulo.o unsigned.o \
itoa_base10.o ft_strlen.o ft_calloc.o ft_bzero.o what.o isin.o \
ft_isdigit.o whatl.o hexal.o charl.o stringl.o hexall.o whatll.o \
unsignedll.o whath.o extra.o ft_atoi.o
all:$(NAME)
$(NAME): $(object)
	@ar -rsc $(NAME) $(object) 
$(object): $(srcs)
	@gcc -c $(srcs) $(flags)
bonus: re
clean:
	@rm -f $(object) $(obj_bonus)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all bonus 
