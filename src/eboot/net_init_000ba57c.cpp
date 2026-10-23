/* HSTMATCH module=EBOOT.BIN start=0x000ba57c end=0x000ba78c symbol=FUN_000ba57c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The eight-word config copy is written field by field: a struct assignment of the same 32 bytes makes MWCC
   copy through $f0..$f3 with lwc1/swc1 instead of lw/sw (see docs/MWCC-NOTES.md). */
extern "C" char s_sceNetInit___failed_0x_X__002d4d64[];
extern "C" char s_sceNetInit___success_002d4d80[];
extern "C" char s_sceNetAdhocInit___failed_0x_X__002d4d98[];
extern "C" char s_sceNetAdhocInit___success_002d4db8[];
extern "C" char s_sceNetAdhocctlInit___failed_0x_X_002d4dd4[];
extern "C" char s_sceNetAdhocctlInit___success_002d4df8[];
extern "C" char s_sceNetAdhocctlAddHandler___faile_002d4e18[];
extern "C" char s_sceNetAdhocctlAddHandler___succe_002d4e44[];

extern "C" void FUN_000ba9e0(void *, void *);
extern "C" int FUN_000ba3ac(char *, ...);
extern "C" int FUN_002b7d98(int, int, int, int, int);
extern "C" int FUN_002b7e60(void);
extern "C" int FUN_002b7d80(int, int, int);
extern "C" int FUN_002b7d60(void *, int);
extern "C" void *FUN_00000a90(int);
extern "C" void FUN_000baa34(void *, int);
extern "C" void FUN_000bc108(void);

extern int DAT_00338ac8;
extern int DAT_002d4ab0;

struct Config {
  int f00;
  int f04;
  int f08;
  int f0c;
  int f10;
  int f14;
  int f18;
  int f1c;
};

struct Net {
  char pad0[4];
  Config config;
  int f24;
  char pad1[0x168 - 0x28];
  unsigned char f168;
  char pad2[0x180 - 0x169];
  void *f180;
  void *f184;
  void *f188;
  int f18c;
  int f190;
  int f194;
  char pad2b[0x1dc - 0x198];
  int f1dc[0x10];
  unsigned char f21c[0x10];
  int *f22c[0x10];
  char pad3[0x274 - 0x26c];
  int f274;
  unsigned char f278;
  char pad4[0x284 - 0x279];
  int f284;
};

extern "C" int FUN_000ba57c(Net *self, Config *cfg)
{
  int ret;
  int i;

  if (cfg != 0) {
    self->config.f00 = cfg->f00;
    self->config.f04 = cfg->f04;
    self->config.f08 = cfg->f08;
    self->config.f0c = cfg->f0c;
    self->config.f10 = cfg->f10;
    self->config.f14 = cfg->f14;
    self->config.f18 = cfg->f18;
    self->config.f1c = cfg->f1c;
  } else {
    FUN_000ba9e0(self, &self->config);
  }

  ret = FUN_002b7d98(self->config.f10, 0x29, 0x2000, 0x29, 0x2000);
  if (ret < 0) {
    FUN_000ba3ac(s_sceNetInit___failed_0x_X__002d4d64, ret);
    return 0;
  }
  FUN_000ba3ac(s_sceNetInit___success_002d4d80);
  ret = FUN_002b7e60();
  if (ret < 0) {
    FUN_000ba3ac(s_sceNetAdhocInit___failed_0x_X__002d4d98, ret);
    return 0;
  }
  FUN_000ba3ac(s_sceNetAdhocInit___success_002d4db8);
  ret = FUN_002b7d80(0x2000, 0x30, self->config.f18);
  if (ret < 0) {
    FUN_000ba3ac(s_sceNetAdhocctlInit___failed_0x_X_002d4dd4, ret);
    return 0;
  }
  FUN_000ba3ac(s_sceNetAdhocctlInit___success_002d4df8);
  ret = FUN_002b7d60((void *)FUN_000bc108, 0);
  if (ret < 0) {
    FUN_000ba3ac(s_sceNetAdhocctlAddHandler___faile_002d4e18, ret);
    return 0;
  }
  self->f24 = FUN_000ba3ac(s_sceNetAdhocctlAddHandler___succe_002d4e44);
  self->f190 = 0;
  self->f194 = 0;
  self->f274 = 0;
  self->f168 = 0;
  DAT_00338ac8 = 0;
  DAT_002d4ab0 = -1;

  for (i = 0; i < 0x10; i++) {
    self->f21c[i] = 0;
    self->f1dc[i] = 0;
  }

  self->f184 = FUN_00000a90(self->config.f00);
  self->f180 = FUN_00000a90(self->config.f04);
  self->f188 = FUN_00000a90(self->config.f00);
  self->f284 = 0;
  FUN_000baa34(self, 0);
  self->f278 = 1;
  return 1;
}
