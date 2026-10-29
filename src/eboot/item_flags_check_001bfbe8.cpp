/* HSTMATCH module=EBOOT.BIN start=0x001bfbe8 end=0x001bfdd0 symbol=FUN_001bfbe8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/item_table.h"

extern u8 DAT_002e9fec;
extern u8 DAT_002e9ff4;
extern u8 DAT_002e9ffc;
extern int DAT_0034174c;

extern "C" {
int FUN_0000d62c(int);
int FUN_00014d64(int, void *);
int FUN_000650e0(int);
int FUN_0006517c(int, int, int);
int FUN_001bfbe8(ItemTable *table, int entry);
}

/* True when every item of entry `entry` has its flag in state A or B. */
int FUN_001bfbe8(ItemTable *table, int entry)
{
    int ok;
    int list;
    int i;
    int item;
    int id;
    char *p;
    unsigned char val;

    ok = 0;
    list = DAT_0034174c;
    if (list != 0 && entry >= 0 && entry < FUN_000650e0(list)) {
        ok = 1;
        for (i = 0; i < 4; i++) {
            item = FUN_0006517c(list, entry + 1, i + 1);
            if (item != 0) {
                if (FUN_00014d64(item, &DAT_002e9fec) != 0) {
                    id = FUN_0000d62c(item + 5);
                    val = 0;
                    if (id >= 0) {
                        if (id < ITEM_FLAG_COUNT) {
                            p = (char *)&table->flag_a[id];
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - ITEM_STATE_A) > 1)
                        ok = 0;
                } else if (FUN_00014d64(item, &DAT_002e9ff4) != 0) {
                    id = FUN_0000d62c(item + 5);
                    val = 0;
                    if (id >= 0) {
                        if (id < ITEM_FLAG_COUNT) {
                            p = (char *)&table->flag_b[id];
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - ITEM_STATE_A) > 1)
                        ok = 0;
                } else if (FUN_00014d64(item, &DAT_002e9ffc) != 0) {
                    id = FUN_0000d62c(item + 5);
                    val = 0;
                    if (id >= 0) {
                        if (id < ITEM_FLAG_COUNT) {
                            p = (char *)&table->flag_c[id];
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - ITEM_STATE_A) > 1)
                        ok = 0;
                }
            }
        }
    }
    return ok;
}
