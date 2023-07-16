cards_list = []
def show_welcome():
	print("--" * 25)
	print("|欢迎进入名片管理系统！\t\t\t\t", end="")
	print("  |\n|\t\t\t\t\t\t  |")
	print("|\t1. 新建名片\t\t\t\t  |\n|\t2. 显示全部\t\t\t\t  |\n|\t3. 查询名片\t\t\t\t  |\n|\t\t\t\t\t\t  |\n|\t0. 退出系统\t\t\t\t  |")
	print("--" * 25)

def new_card():
	name = input("请输入姓名：")
	qq = input("请输入QQ：")
	email = input("请输入Email：")
	new_dict = {"姓名":name,
				"QQ":qq,
				"邮箱":email}
	cards_list.append(new_dict)
	print("%s 添加成功！" % name)
def show_all():
	print("")
	print("-" *50)
	print("|%-10s\t%s\t\t%s\t\t|" %("姓名", "QQ", "邮箱"))
	print("|", end="")
	print("." * 47, end="")
	print("|")
	for tmp_dict in cards_list:
		print("|%-10s\t%s\t\t%s\t\t|" % (tmp_dict["姓名"], tmp_dict["QQ"], tmp_dict["邮箱"]))
	
	print("-" * 50)
	
def search_card():
	find_name = input("请输入需要查询的姓名：")
	for tmp_dict in cards_list:
		if find_name == tmp_dict["姓名"]:

			print("")
			print("%-10s\t%s\t\t%s" %("姓名", "QQ", "邮箱"))
			print("-" * 50)
			print("%-10s\t%s\t\t%s" % (tmp_dict["姓名"], tmp_dict["QQ"], tmp_dict["邮箱"]))
			print("")
			print("修改(1)\t删除(2)\t退出(其他)")
			tmp = input("请输入要进行的操作：")
			deal_search_card(tmp, tmp_dict)
			break
	else:
		print("未找到 %s" % find_name)
	


def deal_search_card(tmp, tmp_dict):
	if tmp == "1":
		tname = input("请输入修改后的姓名（回车键不修改）:")
		tqq = input("请输入修改后的QQ（回车键不修改）:")
		te = input("请输入修改后的邮箱（回车键不修改）:")
		if len(tname) != 0:
			tmp_dict["姓名"] = tname
		if len(tqq) != 0:
			tmp_dict["QQ"] = tqq
		if len(te) != 0:
			tmp_dict["邮箱"] = te
		#show_all()
	elif tmp == "2":
		cards_list.remove(tmp_dict)
	else:
		print("未找到%s"%tname)
		

			

