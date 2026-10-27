/* HSTMATCH module=EBOOT.BIN start=0x0018c4dc end=0x0018c660 symbol=FUN_0018c4dc lang=c99 data=0x002e0bc4 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the table store chained into the null test); names and types await human review. Data: its string literals (4 strings, 0x002e0bc4-0x002e0c15) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_0030ebf4[];
extern int DAT_00341530;
extern int DAT_0034156c;
extern void FUN_0001ca58(char *, char *);
extern void FUN_0001cb88(char *);
extern void FUN_000143b0(char *, char *, ...);
extern int FUN_0004cad0(char *, int, int, int);
extern void *FUN_0004e780(int *, int *, int, int, int, int);
extern void *FUN_00051050(void *, char *, void *, int);
extern void *FUN_00051450(void *);
extern void FUN_00011090(char *, char *, int);
extern void *FUN_00000bcc(int);

void FUN_0018c4dc(void)
{
  char name[64];
  int a;
  int b;
  char path[64];
  int i;
  int j;
  void *buf;
  void *obj;
  void *u;
  int *tab1;
  int h;
  int *tab2;

  if (DAT_00341530 != 0) return;
  a = 0;
  b = 0;
  FUN_0001ca58(DAT_0030ebf4, "menu/chrsel_020_prerender.xb");
  i = 0;
  tab1 = &DAT_00341530;
  tab2 = &DAT_0034156c;
  do {
    FUN_000143b0(name, "%sdef_%02d.bin", "data/menu/chrselect/", i);
    if ((h = *tab1 = FUN_0004cad0(name, 0, 0x10, 1)) != 0) {
      FUN_000143b0(path, "PreD%02d", i);
      u = FUN_0004e780(&a, &b, 1, 0, 0x40, 0x40);
      obj = FUN_00000bcc(0x48);
      if (obj != 0) obj = FUN_00051050(obj, path, u, 0);
      buf = FUN_00051450(obj);
      j = 0;
      do {
        FUN_00011090((char *)buf + j * 0x80, (char *)h + j * 0x80, 0x80);
        j++;
      } while (j < 0x40);
      *tab2 = (int)obj;
    }
    i++;
    tab1++;
    tab2++;
  } while (i < 15);
  FUN_0001cb88(DAT_0030ebf4);
}
