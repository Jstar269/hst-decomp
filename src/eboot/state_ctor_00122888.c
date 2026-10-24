/* HSTMATCH module=EBOOT.BIN start=0x00122888 end=0x00122a80 symbol=FUN_00122888 lang=c99 */
/* Hand-written reconstruction from the disassembly (near miss wip/state_ctor_00122888.c, completed: third argument of FUN_00124bf8 is the state pointer; matching idioms: #pragma opt_strength_reduction off, explicit byte-offset loop variable `off` next to the index `i`, and a char * cast on the first slot store so its address is not CSE'd with the later ones); exact match verified; names and types await human review. */
extern void FUN_0001f06c(void);
extern int FUN_00000bcc(int);
extern int FUN_00125d38(int);
extern int FUN_00216174(int);
extern void FUN_00124bf8(int *, int, char *);
extern void FUN_00132124(int, void *);
extern int FUN_001252fc(int *, int);
extern void FUN_00124b98(float, int *, void *, void *);
extern int DAT_00308028;
extern char DAT_0033b584;
extern char DAT_0033b5a0;
extern char DAT_0033b5ca;
extern char DAT_0033b5d2;

#pragma opt_strength_reduction off
int *FUN_00122888(int *param_1)
{
    int *self;
    int i;
    int off;
    int v;
    int *obj;
    int state;
    int other;
    float f;
    int iv;
    int tmp;
    char *cur;

    self = param_1;
    FUN_0001f06c();
    *self = (int)&DAT_00308028;
    self[0x15] = 0;
    i = 0;
    off = 0;
    do {
        *(int *)((char *)self + off + 0x3c) = 0;
        v = FUN_00000bcc(0xa0);
        if (v != 0)
            v = FUN_00125d38(v);
        *(int *)((int)self + off + 0x3c) = v;
        *(int *)((int)self + off + 0x48) = 0;
        obj = *(int **)((int)self + off + 0x3c);
        obj[0x24] = (int)self + off + 0x48;
        obj = *(int **)((int)self + off + 0x3c);
        obj[0x25] = i;
        i = i + 1;
        off = off + 4;
    } while (i < 3);
    v = FUN_00000bcc(0x50);
    if (v != 0)
        v = FUN_00216174(v);
    self[0x15] = v;
    *(unsigned char *)(self + 0x1e) = 0;
    *(unsigned char *)((int)param_1 + 0x79) = 0;
    *(unsigned char *)((int)param_1 + 0x7a) = 1;
    *(unsigned char *)((int)param_1 + 0x7b) = 0;
    *(unsigned char *)(self + 0x1f) = 0;
    self[0x20] = -1;
    self[0x21] = 0xbf800000;
    self[0x22] = 0;
    *(unsigned char *)(self + 0x23) = 0;
    self[0x24] = 0;
    *(unsigned char *)(self + 0x25) = 0;
    *(unsigned char *)((int)param_1 + 0x95) = 0;
    self[0x26] = 0;
    self[0x27] = 0;
    self[0x16] = 0;
    self[0x17] = 0;
    self[0x18] = 0;
    self[0x19] = 0;
    self[0x1a] = 0;
    self[0x1b] = 0xbf800000;
    self[0x1c] = 0;
    self[0x1d] = 0;
    if (*(signed char *)(&DAT_0033b5d2 + self[0x16] * 0x58) == 0) {
        cur = &DAT_0033b584 + self[0x16] * 0x58;
        self[0x12] = (int)cur;
        FUN_00124bf8(self, 0, cur);
    } else {
        f = *(float *)(&DAT_0033b5a0 + self[0x16] * 0x58);
        iv = (int)f;
        FUN_00132124(*(short *)(&DAT_0033b5ca + self[0x16] * 0x58), &tmp);
        other = FUN_001252fc(self, tmp);
        FUN_00124b98((float)iv, self, &DAT_0033b584 + self[0x16] * 0x58,
                     &DAT_0033b584 + other * 0x58);
    }
    return self;
}
