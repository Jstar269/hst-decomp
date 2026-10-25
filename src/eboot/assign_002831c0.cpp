/* HSTMATCH module=EBOOT.BIN start=0x002831c0 end=0x00283358 symbol=FUN_002831c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Implicit copy assignment of a class derived from S_00097b2c (whose operator= is FUN_00097b2c), same pattern as assign_00285230.cpp. */
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

struct Pair_002831c0 {
  unsigned char a, b;
};

struct V4 { float x, y, z, w; };
struct F2 { float a, b; };

struct S_002831c0 : public S_00097b2c {
  Pair_002831c0 p9c;
  unsigned char b9e, b9f;
  char ba0;
  V4 va4;
  float fb4;
  int ib8;
  short arr_bc[6];
  unsigned char bc8, bc9, bca, bcb;
  char arr_cc[32];
  unsigned char bec, bed, bee, bef, bf0;
  int if4, if8;
  float ffc;
  unsigned char b100, b101;
  int i104;
  char arr_108[16];
  F2 f118;
  S_002831c0();
};

extern "C" S_002831c0 *FUN_002831c0(S_002831c0 *a, const S_002831c0 *b)
{
  *a = *b;
  return a;
}
