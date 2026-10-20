/* HSTMATCH module=EBOOT.BIN start=0x001fdd50 end=0x001fe010 symbol=FUN_001fdd50 lang=c++ */

extern int DAT_00331b84;
extern void *DAT_003415ac;
extern char DAT_0034a678;

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x3c];
    int f3c;
    int f40;
    int f44;
    int f48;
    char pad2[0x7d8 - 0x4c];
    int f7d8;
    char pad3[0x1290 - 0x7dc];
    unsigned char flag_1290;
};

extern "C" {
void FUN_00063830(int, const Vec4 *, const Vec4 *, int, int, int, float, float);
void FUN_0023466c(char *);
int FUN_001155c0(void *);
void FUN_00103628(void *, int);
int FUN_001156d4(void *);
}

static inline void HandleCase(Obj *self, int val)
{
    self->f3c = val;
    self->f44 = 9;
    if (self->flag_1290 != 0) {
        if (self->f3c == 1 || self->f3c == 3 || self->f3c == 2) {
            Vec4 a;
            a.x = 0.0f; a.y = 0.0f; a.z = 0.0f; a.w = 0.0f;
            Vec4 b;
            b.x = 0.0f; b.y = 0.0f; b.z = 0.0f; b.w = 0.0f;
            FUN_00063830(DAT_00331b84, &b, &a, 0, 0, 0, 0.0f, -1.0f);
            FUN_0023466c(&DAT_0034a678);
        }
    }
}

extern "C" void FUN_001fdd50(Obj *self)
{
    if (self->f44 != 0) {
        self->f40 = self->f44;
        self->f44 = 0;
    }

    int state = self->f40;
    if (state == 8) goto CASE_8;
    if (state == 7) goto CASE_7;
    if (state == 6) goto CASE_6;
    if (state == 4) goto CASE_4;
    if (state == 1) goto CASE_1;
    return;

CASE_1:
    if (self->f7d8 == 3) {
        self->f44 = 2;
    }
    return;

CASE_4:
    if (FUN_001155c0(DAT_003415ac) != 0) {
        FUN_00103628(DAT_003415ac, 1);
        if (FUN_001156d4(DAT_003415ac) != 0) {
            self->f44 = self->f48;
        } else {
            self->f44 = 7;
        }
    }
    return;

CASE_6:
    HandleCase(self, 3);
    return;

CASE_7:
    HandleCase(self, 2);
    return;

CASE_8:
    HandleCase(self, 1);
    return;
}
// near miss from lane s10171846g1r1-0 (unreviewed)
