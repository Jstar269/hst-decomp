/* HSTMATCH module=EBOOT.BIN start=0x0015cce8 end=0x0015ced4 symbol=FUN_0015cce8 lang=c99 rodata=0x002c1d28 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/entry_kind.h"

/* One table entry (0x28 bytes). */
typedef struct TableEntry { char b[0x28]; } TableEntry;

/* Entry counts of the tables (the index must be below the count). */
enum { COUNT_KIND_0 = 54, COUNT_KIND_1 = 21, COUNT_KIND_2 = 11, COUNT_KIND_3 = 15, COUNT_KIND_4 = 8,
       COUNT_KIND_6 = 5, COUNT_KIND_10 = 3, COUNT_KIND_11 = 11 };

extern TableEntry DAT_002dcc24[];
extern TableEntry DAT_002dd50c[];
extern TableEntry DAT_002dd854[];
extern TableEntry DAT_002ddbc4[];
extern TableEntry DAT_002dde1c[];
extern TableEntry DAT_002ddf5c[];
extern TableEntry DAT_002ddf84[];
extern TableEntry DAT_002dd494[];
extern TableEntry DAT_002dda0c[];
extern void FUN_0015cbc4(int, int *, unsigned *);

/* Map a flat id to the address of its table entry (0 when the id has none). */
int FUN_0015cce8(int unused, int id)
{
    int kind = 0;
    unsigned idx = 0;
    int entry = 0;
    FUN_0015cbc4(id, &kind, &idx);
    switch (kind) {
    case ENTRY_KIND_0:
        if (idx < COUNT_KIND_0) {
            entry = (int)&DAT_002dcc24[idx];
        }
        break;
    case ENTRY_KIND_1:
        if (idx < COUNT_KIND_1) {
            entry = (int)&DAT_002dd50c[idx];
        }
        break;
    case ENTRY_KIND_2:
        if (idx < COUNT_KIND_2) {
            entry = (int)&DAT_002dd854[idx];
        }
        break;
    case ENTRY_KIND_3:
        if (idx < COUNT_KIND_3) {
            entry = (int)&DAT_002ddbc4[idx];
        }
        break;
    case ENTRY_KIND_4:
        if (idx < COUNT_KIND_4) {
            entry = (int)&DAT_002dde1c[idx];
        }
        break;
    case ENTRY_KIND_5:
        if (idx == 0) {
            entry = (int)&DAT_002ddf5c[idx];
        }
        break;
    case ENTRY_KIND_6:
        if (idx < COUNT_KIND_6) {
            entry = (int)&DAT_002ddf84[idx];
        }
        break;
    case ENTRY_KIND_7:
    case 8:
    case 9:
        break;
    case ENTRY_KIND_10:
        if (idx < COUNT_KIND_10) {
            entry = (int)&DAT_002dd494[idx];
        }
        break;
    case ENTRY_KIND_11:
        if (idx < COUNT_KIND_11) {
            entry = (int)&DAT_002dda0c[idx];
        }
        break;
    }
    return entry;
}
