/* HSTMATCH module=hstp_trans_main.prx start=0x00296718 end=0x00296838 symbol=FUN_00296718 lang=c++ */
/* Clone of src/eboot/copy_construct_record_00285110.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V3s_00099c98 { short x, y, z; };
struct S_00099c98 {
    short a00[6];
    unsigned char b0c, b0d, b0e;
    char s0f[16];
    unsigned short h20, h22;
    unsigned char b24;
    char s25[6];
    unsigned char b2b, b2c;
    char s2d[16];
    short h3e, h40;
    unsigned char b42, b43;
    float f44, f48, f4c;
    short h50, h52;
    char s54[16];
    unsigned char b64, b65, b66, b67;
    char s68[16];
    short h78, h7a;
    unsigned char b7c;
    char s7d[12];
    V3s_00099c98 v8a;
    short a90[5];
    S_00099c98();
    S_00099c98 &operator=(const S_00099c98 &);
};

struct Pair_00296718 { unsigned char a, b; };
struct V4 { float x, y, z, w; };

struct S_00296718 : public S_00099c98 {
    Pair_00296718 p9c;
    unsigned char b9e, b9f;
    char ba0;
    V4 va4;
    float fb4;
    int ib8;
    short arr_bc[6];
    S_00296718();
};

extern "C" void FUN_000114c0(void *, int, int);
extern "C" void FUN_000dbb60(void *);

extern "C" S_00296718 *FUN_00296718(S_00296718 *self, const S_00296718 *o)
{
    FUN_000114c0(self, 0, 0x9c);
    self->h22 = 0xffff;
    self->h20 = 0xffff;
    self->a00[0] = -1;
    self->a00[1] = -1;
    self->a00[2] = -1;
    self->a00[3] = -1;
    self->a00[4] = -1;
    self->a00[5] = -1;
    self->h7a = -1;
    self->s54[0] = 45;
    self->s54[1] = 49;
    self->s54[2] = 0;
    self->s68[0] = 45;
    self->s68[1] = 49;
    self->s68[2] = 0;
    *self = *o;
    FUN_000dbb60(self);
    return self;
}
