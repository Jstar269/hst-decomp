/* HSTMATCH module=hstp_trans_main.prx start=0x001cc6bc end=0x001cc904 symbol=FUN_001cc6bc lang=c++ */
/* Clone of src/eboot/slot_table_reset_001be968.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Row {
    short v[4];
    int pad;
};
struct Sub {
    unsigned char a;
    unsigned char b;
    short c;
    float f;
    Row rows[4];
};
struct Self {
    int hdr;
    Sub subs[15];
};
struct Info {
    char pad[0x60];
    signed char state;
};

extern "C" {
Info *FUN_000dca74(void *mgr, int a, int i);
void FUN_000114c0(void *p, int c, unsigned n);
void FUN_001cd380(Self *self, int i, int n);
short FUN_001c96a0(int kind, int i);
void FUN_001c98a0(Sub *s);
}

extern void *DAT_003e1e48;
extern int DAT_00391980;
extern float DAT_00391984;

inline float Clamp(const float &v, const int &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

extern "C" void FUN_001cc6bc(Self *self, int force, int unused, bool setLimit)
{
    for (int i = 0; i < 15; i++) {
        Sub *s = &self->subs[i];
        Info *p = FUN_000dca74(DAT_003e1e48, 0, i);
        s->a = 0;
        s->c = 0;
        s->b = 0;
        s->f = 0;
        for (int r = 0; r < 4; r++)
            FUN_000114c0(&s->rows[r], 0, sizeof(Row));
        if (p != 0 && p->state >= 0) {
            if (force != 0)
                FUN_001cd380(self, i, 4);
            else if (p->state == 1)
                FUN_001cd380(self, i, 4);
            s->c = FUN_001c96a0(5, i);
            for (int r = 0; r < 4; r++) {
                Row &row = s->rows[r];
                for (int k = 0; k < 4; k++) {
                    switch (k) {
                    case 0:
                        row.v[k] = FUN_001c96a0(1, i);
                        break;
                    case 1:
                        row.v[k] = FUN_001c96a0(2, i);
                        break;
                    case 2:
                        row.v[k] = FUN_001c96a0(3, i);
                        break;
                    case 3:
                        row.v[k] = FUN_001c96a0(4, i);
                        break;
                    }
                }
            }
            if (setLimit) {
                float lim = 9999.0f;
                s->f = Clamp(lim, DAT_00391980, DAT_00391984);
                FUN_001c98a0(s);
            }
        }
    }
}
