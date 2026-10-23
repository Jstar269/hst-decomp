/* HSTMATCH module=EBOOT.BIN start=0x002af0ec end=0x002af1ac symbol=FUN_002af0ec lang=c99 */
extern char *DAT_003415a8;
extern int DAT_00302dd8;

void FUN_002af0ec(int param_1, int *param_2, int *param_3)
{
    int *piVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    char *p;

    p = DAT_003415a8 + 0x87128;
    if (*(int *)(p + 0x9038) < DAT_00302dd8) {
        piVar1 = (int *)(p + 0x9038);
    } else {
        piVar1 = &DAT_00302dd8;
    }
    iVar3 = *piVar1;
    iVar4 = 0;
    *param_2 = 0;
    *param_3 = 0;
    if (0 < iVar3) {
        do {
            iVar2 = *(int *)(p + 0x9160);
            if (iVar2 == 5) {
                *param_2 = *param_2 + 1;
            } else {
                if (iVar2 == 4 || iVar2 == 3) {
                    *param_2 = *param_2 + 1;
                } else {
                    *param_3 = *param_3 + 1;
                }
            }
            iVar4 = iVar4 + 1;
            p = p + 0x134;
        } while (iVar4 < iVar3);
    }
}
// NEAR MISS (lane fm3): 32 of 48 words, all of them register renames from a one-slot shift in temp
// allocation (retail: p in t3, count in t1, i in t2, 4/3/5 in a3/a0/t0; ours: p in t0, count in a3,
// i in t1, 5/4/3 in a0/...). One word short overall.
// Keep these findings: the base must be a POINTER local (`char *p = DAT_003415a8 + 0x87128;`) and the
// count/record fields expressed relative to it (`*(int *)(p + 0x9038)`, `*(int *)(p + 0x9160)`),
// otherwise mwcc emits lwr/lwl for an unaligned int load; and the 3/4/5 test must be
// `if (x == 5) {..} else { if (x == 4 || x == 3) {..} else {..} }` (a single
// `x == 5 || x == 4 || x == 3` gets folded to `addiu -3; sltiu 3`; three separate else-ifs expand
// everything).
// near miss from lane fm3 (unreviewed)
