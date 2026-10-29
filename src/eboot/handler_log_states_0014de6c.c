/* HSTMATCH module=EBOOT.BIN start=0x0014de6c end=0x0014df40 symbol=FUN_0014de6c lang=c99 helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (restructured from the ds6 near miss: the final log call sits outside the second flag test, the done-state test is an inline return-A-or-B helper that materialises both compares, and the data addresses are 0x2dc240/0x2dc24c/0x2dc314 after sign-extending the low half); the empty variadic stub FUN_0014c610 is placed by helpers= and already has its own source; exact match verified; names and types await human review. */
typedef struct {
  char pad[8];
  int state;
} Sub;

typedef struct {
  char pad[0x18];
  int count;
  Sub *sub;
} Obj;

extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc314[];
extern void FUN_0014f3cc(void *out, void *list, int *pos);

static void FUN_0014c610(...)
{
}

static inline int IsDone(int s)
{
  return s == 1 || s == 2;
}

int FUN_0014de6c(void *self, Obj *obj)
{
  void *out;
  int pos;
  int state;
  int i;

  pos = (int)obj->sub;
  FUN_0014f3cc(&out, &obj->count, &pos);
  if (DAT_003402f0 != 0) {
    state = obj->count > 0 ? obj->sub->state : 0;
    if (!IsDone(state)) {
      if (DAT_003402f0 != 0) {
        FUN_0014c610(DAT_002dc240);
        for (i = 0; i < obj->count + 1; i++)
          FUN_0014c610(DAT_002dc24c);
      }
      FUN_0014c610(DAT_002dc314);
    }
  }
  return 0;
}
