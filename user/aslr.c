#include <stdio.h>

void print_memory(unsigned char *addr, int size)
{
    if (size <= 0)
    {
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        if (i % 8 == 0)
        {
            cprintf("%08x: ", addr + i);
        }
        cprintf("%02x ", addr[i]);
        if (i % 8 == 7)
        {
            cprintf("\n");
        }
    }
    if (size % 8 != 0)
    {
        cprintf("\n");
    }
}

int main(void)
{
    int x = 5;
    int y = 10;
    char *s = "abcdefg";

    cprintf("%p %p %p\n", &x, &y, &s);

    print_memory((unsigned char *)(&s - 2), 0x20);

    return 0;
}
