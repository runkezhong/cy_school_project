class MyList:
    def __isnumber(self, n):
        if not isinstance(n, (int, float, complex)):
            return False
        return True
    
    def __init__(self, *args):
        for arg in args:
            if not self.__isnumber(arg):
                print("所有的元素必须是数字类型")
                return
        self.__value = list(args)

    def __str__(self):
        return str(self.__value)
    
    def __del__(self):
        del self.__value
    # 重载运算符 +
    def __add__(self, num):
        if self.__isnumber(num):
            my_list = MyList()
            my_list.__value = [elem + num for elem in self.__value]
            return my_list
    # 重载运算符 - 
    # 数组中每个元素都与数字num相减，返回新数组
    def __sub__(self, num):
        if not self.__isnumber(num):
            print("所有的元素必须是数字类型")
            return
        my_list = MyList()
        my_list.__value = [elem - num for elem in self.__value]
        return my_list
    # 重载运算符 * 
    # 数组中每个元素都与数字num相乘，返回新数组
    def __mul__(self, num):
        if not self.__isnumber(num):
            print("所有的元素必须是数字类型")
            return
        my_list = MyList()
        my_list.__value = [elem * num for elem in self.__value]
        return my_list
    # 重载运算符 /
    # 数组中每个元素都与数字num相除，返回新数组
    def __truediv__(self, num):
        if not self.__isnumber(num):
            print("所有的元素必须是数字类型")
            return
        my_list = MyList()
        my_list.__value = [elem / num for elem in self.__value]
        return my_list

add_demo = MyList(1, 2, 3, 4, 5)
print(add_demo+1)
print(add_demo-2)
print(add_demo*2)
print(add_demo/2)