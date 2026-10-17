/* HSTMATCH module=EBOOT.BIN start=0x001fd7e8 end=0x001fdb80 symbol=FUN_001fd7e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the record copy `self->rec = *r` relies on Str16 having a user constructor (non-POD, so the implicit copy is memberwise: 2-per-pass count-down loops for the 16-char arrays); Rgb and S3 are 3-member sub-structs only because retail copies those runs as one batch (loads first, then stores); the mode tests are switches (cases listed ascending, tests come out reversed). */
struct Str16 { char c[16]; Str16() {} };
struct Rgb { unsigned char r, g, b; };
struct S3 { short a, b, c; };
struct Rec {
    Str16 a;
    unsigned short s10;
    Str16 b;
    short s22;
    short s24;
    unsigned char b26, b27, b28, b29, b2a, b2b;
    char b2c, b2d;
    unsigned char b2e;
    char b2f;
    unsigned char b30, b31;
    char b32;
    unsigned char b33, b34;
    short s36, s38, s3a, s3c;
    Str16 c;
    Str16 d;
    Rgb rgb;
    S3 s3;
    short s68, s6a;
};
struct Obj {
    char pad0[0x3c];
    int f3c, f40, f44, f48, f4c, f50, f54;
    Rec rec;
    unsigned char fc4;
    char padc5[3];
    char blk_c8[0xcd0 - 0xc8];
    char blk_cd0[0xf90 - 0xcd0];
    char blk_f90[0x1250 - 0xf90];
    unsigned char f1250;
    char pad1251[0x1292 - 0x1251];
    unsigned char f1292;
};
struct Ctx { char pad[0x138]; int f138; };
extern "C" {
extern int DAT_00341d84;
extern int DAT_0034a678;
Rec *FUN_00193118(int);
void FUN_0001f1fc(Obj *, int);
void FUN_000149a8(char *, char *);
unsigned char FUN_002b79e8(void);
Ctx *FUN_0022cd60(void);
void FUN_001fd50c(Obj *, int);
void FUN_001fff40(char *, Rec *);
void FUN_00200bc4(char *, char *, char *);
void FUN_00200bcc(char *, char *, char *);
void FUN_00200d94(char *);
void FUN_00201724(char *);
void FUN_00201a84(char *, int, int, int);
}
extern "C" void FUN_001fd7e8(Obj *self, int id, int p3, int p4)
{
    Rec *r = FUN_00193118(id);
    if (r != 0) {
        self->rec = *r;
        self->f40 = 0;
        self->f44 = 0;
        self->f48 = 0;
        self->f3c = 0;
        self->f50 = 1;
        self->f54 = 0;
        switch (DAT_0034a678) {
        case 5:
            if ((FUN_002b79e8() & 2) != 0) {
                self->rec.b28 = 1;
                self->rec.s3a = self->rec.s36;
                self->rec.s3c = self->rec.s38;
                FUN_000149a8(self->rec.d.c, self->rec.c.c);
            }
            break;
        case 2:
        case 0x20:
            if (DAT_00341d84 != 0) {
                self->rec.b2c = DAT_00341d84;
            }
            break;
        }
        switch (self->rec.b28) {
        case 0:
        case 4:
            self->fc4 = 0;
            break;
        default:
            self->fc4 = 1;
            break;
        }
        Ctx *ctx = FUN_0022cd60();
        switch (ctx->f138) {
        case 0:
            self->f4c = 0;
            break;
        case 2:
            self->f4c = 2;
            break;
        default:
            self->f4c = 1;
            break;
        }
        FUN_001fd50c(self, self->f1292);
        FUN_001fff40(self->blk_c8, &self->rec);
        switch (self->rec.b28) {
        case 0:
        case 4:
        case 2:
            FUN_00200bc4(self->blk_c8, self->blk_cd0, self->blk_f90);
            break;
        default:
            FUN_00200bcc(self->blk_c8, self->blk_cd0, self->blk_f90);
            break;
        }
        FUN_00200d94(self->blk_c8);
        FUN_00201724(self->blk_c8);
        FUN_00201a84((char *)&self->f1250, self->fc4, p3, p4);
        self->f1250 = 1;
        self->f44 = 1;
    } else {
        self->f44 = 6;
    }
    FUN_0001f1fc(self, 1);
}
