/* HSTMATCH module=EBOOT.BIN start=0x000d3298 end=0x000d3414 symbol=FUN_000d3298 lang=c99 */
/* Fresh reconstruction from the disassembly; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern undefined4 DAT_00307484;
extern undefined4 DAT_00056cb0;
extern void FUN_00000788(int,int,int,int);
extern void FUN_00000a00(int);
extern void FUN_0001f0f0(int,int);
extern void FUN_00053718(int,int);
extern void FUN_00055e48(int,int);
extern void FUN_0006eb04(int,int);
extern void FUN_000d564c(int,int);
extern void FUN_000d5730(int,int);

int *FUN_000d3298(int *param_1,int param_2)
{
  int *it;
  int *el;
  int end;
  unsigned int more;

  if (param_1 != 0) {
    param_1[0] = (int)&DAT_00307484;
    it = (int *)param_1[0xf];
    end = param_1[0xf] + param_1[0x10] * 4;
    more = (((unsigned int)((int)it ^ end) < 1) ^ 1);
    if (more != 0) {
      el = (int *)*it;
      while (1) {
        if (el != 0) {
          if (param_1[0x10] != 0) {
            *it = 0;
            (*(void (**)(int *,int))(*el + 8))(el,1);
          }
          *it = 0;
        }
        it = it + 1;
        end = param_1[0xf] + param_1[0x10] * 4;
        more = (((unsigned int)((int)it ^ end) < 1) ^ 1);
        if (more == 0) {
          break;
        }
        el = (int *)*it;
      }
    }
    param_1[0x10] = param_1[0x10] - *(int *)it;
    FUN_000d564c((int)(param_1 + 0x12),param_1[0x13]);
    if (param_1[0x1e9] != 0) {
      FUN_00053718(param_1[0x1e9],1);
      param_1[0x1e9] = 0;
    }
    if (param_1[0x1ea] != 0) {
      FUN_00055e48(param_1[0x1ea],1);
      param_1[0x1ea] = 0;
    }
    FUN_00000788((int)(param_1 + 0x38),(int)&DAT_00056cb0,0x1b0,4);
    if (param_1 + 0x12 != 0) {
      FUN_000d5730((int)(param_1 + 0x12),0);
    }
    if (param_1 + 0xf != 0) {
      FUN_0006eb04((int)(param_1 + 0xf),0);
    }
    FUN_0001f0f0((int)param_1,0);
    if (0 < (short)param_2) {
      FUN_00000a00((int)param_1);
    }
  }
  return param_1;
}
// parked: 95/95 62 differ; retail frame 32 vs ours 16 (an extra saved register) and p[0x10] lands in a0 vs our a1 (sll v0). Expression-order/declaration changes tried before; needs the caller/class layout to pin the missing local.
// near miss from lane dsn3 (unreviewed)
