/* HSTMATCH module=hstp_trans_main.prx start=0x0020dc70 end=0x0020dd24 symbol=FUN_0020dc70 lang=c99 */
/* Clone of src/eboot/check_record_state_001ff4a0.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of check_id_match_001ff3dc.c: tests the two global managers, calls FUN_000c1e54 with the
   second one and then looks at the record the first one points at (base pointer at +0x40, selected by
   the flag byte at +0x178 of the second global: +0x1aa0 for the flag clear, +0x1ef8 for it set).
   The record answers with a byte at +0x12d and two ints at +0x3c0/+0x3c4, both of which must be 11.
   Matching idioms: the three global tests are NESTED ifs (not early returns) and the inner pair is
   repeated around the record lookup, so the null paths leave the record pointer at 0 and fall into the
   shared test block; the call's argument (the second global) is loaded into a0 before its own test. */
typedef unsigned char u8;

extern void *DAT_003e1a08;
extern void *DAT_003e1e04;
extern int FUN_000c1e54(void *arg);

int FUN_0020dc70(void)
{
    int res = 0;
    if (DAT_003e1a08 != 0) {
        if (DAT_003e1e04 != 0) {
            if (FUN_000c1e54(DAT_003e1e04) != 0) {
                char *sub = 0;
                if (DAT_003e1a08 != 0) {
                    if (DAT_003e1e04 != 0) {
                        char *base = *(char **)((char *)DAT_003e1a08 + 0x40);
                        if (*(u8 *)((char *)DAT_003e1e04 + 0x178) != 0) {
                            sub = base + 0x1ef8;
                        } else {
                            sub = base + 0x1aa0;
                        }
                    }
                }
                if (*(u8 *)(sub + 0x12d) != 0 && *(int *)(sub + 0x3c0) == 11 && *(int *)(sub + 0x3c4) == 11) {
                    res = 1;
                }
            }
        }
    }
    return res;
}
