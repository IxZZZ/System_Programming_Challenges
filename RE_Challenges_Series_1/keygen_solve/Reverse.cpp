#include <iostream>
#include <string>
using namespace std;
char username[] = "aaaabbbbcccc";
string password = "aa-abbb-cccc";
char equal_password_3 = 'a';
int func_preprocess_before_check()
{
    char *v0;                            // edi
    int v1;                              // ecx
    bool v2;                             // zf
    unsigned __int8 v3;                  // cl
    int v4;                              // ebx
    unsigned __int8 *v5;                 // esi
    unsigned __int8 v6;                  // al
    int v7;                              // ebx
    int result;                          // eax
    char *reference_to_equal_password_3; // esi
    int v10;                             // ecx

    v0 = username;
    v1 = 255;
    do
    {
        if (!v1)
            break;
        cout << "Iterate v0: " << *v0 << endl;
        v2 = *v0++ == 0;

        --v1;
    } while (!v2);
    cout << "v1=" << v1 << endl;
    v3 = -(char)v1 - 2;
    v4 = 0;
    v5 = (unsigned __int8 *)&username;
    do
    {
        cout << "Iterate v5: " << *v5 << endl;
        v6 = *v5++;
        v4 += (unsigned int)(v3 * v6);
        ++v0;
        --v3;
    } while (v3);
    cout << "v4= " << v4 << endl;
    v7 = ~(v4 ^ 0x13131313) ^ 0x1234ABCD;
    cout << "v7=" << v7 << endl;
    result = v7 & 0xF0F0F0F;
    cout << "result=" << result << endl;
    equal_password_3 = v7 & 0xF0F0F0F;
    cout <<"equal_password_3="<< equal_password_3 << endl;
    *(&equal_password_3 + 4) = (v7 & 0xF0F0F0F0) >> 4;
    reference_to_equal_password_3 = &equal_password_3;
    v10 = 8;
    do
    {
        if (*(int *)reference_to_equal_password_3 > 9)
            *(int *)reference_to_equal_password_3 += 55;
        else
            *(int *)reference_to_equal_password_3 |= 0x30;
        reference_to_equal_password_3 = (char *)((char *)reference_to_equal_password_3 + 1);
        --v10;
    } while (v10);

    cout << (int)(*reference_to_equal_password_3) << endl;
    return result;
}
int func_check_and_print_correct()
{
    int result; // eax

    if (password[3] == equal_password_3 && *(char *)((char *)&password[3] + 5) == *(&equal_password_3 + 1) && password[2] == 45 && password[7] == 45)
    {
        result = printf("\nSerial is correct, now make a keygen.\n");
    }
    else
    {
        result = printf("\nIncorrect serial !!!\n");
    }
    return result;
}

int main()
{
    int a = func_preprocess_before_check();
    cout << "end" << endl;
    return 0;
}