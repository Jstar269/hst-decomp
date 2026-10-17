/* HSTMATCH module=hstp_trans_main.prx start=0x000c8a98 end=0x000c8b48 symbol=FUN_000c8a98 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: byte entries as a typed 7-byte struct array (unsigned char flag, lbu), for-loop with the index declared first, typed pointer arguments, and the callee's dropped argument restored (FUN_000c0ab8(G)); same shape as the matched EBOOT twin src/eboot/slot_scan_notify_000c5014.c; exact match verified; names and types await human review. */
/* For each of the first 2 (4 when DAT_003eaaf0 is set) 7-byte entries at +0x5e of the global object, calls 0xc0ab8 on the object when the entry's flag is set and its index equals the object's current index (+0x198); then calls 0xbe5d8. */
typedef struct Ent { unsigned char on; char pad[6]; } Ent;
typedef struct Obj { char pad0[0x5e]; Ent ent[4]; char pad1[0x198 - 0x5e - 28]; int cur; } Obj;

extern Obj * DAT_003e1e04;
extern unsigned char DAT_003eaaf0;
extern void FUN_000be5d8(Obj *);
extern void FUN_000c0ab8(Obj *);

void FUN_000c8a98(void)
{
  if (DAT_003e1e04 != 0) {
    int cur = DAT_003e1e04->cur;
    int n;
    int i;
    if (DAT_003eaaf0 == 0) {
      n = 2;
    }
    else {
      n = 4;
    }
    for (i = 0; i < n; i++) {
      if (DAT_003e1e04->ent[i].on != 0 && i == cur) {
        FUN_000c0ab8(DAT_003e1e04);
      }
    }
    FUN_000be5d8(DAT_003e1e04);
  }
}
