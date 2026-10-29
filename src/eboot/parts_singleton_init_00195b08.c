/* HSTMATCH module=EBOOT.BIN start=0x00195b08 end=0x00195b90 symbol=FUN_00195b08 lang=c99 data=0x002e15b0 */
/* LoadPartsSetTable: data/common/parts/Parts_P_Set.txt; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002e15b0-0x002e15d6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034174c;
extern int DAT_003070bc;
extern void *FUN_00000bcc(int size);
extern void FUN_000649c0(void *obj);
extern void FUN_000651b8(void *obj, char *name, int a, int b, char *c);
extern void FUN_0008c230(void *p);

#define PARTS_OBJ_SIZE 0x30 /* allocation size of the parts-table object */

/* Create the parts-set table object once and load its table file. */
void FUN_00195b08(void)
{
  int obj;

  if (DAT_0034174c == 0) {
    if ((obj = (int)FUN_00000bcc(PARTS_OBJ_SIZE)) != 0) {
      FUN_000649c0((void *)obj);
      *(int *)obj = (int)&DAT_003070bc;
      FUN_0008c230((void *)(obj + 0x10));
      FUN_0008c230((void *)(obj + 0x20));
    }
    DAT_0034174c = obj;
    FUN_000651b8((void *)obj, "data/common/parts/Parts_P_Set.txt", 0, 0, "\t");
  }
}
