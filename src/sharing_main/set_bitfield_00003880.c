/* HSTMATCH module=hstp_trans_main.prx start=0x00003880 end=0x000038c4 symbol=FUN_00003880 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: replaced bitwise shift and mask on word with 31-bit bitfield member assignment; exact match verified; names and types await human review. */

struct Bitfield {
    unsigned int a : 1;
    unsigned int b : 31;
};

extern struct Bitfield *FUN_00003004(void *obj);

void FUN_00003880(void *obj, int val)
{
    struct Bitfield *p = FUN_00003004(obj);
    p->b = val;
}
