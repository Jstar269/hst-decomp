/* HSTMATCH module=hstp_trans_main.prx start=0x002946e0 end=0x00294878 symbol=FUN_002946e0 lang=c++ */
/* Clone of src/eboot/assign_002831c0.cpp (hstclone.py tag nxc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Implicit copy assignment of a class derived from S_00099c98 (whose operator= is FUN_00099c98), same pattern as assign_00285230.cpp. */
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

struct Pair_002946e0 {
  unsigned char a, b;
};

struct V4 { float x, y, z, w; };
struct F2 { float a, b; };

struct S_002946e0 : public S_00099c98 {
  Pair_002946e0 p9c;
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
  S_002946e0();
};

extern "C" S_002946e0 *FUN_002946e0(S_002946e0 *a, const S_002946e0 *b)
{
  *a = *b;
  return a;
}
