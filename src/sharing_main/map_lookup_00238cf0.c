/* HSTMATCH module=hstp_trans_main.prx start=0x00238cf0 end=0x00238d4c symbol=FUN_00238cf0 lang=c99 */
/* Clone of src/eboot/map_lookup_0022977c.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared key before iterator buffer, used explicit 0xffff0000 mask and inverted equality to return -1; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern void FUN_00238e5c(void *ret, void *map, void *key);

int FUN_00238cf0(int *param_1, int param_2, uint param_3)
{
    uint key = (param_2 << 16 & 0xffff0000) | (param_3 & 0xffff);
    int *local_c[2];
    FUN_00238e5c(local_c, param_1 + 4, &key);
    if (local_c[0] != param_1 + 5) {
        return local_c[0][4];
    }
    return -1;
}
