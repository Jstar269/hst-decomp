/* HSTMATCH module=EBOOT.BIN start=0x0022977c end=0x002297d8 symbol=FUN_0022977c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared key before iterator buffer, used explicit 0xffff0000 mask and inverted equality to return -1; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern void FUN_002298e8(void *ret, void *map, void *key);

int FUN_0022977c(int *param_1, int param_2, uint param_3)
{
    uint key = (param_2 << 16 & 0xffff0000) | (param_3 & 0xffff);
    int *local_c[2];
    FUN_002298e8(local_c, param_1 + 4, &key);
    if (local_c[0] != param_1 + 5) {
        return local_c[0][4];
    }
    return -1;
}
