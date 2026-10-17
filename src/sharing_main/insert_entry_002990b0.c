/* HSTMATCH module=hstp_trans_main.prx start=0x002990b0 end=0x00299114 symbol=FUN_002990b0 lang=c99 */
/* Clone of src/eboot/insert_entry_0028797c.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: callee-analyzed 24-byte record layout, branch polarity, stack frame alignment; exact match verified; names and types await human review. */

extern char DAT_003eaad8[];

extern int FUN_001c0bb0(void *p);
extern void FUN_0029ace0(void *buf, void *f64, void *pptr, void *pargs);

struct Obj_002990b0 {
    char pad[0x4c];
    int f4c;              // +0x4c (76)
    char pad2[0x64 - 0x50];
    int f64;              // +0x64 (100)
    int f68;              // +0x68 (104)
};

struct Args_002990b0 {
    int a;                // +0
    int b;                // +4
    int c;                // +8
    int d;                // +12
    int e;                // +16
    int f;                // +20
};

void FUN_002990b0(struct Obj_002990b0 *self, int param_2, int param_3)
{
    struct Args_002990b0 args;
    void *buf;
    void *ptr;

    if (param_3 <= 0) {
        self->f4c = FUN_001c0bb0(&DAT_003eaad8);
    } else {
        args.a = 0x4c;
        args.b = param_3;
        args.c = param_2;
        ptr = &self->f68;
        FUN_0029ace0(&buf, &self->f64, &ptr, &args);
    }
}
