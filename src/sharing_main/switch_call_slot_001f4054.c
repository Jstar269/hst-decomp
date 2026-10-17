/* HSTMATCH module=hstp_trans_main.prx start=0x001f4054 end=0x001f4118 symbol=FUN_001f4054 lang=c99 */
/* Clone of src/eboot/switch_call_slot_001e5e3c.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the else-if ladder on param_2 is a switch with cases 1-4 in source order (tests come out reversed), typed Rec/Obj views with four 0x8c-byte records, and an inline helper for the shared call; exact match verified; names and types await human review. */
typedef struct { char pad[8]; short x; short y; char rest[0x8c - 12]; } Rec;
typedef struct { char pad[0x1fb4]; Rec recs[4]; } Obj;
extern void FUN_0022687c(Rec *r, int a, int b, int c, int d, int e);

static inline void Call(Rec *r)
{
  FUN_0022687c(r, r->x + 0x15e, r->y, r->x, r->y, 5);
}

void FUN_001f4054(Obj *param_1, int param_2)
{
  switch (param_2) {
  case 1:
    Call(&param_1->recs[0]);
    break;
  case 2:
    Call(&param_1->recs[1]);
    break;
  case 3:
    Call(&param_1->recs[2]);
    break;
  case 4:
    Call(&param_1->recs[3]);
    break;
  }
}
