/* HSTMATCH module=EBOOT.BIN start=0x00154e30 end=0x00154f28 symbol=FUN_00154e30 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dca24[];
extern char *DAT_0034a118;
extern char *DAT_0034a114;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
extern void FUN_00288cf4(int);

int FUN_00154e30(int param_1, int param_2)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dca24, *(int *)(param_1 + 8));
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
        FUN_00288cf4(result);
    return 0;
}
// near miss: 56/62 words (39 differ). Retail lays the id == -1 block out first and jumps over the
// id >= 0 chain (`b end` after `addiu v0,v0,224`), then guards the chain with `bgezl a1` + `b end`;
// ours falls the -1 block through and emits `bltz a1,end` instead. Ruled out: else-if vs two ifs,
// `0 <= id`, `!(id < 0)` spellings (same layout).
// near miss from lane fm6 (unreviewed)
