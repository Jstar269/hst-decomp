/* HSTMATCH module=EBOOT.BIN start=0x0009547c end=0x00095d0c symbol=__ct__10C_0009547cFiii lang=c++ data=0x002d4368 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d4368-0x002d4377) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Player constructor (Player.cpp per the Sharing twin's assert): base ctor 0x1f06c, own vtable 0x30729c, then
   members in declaration order - inline scalar initialisers, two identity matrices copied memberwise from
   the global identity (unscheduled lwc1/swc1 pairs), a sub-object at 0x1b0 whose members have out-of-line
   ctors (0x95d64..0x95f90, here inline wrappers so member arrays get MWCC's own construction loop) and whose
   body clears 0x1c0..0x1c8, two memset blocks, long zero-init runs. The body creates the two 224-byte helper
   objects (0x91830 / 0x5eaa8, `if (mem) mem = ctor(mem)` form), swaps the per-player global slot, sets up the
   face texture ("__InpaneFace%d") and finishes with 0x97520. The two-byte flag clear only stays a loop as a
   do/while (a for loop is unrolled). Names provisional. */
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
void *FUN_0001dc7c(void *);
void *FUN_00095f90(void *);
void *FUN_00095f60(void *);
void *FUN_00095f30(void *);
void *FUN_00095f00(void *);
void *FUN_00095ed0(void *);
void *FUN_00095ea0(void *);
void *FUN_00095e70(void *);
void *FUN_00095e40(void *);
void *FUN_00095e10(void *);
void *FUN_00095dd8(void *);
void *FUN_00095da8(void *);
void *FUN_00095d94(void *);
void *FUN_00095d64(void *);
void *FUN_00056b98(void *);
void *FUN_00050fc0(void *);
void *FUN_000114c0(void *, int, unsigned);
}

struct M_1dc7c { char d[0xc0]; M_1dc7c() { FUN_0001dc7c(this); } };
struct M_95f90 { char d[4]; M_95f90() { FUN_00095f90(this); } };
struct M_95f60 { char d[12]; M_95f60() { FUN_00095f60(this); } };
struct M_95f30 { char d[0x30]; M_95f30() { FUN_00095f30(this); } };
struct M_95f00 { char d[12]; M_95f00() { FUN_00095f00(this); } };
struct M_95ed0 { char d[12]; M_95ed0() { FUN_00095ed0(this); } };
struct M_95ea0 { char d[12]; M_95ea0() { FUN_00095ea0(this); } };
struct M_95e70 { char d[0x30]; M_95e70() { FUN_00095e70(this); } };
struct M_95e40 { char d[0x30]; M_95e40() { FUN_00095e40(this); } };
struct M_95e10 { char d[0x10]; M_95e10() { FUN_00095e10(this); } };
struct M_95dd8 { char d[0x40]; M_95dd8() { FUN_00095dd8(this); } };
struct M_95da8 { char d[8]; M_95da8() { FUN_00095da8(this); } };
struct M_95d94 { char d[8]; M_95d94() { FUN_00095d94(this); } };
struct M_95d64 { char d[0x90]; M_95d64() { FUN_00095d64(this); } };
struct M_56b98 { char d[0x1b0]; M_56b98() { FUN_00056b98(this); } };
struct M_50fc0 { int d[0x48 / 4]; M_50fc0() { FUN_00050fc0(this); } };
struct Blk48 { char d[0x30]; Blk48() { FUN_000114c0(this, 0, sizeof(*this)); } };

