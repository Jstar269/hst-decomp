/* HSTMATCH module=EBOOT.BIN start=0x001f4bbc end=0x001f4bfc symbol=FUN_001f4bbc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001f4bbc.c (tag: a1) */
struct Obj {
    char pad[0x5b4];
    int handle;
};

extern unsigned int DAT_0034179c;
extern int FUN_001b1f84(void *, int *);

void FUN_001f4bbc(struct Obj *param_1)
{
    if (param_1->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &param_1->handle);
        param_1->handle = -1;
    }
}
