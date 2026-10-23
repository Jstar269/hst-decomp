/* HSTMATCH module=EBOOT.BIN start=0x001991f8 end=0x00199244 symbol=FUN_001991f8 lang=c99 */
/* Hand-written reconstruction (external matching lane): the flag global is written with a literal 1/0
   in each arm of an inverted if (param_2 != 1), which is what puts the zero-store on the fallthrough
   and the body out of line; writing `DAT = param_2 == 1` after the if instead re-derives the
   comparison (xori/sltiu) and keeps param_2 alive in s0 across the call. Exact match verified; names
   and types await human review. */
extern unsigned char DAT_00341771;
extern void FUN_002b7cd8(int *);

void FUN_001991f8(int param_1, int param_2)
{
    *(int *)(param_1 + 0x7c) = param_2;
    if (param_2 != 1) {
        DAT_00341771 = 0;
    } else {
        *(int *)(*(int *)(param_1 + 0x70) + 0x30) = 8;
        FUN_002b7cd8((int *)(param_1 + 0x3c));
        DAT_00341771 = 1;
    }
}
