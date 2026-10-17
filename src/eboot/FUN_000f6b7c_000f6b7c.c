/* HSTMATCH module=EBOOT.BIN start=0x000f6b7c end=0x000f6c48 symbol=FUN_000f6b7c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern uint FUN_0001342c();

void FUN_000f6b7c(int param_1)
{
  uint index = 0;
  char *entry = (char *)param_1;
  do {
    if (*(unsigned char *)(entry + 0x30) != 0) {
      int count = *(int *)(entry + 0x60);
      if (count > 0) {
        count = count - 1;
        *(int *)(entry + 0x60) = count;
        if (*(unsigned char *)(entry + 0x30) != 0) {
          float value = *(float *)(*(int *)(*(int *)(param_1 + 0x830) +
                                      *(int *)(entry + 0x34) * 4) + 8);
          if (value > 0.0f) {
            count = *(int *)(entry + 0x60);
            if (count % 2 == 0) {
              *(int *)(entry + 0x68) = FUN_0001342c();
            }
          }
        }
      } else {
        *(unsigned char *)(entry + 0x30) = 0;
      }
    }
    index = index + 1;
    entry = entry + 0x40;
  } while (index < 0x20);
}
