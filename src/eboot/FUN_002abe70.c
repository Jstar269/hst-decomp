/* HSTMATCH module=EBOOT.BIN start=0x002abe70 end=0x002abe88 symbol=FUN_002abe70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct SelObj {
  char pad00[0x54];
  int sel; /* 0x54 */
} SelObj;

/* Set the selection field (store only when it changes). */
void FUN_002abe70(SelObj *obj,int sel)
{
  if (sel != obj->sel) {
    obj->sel = sel;
  }
}
