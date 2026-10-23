/* HSTMATCH module=EBOOT.BIN start=0x0022acf0 end=0x0022ad48 symbol=FUN_0022acf0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined1;

struct Tbl { char pad[0x3d00]; unsigned char cell; };
extern struct Tbl *DAT_003415a8;

undefined1 FUN_0022acf0(int param_1,int param_2,int param_3)
{
  if (param_3 == 1) {
    return *(unsigned char *)((char *)&DAT_003415a8->cell + param_1 * 0x14 + (param_2 + 10));
  }
  return *(unsigned char *)((char *)&DAT_003415a8->cell + param_1 * 0x14 + param_2);
}
