/* HSTMATCH module=EBOOT.BIN start=0x002796b4 end=0x0027977c symbol=FUN_002796b4 lang=c99 helpers=FUN_0026f7f4@0x0026f7f4-0x0026f820 */
/* Hand-written reconstruction from the disassembly (near miss wip/dbg_add_mode_value_002796b4.c, completed with its same-file static helper FUN_0026f7f4 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x104];
  int mode;
  char pad108[0x134 - 0x108];
  int vals[5];
} Obj;
extern char DAT_002fe648[];
extern char DAT_002fe660[];
static void FUN_0026f7f4(...) {}

static inline int Get(Obj *o)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->vals[m];
  default:
    FUN_0026f7f4(DAT_002fe648, m);
    return 0;
  }
}

static inline void Set(Obj *o, int val)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->vals[m] = val;
    FUN_0026f7f4(DAT_002fe660, m, val);
    break;
  }
}

void FUN_002796b4(Obj *param_1, int param_2)
{
  Set(param_1, param_2 + Get(param_1));
}
