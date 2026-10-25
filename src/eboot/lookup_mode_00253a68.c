/* HSTMATCH module=EBOOT.BIN start=0x00253a68 end=0x00253afc symbol=FUN_00253a68 lang=c99 helpers=FUN_0018c9f4@0x0018c9f4-0x0018ca94 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: volatile offset read preserves the helper-returned base in v0 until the first indexed field load. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_002cc560;
extern undefined DAT_002ca6c0;
extern undefined DAT_002ca6c4;
extern undefined * DAT_003415b0;
extern char DAT_003415b4;
extern char DAT_003415b8[];
typedef struct T { char c; int i; } T;
extern T DAT_003415c4;
extern undefined4 FUN_00000f74();
extern undefined4 FUN_0010ad1c();
extern void FUN_000fcb7c();

static undefined1 * FUN_0018c9f4(int param_1)
{
  undefined1 *puVar1;
  
  if ((DAT_003415b0 == 0) && (param_1 == 0x10)) {
    if (DAT_003415b4 == 0) {
      DAT_003415c4.c = 0;
      DAT_003415c4.i = 0;
      FUN_00000f74(&DAT_003415c4,FUN_000fcb7c,DAT_003415b8);
      DAT_003415b4 = 1;
    }
    FUN_0010ad1c(&DAT_003415c4,&DAT_002cc560);
    puVar1 = (unsigned char *)(&DAT_003415c4);
  }
  else {
    puVar1 = (undefined1 *)(DAT_003415b0 + param_1 * 0x10);
  }
  return puVar1;
}

int FUN_00253a68(int param_1)
{
  int *entry = (int *)(&DAT_002ca6c0 + param_1 * 8);
  undefined1 *base = FUN_0018c9f4(entry[0]);
  int first = *(volatile int *)(base + 12);
  int count = *(int *)(&DAT_002ca6c4 + param_1 * 8);
  int row_offset = count * 12;
  row_offset += first;
  int value = *(int *)(row_offset + 4);

  switch (param_1) {
  case 2:
  case 5:
  case 6:
    break;
  default:
    return value;
  }
  return value - 1;
}
