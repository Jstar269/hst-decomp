/* HSTMATCH module=EBOOT.BIN start=0x002387dc end=0x002388d4 symbol=FUN_002387dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: unified element pointer in reverse destruction loop, typed buffer delete; exact match verified; names and types await human review. */

typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern void FUN_00000788(void *, void *, int, int);
extern void FUN_00000a00(void *);
extern int FUN_002388d4(void *);
extern void FUN_00235c04(void);

typedef struct Elem {
    char pad[560];
} Elem;

int * FUN_002387dc(int *param_1, short param_2)
{
  Elem *first;
  Elem *last;
  
  if (param_1 != (int *)0) {
    first = (Elem *)(*param_1 + param_1[4] * 560);
    last = (Elem *)((char *)first + param_1[1] * 560);
    if (first < last) {
      do {
        --last;
        if (last != 0) {
          FUN_00000788((char *)last + 196, FUN_00235c04, 24, 3);
        }
      } while (first < last);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if (param_1 != 0) {
      FUN_002388d4(param_1);
      if ((void *)*param_1 != 0) {
        FUN_00000a00((void *)*param_1);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
