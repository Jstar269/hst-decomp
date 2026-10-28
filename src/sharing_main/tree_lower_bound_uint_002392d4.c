/* HSTMATCH module=hstp_trans_main.prx start=0x002392d4 end=0x0023930c symbol=FUN_002392d4 lang=c99 */
/* Clone of src/eboot/tree_lower_bound_uint_00229d60.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *f00; struct Node *f04; char pad[4]; unsigned int key; };

struct Node *FUN_002392d4(void *self, unsigned int *k, struct Node *cur, struct Node *best)
{
    while (cur != 0) {
        if (cur->key >= *k) {
            best = cur;
            cur = cur->f00;
        } else
            cur = cur->f04;
    }
    return best;
}
