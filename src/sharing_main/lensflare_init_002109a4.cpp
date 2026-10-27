/* HSTMATCH module=hstp_trans_main.prx start=0x002109a4 end=0x00210e9c symbol=FUN_002109a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* lensflare.cpp (assert strings of FUN_00211238 "m_nCount < MAX_FLARE" and FUN_00211324 "nAngle <= MAX_STREAK"):
   initialises the flare object: streak count 20, colours, a 41-entry cos/sin table over 2*pi/40 steps
   (double division through the soft-float helpers), the twelve flare keys when the flag is set, then the
   two 0x48-byte sprite objects ("data/menu/game_eff/flare/flare3" and a plain one). Colours are a
   4-byte RGBA class with a constructor: the word stores read the temporary back through Word(), and the
   flare keys pass a temporary by const reference (one stack slot per call, as retail). */
struct Color {
    unsigned char r, g, b, a;
    Color(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
    unsigned Word() const { return *(const unsigned *)this; }
};

struct LensFlare {
    char pad0[0x14];
    int m_nCount;
    char pad18[0xdc - 0x18];
    float fdc;
    float fe0;
    int fe4;
    unsigned fe8;
    unsigned fec;
    char padf0[0xf4 - 0xf0];
    float ff4;
    int ff8;
    char padfc[0x37c - 0xfc];
    float f37c;
    char pad380[0x390 - 0x380];
    int f390;
    float f394[(0x438 - 0x394) / 4];
    float f438[(0x4dc - 0x438) / 4];
    float f4dc;
    float f4e0;
    char pad4e4[0x520 - 0x4e4];
    void *f520;
    void *f524;
};

extern "C" {
extern char DAT_00397238[];
void FUN_00211324(LensFlare *, int);
float FUN_0000bc4c(float);
float FUN_0000bf4c(float);
void FUN_00211020(LensFlare *, int);
void FUN_00210f28(float, float, LensFlare *);
int FUN_00211238(LensFlare *, float, int, int, const Color &);
void *FUN_00000bcc(unsigned);
void *FUN_00051908(void *, char *, int);
void *FUN_000518d4(void *);
void FUN_00051d38(void *, float);
void FUN_00051d40(void *, int);
void FUN_00051d9c(void *, int);
}

extern "C" LensFlare *FUN_002109a4(LensFlare *self, int flag)
{
    float a;
    float step;
    int i;
    void *p;

    self->m_nCount = 0;
    self->ff8 = -1;
    FUN_00211324(self, 20);
    self->f37c = 10.0f;
    self->fe0 = 32768.0f;
    self->fdc = 8192.0f;
    self->ff4 = FUN_0000bc4c(1.5707964f);
    self->fe8 = Color(0xf0, 0xe0, 0xd0, 0x80).Word();
    self->fec = Color(0xc0, 0x80, 0x00, 0x80).Word();
    self->fe4 = 24;
    FUN_00211020(self, 1);
    self->f4dc = 150.0f;
    self->f4e0 = 500.0f;
    self->f390 = 40;
    a = 0.0f;
    step = 6.283185307179586 / self->f390;
    for (i = 0; i < self->f390 + 1; i++) {
        self->f438[i] = FUN_0000bc4c(a);
        self->f394[i] = FUN_0000bf4c(a);
        a += step;
    }
    FUN_00210f28(0.7853982f, 0.0f, self);
    if (flag) {
        FUN_00211238(self, 0.0f, 6, 0, Color(0x80, 0x80, 0x80, 0x80));
        FUN_00211238(self, 0.55f, 1, 24, Color(0x24, 0x24, 0x20, 0x80));
        FUN_00211238(self, 0.7f, 2, 72, Color(0x10, 0x10, 0x13, 0x80));
        FUN_00211238(self, 0.8f, 1, 36, Color(0x10, 0x10, 0x13, 0x80));
        FUN_00211238(self, 0.9f, 2, 24, Color(0x24, 0x20, 0x20, 0x80));
        FUN_00211238(self, 0.95f, 0, 12, Color(0x20, 0x24, 0x20, 0x80));
        FUN_00211238(self, 1.05f, 0, 12, Color(0x20, 0x24, 0x20, 0x80));
        FUN_00211238(self, 1.07f, 3, 200, Color(0x0c, 0x0a, 0x0a, 0x80));
        FUN_00211238(self, 1.1f, 1, 36, Color(0x14, 0x10, 0x10, 0x80));
        FUN_00211238(self, 1.14f, 2, 114, Color(0x14, 0x10, 0x10, 0x80));
        FUN_00211238(self, 1.16f, 1, 24, Color(0x14, 0x10, 0x10, 0x80));
        FUN_00211238(self, 1.18f, 2, 48, Color(0x10, 0x14, 0x10, 0x80));
    }
    p = FUN_00000bcc(0x48);
    if (p) p = FUN_00051908(p, DAT_00397238, 0);
    self->f520 = p;
    FUN_00051d38(self->f520, 3000.0f);
    FUN_00051d40(self->f520, 1);
    FUN_00051d9c(self->f520, 1);
    p = FUN_00000bcc(0x48);
    if (p) p = FUN_000518d4(p);
    self->f524 = p;
    FUN_00051d40(self->f524, 1);
    FUN_00051d9c(self->f524, 1);
    return self;
}
