/* HSTMATCH module=hstp_trans_main.prx start=0x0029c624 end=0x0029c6a8 symbol=FUN_0029c624 lang=c++ */
/* Clone of src/eboot/ctor_0028ae30.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: added empty Tag temporary parameter to sub-object init calls; exact match verified; names and types await human review. */

struct Tag {};

extern "C" {
void FUN_0029deb0(void *, int, Tag);
void FUN_0029df6c(void *, int, Tag);
void FUN_0029e028(void *, int, Tag);

void *FUN_0029c624(int *param_1)
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
    FUN_0029deb0(param_1, param_1[1], Tag());
    FUN_0029df6c(param_1 + 3, param_1[4], Tag());
    FUN_0029e028(param_1 + 6, param_1[7], Tag());
    param_1[9] = 0;
    return param_1;
}
}
