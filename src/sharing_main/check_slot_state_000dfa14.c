/* HSTMATCH module=hstp_trans_main.prx start=0x000dfa14 end=0x000dfb00 symbol=FUN_000dfa14 lang=c99 */
/* Clone of src/eboot/check_slot_state_000db9f4.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Rec { char pad[0xe3]; unsigned char v; char pad2[0x120 - 0xe4]; } Rec;
extern Rec DAT_003eaaf0[2];
extern int FUN_000e30f8(void *);

typedef struct O {
  char pad[0x8c];
  int f8c;
  char pad1[0xc4 - 0x90];
  int c4[2];
  char pad2[0xd0 - 0xcc];
  unsigned d0[2];
} O;

static inline int A(O *o)
{
  int i;
  for (i = 0; i < 2; i++) {
    if (o->f8c != 0) return 0;
  }
  return 1;
}
static inline int B(O *o)
{
  int i;
  for (i = 0; i < 2; i++) {
    unsigned v;
    if (FUN_000e30f8(o) != 0) v = 0; else v = DAT_003eaaf0[i].v;
    if (o->d0[i] != v) return 0;
  }
  return 1;
}
static inline int C(O *o)
{
  int i;
  for (i = 0; i < 2; i++) {
    if (o->c4[i] != 0) return 0;
  }
  return 1;
}

int FUN_000dfa14(O *o)
{
  int r = A(o);
  if (r == 0) r = 0; else r = B(o);
  if (r == 0) r = 0; else r = C(o);
  return r;
}
