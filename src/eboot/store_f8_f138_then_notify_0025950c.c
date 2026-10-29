/* HSTMATCH module=EBOOT.BIN start=0x0025950c end=0x002595e8 symbol=FUN_0025950c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed Obj struct, bool flags as ints, the && test on the two values as !((x != 0) ^ 1) && !((y != 0) ^ 1) (matching idiom: materialised sltu/xori tests), `if (need_id_check == 0)` with one shared store, and notify = 0 on equality instead of a != materialisation; readability pass; exact match verified; names and types await human review. */
/* Obj fields: the name at +0xf8 (a string pointer kept as int) and the id at +0x138. */
typedef struct Obj { char pad00[0xf8]; int name; char pad_fc[0x3c]; int id; } Obj;
extern int FUN_00014934(int, int);
extern void FUN_0010d4a8(Obj *);

/* Stores a new name and id. The change helper runs when forced, when the name differs (a missing name counts as
   different) or when the id differs. */
void FUN_0025950c(Obj *obj, int new_name, int new_id, int force)
{
  int notify;
  int need_id_check;
  int names_differ;
  int not_both_set;

  notify = 1;
  need_id_check = 1;
  if (force == 0) {
    names_differ = 1;
    not_both_set = 1;
    if (!((obj->name != 0) ^ 1) && !((new_name != 0) ^ 1)) not_both_set = 0;
    if ((not_both_set == 0) && (FUN_00014934(obj->name, new_name) == 0)) {
      names_differ = 0;
    }
    if (names_differ == 0) {
      need_id_check = 0;
    }
  }
  if (need_id_check == 0) {
    if (obj->id == new_id) notify = 0;
  }
  obj->name = new_name;
  obj->id = new_id;
  if (notify) {
    FUN_0010d4a8(obj);
  }
}
