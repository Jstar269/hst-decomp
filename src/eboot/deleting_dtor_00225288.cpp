/* HSTMATCH module=EBOOT.BIN start=0x00225288 end=0x002254ec symbol=FUN_00225288 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the global tested before FUN_00291cdc is that call's argument (Ghidra dropped it, so retail loads it into a0); readability pass; exact match verified; names and types await human review. */
#include "hst/mode_parts.h"

extern "C" {
extern void *DAT_0034a820;
extern void FUN_00000a00(...);
extern int * FUN_000f64d8(...);
extern int FUN_0021aa6c(...);
extern void FUN_00291cdc(void *);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };
struct VC_6 { virtual ~VC_6(); };
struct VC_7 { virtual ~VC_7(); };
struct VC_8 { virtual ~VC_8(); };
struct VC_9 { virtual ~VC_9(); };
struct VC_10 { virtual ~VC_10(); };

/* Destroy the part set: delete each owned part (and clear its pointer), then the optional global. */
extern "C" ModeParts * FUN_00225288(ModeParts *parts,short delete_flag)
{
  void *obj;
  void *other;
  
  if (parts != (ModeParts *)0x0) {
    obj = parts->part00;
    if (obj != (void *)0x0) {
      delete ((VC_0 *)(obj));
      parts->part00 = 0;
    }
    obj = parts->part04;
    if (obj != (void *)0x0) {
      delete ((VC_1 *)(obj));
      parts->part04 = 0;
    }
    obj = parts->part08;
    if (obj != (void *)0x0) {
      delete ((VC_2 *)(obj));
      parts->part08 = 0;
    }
    obj = parts->part0c;
    if (obj != (void *)0x0) {
      delete ((VC_3 *)(obj));
      parts->part0c = 0;
    }
    obj = parts->part10;
    if (obj != (void *)0x0) {
      delete ((VC_4 *)(obj));
      parts->part10 = 0;
    }
    obj = parts->part14;
    if (obj != (void *)0x0) {
      delete ((VC_5 *)(obj));
      parts->part14 = 0;
    }
    obj = parts->part18;
    if (obj != (void *)0x0) {
      delete ((VC_6 *)(obj));
      parts->part18 = 0;
    }
    obj = parts->part1c;
    if (obj != (void *)0x0) {
      delete ((VC_7 *)(obj));
      parts->part1c = 0;
    }
    obj = parts->part20;
    if (obj != (void *)0x0) {
      delete ((VC_8 *)(obj));
      parts->part20 = 0;
    }
    obj = parts->part24;
    if (obj != (void *)0x0) {
      delete ((VC_9 *)(obj));
      parts->part24 = 0;
    }
    other = parts->part28;
    if (other != 0) {
      FUN_0021aa6c(other,1);
      parts->part28 = 0;
    }
    obj = parts->part2c;
    if (obj != (void *)0x0) {
      delete ((VC_10 *)(obj));
      parts->part2c = 0;
    }
    other = parts->part30;
    if (other != 0) {
      if (other != 0) {
        FUN_000f64d8(other,0);
        FUN_00000a00(other);
      }
      parts->part30 = 0;
    }
    if (DAT_0034a820) {
      FUN_00291cdc(DAT_0034a820);
    }
    if (0 < delete_flag) {
      FUN_00000a00(parts);
    }
  }
  return parts;
}
