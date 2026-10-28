/* HSTMATCH module=hstp_trans_main.prx start=0x00098bc8 end=0x00098d64 symbol=FUN_00098bc8 lang=c99 data=0x0037a74c */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed structs, gate flag as int ok = (G != 0); if (ok) ok = (b != 0) ^ 1, unsigned char flags, entry byte compared through an int local with (uchar) cast; matching idiom: the result of the debug print stub FUN_00097e3c is assigned back to the entry pointer (retail keeps the entry in v0 across the stub call, as MWCC does for an empty static stub defined earlier in the same file, which hstmatch cannot place); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037a74c-0x0037a760) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

typedef struct {
  char pad0[0x148];
  int idx;
  char pad1[0x68];
  u8 flag;
  char pad2[0x143];
  u8 b2f8;
  char b2f9;
  int w2fc;
} Obj;

typedef struct {
  char pad[0x780];
  int w780;
} Mgr;

typedef struct {
  char pad0[0x5c];
  u8 b5c;
  char pad1[0x3f];
  int w9c;
} Sys;

typedef struct {
  u8 b0;
  char pad[0x137];
  u8 b138;
  char b139;
  int w13c;
} Entry;

extern u8 DAT_003e19f8;
extern Mgr *DAT_003e1e30;
extern Sys *DAT_003e1e84;
extern Entry *FUN_00097e3c();
extern Entry *FUN_000c8538();

void FUN_00098bc8(Obj *o)
{
  int ok;
  int mode;
  int ch;
  Entry *e;

  if (DAT_003e19f8 != 0 && DAT_003e1e30 != 0) {
    ok = DAT_003e19f8 != 0;
    if (ok) {
      ok = (o->flag != 0) ^ 1;
    }
    if (ok) {
      mode = DAT_003e1e84->b5c;
      ch = DAT_003e1e84->w9c;
      e = FUN_000c8538(DAT_003e1e30, o->idx);
      if (e->b138 != (u8)mode || e->b139 != ch) {
        ok = DAT_003e19f8 != 0;
        if (ok) {
          ok = (o->flag != 0) ^ 1;
        }
        if (ok && DAT_003e1e30 != 0) {
          e = FUN_000c8538(DAT_003e1e30, o->idx);
          e->w13c = DAT_003e1e30->w780;
          e->b138 = mode;
          e->b139 = ch;
        }
      }
    }
    ok = 0;
    if (DAT_003e19f8 != 0 && o->flag != 0) ok = 1;
    if (ok) {
      ok = DAT_003e19f8 != 0;
      if (ok) {
        ok = o->flag != 0;
      }
      if (ok && DAT_003e1e30 != 0) {
        e = FUN_000c8538(DAT_003e1e30, o->idx);
        if (e->b0 != 0 && o->w2fc != e->w13c) {
          e = FUN_00097e3c("ReceivePoint %d %d\n", e->b138, (int)e->b139);
          o->b2f8 = e->b138;
          o->b2f9 = e->b139;
          o->w2fc = e->w13c;
        }
      }
    }
  }
}
