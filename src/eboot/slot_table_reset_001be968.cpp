/* HSTMATCH module=EBOOT.BIN start=0x001be968 end=0x001bebb0 symbol=FUN_001be968 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/flag_tables.h"

extern "C" {
MgrEntry *FUN_000d8c24(void *mgr, int a, int i);
void FUN_000114c0(void *p, int c, unsigned n);
void FUN_001bf62c(FlagTables *self, int i, int n);
short FUN_001bb8b8(int kind, int i);
void FUN_001bbab8(SubRec *s);
}

extern void *DAT_00338b08;
extern int DAT_002e9d48;
extern float DAT_002e9d4c;

inline float Clamp(const float &v, const int &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

/* Reset the 15 kind-0 records; for entries that exist, fill each record's id and row values from FUN_001bb8b8 queries. */
extern "C" void FUN_001be968(FlagTables *self, int force, int unused, bool setLimit)
{
    for (int i = 0; i < SUB_REC_COUNT; i++) {
        SubRec *rec = &self->subs[i];
        MgrEntry *entry = FUN_000d8c24(DAT_00338b08, 0, i);
        rec->a = 0;
        rec->c = 0;
        rec->b = 0;
        rec->f = 0;
        for (int r = 0; r < SUB_ROW_COUNT; r++)
            FUN_000114c0(&rec->rows[r], 0, sizeof(SubRow));
        if (entry != 0 && entry->state >= 0) {
            if (force != 0)
                FUN_001bf62c(self, i, 4);
            else if (entry->state == 1)
                FUN_001bf62c(self, i, 4);
            rec->c = FUN_001bb8b8(5, i);
            for (int r = 0; r < SUB_ROW_COUNT; r++) {
                SubRow &row = rec->rows[r];
                for (int k = 0; k < SUB_ROW_VALUE_COUNT; k++) {
                    switch (k) {
                    case 0:
                        row.v[k] = FUN_001bb8b8(1, i);
                        break;
                    case 1:
                        row.v[k] = FUN_001bb8b8(2, i);
                        break;
                    case 2:
                        row.v[k] = FUN_001bb8b8(3, i);
                        break;
                    case 3:
                        row.v[k] = FUN_001bb8b8(4, i);
                        break;
                    }
                }
            }
            if (setLimit) {
                float lim = 9999.0f;
                rec->f = Clamp(lim, DAT_002e9d48, DAT_002e9d4c);
                FUN_001bbab8(rec);
            }
        }
    }
}
