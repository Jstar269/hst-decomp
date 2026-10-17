/* HSTMATCH module=hstp_trans_main.prx start=0x00209394 end=0x00209720 symbol=FUN_00209394 lang=c++ */
/* Clone of src/eboot/record_rows_001fac7c.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: lang=c++ with `bool ok, full, part` declared at function scope (byte-sized stack slots 59/58(sp); unsigned char, volatile or struct flags give word slots), `*p - 4U > 1` (sltiu at), rem and quot computed before the flags are declared (prologue schedule), the row pointer computed BEFORE the sum is read into `v`, and `#pragma opt_unroll_loops off` for the ten-table loop. */
#pragma opt_unroll_loops off
typedef struct Row {
    unsigned char used;
    int a;
    int b;
    int c;
    int d;
} Row;
typedef struct Table {
    Row rows[128];
} Table;
typedef struct Obj {
    char pad[0x136c];
    Table tables[11];
} Obj;
typedef struct Pair {
    unsigned char lo;
    unsigned char hi;
} Pair;
typedef struct Tab {
    char pad[0x34c];
    Pair w[640];
    unsigned char t1[640];
    unsigned char t2[640];
    unsigned char t3[640];
} Tab;
typedef struct Rec {
    char pad[0x5c];
    short code;
    char pad1[3];
    signed char amount;
} Rec;

extern "C" Tab *FUN_00177d4c(void);
extern "C" int FUN_0023c5e0(int);

extern "C" void FUN_00209394(Obj *self, int *cnts, int *sums, int *cnt11, int *sum11, int mode, Rec *rec, int idx)
{
    int rem = rec->code % 100;
    int quot = rec->code / 100;
    bool ok = false;
    bool full = false;
    bool part = false;
    Tab *tab = FUN_00177d4c();
    unsigned char *p;

    switch (mode) {
    case 1:
        if (idx >= 0 && idx < 640) p = &tab->t1[idx]; else p = 0;
        if (*p - 4U > 1) ok = true;
        break;
    case 2:
        if (idx >= 0 && idx < 640) p = &tab->t2[idx]; else p = 0;
        if (*p - 4U > 1) ok = true;
        break;
    case 3:
        if (idx >= 0 && idx < 640) p = &tab->t3[idx]; else p = 0;
        if (*p - 4U > 1) ok = true;
        break;
    case 4:
        if (idx >= 0 && idx < 640) p = &tab->w[idx].lo; else p = 0;
        if (*p - 4U > 1) ok = true;
        break;
    }
    if (ok) {
        full = false;
        part = false;
        ok = false;
        if (quot > 0 && FUN_0023c5e0(quot - 1) != 0) {
            ok = true;
            full = true;
        }
        if (rem == 99) {
            ok = true;
            full = true;
        }
        if (quot == 0 && rem > 0) {
            ok = true;
            part = true;
        }
        if (ok) {
            int amt = rec->amount;
            if (full) {
                int i;
                for (i = 0; i < 10; i++) {
                    Row *r = &self->tables[i].rows[cnts[i]];
                    int v = sums[i];
                    r->used = 1;
                    r->a = v;
                    r->b = amt;
                    r->c = mode;
                    r->d = idx;
                    cnts[i] = cnts[i] + 1;
                    sums[i] = sums[i] + amt;
                }
                {
                    Row *r = &self->tables[10].rows[*cnt11];
                    int v = *sum11;
                    r->used = 1;
                    r->a = v;
                    r->b = amt;
                    r->c = mode;
                    r->d = idx;
                    *cnt11 = *cnt11 + 1;
                    *sum11 = *sum11 + amt;
                }
            } else if (part) {
                int k = rem - 1;
                Row *r = &self->tables[k].rows[cnts[k]];
                int v = sums[k];
                r->used = 1;
                r->a = v;
                r->b = amt;
                r->c = mode;
                r->d = idx;
                cnts[k] = cnts[k] + 1;
                sums[k] = sums[k] + amt;
            }
        }
    }
}
