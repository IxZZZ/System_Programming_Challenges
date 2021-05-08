import struct


def swap32(i):
    return struct.unpack("<I", struct.pack(">I", i))[0]


def LOBYTE(num):
    return num & 0xFFFF


def HIBYTE(num):
    return num >> 16


def string_to_ASCII(str):
    res = 0
    for i in str[::-1]:
        res = res << 8
        res += ord(i)

    return res


password = "12345678" # test
username = "abcde"

v5 = 0

for i in range(4, len(username)):
    v5 += ord(username[i])
print(v5)

v6 = v5 << 8
v6 += v5

v7 = swap32(v6)


v7 += v5 << 8
v7 += v5

username_val = string_to_ASCII(username)
v8 = swap32(swap32(swap32((username_val ^ v7) &
            0xffffffff) + 0x3022006) + 0x21523f22)

v8 += 1
v8 = (((v8 >> 8) + 1) << 8) + (((v8 << 24) & 0xffffffff) >> 24)

v9 = swap32(v8)

v9 -= 1
v9 = (((v9 >> 8) - 1) << 8) + (((v9 << 24) & 0xffffffff) >> 24)

v10 = swap32((swap32(swap32(swap32(swap32(swap32((swap32(swap32(v9) ^ 0xEDB88320) -
             0x28955B88) & 0xffffffff) + 0x4FF40532) + 0xBADBEEF)+1) - 1) + username_val) & 0xffffffff)
print("hex=", hex(v10))


v10 += 1
v11 = swap32(v10)

v11 += 1
C8 = v11

print(hex(C8))

b3 = (((C8 >> 24) & 0xff)-52) ^ 0x12
b2 = (((C8 >> 16) & 0xff)-120) ^ 0x56
b1 = (((C8 >> 8) & 0xff)+85) ^ 0x90
b0 = ((C8 & 0xff)+17) ^ 0xCD
print(b0, b1, b2, b3)
print(b0-16*5)
print(b1-16*4)
print(b2-16*1)
print(b3-16*11)
arr = [11,b3-16*11,1,b2-16*1,4,b1-16*4,5,b0-16*5]
str = [11, 14, 1, 4, 4, 0, 5, 14]
# B8 = "" # generate from username
# C8 = 0x827bbae0
# C8 = swap32(C8)
passw = ""
for i in arr:
    if i >= 0 and i <= 9:
        passw += chr(i + 48)
    else:  # 0->9
        passw += chr(i + 55)
print("Serial: ",passw)