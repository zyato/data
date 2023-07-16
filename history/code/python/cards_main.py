import cards_tools

while True:
	cards_tools.show_welcome()

	choice = input("请选择操作功能（1、2、3、0）:")
	
	if choice in ["1", "2", "3"]:
		if choice == "1":
			cards_tools.new_card()
		elif choice == "2":
			cards_tools.show_all()
		else:
			cards_tools.search_card()
	elif choice == "0":
		print("系统退出成功！")
		break
	else:
		print("输入有误，请重新输入！")
		continue


