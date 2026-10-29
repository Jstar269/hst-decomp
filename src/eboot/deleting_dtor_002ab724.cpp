/* HSTMATCH module=EBOOT.BIN start=0x002ab724 end=0x002ab8fc symbol=FUN_002ab724 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vshistory.h"

struct CommonPanel { virtual ~CommonPanel(); };
struct Page1 { virtual ~Page1(); };
struct Page2 { virtual ~Page2(); };
struct Page3 { virtual ~Page3(); };
struct HistoryEntry { virtual ~HistoryEntry(); };

struct EntryInfo {
  char pad00[0x24];
  u32 unk24; /* 0x24 */
  u32 unk28; /* 0x28 */
};
struct EntryOwner {
  char pad00[0x70];
  EntryInfo *info; /* 0x70 */
};

extern "C" {
extern u8 DAT_00309efc;
extern u32 DAT_003415d4;
extern u32 DAT_0034179c;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern EntryOwner * FUN_00190830(u32);
extern int FUN_0019083c(...);
extern void FUN_001b338c(...);
extern void FUN_001b3e2c(...);
}

/* Deleting destructor of the screen: stop its sounds, delete the four parts and the entry, then the base. */
extern "C" HistoryScreen * FUN_002ab724(HistoryScreen *self,short delete_flag)
{
  EntryOwner *owner;
  u32 value;
  
  if (self != (HistoryScreen *)0x0) {
    self->vtbl = &DAT_00309efc;
    FUN_001b3e2c(&DAT_0034179c);
    FUN_001b338c(&DAT_0034179c,4);
    if (self->common != (CommonPanel *)0x0) {
      delete self->common;
      self->common = 0;
    }
    if (self->page1 != (Page1 *)0x0) {
      delete self->page1;
      self->page1 = 0;
    }
    if (self->page2 != (Page2 *)0x0) {
      delete self->page2;
      self->page2 = 0;
    }
    if (self->page3 != (Page3 *)0x0) {
      delete self->page3;
      self->page3 = 0;
    }
    if (DAT_003415d4 != 0) {
      owner = FUN_00190830(DAT_003415d4);
      value = FUN_0019083c(DAT_003415d4);
      if (owner != 0) {
        owner->info->unk24 = 0x3f;
        owner->info->unk28 = value;
      }
    }
    if (self->entry != (HistoryEntry *)0x0) {
      delete self->entry;
      self->entry = 0;
    }
    if ((char *)self + 0x74 != (char *)0) {
      FUN_000462a0(&self->label.r,0xffffffff);
      FUN_00004138(&self->label.s,0);
    }
    if ((char *)self + 0x5c != (char *)0) {
      FUN_000462a0(&self->text.r,0xffffffff);
      FUN_00004138(&self->text.s,0);
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
