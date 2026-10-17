/* HSTMATCH module=hstp_trans_main.prx start=0x0020bfb8 end=0x0020c350 symbol=FUN_0020bfb8 lang=c++ */
/* Clone of src/eboot/load_record_and_init_001fd7e8.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003eb0bc;
extern int DAT_003f39a8;
Rec *FUN_0019f928(int);
void FUN_0001ef14(Obj *, int);
void FUN_000149a8(char *, char *);
unsigned char FUN_002c7788(void);
Ctx *FUN_0023ce60(void);
void FUN_0020bcdc(Obj *, int);
void FUN_0020e710(char *, Rec *);
void FUN_0020f394(char *, char *, char *);
void FUN_0020f39c(char *, char *, char *);
void FUN_0020f564(char *);
void FUN_0020fef4(char *);
void FUN_00210254(char *, int, int, int);
}
extern "C" void FUN_0020bfb8(Obj *self, int id, int p3, int p4)
{
    Rec *r = FUN_0019f928(id);
    if (r != 0) {
        self->rec = *r;
        self->f40 = 0;
        self->f44 = 0;
        self->f48 = 0;
        self->f3c = 0;
        self->f50 = 1;
        self->f54 = 0;
        switch (DAT_003f39a8) {
        case 5:
            if ((FUN_002c7788() & 2) != 0) {
                self->rec.b28 = 1;
                self->rec.s3a = self->rec.s36;
                self->rec.s3c = self->rec.s38;
                FUN_000149a8(self->rec.d.c, self->rec.c.c);
            }
            break;
        case 2:
        case 0x20:
            if (DAT_003eb0bc != 0) {
                self->rec.b2c = DAT_003eb0bc;
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
        Ctx *ctx = FUN_0023ce60();
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
        FUN_0020bcdc(self, self->f1292);
        FUN_0020e710(self->blk_c8, &self->rec);
        switch (self->rec.b28) {
        case 0:
        case 4:
        case 2:
            FUN_0020f394(self->blk_c8, self->blk_cd0, self->blk_f90);
            break;
        default:
            FUN_0020f39c(self->blk_c8, self->blk_cd0, self->blk_f90);
            break;
        }
        FUN_0020f564(self->blk_c8);
        FUN_0020fef4(self->blk_c8);
        FUN_00210254((char *)&self->f1250, self->fc4, p3, p4);
        self->f1250 = 1;
        self->f44 = 1;
    } else {
        self->f44 = 6;
    }
    FUN_0001ef14(self, 1);
}
