/* HSTMATCH module=hstp_trans_main.prx start=0x001b2194 end=0x001b21e8 symbol=FUN_001b2194 */
/* Clone of src/eboot/FUN_001a4bc8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Returns whether the entry with the given id is set. */
/* This object was built without loop strength reduction (index recomputed each iteration). */
#pragma opt_strength_reduction off
typedef struct {
    char pad0[0x348];
    unsigned int *ids;
    char pad1[8];
    unsigned int *state;
    volatile unsigned int count;
} IdTable;

int FUN_001b2194(IdTable *c, unsigned int id)
{
    unsigned int i = 0;
    if (c->count != 0) {
        unsigned int *ids = c->ids;
        do {
            if (ids[i] == id) {
                return c->state[i] != 0;
            }
        } while (++i < c->count);
    }
    return 0;
}
