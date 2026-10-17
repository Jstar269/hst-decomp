/* HSTMATCH module=EBOOT.BIN start=0x00045160 end=0x000451c8 symbol=FUN_00045160 lang=c99 */
/* Clone of src/sharing_main/lower_bound_00045260.c (hstclone.py tag u1r5e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Entry {
    unsigned short key;
    unsigned short val;
};

struct Entry *FUN_00045160(struct Entry *first, struct Entry *last, const unsigned short *val)
{
    int len = last - first;
    if (len > 0) {
        unsigned int target = *val;
        do {
            int half = len / 2;
            struct Entry *mid = first + half;
            if ((unsigned int)mid->key < target) {
                first = mid + 1;
                len -= half + 1;
            } else {
                len = half;
            }
        } while (len > 0);
    }
    return first;
}
