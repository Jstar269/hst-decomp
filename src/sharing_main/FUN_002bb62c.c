/* HSTMATCH module=hstp_trans_main.prx start=0x002bb62c end=0x002bb644 symbol=FUN_002bb62c lang=c99 */
/* Clone of src/eboot/FUN_002abe70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef struct SelObj {
  char pad00[0x54];
  int sel; /* 0x54 */
} SelObj;

/* Set the selection field (store only when it changes). */
void FUN_002bb62c(SelObj *obj,int sel)
{
  if (sel != obj->sel) {
    obj->sel = sel;
  }
}
