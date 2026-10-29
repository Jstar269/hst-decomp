/* HSTMATCH module=EBOOT.BIN start=0x001ff3dc end=0x001ff4a0 symbol=FUN_001ff3dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/adhoc_net.h"
#include "hst/record_bank.h"

extern RecordRoot *DAT_003386c8;
extern AdhocNet *DAT_00338ac4;
extern int FUN_000be7b4(void *arg);

/* Return 1 when the active bank is in use and id is non-zero and equals both of its ids at 0x3b0 and 0x3b4. */
int FUN_001ff3dc(int id) {
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
                if (bank->unk12d != 0 && id != 0 && id == bank->unk3b0 && id == bank->unk3b4) {
                    res = 1;
                }
            }
        }
    }
    return res;
}
