/* HSTMATCH module=hstp_trans_main.prx start=0x00159d14 end=0x00159de8 symbol=FUN_00159d14 lang=c99 helpers=FUN_00157280@0x00157280-0x001572ac */
/* Clone of src/eboot/handler_log_states_0014de6c.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (restructured from the ds6 near miss: the final log call sits outside the second flag test, the done-state test is an inline return-A-or-B helper that materialises both compares, and the data addresses are 0x3836b8/0x3836c4/0x38378c after sign-extending the low half); the empty variadic stub FUN_00157280 is placed by helpers= and already has its own source; exact match verified; names and types await human review. */
typedef struct {
  char pad[8];
  int state;
} Sub;

typedef struct {
  char pad[0x18];
  int count;
  Sub *sub;
} Obj;

extern unsigned char DAT_003e9630;
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern char DAT_0038378c[];
extern void FUN_0015b3cc(void *out, void *list, int *pos);

static void FUN_00157280(...)
{
}

static inline int IsDone(int s)
{
  return s == 1 || s == 2;
}

int FUN_00159d14(void *self, Obj *obj)
{
  void *out;
  int pos;
  int state;
  int i;

  pos = (int)obj->sub;
  FUN_0015b3cc(&out, &obj->count, &pos);
  if (DAT_003e9630 != 0) {
    state = obj->count > 0 ? obj->sub->state : 0;
    if (!IsDone(state)) {
      if (DAT_003e9630 != 0) {
        FUN_00157280(DAT_003836b8);
        for (i = 0; i < obj->count + 1; i++)
          FUN_00157280(DAT_003836c4);
      }
      FUN_00157280(DAT_0038378c);
    }
  }
  return 0;
}
