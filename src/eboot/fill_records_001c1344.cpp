/* HSTMATCH module=EBOOT.BIN start=0x001c1344 end=0x001c14c8 symbol=FUN_001c1344 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/record_table.h"

/* Table entry looked up by index; only its kind byte is read here. */
struct Ent {
    char pad[0x60];
    signed char kind; /* negative when the entry is unused */
};

extern "C" {
extern int DAT_00338b08;
Ent *FUN_000d8c24(int, int, int);
void FUN_000114c0(void *, int, int);
int FUN_001bb8b8(int, int);
}

/* Clear every record, then refill the ones whose source entry is in use. */
extern "C" void FUN_001c1344(RecordTable *self)
{
    for (int i = 0; i < RECORD_COUNT; i++) {
        RecordEntry *rec = &self->rec[i];
        Ent *entry = FUN_000d8c24(DAT_00338b08, 0, i);
        rec->unk0 = 0;
        rec->unk2 = 0;
        rec->unk1 = 0;
        rec->unk4 = 0;
        for (int r = 0; r < RECORD_ROWS; r++) {
            FUN_000114c0(&rec->row[r], 0, sizeof(RecordRow));
        }
        if (entry != 0 && entry->kind >= 0) {
            if (entry->kind == 1) {
                rec->unk0 = 4;
            }
            rec->unk2 = FUN_001bb8b8(5, i);
            for (int r = 0; r < RECORD_ROWS; r++) {
                short *cell = rec->row[r].cell;
                for (int c = 0; c < ROW_CELLS; c++) {
                    switch (c) {
                    case 0:
                        cell[c] = FUN_001bb8b8(1, i);
                        break;
                    case 1:
                        cell[c] = FUN_001bb8b8(2, i);
                        break;
                    case 2:
                        cell[c] = FUN_001bb8b8(3, i);
                        break;
                    case 3:
                        cell[c] = FUN_001bb8b8(4, i);
                        break;
                    }
                }
            }
        }
    }
}
