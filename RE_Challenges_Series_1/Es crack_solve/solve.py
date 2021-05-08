from pwn import *
f = open("solve.txt", 'wb')

f.write(p32(0x804A000))
print(p32(0x804A000))
