/* HSTMATCH module=hstp_trans_main.prx start=0x001cf558 end=0x001cf6dc symbol=FUN_001cf558 lang=c++ */
/* Clone of src/eboot/fill_records_001c1344.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Row {
    short h[4];
    char pad[4];
};

struct Rec {
    unsigned char b0;
    unsigned char b1;
    short h2;
    int i4;
    Row rows[4];
};

struct Obj {
    char pad[0xc8];
    Rec recs[15];
};

struct Ent {
    char pad[0x60];
    signed char b60;
};

extern "C" {
extern int DAT_003e1e48;
Ent *FUN_000dca74(int, int, int);
void FUN_000114c0(void *, int, int);
int FUN_001c96a0(int, int);
}

extern "C" void FUN_001cf558(Obj *o)
{
    for (int i = 0; i < 15; i++) {
        Rec *rec = &o->recs[i];
        Ent *e = FUN_000dca74(DAT_003e1e48, 0, i);
        rec->b0 = 0;
        rec->h2 = 0;
        rec->b1 = 0;
        rec->i4 = 0;
        for (int r = 0; r < 4; r++) {
            FUN_000114c0(&rec->rows[r], 0, 12);
        }
        if (e != 0 && e->b60 >= 0) {
            if (e->b60 == 1) {
                rec->b0 = 4;
            }
            rec->h2 = FUN_001c96a0(5, i);
            for (int r = 0; r < 4; r++) {
                short *h = rec->rows[r].h;
                for (int c = 0; c < 4; c++) {
                    switch (c) {
                    case 0:
                        h[c] = FUN_001c96a0(1, i);
                        break;
                    case 1:
                        h[c] = FUN_001c96a0(2, i);
                        break;
                    case 2:
                        h[c] = FUN_001c96a0(3, i);
                        break;
                    case 3:
                        h[c] = FUN_001c96a0(4, i);
                        break;
                    }
                }
            }
        }
    }
}
