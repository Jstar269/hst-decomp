/* HSTMATCH module=hstp_trans_main.prx start=0x00238d4c end=0x00238ddc symbol=FUN_00238d4c lang=c99 */
/* Clone of src/eboot/tree_lookup_002297d8.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed sentinel ternaries and local array dimensions for 48-byte frame; exact match verified; names and types await human review. */

typedef unsigned int uint;

extern void FUN_00238ddc(void *, const void *, const int *);
extern void FUN_00238e5c(void *, const void *, const int *);

struct Node {
    char pad[16];
    int value;
};

int FUN_00238d4c(char *param_1, int param_2, uint param_3)
{
    int key1 = param_2;
    int key2[2];
    struct Node *it1[2];
    struct Node *it2;

    FUN_00238ddc(it1, param_1, &key1);
    int val1 = (it1[0] != (struct Node *)(param_1 + 4)) ? it1[0]->value : -1;

    key2[0] = ((val1 << 16) & 0xffff0000) | (param_3 & 0xffff);
    FUN_00238e5c(&it2, param_1 + 16, key2);
    return (it2 != (struct Node *)(param_1 + 20)) ? it2->value : -1;
}
