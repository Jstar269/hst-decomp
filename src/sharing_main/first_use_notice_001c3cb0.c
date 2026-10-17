/* HSTMATCH module=hstp_trans_main.prx start=0x001c3cb0 end=0x001c3d58 symbol=FUN_001c3cb0 lang=c99 */
/* Clone of src/eboot/first_use_notice_001b5ff0.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: ternary (x >= 0 ? tab[x] : 0) for the if/else assignment, single && condition (owner == cur && flag == 0) instead of nested ifs with a duplicated tail load, &DAT_003eaad8 symbol address, typed structs; exact match verified; names and types await human review. */
typedef struct Mgr { char pad0[0x140]; int *tab; char pad1[0xd60 - 0x144]; int sel; } Mgr;
typedef struct Item { char pad0[0x10]; char a[0x10]; char b[0x18]; int arg; int pad1; int owner; } Item;
typedef struct Obj { char pad[0x7b]; unsigned char flag; } Obj;

extern Mgr * DAT_003e95e0;
extern char DAT_003eaad8;
extern void FUN_001c0ce8(char *, int);
extern void FUN_001c3974(Obj *, int, char *, int, char *);

void FUN_001c3cb0(Obj *param_1, Item *param_2, int param_3)
{
  int cur;

  cur = DAT_003e95e0->sel >= 0 ? DAT_003e95e0->tab[DAT_003e95e0->sel] : 0;
  if (param_2->owner == cur && param_1->flag == 0) {
    FUN_001c0ce8(&DAT_003eaad8, 0x9b);
    param_1->flag = 1;
  }
  FUN_001c3974(param_1, param_2->arg, param_2->a, param_3, param_2->b);
}
