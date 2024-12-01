num1 = float(input("请输入第一个操作数："))
operator = input("请输入运算符(+, -, *, /)：")
num2 = float(input("请输入第二个操作数："))
operator = operator.strip()
result = None
if  operator== "+":
    result = num1 + num2
elif operator == "-":
    result = num1 - num2 
elif operator == "*":
    result = num1 * num2
elif operator == "/":
    assert num2 != 0.0, "被除数不能为零"
    result = num1 / num2
if result is not None:
    print(f"故{num1}{operator}{num2}={result}")
else:
    raise Exception("有异常")


import random
random_num = random.randint(0, 100)
for frequency in range(1, 11):
    input_num = input(f"请输入第{frequency}次猜测的数字：")
    assert input_num.isdigit() is True, "请输入一个正确的数字"
    random_num, input_num = int(random_num), int(input_num)
    if input_num < 0 or input_num > 100:
        print("请输入1-100范围的数字")
    elif input_num == random_num:
        print(f"恭喜你用了{frequency}次猜对了")
        break
    elif random_num > input_num:
        print("很遗憾，你猜小了")
    elif random_num < input_num:
        print("很遗憾，你猜大了")
    else:
        print("nothing")
    if frequency == 10:
        print(f"很遗憾，{frequency}次机会已用完，游戏结束，答案为{random}")


# 3.
for i in range(1, 1001):
    if "7" in str(i) or i % 7 == 0:
        print("*", end=" ")
    elif "7" not in str(i) and  i % 7 != 0:
        print(f"{i}", end=" ")

# 4.
print("\n" + "="*10 + "消消乐小飞侠来咯" + "=" *10)
level = input("请输入你的级别(1v1, 1v2)：")
if level == "1v1":
    print("随便玩")
else:
    print(f"{level}为付费级别，请充值")
    money = int(input("请充值(须为100的倍数)："))
    if money % 100 == 0 and money > 0:
        print(f"充值成功，金额为{money}")
    else:
        print(f"充值失败，须为100的倍数")


# 5.跳过偶数
for i in range(1, 101):
    if i%2==0:
        continue
    print(i, end=" ")

# 6. for...else语句
f = open("num.txt", "w", encoding="utf-8")
for i in range(1, 10):
    f.write(str(i) + "\n")
else:
    f.close()

print()
# 7. 用户登录
username = "zrk"
password = "123456"
for i in range(3):
    input_name = str(input("请输入用户名："))
    input_pwd = str(input("请输入密码："))
    if input_name == username and input_pwd == password:
        print("登录成功")
        break
    else:
        print(f"用户名或密码有误，请重试，错误{i}次，三次锁定用户")
else:
    print("已错误三次，用户被锁定")