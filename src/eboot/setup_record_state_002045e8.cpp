/* HSTMATCH module=EBOOT.BIN start=0x002045e8 end=0x00204754 symbol=FUN_002045e8 lang=c++ helpers=__ct__10S_00097b2cFRC10S_00097b2c@0x00204754-0x0020498c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* EBOOT twin of the Sharing 0x212e50 (same source). Rebuilds a 200-byte record state from the 0x9c-byte table
   entry `id` (0x193474) when there is one - a temporary built by the inline ctor (implicit copy ctor of the record,
   five flag bytes cleared, 0xd7e70 resets the rest) and assigned with the implicit copy assignment (the record part
   through its out-of-line operator= 0x97b2c, then the members: the two-byte pair batched, the 16-byte float struct
   batched, the halfword array as a count-down loop), then destroyed by the out-of-line dtor 0xd7e30 - and then
   stores the six halfwords, the byte at +0x67 and the byte at +0xa0 from the parameters. The record's implicit copy
   constructor is emitted by this file right after the function, at 0x204754, and is placed there by helpers= (its
   own source is src/eboot/assign_00204754.cpp). The ninth parameter is a word (retail reads it with lw from the
   caller's argument slot). */
struct V3s_00097b2c { short x, y, z; };
struct S_00097b2c {
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
    V3s_00097b2c v8a;
    short a90[5];
    S_00097b2c();
    S_00097b2c &operator=(const S_00097b2c &);
};

struct Pair_002045e8 { unsigned char a, b; };
struct V4 { float x, y, z, w; };

struct S_002045e8;
extern "C" void FUN_000d7e70(S_002045e8 *s);
extern "C" S_00097b2c *FUN_00193474(int id);

struct S_002045e8 : public S_00097b2c {
    Pair_002045e8 p9c;
    unsigned char b9e, b9f;
    char ba0;
    V4 va4;
    float fb4;
    int ib8;
    short arr_bc[6];
    S_002045e8(const S_00097b2c &rec) : S_00097b2c(rec)
    {
        p9c.a = 0;
        p9c.b = 0;
        b9e = 0;
        b9f = 0;
        ba0 = 0;
        FUN_000d7e70(this);
    }
    ~S_002045e8();
};

extern "C" void FUN_002045e8(S_002045e8 *self, int id, short a, short b, short c, short d, short e, char f, int g)
{
    S_00097b2c *rec = FUN_00193474(id);
    if (rec != 0) {
        *self = S_002045e8(*rec);
    }
    self->a00[0] = id;
    self->a00[1] = a;
    self->a00[2] = b;
    self->a00[3] = c;
    self->a00[4] = d;
    self->a00[5] = e;
    self->b67 = f;
    self->ba0 = g;
}
