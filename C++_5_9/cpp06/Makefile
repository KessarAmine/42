all:
	@clear
	@make -C ./ex00
	@make -C ./ex01
	@make -C ./ex02
	@clear
	@echo "all set"
	@echo "==============ex00=============="
	@echo "<<<<<<<<<<<<<<<<0>>>>>>>>>>>>>>>>"
	@./ex00/run 0
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<nan>>>>>>>>>>>>>>>>"
	@./ex00/run nan
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<inf>>>>>>>>>>>>>>>>"
	@./ex00/run inf
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<42.0f>>>>>>>>>>>>>>>>"
	@./ex00/run 42.0f
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<42>>>>>>>>>>>>>>>>"
	@./ex00/run 12
	@read -p "Press Enter to continue..."
	@clear
	@echo "==============ex01=============="
	@./ex01/run
	@read -p "Press Enter to continue..."
	@clear
	@echo "==============ex02=============="
	@./ex02/run

fclean:
	@clear
	make fclean -C ./ex00
	make fclean -C ./ex01
	make fclean -C ./ex02
	@clear
