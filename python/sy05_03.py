def print_menu():
    print("=" * 30)
    print("学生管理系统V9.9")
    print("1.添加学生信息")
    print("2.删除学生信息")
    print("3.修改学生信息")
    print("4.查询所有学生信息")
    print("0.退出系统")
    print("=" * 30)
stu_info = []
def add_stu_info():
    new_name = input("请输入新学生的姓名：")
    new_gender = input('请输入新学生的性别：')
    new_phone = input("请输入新学生的手机号码")
    new_info = dict()
    new_info['name'] = new_name
    new_info['gender'] = new_gender
    new_info['phone'] = new_phone
    stu_info.append(new_info)

def del_stu_info():
    del_num = int(input('请输入要删除的序号：')) - 1
    del stu_info[del_num]
    print("删除成功")

def modify_stu_info():
    if len(stu_info) != 0:
        stu_id = int(input("请输入要修改学生的序号：")) 
        new_name = input("请输入要修改学生的姓名：")
        new_gender = input("请输入要修改学生的性别：(男/女)")
        new_phone = input("请输入要修改学生的手机号码：")
        if stu_id <= len(stu_info):
            stu_info[stu_id-1]['name'] = new_name
            stu_info[stu_id-1]['gender'] = new_gender
            stu_info[stu_id-1]['phone'] = new_phone
        else:
            print("没有此学生id")
    else:
        print("学生信息为空")

def show_stu_info():
    """
    显示所有学生信息
    """
    print("学生的信息如下：")
    print("=" * 30)
    print("序号     姓名    性别    手机号码\t")
    i = 1
    for info in stu_info:
        print("{} {}  {}  {}".format(i, info["name"], info["gender"], info["phone"]))
        i+=1

def main():
    while True:
        print_menu()
        key = input("请输入功能对应的数字：")
        if key == "1":
            add_stu_info()
        elif key == "2":
            del_stu_info()
        elif key == "3":
            modify_stu_info()
        elif key == "4":
            show_stu_info()
        elif key == "0":
            quit_confirm = input("亲，真的要退出吗？(yes or no)：").lower()
            if quit_confirm == 'yes':
                print("感谢使用!")
                break
            elif quit_confirm == 'no':
                continue
            else:
                print("输入有误")


if __name__ == '__main__':
    main()