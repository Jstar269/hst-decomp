/* HSTMATCH module=EBOOT.BIN start=0x00154cc0 end=0x00154dc8 symbol=FUN_00154cc0 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc9e8[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int, int);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
extern void FUN_00288350(int, int, int);

int FUN_00154cc0(int param_1, int param_2)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc9e8, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc),
                     *(int *)(param_1 + 0x10));
    }
    id = *(int *)(param_1 + 8);
    result = *(int *)(param_2 + 0xc);
    if (id == -1) {
        result = (int)DAT_0034a118;
        if (DAT_0034a118 != 0)
            result = (int)DAT_0034a118 + 0xe0;
    }
    if (id >= 0) {
        if (id < 100)
            result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = FUN_001c6f70(DAT_0034a114, id, 0);
        else
            result = FUN_001c70c0(DAT_0034a114);
    }
    if (result != 0)
        FUN_00288350(result, *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x10));
    return 0;
}
// near miss: 60/66 words -- identical to 0x00153f54's result: every instruction matches except
// the six words retail spends on the family's `bgezl a1` guard (duplicated `slti at,a1,100` in
// the likely delay and at the target). Same two source facts: FUN_0014d044 takes only the int,
// and the id < 1000 arm must keep the call's return in `result`. Tail: FUN_00288350(result,
// param_1[3], param_1[4]) and the `lw ra` is hoisted into the tail guard's delay slot.
// near miss from lane fm6 (unreviewed)
