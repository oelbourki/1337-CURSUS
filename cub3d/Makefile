flags = -Wall -Werror -Wextra
name = cub3D
gnl = gnl.a
src = init.c creat_image.c process_extra4.c process.c process_extra.c process_extra3.c process_extra_extra.c dda.c key.c keys.c sprite.c draw_img.c error.c error_message.c
obj = init.o creat_image.o process_extra4.o process.o process_extra.o process_extra3.o process_extra_extra.o dda.o key.o keys.o sprite.o draw_img.o error.o error_message.o
gnl_src = get_next_line.c get_next_line_utils.c
gnl_obj = get_next_line.o get_next_line_utils.o
libft_src = ft_atoi.c ft_split.c ft_strcmp.c ft_strnstr.c ft_strrchr.c ft_memcpy.c ft_realloc.c
libft_obj = ft_atoi.o ft_split.o ft_strcmp.o ft_strnstr.o ft_strrchr.o ft_memcpy.o ft_realloc.o
all: $(name)
$(name): $(gnl) $(obj)
	gcc game.c $(obj) $(gnl) $(libft_src) $(flags) -lmlx -framework OpenGl -framework AppKit -o $(name)
$(gnl): $(gnl_obj)
	ar -rc $(gnl) $(gnl_obj)
$(gnl_obj):
	gcc -c $(gnl_src)
$(obj):
	gcc -c $(src)
bonus: re
clean:
	rm -rf $(gnl_obj) $(libft_obj) game.o $(obj)
fclean: clean
	rm -rf $(name) test.bmp $(gnl)
re : fclean all