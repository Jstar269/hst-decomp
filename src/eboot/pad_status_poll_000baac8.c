/* HSTMATCH module=EBOOT.BIN start=0x000baac8 end=0x000bab10 symbol=FUN_000baac8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char bool;
typedef unsigned char undefined1;
extern undefined1 DAT_002d4f98[];
extern undefined1 DAT_002d4fc0[];
extern void FUN_000ba3ac();
extern int FUN_002b7dc0(void);

bool FUN_000baac8(void)
{
  int r;

  r = FUN_002b7dc0();
  if (r < 0) {
    FUN_000ba3ac(DAT_002d4f98,r);
    return 0;
  }
  FUN_000ba3ac(DAT_002d4fc0);
  return 1;
}
