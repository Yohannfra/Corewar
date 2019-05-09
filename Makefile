##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile Corewar
##

SHELL		=	sh

MAKE		=	make

COMPILERDIR	=	./asm

VMDIR		=	./corewar

LIBDIR		=	./lib/my

all:
			$(MAKE) -C $(LIBDIR)
			$(MAKE) -C $(COMPILERDIR)
			$(MAKE) -C $(VMDIR)

debug:
			$(MAKE) debug -C $(LIBDIR)
			$(MAKE) debug -C $(COMPILERDIR)
			$(MAKE) debug -C $(VMDIR)

clean:
			$(MAKE) clean -C $(LIBDIR)
			$(MAKE) clean -C $(COMPILERDIR)
			$(MAKE) clean -C $(VMDIR)

fclean:
			$(MAKE) fclean -C $(LIBDIR)
			$(MAKE) fclean -C $(COMPILERDIR)
			$(MAKE) fclean -C $(VMDIR)
			#find . \( -name '*~' -o -name '*.cor' \) -delete

re: fclean all

.PHONY: debug clean fclean re all
