/* HSTMATCH module=hstp_trans_main.prx start=0x00097520 end=0x00097de4 symbol=__ct__10C_00097520Fiii lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Player constructor (Player.cpp, per its assert `s_pScene` at line 697): base ctor 0x1ec44, own vtable 0x3b0568, then
   members in declaration order - inline scalar initialisers, two identity matrices copied memberwise from
   the global identity (unscheduled lwc1/swc1 pairs), a sub-object at 0x1b0 whose members have out-of-line
   ctors (0x97e68..0x98094, here inline wrappers so member arrays get MWCC's own construction loop) and whose
   body clears 0x1c0..0x1c8, two memset blocks, long zero-init runs. The body creates the two 224-byte helper
   objects (0x934c8 / 0x5f898, `if (mem) mem = ctor(mem)` form), swaps the per-player global slot, sets up the
   face texture ("__InpaneFace%d") and finishes with 0x99658. The two-byte flag clear only stays a loop as a do/while (a for loop is
   unrolled). Sharing twin of EBOOT 0x9547c (src/eboot/player_ctor_0009547c.cpp): same source plus the
   `s_pScene` debug assert (print stub 0x97e3c + endless loop). Names provisional. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
};
struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
};

extern "C" {
void *FUN_0001d8c8(void *);
void *FUN_00098094(void *);
void *FUN_00098064(void *);
void *FUN_00098034(void *);
void *FUN_00098004(void *);
void *FUN_00097fd4(void *);
void *FUN_00097fa4(void *);
void *FUN_00097f74(void *);
void *FUN_00097f44(void *);
void *FUN_00097f14(void *);
void *FUN_00097edc(void *);
void *FUN_00097eac(void *);
void *FUN_00097e98(void *);
void *FUN_00097e68(void *);
void *FUN_000577ec(void *);
void *FUN_000518d4(void *);
void *FUN_000114c0(void *, int, unsigned);
}

struct M_1d8c8 { char d[0xc0]; M_1d8c8() { FUN_0001d8c8(this); } };
struct M_98094 { char d[4]; M_98094() { FUN_00098094(this); } };
struct M_98064 { char d[12]; M_98064() { FUN_00098064(this); } };
struct M_98034 { char d[0x30]; M_98034() { FUN_00098034(this); } };
struct M_98004 { char d[12]; M_98004() { FUN_00098004(this); } };
struct M_97fd4 { char d[12]; M_97fd4() { FUN_00097fd4(this); } };
struct M_97fa4 { char d[12]; M_97fa4() { FUN_00097fa4(this); } };
struct M_97f74 { char d[0x30]; M_97f74() { FUN_00097f74(this); } };
struct M_97f44 { char d[0x30]; M_97f44() { FUN_00097f44(this); } };
struct M_97f14 { char d[0x10]; M_97f14() { FUN_00097f14(this); } };
struct M_97edc { char d[0x40]; M_97edc() { FUN_00097edc(this); } };
struct M_97eac { char d[8]; M_97eac() { FUN_00097eac(this); } };
struct M_97e98 { char d[8]; M_97e98() { FUN_00097e98(this); } };
struct M_97e68 { char d[0x90]; M_97e68() { FUN_00097e68(this); } };
struct M_577ec { char d[0x1b0]; M_577ec() { FUN_000577ec(this); } };
struct M_518d4 { int d[0x48 / 4]; M_518d4() { FUN_000518d4(this); } };
struct Blk48 { char d[0x30]; Blk48() { FUN_000114c0(this, 0, sizeof(*this)); } };

struct Sub1b0 {
    int i00;
    char c04;
    char pad05[0x10 - 0x05];
    char c10, c11;
    short s12;
    int i14;
    int i18;
    M_98094 a1c[2];
    M_98064 m24;
    M_98034 m30;
    M_98004 a60[2];
    M_97fd4 m78;
    M_97fa4 m84;
    M_97f74 m90;
    M_97f44 mc0;
    M_97f14 mf0;
    M_97edc m100;
    M_97eac m140;
    M_97e98 m148;
    M_97e68 m150;
    Sub1b0() : i00(-1), c04(0)
    {
        c10 = 0;
        c11 = 0;
        s12 = 0;
        i14 = 0;
        i18 = 0;
    }
};

struct Deletable { virtual ~Deletable(); };
struct Model224 {
    virtual void v0();
    virtual void Init(int);
    char pad4[0xc0 - 4];
    bool cc0;
    float speed;
    char padc8[0xd0 - 0xc8];
    float speed2;
};
struct Game { char pad0[0x80]; int f80; int f84; };
struct Row26 { unsigned char b; char pad[0x11f]; };
struct Row88 { unsigned char b; char pad[0x11f]; };
struct RowC4 { int w; char pad[0x11c]; };

extern int DAT_003751d4;
extern Row88 DAT_003eabd0[];
extern Row26 DAT_003eab6e[];
extern RowC4 DAT_003eac0c[];
extern Mat4 DAT_002cc260;
extern Deletable *DAT_003f468c[];
extern Game *DAT_003e19f0;
extern int DAT_003e1aac;
extern void *DAT_003e1a54;     /* s_pScene */
/* "assertion \"%s\" failed: file \"%s\", line %d
", "s_pScene", "Player.cpp" */
extern char DAT_0037a6cc[], DAT_0037a6f8[], DAT_0037a704[];
extern "C" void FUN_00097e3c(...);   /* debug print stub */
extern char DAT_0037a710[];   /* "__InpaneFace%d" */

