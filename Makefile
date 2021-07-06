SOURCE			= 	utils/utils_1.c utils/utils_2.c utils/utils_3.c utils/utils_4.c utils/utils_5.c utils/utils_6.c utils/utils_7.c\
				libft/lib_1.c libft/lib_2.c libft/lib_3.c libft/lib_4.c libft/lib_5.c \
				utils/file_1.c utils/func_rt.c \
				maps_pars/cy_p.c maps_pars/lig_p.c maps_pars/maps_p.c maps_pars/pl_p.c \
				maps_pars/sp_p.c maps_pars/sq_p.c maps_pars/tr_p.c \
				obj_int/int_1.c  obj_int/int_2.c obj_int/int_3.c obj_int/int_4.c \

HEADER_D	= ./miniRT_files/includes/

SOURCES_D	= ./miniRT_files/sources/

SOURCES		= $(addprefix $(SOURCES_D), $(SOURCE))

OBJS		= $(SOURCES:.c=.o)

LIMBLX 		= libmlx.dylib

NAMING		= miniRT

GCC			= gcc -g

FLAGS		= -Wall -Werror -Wextra

RM			= rm -f

%.o: %.c
				$(GCC) $(FLAGS) -I $(HEADER_D) -c $< -o $@

$(NAMING):	$(OBJS)
			make -C ./mlx
			cp ./mlx/libmlx.dylib .
			$(GCC) $(FLAGS) -I $(HEADER_D) $(LIMBLX) $(OBJS) -o $(NAMING)


clean:
					$(RM) $(OBJS)

fclean:		clean
				make clean -C ./mlx
				$(RM) $(LIMBLX)
				$(RM) $(NAMING)

all:		$(NAMING)

re:				fclean all

.PHONY:		all clean fclean re
