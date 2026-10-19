/* HSTMATCH module=hstp_trans_main.prx start=0x001c6834 end=0x001c68e8 symbol=FUN_001c6834 lang=c99 */
/* Clone of src/eboot/FUN_001b8b48.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int DAT_003eaad8;
extern int FUN_001c0010(void *table, int id);
extern int FUN_001c0ce8(void *table, int param_2);
extern void FUN_001c72f4(void *out, void *p60, void *p24, void *p32);

struct Info {
    int p2;
    int p3;
    void *p100_a;
    void *p100_b;
};

void FUN_001c6834(char *self, int param_2, int param_3)
{
    struct Info info;
    int local_28;
    void *local_24;

    if (param_3 <= 0 &&
        (self + 100 == 0 ||
         FUN_001c0010(&DAT_003eaad8, *(int *)(self + 100)) == 0)) {
        int r = FUN_001c0ce8(&DAT_003eaad8, param_2);
        if (self + 100 != 0) {
            *(int *)(self + 100) = r;
        }
    } else {
        info.p2 = param_2;
        info.p3 = param_3;
        info.p100_a = self + 100;
        info.p100_b = self + 100;
        local_24 = self + 64;
        FUN_001c72f4(&local_28, self + 60, &local_24, &info);
    }
}
