all:
	@clear
	@make -C ./ex00
	@make -C ./ex01
	@make -C ./ex02
	@clear
	@echo "all set"
	@read -p "Press Enter to continue..."
	@clear
	@echo "==============ex00=============="
	@./ex00/run ./input.csv
	@read -p "Press Enter to continue..."
	@clear
	@echo "==============ex01=============="
	@echo "<<<<<<<<<<<<<<<<8 9 * 9 - 9 - 9 - 4 - 1 +>>>>>>>>>>>>>>>>"
	@./ex01/run "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 ->>>>>>>>>>>>>>>>"
	@./ex01/run "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	@read -p "Press Enter to continue..."
	@echo "<<<<<<<<<<<<<<<<1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 />>>>>>>>>>>>>>>>"
	@./ex01/run "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
	@read -p "Press Enter to continue..."
	@clear
	@echo "==============ex02=============="
	@echo "<<<<<<<<<<<<<<<<jot -r 3000 1 1000 | tr '\n' ' '>>>>>>>>>>>>>>>>"
	@./ex02/run `jot -r 3000 1 1000 | tr '\n' ' '`

fclean:
	@clear
	make fclean -C ./ex00
	make fclean -C ./ex01
	make fclean -C ./ex02
	@clear
