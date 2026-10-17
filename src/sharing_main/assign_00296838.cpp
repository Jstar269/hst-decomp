/* HSTMATCH module=hstp_trans_main.prx start=0x00296838 end=0x0029693c symbol=FUN_00296838 lang=c++ */
/* Clone of src/eboot/assign_00285230.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
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

struct Pair_00296838 {
  unsigned char a, b;
};

struct V4 { float x, y, z, w; };

struct S_00296838 : public S_00099c98 {
  Pair_00296838 p9c;
  unsigned char b9e, b9f;
  char ba0;
  V4 va4;
  float fb4;
  int ib8;
  short arr_bc[6];
  unsigned char bc8;
  char arr_c9[32];
  float fec;
  unsigned char bf0, bf1;
  S_00296838();
};

extern "C" S_00296838 *FUN_00296838(S_00296838 *a, const S_00296838 *b)
{
  *a = *b;
  return a;
}
