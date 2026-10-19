/* HSTMATCH module=hstp_trans_main.prx start=0x002b4e10 end=0x002b4f7c symbol=FUN_002b4e10 lang=c99 */
/* Clone of src/eboot/select_mode_002a5680.c (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: switch structure for mode dispatch, loop predicate variable, matching idiom (loop counter declared as parameter to steer s-register allocation); exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned int undefined4;

extern undefined4 DAT_003f46a0;
extern void FUN_00105470(undefined4, int);
extern void FUN_00111aa4(undefined4, int, int);
extern void FUN_0011988c(undefined4, uint, int);
extern void * FUN_0020d1e0(int, int, int);
extern void FUN_002b4f7c(int, int, int);

void FUN_002b4e10(int param_1, int param_2, int i)
{
    int eq;
    int p;

    i = 0;
    p = param_1;
    for (; i < 4; i++, p += 4) {
        eq = i == param_2;
        FUN_00105470(*(undefined4 *)(p + 0x78), !eq);
        FUN_00105470(*(undefined4 *)(p + 0x88), eq);
    }
    FUN_002b4f7c(param_1, param_2, 0);
    FUN_00111aa4(*(undefined4 *)(param_1 + 0xd4), param_2, 0);
    switch (param_2) {
    case 0:
        FUN_0011988c(DAT_003f46a0, (uint)FUN_0020d1e0(18, 49, 13), 0);
        break;
    case 1:
        FUN_0011988c(DAT_003f46a0, (uint)FUN_0020d1e0(18, 49, 14), 0);
        break;
    case 2:
        FUN_0011988c(DAT_003f46a0, (uint)FUN_0020d1e0(18, 49, 17), 0);
        break;
    case 3:
        FUN_0011988c(DAT_003f46a0, (uint)FUN_0020d1e0(18, 49, 18), 0);
        break;
    }
}
