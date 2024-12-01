"""
十大歌手
（1）按照“由评委组的十名评委打分”的描述，需要找一个列表记录每个评委的分数，此时列表中的元素是没有顺序的。
（2）找出列表中的最高分和最低分，也就是先使用sort()方法按从低到高的顺序排列列表元素，此时列表中位于开头的元素为最低分，位于结尾的元素为最高分。
（3）去掉最高分和最低分就相当于删除列表的头尾元素，可借助remove()方法删除列表的首位元素，借助pop()方法删除列表的尾部元素，此时列表中的元素是计算得分需要的列表。
（4）计算得分操作也就是遍历列表求和、求平均数。
"""
def calculate_score(scores):
    # 确保输入的scores是一个列表
    if not isinstance(scores, list) or len(scores) < 3:
        raise ValueError("Scores must be a list with at least 3 elements.")
    
    scores.sort()

    lowest_score = scores.pop(0)
    highest_score = scores.pop()

    average_score = sum(scores) / len(scores)
    return lowest_score, highest_score, average_score

scores_text = input("请连续输入分数以,英文逗号间隔，结束请回车：\n")
try:
    scores = [float(score) for score in scores_text.split(",")]
except Exception as e:
    raise Exception(e)

lowest_score, highest_score, average_score = calculate_score(scores)
print(f"去掉最低分：{lowest_score}")
print(f"去掉最高分：{highest_score}")
print(f"选手最终得分：{average_score}")

"""
2. 青春有你
本案例要求编写程序，接收选手的姓名和票数，输出排序后的成绩。
（1）上面描述的选手的姓名与票数是一一对应的关系，因此可通过字典保存像这种关系的数据。
（2）按“选择的票数越多，排名越靠前”描述，此处需要比较字典中保存的票数，票数最高的选手位列第1名，票数最少的选手位列最后一名，可借助列表的sort()方法进行排序。
代码实现：（本例中另一排序方式：设置sort()函数的reverse参数降序排序，自行给出）
张三:90,李四:80,王五:92,豪七:99
"""

humans = input("请输入选手名称与分数，以:英文冒号间隔，多个选手以,英文逗号间隔：\n")
humans_dict = {human.split(":")[0]: human.split(":")[1] for human in humans.split(",")}
names = []
scores = []
for human in humans_dict.items():
    names.append(human[0])
    scores.append(human[1])
b = sorted(enumerate(scores), key=lambda scores:scores[1], reverse=True)  # x[1]是因为在enumerate(a)中，a数值在第1位
c = [x[0] for x in b]  # 获取排序好后b坐标,下标在第0位
for i, idx in enumerate(c):
    i+=1
    print(f"第{i}名，{names[idx]}，成绩：{scores[idx]}")
print(humans_dict)

"""
手机通讯录
手机通讯录通常包含多个联系人，每个联系人都包含姓名、手机号、邮箱、地址等基本信息，且这些信息之间是相互对应的，因此这里可将联系人视为包含4个键值对的字典，将通讯录视为一个包含多个字典的数组，将通讯录中新增联系人、删除联系人、修改联系人、查看联系人的功能视为字典的增删改查操作。
根据以上分析可整理出以下基本实现思路：
（1）创建一个空列表，使用该列表存储联系人信息；
（2）打印通讯录的功能菜单；
（3）创建一个空字典，使用该字典存储联系人的姓名、手机号、邮箱和地址信息。
（4）接收用户输入的功能序号，并根据输入的序号执行相应的操作：用户输入“1”执行增加字典元素的操作；用户输入“2”执行查看字典的操作；用户输入“3”执行删除字典元素的操作；用户输入“4”执行修改字典元素的操作；用户输入“5”执行遍历字典元素的操作；用户输入“6”执行结束程序的操作。
"""
persons = []
def input_for_user():
    name = input("请输入姓名：")
    phone = input("请输入手机号：")
    email = input("请输入邮箱：")
    address = input("请输入地址：")
    return {
        "姓名": name,
        "手机号": phone,
        "邮箱": email,
        "地址": address
    }

def create_person():
    global persons
    person = input_for_user()
    persons.append(person)
    print("创建成功")

def get_person():
    global persons
    name = input("请输入联系人姓名：")
    for person in persons:
        if person['姓名'] == name:
            print(f"已查询到{person}")
            return 
    print("没有此联系人")

def del_person():
    global persons
    name = input("请输入联系人姓名：")
    for id, person in enumerate(persons):
        if person['姓名'] == name:
            persons.pop(id)
            print("删除成功")
            return
    print("没有此联系人")

def alter_person():
    global persons
    name = input("请输入要修改的联系人姓名")
    for id, person in enumerate(persons):
        if person['姓名'] == name:
            print("请输入修改信息\n")
            phone = input("手机号：")
            email = input("邮箱：")
            address = input("地址：")
            persons[id]['手机号'] = phone
            persons[id]['邮箱'] = email
            persons[id]['地址'] = address
            print("修改成功")
            return
    print("没有此联系人")

def get_all_person():
    global persons
    print(persons)

while True:
    print("*" * 50)
    print("="*23 + "通讯录" + "=" * 23)
    print("*" * 50)
    print("= 1.新增联系人")
    print("= 2.查看联系人")
    print("= 3.删除联系人")
    print("= 4.修改联系人")
    print("= 5.查看所有联系人")
    print("= 6.退出")
    try:
        flag = int(input("= 请输入你的选项，以回车结束："))
    except Exception as e:
        print("没有此选项，请重试")
        continue
    if flag == 1:
        create_person()
    elif flag == 2:
        get_person()
    elif flag == 3:
        del_person()
    elif flag == 4:
        alter_person()
    elif flag == 5:
        get_all_person()
    elif flag == 6:
        break

    


