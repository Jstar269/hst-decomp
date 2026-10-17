/* HSTMATCH module=hstp_trans_main.prx start=0x00045260 end=0x000452c8 symbol=FUN_00045260 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Entry {
    unsigned short key;
    unsigned short val;
};

struct Entry *FUN_00045260(struct Entry *first, struct Entry *last, const unsigned short *val)
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
