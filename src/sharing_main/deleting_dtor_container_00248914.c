/* HSTMATCH module=hstp_trans_main.prx start=0x00248914 end=0x00248a0c symbol=FUN_00248914 lang=c99 */
/* Clone of src/eboot/deleting_dtor_container_002387dc.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: unified element pointer in reverse destruction loop, typed buffer delete; exact match verified; names and types await human review. */

typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern void FUN_00000788(void *, void *, int, int);
extern void FUN_00000a00(void *);
extern int FUN_00248a0c(void *);
extern void FUN_00245d30(void);

typedef struct Elem {
    char pad[560];
} Elem;

int * FUN_00248914(int *param_1, short param_2)
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
          FUN_00000788((char *)last + 196, FUN_00245d30, 24, 3);
        }
      } while (first < last);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if (param_1 != 0) {
      FUN_00248a0c(param_1);
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
