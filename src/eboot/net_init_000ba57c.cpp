/* HSTMATCH module=EBOOT.BIN start=0x000ba57c end=0x000ba78c symbol=FUN_000ba57c lang=c++ data=0x002d4d64 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The eight-word config copy is written field by field: a struct assignment of the same 32 bytes makes MWCC
   copy through $f0..$f3 with lwc1/swc1 instead of lw/sw (see docs/MWCC-NOTES.md). Data: its string literals (8 strings, 0x002d4d64-0x002d4e68) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/adhoc_net.h"

extern "C" void FUN_000ba9e0(void *, void *);
extern "C" int FUN_000ba3ac(char *, ...);
extern "C" int FUN_002b7d98(int, int, int, int, int);
extern "C" int FUN_002b7e60(void);
extern "C" int FUN_002b7d80(int, int, const void *);
extern "C" int FUN_002b7d60(void *, int);
extern "C" void *FUN_00000a90(int);
extern "C" void FUN_000baa34(void *, int);
extern "C" void FUN_000bc108(void);

extern int DAT_00338ac8;
extern int DAT_002d4ab0;

/* Brings the net stack up (net, ad-hoc, ad-hoc control) and allocates the working buffers; returns 1 on success. */
extern "C" int FUN_000ba57c(AdhocNet *self, AdhocConfig *cfg)
{
  int ret;
  int i;

  if (cfg != 0) {
    self->config.bufSizeA = cfg->bufSizeA;
    self->config.bufSizeB = cfg->bufSizeB;
    self->config.unk08 = cfg->unk08;
    self->config.unk0c = cfg->unk0c;
    self->config.poolSize = cfg->poolSize;
    self->config.unk14 = cfg->unk14;
    self->config.product = cfg->product;
    self->config.groupName = cfg->groupName;
  } else {
    FUN_000ba9e0(self, &self->config);
  }

  ret = FUN_002b7d98(self->config.poolSize, 0x29, 0x2000, 0x29, 0x2000);
  if (ret < 0) {
    FUN_000ba3ac("sceNetInit() failed(0x%X)\n", ret);
    return 0;
  }
  FUN_000ba3ac("sceNetInit() success\n");
  ret = FUN_002b7e60();
  if (ret < 0) {
    FUN_000ba3ac("sceNetAdhocInit() failed(0x%X)\n", ret);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocInit() success\n");
  ret = FUN_002b7d80(0x2000, 0x30, self->config.product);
  if (ret < 0) {
    FUN_000ba3ac("sceNetAdhocctlInit() failed(0x%X)\n", ret);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocctlInit() success\n");
  ret = FUN_002b7d60((void *)FUN_000bc108, 0);
  if (ret < 0) {
    FUN_000ba3ac("sceNetAdhocctlAddHandler() failed(0x%X)\n", ret);
    return 0;
  }
  self->unk24 = FUN_000ba3ac("sceNetAdhocctlAddHandler() success\n");
  self->unk190 = 0;
  self->unk194 = 0;
  self->unk274 = 0;
  self->unk168 = 0;
  DAT_00338ac8 = 0;
  DAT_002d4ab0 = -1;

  for (i = 0; i < ADHOC_SLOT_COUNT; i++) {
    self->slotFlag[i] = 0;
    self->slotObj[i] = 0;
  }

  self->bufA = FUN_00000a90(self->config.bufSizeA);
  self->bufB = FUN_00000a90(self->config.bufSizeB);
  self->bufC = FUN_00000a90(self->config.bufSizeA);
  self->unk284 = 0;
  FUN_000baa34(self, 0);
  self->unk278 = 1;
  return 1;
}
