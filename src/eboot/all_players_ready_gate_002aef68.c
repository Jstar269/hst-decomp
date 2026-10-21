/* HSTMATCH module=EBOOT.BIN start=0x002aef68 end=0x002af094 symbol=FUN_002aef68 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the four-flag gate is a materialised bool chain 'ok = a; if (ok) ok = b; ...' and the guard is written as an early return); names and types await human review. */
struct Row {
    char pad0[0xe0];
    unsigned char f_e0;
    char pad1[0x120 - 0xe1];
};
extern unsigned char DAT_003386b8;
extern int DAT_00338af0;
extern int DAT_0034a678;
extern unsigned char DAT_003417be;
extern unsigned char *DAT_00338b44;
extern struct Row DAT_003417b8[];
extern unsigned char *FUN_000c4ba0(int, int);
extern void FUN_002ae670(int *);

void FUN_002aef68(int *param_1)
{
    int ok = DAT_003386b8 != 0;
    if (ok) ok = DAT_00338af0 != 0;
    if (ok) ok = DAT_0034a678 == 0x44;
    if (ok) ok = (DAT_003417be != 0) ^ 1;
    if (!ok || *param_1 == 0)
        return;
    int allReady = 1;
    int i = 0;
    struct Row *p = DAT_003417b8;
    while (i < (DAT_00338b44[0x45] == 0 ? 4 : 2)) {
        if (p->f_e0 == 0) {
            unsigned char *e = FUN_000c4ba0(DAT_00338af0, i);
            if (e[0x1cc] != 1) allReady = 0;
        }
        p++;
        i++;
    }
    if (allReady) {
        FUN_002ae670(param_1);
        *param_1 = 0;
    }
}
