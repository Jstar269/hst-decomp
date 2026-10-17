/* HSTMATCH module=EBOOT.BIN start=0x001c1344 end=0x001c14c8 symbol=FUN_001c1344 lang=c++ */
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
extern int DAT_00338b08;
Ent *FUN_000d8c24(int, int, int);
void FUN_000114c0(void *, int, int);
int FUN_001bb8b8(int, int);
}

extern "C" void FUN_001c1344(Obj *o)
{
    for (int i = 0; i < 15; i++) {
        Rec *rec = &o->recs[i];
        Ent *e = FUN_000d8c24(DAT_00338b08, 0, i);
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
            rec->h2 = FUN_001bb8b8(5, i);
            for (int r = 0; r < 4; r++) {
                short *h = rec->rows[r].h;
                for (int c = 0; c < 4; c++) {
                    switch (c) {
                    case 0:
                        h[c] = FUN_001bb8b8(1, i);
                        break;
                    case 1:
                        h[c] = FUN_001bb8b8(2, i);
                        break;
                    case 2:
                        h[c] = FUN_001bb8b8(3, i);
                        break;
                    case 3:
                        h[c] = FUN_001bb8b8(4, i);
                        break;
                    }
                }
            }
        }
    }
}
