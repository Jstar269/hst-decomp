/* HSTMATCH module=EBOOT.BIN start=0x0015d3fc end=0x0015d46c symbol=FUN_0015d3fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined1;

extern undefined1 * FUN_0022cd60(void);
extern undefined1 DAT_0034100c;

undefined1 FUN_0015d3fc(void)
{
  int iVar1;
  int i;
  char *puVar2;
  unsigned char uVar3;

  uVar3 = 0;
  iVar1 = (int)FUN_0022cd60();
  for (i = 0, puVar2 = (char *)&DAT_0034100c; i < 5; i++, puVar2++) {
    if ((*(char *)(iVar1 + 0xf0) & (1 << i)) != 0 && puVar2[0xd0] == '\0') {
      uVar3 = 1;
      break;
    }
  }
  return uVar3;
}
