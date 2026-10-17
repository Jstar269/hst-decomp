/* HSTMATCH module=EBOOT.BIN start=0x00279578 end=0x002795dc symbol=FUN_00279578 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained the four-case switch and typed its table as a member array; exact match verified; names and types await human review. */
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

extern char DAT_002fe648[];
extern void FUN_0026f7f4();

typedef struct {
  char pad[0x134];
  undefined4 values[5];
} Obj;

undefined4 FUN_00279578(Obj *param_1,int param_2)
{
  undefined4 result;

  switch (param_2) {
    case 1:
    case 2:
    case 3:
    case 4:
      result = param_1->values[param_2];
      break;
    default:
      FUN_0026f7f4(DAT_002fe648);
      result = 0;
  }
  return result;
}
