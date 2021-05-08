#include <iostream>
#include<string>
using namespace std;
string username = "abcde";
string password = "12345678";
string LOBYTE(string &byte, string asign)
{
    byte.replace(4, 4, asign);
}
string HIBYTE(string byte, string assign)
{
    byte.replace(0, 4, assign);
}
void Func()
{
    // v4 = &username[4];
    int v5 = 0;
    // do
    //     v5 += *v4++;
    // while (*v4);
    for (int i = 4; i < username.length(); i++)
    {
        v5 += username[i];
    }
    string v6 = "00000000";
    LOBYTE(v6, v5);
    string v6 = LOBYTE(v6, v5);
    HIBYTE(v6) = v5;
    v7 = _byteswap_ulong(v6);
    LOBYTE(v7) = v5;
    BYTE1(v7) = v5;
    v8 = _byteswap_ulong(_byteswap_ulong(_byteswap_ulong(*(_DWORD *)username ^ v7) + 0x3022006) + 0x21523F22);
    LOBYTE(v8) = v8 + 1;
    ++BYTE1(v8);
    v9 = _byteswap_ulong(v8);
    LOBYTE(v9) = v9 - 1;
    --BYTE1(v9);
    v10 = _byteswap_ulong(
        *(_DWORD *)username + _byteswap_ulong(
                                  _byteswap_ulong(
                                      _byteswap_ulong(
                                          _byteswap_ulong(_byteswap_ulong(_byteswap_ulong(_byteswap_ulong(v9) ^ 0xEDB88320) - 680876936) + 1341392178) + 195935983) +
                                      1) -
                                  1));
    LOWORD(v10) = v10 + 1;
    v11 = _byteswap_ulong(v10);
    LOWORD(v11) = v11 + 1;
    dword_4030C8 = _byteswap_ulong(v11);
    v12 = 0;
    v13 = password;
    while (1)
    {
        v14 = *v13;
        if (!*v13)
            break;
        if ((unsigned __int8)v14 < 0x30u)
            return 0;
        if ((unsigned __int8)v14 > 0x39u)
        {
            if ((unsigned __int8)v14 < 0x41u || (unsigned __int8)v14 > 0x46u)
                return 0;
            byte_4030B8[v12] = v14 - 55;
            ++v13;
            ++v12;
        }
        else
        {
            byte_4030B8[v12] = v14 - 48;
            ++v13;
            ++v12;
        }
    }
    if (dword_4030C8 == _byteswap_ulong(
                            (unsigned __int8)(((byte_4030B8[7] + 16 * byte_4030B8[6]) ^ 0xCD) - 17) + (((unsigned __int8)(((byte_4030B8[5] + 16 * byte_4030B8[4]) ^ 0x90) - 85) + (((unsigned __int8)(((byte_4030B8[3] + 16 * byte_4030B8[2]) ^ 0x56) + 120) + ((unsigned __int8)(((byte_4030B8[1] + 16 * byte_4030B8[0]) ^ 0x12) + 52) << 8)) << 8)) << 8)))
    {
        // MessageBoxA(0, Win, Caption, 0x40u);
        // SetWindowTextA(hWnd, aCloneDefeated);
    }
}

int main()
{
    return 0;
}