/* HSTMATCH module=EBOOT.BIN start=0x001cb700 end=0x001cb7d0 symbol=FUN_001cb700 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_00341d7c;
extern int DAT_00341d84;
extern int FUN_00014a40(char *);
extern char *FUN_000149a8(char *, char *);
extern void FUN_001cd88c(int, int, int);
extern void FUN_001c2498(int);

void FUN_001cb700(int param_1, char *param_2)
{
  int flag = *(unsigned char *)(param_1 + 0xfc);
  int obj = *(int *)(param_1 + 0x15c);
  int len;

  DAT_00341d7c = 0;
  *(char *)(obj + 0x90) = 0;
  *(int *)(obj + 0x94) = 2;
  len = FUN_00014a40(param_2);
  FUN_000149a8((char *)(obj + 0x98), param_2);
  *(char *)(len + obj + 0x98) = 0;
  if (flag != 0)
    DAT_00341d84 = 16;
  else
    DAT_00341d84 = 0;
  FUN_001cd88c(obj, 3, 1);
  FUN_001c2498(obj);
  *(char *)(obj + 0x61) = 1;
  if (*(unsigned char *)(obj + 0x61) != 0)
    *(char *)(obj + 0x62) = 1;
  *(char *)(param_1 + 0xfc) = 0;
}
