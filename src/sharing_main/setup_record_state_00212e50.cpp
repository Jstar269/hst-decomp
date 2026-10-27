/* HSTMATCH module=hstp_trans_main.prx start=0x00212e50 end=0x00212fbc symbol=FUN_00212e50 lang=c++ helpers=__ct__10S_00099c98FRC10S_00099c98@0x00212fbc-0x002131f4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rebuilds a 200-byte record state from the 0x9c-byte table entry `id` (0x19fc84) when there is one - a temporary
   built by the inline ctor (implicit copy ctor of the record, five flag bytes cleared, 0xdbb60 resets the rest) and
   assigned with the implicit copy assignment (the record part through its out-of-line operator= 0x99c98, then the
   members: the two-byte pair batched, the 16-byte float struct batched, the halfword array as a count-down loop),
   then destroyed by the out-of-line dtor 0xdbb20 - and then stores the six halfwords, the byte at +0x67 and the
   byte at +0xa0 from the parameters. The record's implicit copy constructor is emitted by this file right after the
   function, at 0x212fbc, and is placed there by helpers= (its own source is src/sharing_main/assign_00212fbc.cpp).
   The ninth parameter is a word (retail reads it with lw from the caller's argument slot). */
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

struct Pair_00212e50 { unsigned char a, b; };
struct V4 { float x, y, z, w; };

struct S_00212e50;
extern "C" void FUN_000dbb60(S_00212e50 *s);
extern "C" S_00099c98 *FUN_0019fc84(int id);

struct S_00212e50 : public S_00099c98 {
    Pair_00212e50 p9c;
    unsigned char b9e, b9f;
    char ba0;
    V4 va4;
    float fb4;
    int ib8;
    short arr_bc[6];
    S_00212e50(const S_00099c98 &rec) : S_00099c98(rec)
    {
        p9c.a = 0;
        p9c.b = 0;
        b9e = 0;
        b9f = 0;
        ba0 = 0;
        FUN_000dbb60(this);
    }
    ~S_00212e50();
};

extern "C" void FUN_00212e50(S_00212e50 *self, int id, short a, short b, short c, short d, short e, char f, int g)
{
    S_00099c98 *rec = FUN_0019fc84(id);
    if (rec != 0) {
        *self = S_00212e50(*rec);
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
