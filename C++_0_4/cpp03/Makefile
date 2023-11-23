all:
	@clear
	@make -C ./ex00
	@make -C ./ex01
	@make -C ./ex02
	@clear
	@echo "	Evaluation results"
	@echo "==============ex00(ClapTrap)=============="
	@./ex00/ex00
	@echo "==============ex01(ScavTrap)=============="
	@./ex01/ex01
	@echo "==============ex02=============="
	@./ex02/ex02

fclean:
	@clear
	make fclean -C ./ex00
	make fclean -C ./ex01
	make fclean -C ./ex02
	@clear

re:	fclean
	make