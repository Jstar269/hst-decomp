/* HSTMATCH module=EBOOT.BIN start=0x0028797c end=0x002879e0 symbol=FUN_0028797c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: callee-analyzed 24-byte record layout, branch polarity, stack frame alignment; exact match verified; names and types await human review. */

extern char DAT_0034179c[];

extern int FUN_001b2af0(void *p);
extern void FUN_00289544(void *buf, void *f64, void *pptr, void *pargs);

struct Obj_0028797c {
    char pad[0x4c];
    int f4c;              // +0x4c (76)
    char pad2[0x64 - 0x50];
    int f64;              // +0x64 (100)
    int f68;              // +0x68 (104)
};

struct Args_0028797c {
    int a;                // +0
    int b;                // +4
    int c;                // +8
    int d;                // +12
    int e;                // +16
    int f;                // +20
};

void FUN_0028797c(struct Obj_0028797c *self, int param_2, int param_3)
{
    struct Args_0028797c args;
    void *buf;
    void *ptr;

    if (param_3 <= 0) {
        self->f4c = FUN_001b2af0(&DAT_0034179c);
    } else {
        args.a = 0x4c;
        args.b = param_3;
        args.c = param_2;
        ptr = &self->f68;
        FUN_00289544(&buf, &self->f64, &ptr, &args);
    }
}
