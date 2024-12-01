# -*- coding: utf-8 -*-
# @FileName : sy06.py
# @Author   : Runke Zhong
# @Time     : 2024/11/20 08:32:01
# @Version  : 0.0.1
# @Desc     : Stay hungry, stay foolish

"""
某些网站要求访问者在访问网站内容之前必须先进行登录，若用户没有该网站的账号，则需要先进行注册。用户注册完账号后，网站的服务器会保存账号信息，以便用户下次访问网站时网站可根据保存的信息验证用户的身份。为保障账户安全，用户可时常修改密码；若后续用户不再使用网站，可以选择注销账户。
本案例要求实现包含用户注册、登录、修改密码和注销功能的用户账户管理程序（要求程序使用文件存储用户的账户信息）。
用户账户管理程序的具体流程如下所示：
（1）	显示功能菜单；
（2）	用户选择功能；
（3）	若选择1，执行用户注册操作；若选择2，执行用户登录操作；若选择3，执行用户注销操作；若选择4，执行修改密码操作；若选择5，执行退出操作。
用户账户管理程序中用户的信息是永久存储的，可以保存到本地文件info.txt中。
"""
import os

def convert_data():
    info_li = []
    with open('info.txt', mode='r+', encoding='utf-8') as f:
        info_data = f.readlines()
        for i in info_data:
            info_dict = dict()

            step_one = i.replace('{', '').replace('}', '')
            step_two = step_one.split(':')
            info_dict["姓名"] = step_two[1].split(',')[0].replace("'", '').strip()
            info_dict["密码"] = step_two[2].replace("'", '').strip()
            # 保存到表中
            info_li.append(info_dict)
    return info_li

def register():
    if os.path.exists('./info.txt') is not True:
        with open('./info.txt', mode='w', encoding='utf-8') as f:
            f.write('')

    name_li = []
    info_li = convert_data()
    person_info = {}
    name = input("请输入注册用户名:\n")
    for i in info_li:
        name_li.append(i['姓名'])
    if name in name_li:
        print("用户已注册")
    else:
        password = input("请输入注册密码:\n")
        person_info['姓名'] = name
        person_info['密码'] = password

        with open('info.txt', mode='a+', encoding='utf-8') as info_data:
            info_data.write(str(person_info) + "\n")


def login():
    if os.path.exists('info.txt') is not True:
        print("当前无数据，请先注册")
    else:
        name_li = []
        info_li = convert_data()
        name = input("请输入登录用户名:\n")
        password = input("请输入登录密码:\n")
        for i in info_li:
            name_li.append(i["姓名"])
        
        if name in name_li:
            modify_index = name_li.index(name)
            if password == info_li[modify_index]['密码']:
                print("登录成功")
            else:
                print("用户名或密码不正确")
        else:
            print("用户名或密码不正确")

def cancel():
    if os.path.exists("info.txt") is not True:
        print("当前无数据，请先注册")
    else:
        cancel_name = input("请输入要注销的用户\n")
        cancel_password = input("请输入密码\n")
        # 用户名列表
        name_li = []
        info_li = convert_data()
        for i in info_li:
            name_li.append(i['姓名'])
        if cancel_name in name_li:
            cancel_index = name_li.index(cancel_name)
            if cancel_password == info_li[cancel_index]['密码']:
                info_li.pop(cancel_index)
                with open('info.txt', mode='w+', encoding='utf-8') as f:
                    f.write("")
                
                for i in info_li:
                    with open("info.txt", mode='a+', encoding='utf-8') as info_data:
                        info_data.write(str(i) + "\n")
                print("用户注销成功")
            else:
                print("用户名或密码不正确")
        else:
            print("注销的用户不存在")

def modify():
    if os.path.exists("info.txt") is not True:
        print("当前无数据，请先注册")
    else:
        name_li = []
        info_li = convert_data()
        modify_name = input("请输入用户名:\n")
        password = input("请输入旧密码:\n")
        for i in info_li:
            name_li.append(i['姓名'])
        if modify_name in name_li:
            modify_index = name_li.index(modify_name)
            if password == info_li[modify_index]['密码']:
                new_password = input("请输入新密码\n")
                info_li[modify_index]['密码'] = new_password
                with open('info.txt', mode='w+', encoding='utf-8') as f:
                    f.write("")
                for i in info_li:
                    with open('info.txt', mode='a+', encoding='utf-8') as info_data:
                        info_data.write(str(i) + "\n")
            else:
                print("用户名或密码不正确")
        else:
            print("用户名或密码不正确")


def welcome():
    print("欢迎使用账户管理程序")
    print("1.用户注册")
    print("2.用户登录")
    print("3.用户注销")
    print("4.修改密码")
    print("5.退出")
    while True:
        option = input("请选择功能\n")
        if option == '1':
            register()
        elif option == '2':
            login()
        elif option == '3':
            cancel()
        elif option == '4':
            modify()
        elif option == '5':
            break

if __name__ == '__main__':
    welcome()