void *operator new(unsigned n);
extern "C" {
Deletable *FUN_000934c8(void *);
Model224 *FUN_0005f898(void *);
void FUN_000935b4(Deletable *, Deletable *);
void FUN_00094e8c(Deletable *);
void FUN_000942f4(Deletable *, int);
void FUN_0005fb08(Model224 *, int, int);
void FUN_0005fe20(Model224 *, float, int);
int FUN_0004eaf8(int *, int *, int, int, int, int);
void FUN_000143b0(char *, const char *, ...);
void FUN_00051b88(M_518d4 *, const char *, int, int, int);
}

struct B_0001ec44 {
    B_0001ec44();
    virtual void v0();
    char pad4[0x3c - 4];
};

struct C_00097520 : B_0001ec44 {
    int m3c;
    int m40;
    int m44;
    char pad48[0x80 - 0x48];
    M_1d8c8 m80;
    int m140;
    int m144;
    int idx;
    bool m14c;
    int m150;
    int m154;
    int m158, m15c, m160, m164;
    int m168, m16c;
    Mat4 m170;
    Sub1b0 sub;
    int m390;
    char pad394[0x3a0 - 0x394];
    Blk48 a3a0[2];
    char m400;
    int m404;
    char m408, m409;
    int m40c;
    char m410, m411;
    int m414;
    char m418, m419;
    int m41c, m420, m424, m428;
    char pad42c[0x438 - 0x42c];
    int m438, m43c, m440, m444, m448, m44c, m450, m454, m458, m45c;
    char m460, m461, m462, m463;
    char pad464[0x470 - 0x464];
    int m470, m474, m478, m47c;
    char m480;
    int m484, m488, m48c, m490, m494, m498;
    char pad49c[0x4b0 - 0x49c];
    int m4b0, m4b4, m4b8, m4bc, m4c0;
    char pad4c4[0x4cc - 0x4c4];
    char m4cc, m4cd, m4ce, m4cf, m4d0, m4d1;
    int m4d4;
    char m4d8, m4d9, m4da;
    int m4dc;
    char m4e0;
    int m4e4, m4e8, m4ec, m4f0;
    char m4f4;
    int m4f8;
    char m4fc, m4fd, m4fe;
    int m500;
    int m504;
    char m508;
    char pad509[0x510 - 0x509];
    Mat4 m510;
    Mat4 m550;
    Vec4 m590;
    Vec4 m5a0;
    char m5b0[2];
    int m5b4;
    char m5b8;
    signed char m5b9;
    Deletable *m5bc;
    int m5c0, m5c4, m5c8;
    char pad5cc[0x5d0 - 0x5cc];
    M_577ec m5d0;
    Model224 *m780;
    char m784;
    M_518d4 m788;
    int m7d0, m7d4, m7d8, m7dc, m7e0, m7e4, m7e8, m7ec, m7f0, m7f4, m7f8;
    char m7fc;
    int m800;
    char m804, m805;
    int m808, m80c, m810, m814, m818, m81c, m820, m824;
    int m828;
    char pad82c[0x844 - 0x82c];
    int m844, m848, m84c, m850, m854, m858, m85c, m860, m864;
    char m868, m869, m86a, m86b, m86c;
    int m870;
    char pad874[0x880 - 0x874];
    int m880, m884, m888, m88c, m890, m894, m898, m89c;
    char m8a0, m8a1, m8a2, m8a3, m8a4, m8a5;
    char pad8a6[0x8c0 - 0x8a6];
    char m8c0;
    int m8c4, m8c8, m8cc, m8d0, m8d4;
    char m8d8;
    int m8dc, m8e0;
    char pad8e4[0x8f0 - 0x8e4];
    int m8f0, m8f4, m8f8, m8fc;

    C_00097520(int a, int i, int b);
    virtual void v1();
};

