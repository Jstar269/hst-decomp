/* HSTMATCH module=hstp_trans_main.prx start=0x000b515c end=0x000b51e4 symbol=FUN_000b515c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char *DAT_003e19f0;
extern char *DAT_003e95c4;
extern float DAT_003ea528;

typedef struct Obj {
  char pad[0x43c];
  float f43c;
} Obj;

int FUN_000b515c(Obj *param_1)
{
  int mode = *(int *)(DAT_003e19f0 + 0x3c);
  if (mode == 4 || mode == 5 || (mode == 7 && *(unsigned char *)(*(char **)(DAT_003e95c4 + 0x80) + 0x78) == 0)) {
    if (param_1->f43c >= 0.7f * DAT_003ea528) {
      return 1;
    }
  }
  return 0;
}
