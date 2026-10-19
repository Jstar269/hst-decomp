/* HSTMATCH module=EBOOT.BIN start=0x001b8b48 end=0x001b8bfc symbol=FUN_001b8b48 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int DAT_0034179c;
extern int FUN_001b1f7c(void *table, int id);
extern int FUN_001b2bb8(void *table, int param_2);
extern void FUN_001b9608(void *out, void *p60, void *p24, void *p32);

struct Info {
    int p2;
    int p3;
    void *p100_a;
    void *p100_b;
};

void FUN_001b8b48(char *self, int param_2, int param_3)
{
    struct Info info;
    int local_28;
    void *local_24;

    if (param_3 <= 0 &&
        (self + 100 == 0 ||
         FUN_001b1f7c(&DAT_0034179c, *(int *)(self + 100)) == 0)) {
        int r = FUN_001b2bb8(&DAT_0034179c, param_2);
        if (self + 100 != 0) {
            *(int *)(self + 100) = r;
        }
    } else {
        info.p2 = param_2;
        info.p3 = param_3;
        info.p100_a = self + 100;
        info.p100_b = self + 100;
        local_24 = self + 64;
        FUN_001b9608(&local_28, self + 60, &local_24, &info);
    }
}
