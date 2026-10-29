/* HSTMATCH module=EBOOT.BIN start=0x001be450 end=0x001be728 symbol=__ct__10C_001be450Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified. Constructor of a 59872-byte object whose members are built by compiler-generated do/while loops: tiny memset-wrapper classes (ZeroByte 1 byte, ZeroShort 2 bytes, ZeroWords3 12 bytes, ZeroRec 56 bytes = ZeroWords3[4] + memset(this)), the 0x2000-byte block at +0x1378 (BlockY: SubInit first + SubInit rest[50], body FUN_001bc7e0(this,0)), and the 0xb460-byte block at +0x3480 (BlockW, FUN_0022a4b8); then the plain field stores, memset of the trailing 256 bytes and FUN_001beffc(this,0). Names and types await human review. */
extern "C" {
void FUN_000114c0(void *, int, int);
void FUN_001bc748(void *, int);
void FUN_001bc7e0(void *, int);
void FUN_0022a4b8(void *);
}

struct ZeroByte {
  unsigned char v;
  ZeroByte() { FUN_000114c0(this, 0, 1); }
};

struct ZeroShort {
  short v;
  ZeroShort() { FUN_000114c0(this, 0, 2); }
};

struct ZeroWords3 {
  int a, b, c;
  ZeroWords3() { FUN_000114c0(this, 0, 12); }
};

struct ZeroRec {
  int h0, h1;
  ZeroWords3 v[4];
  ZeroRec() { FUN_000114c0(this, 0, 56); }
};

struct SubInit {
  char d[160];
  SubInit() { FUN_001bc748(this, 0); }
};

struct BlockY {
  char hdr[32];
  SubInit first;
  SubInit rest[50];
  BlockY() { FUN_001bc7e0(this, 0); }
};

struct BlockW {
  char d[0xb460];
  BlockW() { FUN_0022a4b8(this); }
};

struct C_001be450 {
  int unk000;
  ZeroRec subs[15];
  ZeroShort pairs[640];
  ZeroByte marks1[640];
  ZeroByte marks2[640];
  ZeroByte marks3[640];
  ZeroByte flag_a[21];
  ZeroByte flag_b[8];
  ZeroByte zero_c2[10];
  ZeroByte zero_c3[10];
  ZeroByte zero_c4[15];
  ZeroByte zero_c5[10];
  ZeroByte zero_c6[10];
  char pad1020[0x1034 - 0x1020];
  short unk1034, unk1036, unk1038, unk103a;
  unsigned char unk103c;
  char pad103d;
  short unk103e, unk1040, unk1042, unk1044, unk1046, unk1048;
  unsigned char unk104a, unk104b, unk104c, unk104d, unk104e, unk104f, unk1050, unk1051, unk1052;
  char pad1053;
  int unk1054;
  char pad1058[0x1378 - 0x1058];
  BlockY block;
  char pad3378[0x3480 - 0x3378];
  BlockW tail_block;
  unsigned char tail[256];
  C_001be450();
};

extern "C" void FUN_001beffc(C_001be450 *, int);

C_001be450::C_001be450()
{
  unk1034 = 0;
  unk1036 = 0;
  unk1038 = 0;
  unk103a = 0;
  unk103c = 1;
  unk103e = 0;
  unk1040 = 0;
  unk1042 = 0;
  unk1044 = 0;
  unk1046 = 0;
  unk1048 = 0;
  unk104a = 0;
  unk104b = 0;
  unk104c = 0;
  unk104d = 0;
  unk104e = 0;
  unk104f = 0;
  unk1050 = 0;
  unk1051 = 0;
  unk1052 = 0;
  unk1054 = 0;
  unk000 = 0;
  FUN_000114c0(tail, 0, 256);
  FUN_001beffc(this, 0);
}
