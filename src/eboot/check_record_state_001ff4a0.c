/* HSTMATCH module=EBOOT.BIN start=0x001ff4a0 end=0x001ff554 symbol=FUN_001ff4a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of check_id_match_001ff3dc.c: tests the two global managers, calls FUN_000be7b4 with the
   second one and then looks at the record the first one points at (base pointer at +0x40, selected by
   the flag byte at +0x178 of the second global: +0x1aa0 for the flag clear, +0x1ef8 for it set).
   The record answers with a byte at +0x12d and two ints at +0x3c0/+0x3c4, both of which must be 11.
   Matching idioms: the three global tests are NESTED ifs (not early returns) and the inner pair is
   repeated around the record lookup, so the null paths leave the record pointer at 0 and fall into the
   shared test block; the call's argument (the second global) is loaded into a0 before its own test. */
#include "hst/adhoc_net.h"
#include "hst/record_bank.h"

/* The state value both ints of a finished bank must hold. */
#define RECORD_STATE_DONE 11

extern RecordRoot *DAT_003386c8;
extern AdhocNet *DAT_00338ac4;
extern int FUN_000be7b4(void *arg);

int FUN_001ff4a0(void)
{
    int res = 0;
    if (DAT_003386c8 != 0) {
        if (DAT_00338ac4 != 0) {
            if (FUN_000be7b4(DAT_00338ac4) != 0) {
                RecordBank *bank = 0;
                if (DAT_003386c8 != 0) {
                    if (DAT_00338ac4 != 0) {
                        RecordOwner *owner = DAT_003386c8->owner;
                        if (DAT_00338ac4->unk178 != 0) {
                            bank = &owner->banks[1];
                        } else {
                            bank = &owner->banks[0];
                        }
                    }
                }
                if (bank->unk12d != 0 && bank->unk3c0 == RECORD_STATE_DONE && bank->unk3c4 == RECORD_STATE_DONE) {
                    res = 1;
                }
            }
        }
    }
    return res;
}
