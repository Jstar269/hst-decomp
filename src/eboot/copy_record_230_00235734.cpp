/* HSTMATCH module=EBOOT.BIN start=0x00235734 end=0x00235b50 symbol=FUN_00235734 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00235734.c (tag: a1, hand-written C++ reconstruction) */
struct Vec4 {
    float x, y, z, w;
};

struct Sub24 {
    int a[6];
    Sub24();
    Sub24 &operator=(const Sub24 &);
};

extern "C" Sub24 *FUN_00235b50(Sub24 *, const Sub24 *);

inline Sub24 &Sub24::operator=(const Sub24 &o) {
    return *FUN_00235b50(this, &o);
}

struct Pair8 {
    int a, b;
};

struct Byte3 {
    unsigned char a, b, c;
};

struct Record235734 {
    int f0;                  // 0x00
    signed char f4[16];      // 0x04..0x14
    float f14;               // 0x14
    float f18;               // 0x18
    Vec4 f1c;                // 0x1c..0x2c
    Vec4 f2c;                // 0x2c..0x3c
    Vec4 f3c;                // 0x3c..0x4c
    short f4c;               // 0x4c
    short f4e;               // 0x4e
    float f50;               // 0x50
    int f54;                 // 0x54
    float f58;               // 0x58
    float f5c;               // 0x5c
    short f60[9];            // 0x60..0x72 (pad at 0x72..0x74)
    float f74;               // 0x74
    float f78;               // 0x78
    float f7c;               // 0x7c
    float f80;               // 0x80
    float f84;               // 0x84
    int f88;                 // 0x88
    float f8c;               // 0x8c
    float f90;               // 0x90
    int f94;                 // 0x94
    float f98;               // 0x98
    float f9c;               // 0x9c
    float fa0;               // 0xa0
    float fa4;               // 0xa4
    short fa8;               // 0xa8
    short faa;               // 0xaa
    short fac;               // 0xac
    short fae;               // 0xae
    float fb0;               // 0xb0
    float fb4;               // 0xb4
    float fb8;               // 0xb8
    signed char fbc;         // 0xbc
    signed char fbd;         // 0xbd
    signed char fbe;         // 0xbe
    signed char fbf;         // 0xbf
    signed char fc0;         // 0xc0
    signed char fc1;         // 0xc1
    signed char fc2;         // 0xc2
    signed char fc3;         // 0xc3
    Sub24 fc4;               // 0xc4..0xdc
    Sub24 fdc;               // 0xdc..0xf4
    Sub24 ff4;               // 0xf4..0x10c
    signed char f10c[15];    // 0x10c..0x11b (pad at 0x11b)
    float f11c;              // 0x11c
    float f120;              // 0x120
    float f124;              // 0x124
    float f128;              // 0x128
    Vec4 f12c;               // 0x12c..0x13c
    float f13c;              // 0x13c
    float f140;              // 0x140
    float f144;              // 0x144
    float f148;              // 0x148
    float f14c;              // 0x14c
    float f150;              // 0x150
    float f154;              // 0x154
    signed char f158;        // 0x158
    signed char f159;        // 0x159 (pad at 0x15a..0x15c)
    float f15c;              // 0x15c
    int f160[24];            // 0x160..0x1c0 (24*4 = 96 = 0x60!)
    float f1c0;              // 0x1c0
    float f1c4;              // 0x1c4
    float f1c8;              // 0x1c8
    float f1cc;              // 0x1cc
    float f1d0;              // 0x1d0
    float f1d4;              // 0x1d4
    float f1d8;              // 0x1d8
    float f1dc;              // 0x1dc
    float f1e0;              // 0x1e0
    float f1e4;              // 0x1e4
    signed char f1e8;        // 0x1e8 (pad 0x1e9..0x1ec)
    float f1ec;              // 0x1ec
    float f1f0;              // 0x1f0
    float f1f4;              // 0x1f4
    float f1f8;              // 0x1f8
    float f1fc;              // 0x1fc
    float f200;              // 0x200
    float f204;              // 0x204
    float f208;              // 0x208
    float f20c;              // 0x20c
    float f210;              // 0x210
    float f214;              // 0x214
    float f218;              // 0x218
    float f21c;              // 0x21c
    float f220;              // 0x220
    Byte3 f224;              // 0x224..0x227
    Byte3 f227;              // 0x227..0x22a
    Byte3 f22a;              // 0x22a..0x22d
};

extern "C" void FUN_00235734(int param_1, Record235734 *dst, const Record235734 *src)
{
    if (dst != 0) {
        *dst = *src;
    }
}
