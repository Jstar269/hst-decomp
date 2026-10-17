/* HSTMATCH module=hstp_trans_main.prx start=0x00089f84 end=0x00089fd8 symbol=FUN_00089f84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: unsigned byte flag global (lbu), typed the object and game structs, the 7-byte-stride table read as char-pointer arithmetic (a typed 7-byte entry array puts the index first in addu); exact match verified; names and types await human review. */
typedef struct Game {
  char pad_000[0x198];
  int cur;
} Game;

typedef struct Obj {
  char pad_00[0x70];
  int slots[1];
} Obj;

extern unsigned char DAT_003e19f8;
extern Game *DAT_003e1e04;

int FUN_00089f84(Obj *param_1)
{
  int iVar1;

  iVar1 = 0;
  if (DAT_003e19f8 != 0 && ((unsigned char *)DAT_003e1e04)[DAT_003e1e04->cur * 7 + 0x5e] != 0) {
    iVar1 = param_1->slots[DAT_003e1e04->cur];
  }
  if (iVar1 == 0) {
    iVar1 = param_1->slots[0];
  }
  return iVar1;
}
