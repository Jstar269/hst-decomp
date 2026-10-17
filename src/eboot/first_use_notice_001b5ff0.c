/* HSTMATCH module=EBOOT.BIN start=0x001b5ff0 end=0x001b6098 symbol=FUN_001b5ff0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: ternary (x >= 0 ? tab[x] : 0) for the if/else assignment, single && condition (owner == cur && flag == 0) instead of nested ifs with a duplicated tail load, &DAT_0034179c symbol address, typed structs; exact match verified; names and types await human review. */
typedef struct Mgr { char pad0[0x140]; int *tab; char pad1[0xd60 - 0x144]; int sel; } Mgr;
typedef struct Item { char pad0[0x10]; char a[0x10]; char b[0x18]; int arg; int pad1; int owner; } Item;
typedef struct Obj { char pad[0x7b]; unsigned char flag; } Obj;

extern Mgr * DAT_003402a0;
extern char DAT_0034179c;
extern void FUN_001b2bb8(char *, int);
extern void FUN_001b5cb4(Obj *, int, char *, int, char *);

void FUN_001b5ff0(Obj *param_1, Item *param_2, int param_3)
{
  int cur;

  cur = DAT_003402a0->sel >= 0 ? DAT_003402a0->tab[DAT_003402a0->sel] : 0;
  if (param_2->owner == cur && param_1->flag == 0) {
    FUN_001b2bb8(&DAT_0034179c, 0x9b);
    param_1->flag = 1;
  }
  FUN_001b5cb4(param_1, param_2->arg, param_2->a, param_3, param_2->b);
}
