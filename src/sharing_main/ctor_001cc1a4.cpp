/* HSTMATCH module=hstp_trans_main.prx start=0x001cc1a4 end=0x001cc47c symbol=__ct__10C_001cc1a4Fv lang=c++ */
/* Clone of src/eboot/ctor_001be450.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified. Constructor of a 59872-byte object whose members are built by compiler-generated do/while loops: tiny memset-wrapper classes (B1 1 byte, S2 2 bytes, V12 12 bytes, Rec 56 bytes = V12[4] + memset(this)), the 0x2000-byte block Y at +0x1378 (Z m + Z arr[50], body FUN_001ca5c8(this,0)), and the 0xb460-byte block W at +0x3480 (FUN_00239a2c); then the plain field stores, memset of the trailing 256 bytes and FUN_001ccd50(this,0). Names and types await human review. */
extern "C" {
void FUN_000114c0(void *, int, int);
void FUN_001ca530(void *, int);
void FUN_001ca5c8(void *, int);
void FUN_00239a2c(void *);
}

struct B1 {
  unsigned char v;
  B1() { FUN_000114c0(this, 0, 1); }
};

struct S2 {
  short v;
  S2() { FUN_000114c0(this, 0, 2); }
};

struct V12 {
  int a, b, c;
  V12() { FUN_000114c0(this, 0, 12); }
};

struct Rec {
  int h0, h1;
  V12 v[4];
  Rec() { FUN_000114c0(this, 0, 56); }
};

struct Z {
  char d[160];
  Z() { FUN_001ca530(this, 0); }
};

struct Y {
  char hdr[32];
  Z m;
  Z arr[50];
  Y() { FUN_001ca5c8(this, 0); }
};

struct W {
  char d[0xb460];
  W() { FUN_00239a2c(this); }
};

struct C_001cc1a4 {
  int f0;
  Rec recs[15];
  S2 shorts[640];
  B1 b0[640];
  B1 b1[640];
  B1 b2[640];
  B1 c0[21];
  B1 c1[8];
  B1 c2[10];
  B1 c3[10];
  B1 c4[15];
  B1 c5[10];
  B1 c6[10];
  char pad0[4148 - 4128];
  short s4148, s4150, s4152, s4154;
  unsigned char c4156;
  char pad1;
  short s4158, s4160, s4162, s4164, s4166, s4168;
  unsigned char c4170, c4171, c4172, c4173, c4174, c4175, c4176, c4177, c4178;
  char pad2;
  int f4180;
  char pad3[4984 - 4184];
  Y y;
  char pad4[13440 - 13176];
  W w;
  unsigned char buf[256];
  C_001cc1a4();
};

extern "C" void FUN_001ccd50(C_001cc1a4 *, int);

C_001cc1a4::C_001cc1a4()
{
  s4148 = 0;
  s4150 = 0;
  s4152 = 0;
  s4154 = 0;
  c4156 = 1;
  s4158 = 0;
  s4160 = 0;
  s4162 = 0;
  s4164 = 0;
  s4166 = 0;
  s4168 = 0;
  c4170 = 0;
  c4171 = 0;
  c4172 = 0;
  c4173 = 0;
  c4174 = 0;
  c4175 = 0;
  c4176 = 0;
  c4177 = 0;
  c4178 = 0;
  f4180 = 0;
  f0 = 0;
  FUN_000114c0(buf, 0, 256);
  FUN_001ccd50(this, 0);
}
