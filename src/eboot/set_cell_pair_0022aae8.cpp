/* HSTMATCH module=EBOOT.BIN start=0x0022aae8 end=0x0022ab44 symbol=FUN_0022aae8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0022aae8.c) corrected by hand: C++ with an inline row-address helper; exact match verified; names and types await human review. */
extern char *DAT_003415a8;

/* matching idiom: the row base is built with the scaled index first, as (char *)(i * 0x14) + (int)base + 0x3d00 */
static inline char *Row(int i) { return (char *)(i * 0x14) + (int)DAT_003415a8 + 0x3d00; }

extern "C" void FUN_0022aae8(int param_1, unsigned char param_2, unsigned char param_3, int param_4, int param_5)
{
    int iVar2;
    int iVar1;
    if (param_5 == 1) { iVar2 = 10; iVar1 = 0xf; } else { iVar2 = 0; iVar1 = 5; }
    *(unsigned char *)((iVar2 + param_4) + Row(param_1)) = param_2;
    *(unsigned char *)((iVar1 + param_4) + Row(param_1)) = param_3;
}
