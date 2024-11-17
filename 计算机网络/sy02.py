def crc16(data: bytes, poly=0x8005, init=0xFFFF):

    """
    计算输入数据的CRC-16校验值
    """
    # 初始化寄存器
    crc = init
    for byte in data:
        # print(byte)
        # 将当前字节左移8位并与CRC寄存器异或
        crc ^= byte << 8
        print("=========================")
        for i in range(8):
            if (crc & 0x8000):
                crc = (crc << 1) ^ poly
            else:
                crc = crc << 1
            # 按位与
            crc &= 0xFFFF
            print(f"{i}:{crc:#04x}")
    # return byte
    return crc


if __name__ == '__main__':
    data = b"Hello, CRC-16!"
    print(data)
    crc_value = crc16(data)
    print(f"CRC-16 value: {crc_value:#04x}")