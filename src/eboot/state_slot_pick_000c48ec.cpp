/* HSTMATCH module=EBOOT.BIN start=0x000c48ec end=0x000c4a0c symbol=FUN_000c48ec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: goto next skips the odd/even probe after the (i+2)%4 hit; Free() is an inline helper (gives the three base-pointer copies). */struct Slot {
    unsigned char mode;
    char pad[0xdf];
    unsigned char busy;
    char pad2[0x120 - 0xe1];
};
extern "C" Slot DAT_003417b8[];
extern "C" int DAT_002d5ae8[];

static inline bool Free(int idx)
{
    return DAT_003417b8[idx].busy == 0;
}

extern "C" void FUN_000c48ec(void)
{
    int n = DAT_003417b8[0].mode == 0 ? 2 : 4;
    int i = 0;
    unsigned char mode = DAT_003417b8[0].mode;
    int *dst;
    if (n > 0) {
        dst = DAT_002d5ae8;
        do {
            *dst = -1;
            if (Free(i)) {
                *dst = i;
            } else {
                int a;
                if (mode == 1) {
                    a = (i + 2) % 4;
                    if (Free(a)) {
                        *dst = a;
                        goto next;
                    }
                }
                if ((i & 1) == 0)
                    a = i + 1;
                else
                    a = i - 1;
                if (Free(a)) {
                    *dst = a;
                } else {
                    int b = (a + 2) % 4;
                    if (Free(b))
                        *dst = b;
                }
            }
        next:
            dst++;
            i++;
        } while (i < n);
    }
}