extern "C" void FUN_00099658(C_00097520 *, int, int);

C_00097520::C_00097520(int a, int i, int b)
    : m3c(9), m40(0), m44(-1), m140(DAT_003751d4), m144(a), idx(i), m14c(DAT_003eabd0[i].b != 0), m150(0),
      m154(b), m158(0), m15c(0), m160(0), m164(0), m168(1), m16c(1), m170(DAT_002cc260), m390(0),
      m400(0), m404(0), m408(0), m409(0), m40c(0), m410(0), m411(0), m414(-1), m418(0), m419(0),
      m41c(0), m420(0), m424(0), m428(0),
      m438(0), m43c(0), m440(0), m444(0), m448(0), m44c(0), m450(0), m454(0), m458(0), m45c(0),
      m460(0), m461(0), m462(0), m463(0), m470(0), m474(0), m478(0), m47c(0), m480(0),
      m484(0), m488(0), m48c(0), m490(0), m494(0), m498(0), m4b0(0), m4b4(0), m4b8(0), m4bc(0), m4c0(0),
      m4cc(0), m4cd(0), m4ce(0), m4cf(1), m4d0(0), m4d1(0), m4d4(0), m4d8(0), m4d9(0), m4da(0), m4dc(-1),
      m4e0(0), m4e4(0), m4e8(0), m4ec(0), m4f0(0), m4f4(0), m4f8(208), m4fc(0), m4fd(0), m4fe(0),
      m500(0), m504(-1), m508(0), m510(DAT_002cc260), m550(DAT_002cc260), m590(0.0f, 0.0f, 0.0f, 0.0f),
      m5a0(1.0f, 1.0f, 1.0f, 1.0f), m5b4(208), m5b8(0), m5b9(-1), m5bc(0), m5c0(0), m5c4(0), m5c8(0),
      m780(0), m784(0),
      m7d0(0), m7d4(0), m7d8(0), m7dc(0), m7e0(0), m7e4(0), m7e8(0), m7ec(0), m7f0(0), m7f4(0), m7f8(0),
      m7fc(0), m800(-1), m804(0), m805(0), m808(0), m80c(0), m810(0), m814(0), m818(0), m81c(0), m820(0),
      m824(0), m828(-1), m844(0), m848(0), m84c(0), m850(0), m854(0), m858(0), m85c(0), m860(0), m864(0),
      m868(0), m869(0), m86a(0), m86b(0), m86c(0), m870(0),
      m880(0), m884(0), m888(0), m88c(0), m890(0), m894(0), m898(0), m89c(0),
      m8a0(0), m8a1(0), m8a2(0), m8a3(0), m8a4(0), m8a5(0), m8c0(0), m8c4(0), m8c8(0), m8cc(0), m8d0(0),
      m8d4(0), m8d8(1), m8dc(3), m8e0(3), m8f0(0), m8f4(0), m8f8(0), m8fc(0)
{
    Deletable *mem = (Deletable *)operator new(224);
    if (mem)
        mem = FUN_000934c8(mem);
    m5bc = mem;
    if (DAT_003f468c[idx] != 0) {
        FUN_000935b4(m5bc, DAT_003f468c[idx]);
        Deletable *&slot = DAT_003f468c[i];
        if (slot) {
            delete slot;
            slot = 0;
        }
        slot = m5bc;
    }
    FUN_00094e8c(m5bc);
    FUN_000942f4(m5bc, 1);
    Model224 *mdl = (Model224 *)operator new(224);
    if (mdl)
        mdl = FUN_0005f898(mdl);
    m780 = mdl;
    m780->Init(DAT_003e19f0->f80);
    FUN_0005fb08(m780, 0, DAT_003e19f0->f84);
    FUN_0005fe20(m780, 0.0f, 0);
    m780->cc0 = true;
    m780->speed2 = m780->speed;
    if (!DAT_003e1a54) {
        FUN_00097e3c(DAT_0037a6cc, DAT_0037a6f8, DAT_0037a704, 697);
        for (;;) {
        }
    }
    DAT_003e1aac = 0;
    m150 = DAT_003eab6e[idx].b != 1;
    m16c = DAT_003eac0c[idx].w;
    m168 = DAT_003eac0c[idx].w;
    unsigned k = 0;
    do {
        m5b0[k] = 0;
    } while (++k < 2);
    m480 = 0;
    int w = 0, h = 0;
    int tex = FUN_0004eaf8(&w, &h, 1, 0, 64, 64);
    char name[64];
    FUN_000143b0(name, DAT_0037a710, idx);
    FUN_00051b88(&m788, name, tex, 0, 16);
    FUN_00099658(this, m154, m150);
}
