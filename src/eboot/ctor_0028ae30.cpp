/* HSTMATCH module=EBOOT.BIN start=0x0028ae30 end=0x0028aeb4 symbol=FUN_0028ae30 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: added empty Tag temporary parameter to sub-object init calls; exact match verified; names and types await human review. */

struct Tag {};

extern "C" {
void FUN_0028c6e8(void *, int, Tag);
void FUN_0028c7a4(void *, int, Tag);
void FUN_0028c860(void *, int, Tag);

void *FUN_0028ae30(int *param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    FUN_0028c6e8(param_1, param_1[1], Tag());
    FUN_0028c7a4(param_1 + 3, param_1[4], Tag());
    FUN_0028c860(param_1 + 6, param_1[7], Tag());
    param_1[9] = 0;
    return param_1;
}
}
