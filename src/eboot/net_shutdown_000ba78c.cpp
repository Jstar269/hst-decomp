/* HSTMATCH module=EBOOT.BIN start=0x000ba78c end=0x000ba96c symbol=FUN_000ba78c lang=c++ data=0x002d4e68 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: each slot release keeps a redundant second null test (`if (p != 0) { if (p != 0) ... }`) -
   retail carries three tests per slot (outer guard, redundant guard, and delete's own test), and MWCC folds
   away a single guard. The net teardown is written as sequential early-return guards, which is what puts the
   continuation out of line and leaves `beqzl v0,<success>`. Data: its string literals (6 strings, 0x002d4e68-0x002d4f1a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

#include "hst/adhoc_net.h"

extern "C" void FUN_000009e4(void *);
extern "C" void FUN_000ba3ac(char *, ...);
extern "C" void FUN_000bae04(void *);
extern "C" void FUN_000baac8(void *);
extern "C" int FUN_002b7d78(void);
extern "C" int FUN_002b7e40(void);
extern "C" int FUN_002b7d90(void);

struct AdhocObj {
  virtual ~AdhocObj();
};

/* Releases the working buffers and slot objects, stops matching, then shuts the net stack down; returns 1 on success. */
extern "C" int FUN_000ba78c(AdhocNet *self)
{
  int i;
  int result;
  AdhocObj *obj;

  if (self->bufC != 0) {
    if (self->bufC != 0) {
      FUN_000009e4(self->bufC);
      self->bufC = 0;
    }
  }
  if (self->bufA != 0) {
    if (self->bufA != 0) {
      FUN_000009e4(self->bufA);
      self->bufA = 0;
    }
  }
  if (self->bufB != 0) {
    if (self->bufB != 0) {
      FUN_000009e4(self->bufB);
      self->bufB = 0;
    }
  }

  for (i = 0; i < ADHOC_SLOT_COUNT; i++) {
    obj = self->slotObj[i];
    if (obj != 0) {
      if (obj != 0) {
        delete obj;
        self->slotObj[i] = 0;
      }
    }
    obj = self->slotAux[i];
    if (obj != 0) {
      if (obj != 0) {
        delete obj;
        self->slotAux[i] = 0;
      }
    }
  }

  if (self->unk26c != 0) {
    if (self->unk26c != 0) {
      delete self->unk26c;
      self->unk26c = 0;
    }
  }
  FUN_000bae04(self);
  FUN_000baac8(self);

  result = FUN_002b7d78();
  if (result != 0) {
    FUN_000ba3ac("sceNetAdhocctlTerm() failed(0x%X)\n",result);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocctlTerm() success\n");
  result = FUN_002b7e40();
  if (result != 0) {
    FUN_000ba3ac("sceNetAdhocTerm() failed(0x%X)\n",result);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocTerm() success\n");
  result = FUN_002b7d90();
  if (result != 0) {
    FUN_000ba3ac("sceNetTerm() failed(0x%X)\n",result);
    return 0;
  }
  FUN_000ba3ac("sceNetTerm() success\n");
  return 1;
}
