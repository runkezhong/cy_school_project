
# 1.进制转换
num=int(input("请输入要转换的数据:\n"))
change=input("请选择转换进制：二、八、十、十六\n") 
if change == '2':
    print(f"进制转换后的数据为：{bin(num)}")
elif change == '8':
    print("进制转换后的数据为：%s"%(oct(num)))
elif change == '10':
    print("进制转换后的数据为：%d"%(int(num))) 
elif change == '16':
    print("进制转换后的数据为：{}".format(hex(num)))

# 2.进度条
import time
incomplete_sign = 50
print('='*23+'开始下载'+'='*25)
for i in range(incomplete_sign + 1):
    completed = "*" * i
    incomplete = " " * (incomplete_sign - i)
    percentage = (i / incomplete_sign) * 100
    print("\r{:.0f}%[{}{}]".format(percentage, completed, 
                                   incomplete), end="")
    time.sleep(0.5)
print("\n" + '='*23+'下载完成'+'='*25)

# 3 过滤敏感词
sensitive_character = '你好'
test_sentence = input('请输入一段话:')
for line in sensitive_character:
    if line in test_sentence:
        test_sentence = test_sentence.replace(line, '*')
print(test_sentence)

# 4文字排版工具
string = "他问,你知道cba是什么单词的缩写吗?"
print(string)
print("1.删除空格\n \
      2.英文标点替换\n \
      3.首字母大写\n \
      4.退出")
while True:
    option = input("请输入功能选项：\n")
    if option == '1':
        string = string.replace(' ', '')
        print(string)
    elif option == '2':
        for i in string:
            if i == ',':
                string = string.replace(',', '，')
            elif i == '.':
                string = string.replace('.', '。')
            elif i == '?':
                string = string.replace('?', '？')
            elif i == "'":
                string = string.replace("'", "‘")
        string = string
        print(string)
    elif option == '3':
        #首字母大写
        string = string.upper()
        print(string)
    elif option == '4':
        break


# 5 字符串常见操作
text = "  Python document   "
# 1.输入前5个
print(text[:5])
# 2.移除text变量对应的值两边的空格
text = text.strip()
print(text)
# 3.输出text变量对应的值的后3个字符
print(text[len(text)-3:])
# 4.输出d所在索引位置
print(text.index('d'))
# 5.将text变量对应的值根据"o"分割并输出
print(text.split("o"))
# 6
text = text.replace("o", "p")
print(text)
# 7
print(text.upper())
# 8 
print(text.lower())
# 9 
print(text[:len("Py")] == "Py")
# 10
print(text[-1] == "c")