struct Sub1b0 {
    int i00;
    char c04;
    char pad05[0x10 - 0x05];
    char c10, c11;
    short s12;
    int i14;
    int i18;
    M_95f90 a1c[2];
    M_95f60 m24;
    M_95f30 m30;
    M_95f00 a60[2];
    M_95ed0 m78;
    M_95ea0 m84;
    M_95e70 m90;
    M_95e40 mc0;
    M_95e10 mf0;
    M_95dd8 m100;
    M_95da8 m140;
    M_95d94 m148;
    M_95d64 m150;
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

extern int DAT_002cfc8c;
extern Row88 DAT_00341898[];
extern Row26 DAT_00341836[];
extern RowC4 DAT_003418d4[];
extern Mat4 DAT_002bc410;
extern Deletable *DAT_0034b340[];
extern Game *DAT_003386b0;
extern int DAT_0033876c;

void *operator new(unsigned n);
extern "C" {
Deletable *FUN_00091830(void *);
Model224 *FUN_0005eaa8(void *);
void FUN_0009191c(Deletable *, Deletable *);
void FUN_00092ff8(Deletable *);
void FUN_0009265c(Deletable *, int);
void FUN_0005ed18(Model224 *, int, int);
void FUN_0005f030(Model224 *, float, int);
int FUN_0004e780(int *, int *, int, int, int, int);
void FUN_000143b0(char *, const char *, ...);
void FUN_00051274(M_50fc0 *, const char *, int, int, int);
}

struct B_0001f06c {
    B_0001f06c();
    virtual void v0();
    char pad4[0x3c - 4];
};

struct C_0009547c : B_0001f06c {
    int m3c;
    int m40;
    int m44;
    char pad48[0x80 - 0x48];
    M_1dc7c m80;
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
    M_56b98 m5d0;
    Model224 *m780;
    char m784;
    M_50fc0 m788;
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

    C_0009547c(int a, int i, int b);
    virtual void v1();
};

extern "C" void FUN_00097520(C_0009547c *, int, int);

C_0009547c::C_0009547c(int a, int i, int b)
    : m3c(9), m40(0), m44(-1), m140(DAT_002cfc8c), m144(a), idx(i), m14c(DAT_00341898[i].b != 0), m150(0),
      m154(b), m158(0), m15c(0), m160(0), m164(0), m168(1), m16c(1), m170(DAT_002bc410), m390(0),
      m400(0), m404(0), m408(0), m409(0), m40c(0), m410(0), m411(0), m414(-1), m418(0), m419(0),
      m41c(0), m420(0), m424(0), m428(0),
      m438(0), m43c(0), m440(0), m444(0), m448(0), m44c(0), m450(0), m454(0), m458(0), m45c(0),
      m460(0), m461(0), m462(0), m463(0), m470(0), m474(0), m478(0), m47c(0), m480(0),
      m484(0), m488(0), m48c(0), m490(0), m494(0), m498(0), m4b0(0), m4b4(0), m4b8(0), m4bc(0), m4c0(0),
      m4cc(0), m4cd(0), m4ce(0), m4cf(1), m4d0(0), m4d1(0), m4d4(0), m4d8(0), m4d9(0), m4da(0), m4dc(-1),
      m4e0(0), m4e4(0), m4e8(0), m4ec(0), m4f0(0), m4f4(0), m4f8(208), m4fc(0), m4fd(0), m4fe(0),
      m500(0), m504(-1), m508(0), m510(DAT_002bc410), m550(DAT_002bc410), m590(0.0f, 0.0f, 0.0f, 0.0f),
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
        mem = FUN_00091830(mem);
    m5bc = mem;
    if (DAT_0034b340[idx] != 0) {
        FUN_0009191c(m5bc, DAT_0034b340[idx]);
        Deletable *&slot = DAT_0034b340[i];
        if (slot) {
            delete slot;
            slot = 0;
        }
        slot = m5bc;
    }
    FUN_00092ff8(m5bc);
    FUN_0009265c(m5bc, 1);
    Model224 *mdl = (Model224 *)operator new(224);
    if (mdl)
        mdl = FUN_0005eaa8(mdl);
    m780 = mdl;
    m780->Init(DAT_003386b0->f80);
    FUN_0005ed18(m780, 0, DAT_003386b0->f84);
    FUN_0005f030(m780, 0.0f, 0);
    m780->cc0 = true;
    m780->speed2 = m780->speed;
    DAT_0033876c = 0;
    m150 = DAT_00341836[idx].b != 1;
    m16c = DAT_003418d4[idx].w;
    m168 = DAT_003418d4[idx].w;
    unsigned k = 0;
    do {
        m5b0[k] = 0;
    } while (++k < 2);
    m480 = 0;
    int w = 0, h = 0;
    int tex = FUN_0004e780(&w, &h, 1, 0, 64, 64);
    char name[64];
    FUN_000143b0(name, "__InpaneFace%d", idx);
    FUN_00051274(&m788, name, tex, 0, 16);
    FUN_00097520(this, m154, m150);
}
