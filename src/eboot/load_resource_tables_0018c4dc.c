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

#define ENTRY_COUNT 15      /* entries in each table */
#define PRERENDER_ROWS 0x40 /* rows copied into the pre-render object */
#define ROW_BYTES 0x80      /* bytes per row */

/* Loads the default-data file for each entry into the first table and builds its pre-render object into the second. */
void FUN_0018c4dc(void)
{
  char fileName[64];
  int outA;
  int outB;
  char objName[64];
  int index;
  int row;
  void *pixels;
  void *prerender;
  void *surface;
  int *rawSlot;
  int raw;
  int *objSlot;

  if (DAT_00341530 != 0) return;
  outA = 0;
  outB = 0;
  FUN_0001ca58(DAT_0030ebf4, "menu/chrsel_020_prerender.xb");
  index = 0;
  rawSlot = &DAT_00341530;
  objSlot = &DAT_0034156c;
  do {
    FUN_000143b0(fileName, "%sdef_%02d.bin", "data/menu/chrselect/", index);
    if ((raw = *rawSlot = FUN_0004cad0(fileName, 0, 0x10, 1)) != 0) {
      FUN_000143b0(objName, "PreD%02d", index);
      surface = FUN_0004e780(&outA, &outB, 1, 0, 0x40, 0x40);
      prerender = FUN_00000bcc(0x48);
      if (prerender != 0) prerender = FUN_00051050(prerender, objName, surface, 0);
      pixels = FUN_00051450(prerender);
      row = 0;
      do {
        FUN_00011090((char *)pixels + row * ROW_BYTES, (char *)raw + row * ROW_BYTES, ROW_BYTES);
        row++;
      } while (row < PRERENDER_ROWS);
      *objSlot = (int)prerender;
    }
    index++;
    rawSlot++;
    objSlot++;
  } while (index < ENTRY_COUNT);
  FUN_0001cb88(DAT_0030ebf4);
}
