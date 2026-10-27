/* HSTMATCH module=hstp_trans_main.prx start=0x001d61c4 end=0x001d6284 symbol=FUN_001d61c4 lang=c99 */
/* Hand-written reconstruction from the disassembly (the EBOOT twin src/eboot/FUN_001c7d30_001c7d30.c rewritten with plain types, addresses substituted); exact match verified; names and types await human review. */
extern char *DAT_003e48b4;
extern char DAT_00392770[];
extern char DAT_003eaad8[];
extern char *FUN_00014d64(void *s, const char *t);
extern void FUN_001c28a4(float f, void *p);
extern void FUN_001c1984(float f, void *p);
extern int FUN_00298b14(void *p);
extern void *FUN_00298b5c(void *p);

void FUN_001d61c4(char *self, int a, int b, int c, unsigned char d)
{
    void *s;

    *(int *)(self + 0xd4) = a;
    *(int *)(self + 0xd8) = b;
    *(int *)(self + 0xdc) = c;
    *(unsigned char *)(self + 0xe2) = d;
    if (DAT_003e48b4 != 0) {
        if (FUN_00298b14(DAT_003e48b4 + 0x1320) != 0) {
            s = FUN_00298b5c(DAT_003e48b4 + 0x1320);
            if (s != 0) {
                *(unsigned char *)(self + 0xe0) = FUN_00014d64(s, DAT_00392770) != 0;
            }
        } else {
            *(unsigned char *)(self + 0xe0) = 0;
        }
    } else {
        *(unsigned char *)(self + 0xe0) = 0;
    }
    FUN_001c28a4(0.2f, DAT_003eaad8);
    FUN_001c1984(0.2f, DAT_003eaad8);
    *(int *)(self + 0xc4) = 3;
    *(int *)(self + 0xc8) = 0;
}
