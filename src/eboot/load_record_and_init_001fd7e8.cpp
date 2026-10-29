/* HSTMATCH module=EBOOT.BIN start=0x001fd7e8 end=0x001fdb80 symbol=FUN_001fd7e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the record copy `self->rec = *rec` relies on Str16 having a user constructor (non-POD, so the implicit copy is memberwise: 2-per-pass count-down loops for the 16-char arrays); Rgb and S3 are 3-member sub-structs only because retail copies those runs as one batch (loads first, then stores); the mode tests are switches (cases listed ascending, tests come out reversed). */
struct Str16 { char c[16]; Str16() {} };
struct Rgb { unsigned char r, g, b; };
struct S3 { short a, b, c; };
/* Record loaded from the regulation table (0x6c bytes). */
struct Rec {
    Str16 str00;
    unsigned short unk10;
    Str16 str12;
    short unk22;
    short unk24;
    unsigned char unk26, unk27, unk28, unk29, unk2a, unk2b;
    char unk2c, unk2d;
    unsigned char unk2e;
    char unk2f;
    unsigned char unk30, unk31;
    char unk32;
    unsigned char unk33, unk34;
    short unk36, unk38, unk3a, unk3c;
    Str16 str3e;
    Str16 str4e;
    Rgb rgb;      /* 0x5e */
    S3 unk62;
    short unk68, unk6a;
};
/* Regulation screen object; unnamed parts are opaque here. */
struct RegulationScreen {
    char pad0[0x3c];
    int unk3c, mode, state, unk48, unk4c, flag50, flag54;
    Rec rec;
    unsigned char flagc4;
    char padc5[3];
    char sub0c8[0xcd0 - 0xc8];
    char lights[0xf90 - 0xcd0];
    char sub0f90[0x1250 - 0xf90];
    unsigned char unk1250;
    char pad1251[0x1292 - 0x1251];
    unsigned char mode1292;
};
struct ModeContext { char pad[0x138]; int unk138; };
extern "C" {
extern int DAT_00341d84;
extern int DAT_0034a678;
Rec *FUN_00193118(int);
void FUN_0001f1fc(RegulationScreen *, int);
void FUN_000149a8(char *, char *);
unsigned char FUN_002b79e8(void);
ModeContext *FUN_0022cd60(void);
void FUN_001fd50c(RegulationScreen *, int);
void FUN_001fff40(char *, Rec *);
void FUN_00200bc4(char *, char *, char *);
void FUN_00200bcc(char *, char *, char *);
void FUN_00200d94(char *);
void FUN_00201724(char *);
void FUN_00201a84(char *, int, int, int);
}
/* Loads record `id` into the screen, derives its mode flags and initialises the sub-objects; state 6 when the record is missing. */
extern "C" void FUN_001fd7e8(RegulationScreen *self, int id, int arg3, int arg4)
{
    Rec *rec = FUN_00193118(id);
    if (rec != 0) {
        self->rec = *rec;
        self->mode = 0;
        self->state = 0;
        self->unk48 = 0;
        self->unk3c = 0;
        self->flag50 = 1;
        self->flag54 = 0;
        switch (DAT_0034a678) {
        case 5:
            if ((FUN_002b79e8() & 2) != 0) {
                self->rec.unk28 = 1;
                self->rec.unk3a = self->rec.unk36;
                self->rec.unk3c = self->rec.unk38;
                FUN_000149a8(self->rec.str4e.c, self->rec.str3e.c);
            }
            break;
        case 2:
        case 0x20:
            if (DAT_00341d84 != 0) {
                self->rec.unk2c = DAT_00341d84;
            }
            break;
        }
        switch (self->rec.unk28) {
        case 0:
        case 4:
            self->flagc4 = 0;
            break;
        default:
            self->flagc4 = 1;
            break;
        }
        ModeContext *ctx = FUN_0022cd60();
        switch (ctx->unk138) {
        case 0:
            self->unk4c = 0;
            break;
        case 2:
            self->unk4c = 2;
            break;
        default:
            self->unk4c = 1;
            break;
        }
        FUN_001fd50c(self, self->mode1292);
        FUN_001fff40(self->sub0c8, &self->rec);
        switch (self->rec.unk28) {
        case 0:
        case 4:
        case 2:
            FUN_00200bc4(self->sub0c8, self->lights, self->sub0f90);
            break;
        default:
            FUN_00200bcc(self->sub0c8, self->lights, self->sub0f90);
            break;
        }
        FUN_00200d94(self->sub0c8);
        FUN_00201724(self->sub0c8);
        FUN_00201a84((char *)&self->unk1250, self->flagc4, arg3, arg4);
        self->unk1250 = 1;
        self->state = 1;
    } else {
        self->state = 6;
    }
    FUN_0001f1fc(self, 1);
}
