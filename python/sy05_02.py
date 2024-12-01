# 2.饮品自动售货机
all_goods = {
    "百事可乐": 3.5,
    "可口可乐": 3.5,
    "农夫山泉": 2,
    "天地壹号": 5,
    "娃哈哈纯净水": 2
}
def show_goods():
    print("=======商品列表========")
    i=1
    for name,price in all_goods.items():
        print(f"序号：{i},名称：{name},售价为{price}元\t")
        i+=1
    print("======================")

def total(goods_dict):
    total_price = 0
    for name, num in goods_dict.items():
        total_price += all_goods[name] * num
    print("共需支付{}元".format(total_price))


def main():
    print("=欢迎来到自动售货机=")
    show_goods()
    print("按q结束")
    goods_dict = {}
    while True:
        name = input("请输入想要购买商品的名称：")
        if name == "q":
            break
        if name not in list(all_goods.keys()):
            print("没有此商品，请重新输入")
            continue
        num = input("请输入想要购买的数量：")
        if num.isdigit():
            goods_dict[name] = float(num)
        else:
            print("请输入阿拉伯数字")
            continue
    
    total(goods_dict)

if __name__ == '__main__':
    main()