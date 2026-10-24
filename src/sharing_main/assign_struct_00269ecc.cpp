/* HSTMATCH module=hstp_trans_main.prx start=0x00269ecc end=0x0026a188 symbol=FUN_00269ecc lang=c++ */
/* Clone of src/eboot/assign_struct_00259a1c.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
};

struct Pair {
    unsigned char f01[2];
};

struct Flags {
    Pair p;
    unsigned char f2;
    unsigned char f3;
    signed char f4;
    Flags &operator=(const Flags &o) {
        p = o.p;
        f2 = o.f2;
        f3 = o.f3;
        f4 = o.f4;
        return *this;
    }
} __attribute__((aligned(4)));

struct SubA {
    short arr[6];           /* 0x00 */
    unsigned char f0c;      /* 0x0c */
    unsigned char f0d;      /* 0x0d */
    unsigned char f0e;      /* 0x0e */
    char str1[16];          /* 0x0f */
    unsigned short f20;     /* 0x20 */
    unsigned short f22;     /* 0x22 */
    unsigned char f24;      /* 0x24 */
    char str2[6];           /* 0x25 */
    unsigned char f2b;      /* 0x2b */
    unsigned char f2c;      /* 0x2c */
    char str3[16];          /* 0x2d */
    short f3e;              /* 0x3e */
    short f40;              /* 0x40 */
    unsigned char f42;      /* 0x42 */
    unsigned char f43;      /* 0x43 */
    float f44;              /* 0x44 */
    float f48;              /* 0x48 */
    float f4c;              /* 0x4c */
    short f50;              /* 0x50 */
    short f52;              /* 0x52 */
    char str4[16];          /* 0x54 */
    unsigned char f64;      /* 0x64 */
    unsigned char f65;      /* 0x65 */
    unsigned char f66;      /* 0x66 */
    unsigned char f67;      /* 0x67 */
    char str5[16];          /* 0x68 */
    short f78;              /* 0x78 */
    short f7a;              /* 0x7a */
    unsigned char f7c;      /* 0x7c */
    char str6[12];          /* 0x7d */
    short f8a[3];           /* 0x8a */
    short arr2[5];          /* 0x90 */
    Flags flags;            /* 0x9c */
    Vec4 fa4;               /* 0xa4 */
    float fb4;              /* 0xb4 */
    int fb8;                /* 0xb8 */
    short arr3[6];          /* 0xbc */
};

extern "C" SubA *FUN_00269ecc(SubA *self, const SubA *other)
{
    *self = *other;
    return self;
}
