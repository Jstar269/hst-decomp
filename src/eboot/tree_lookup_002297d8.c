/* HSTMATCH module=EBOOT.BIN start=0x002297d8 end=0x00229868 symbol=FUN_002297d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed sentinel ternaries and local array dimensions for 48-byte frame; exact match verified; names and types await human review. */

#include "hst/types.h"

extern void FUN_00229868(void *, const void *, const int *);
extern void FUN_002298e8(void *, const void *, const int *);

struct Node {
    char pad[16];
    int value;
};

int FUN_002297d8(char *param_1, int param_2, u32 param_3)
{
    int key1 = param_2;
    int key2[2];
    struct Node *it1[2];
    struct Node *it2;

    FUN_00229868(it1, param_1, &key1);
    int val1 = (it1[0] != (struct Node *)(param_1 + 4)) ? it1[0]->value : -1;

    key2[0] = ((val1 << 16) & 0xffff0000) | (param_3 & 0xffff);
    FUN_002298e8(&it2, param_1 + 16, key2);
    return (it2 != (struct Node *)(param_1 + 20)) ? it2->value : -1;
}
