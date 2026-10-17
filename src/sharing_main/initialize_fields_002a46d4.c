/* HSTMATCH module=hstp_trans_main.prx start=0x002a46d4 end=0x002a47a0 symbol=FUN_002a46d4 lang=c99 */
/* Clone of src/eboot/initialize_fields_002930c8.c (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    char padc[0x38 - 0xc];
    float f38;
    char pad3c[4];
    unsigned char f40;
    char pad41[0x4c - 0x41];
    unsigned char f4c;
    unsigned char f4d;
    unsigned char f4e;
    char pad4f;
    float f50;
    unsigned char f54;
} Obj;
extern int DAT_003daec4;
extern int DAT_003daec8;
void FUN_000646f4(float, float, int, Vec4 *, Vec4 *, int, int, int);
void FUN_00064bcc(float, float, int, int);
void FUN_002a46d4(float f, Obj *o, int mode)
{
    o->f40 = 0;
    o->f4 = 30.0f;
    o->f8 = 30.0f;
    o->f38 = 0.0f;
    o->f38 = 1.0f;
    o->f4c = 0;
    o->f4d = 0;
    o->f50 = f;
    o->f54 = 0;
    if (mode != 0) {
        o->f8 = 0.0f;
    }
    o->f4e = mode;
    if (mode != 0) {
        FUN_00064bcc(65535.0f, -1.0f, DAT_003daec8, 7);
    } else {
        Vec4 b, a;
        a.w = 1.0f;
        a.x = 0.0f;
        a.y = 0.0f;
        a.z = 0.0f;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.w = 0.0f;
        FUN_000646f4(f, -1.0f, DAT_003daec4, &b, &a, 15, 0, 0);
    }
}
