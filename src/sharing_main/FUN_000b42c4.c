/* HSTMATCH module=hstp_trans_main.prx start=0x000b42c4 end=0x000b43b0 symbol=FUN_000b42c4 lang=c99 */
/* Clone of src/eboot/FUN_000b12d8.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
extern undefined *DAT_003e19f0;
extern unsigned char *DAT_003e1e84;
extern void FUN_00091d44(void *, float *, float *, float, float, int *, int);
extern void FUN_000cc2a8(void *, int);
extern void FUN_001228c0(int, const float *, int, int);
struct Temps { float local_14[4]; float local_20[4]; int padding[3]; int local_4; };

void FUN_000b42c4(int param_1, const float *param_2)
{
  struct Temps temps;
  float f9;
  float f10;
  int enabled;
  temps.local_20[0] = param_2[0];
  temps.local_20[1] = param_2[1];
  temps.local_20[2] = param_2[2];
  temps.local_20[3] = param_2[3];
  temps.local_14[0] = param_2[4];
  temps.local_14[1] = param_2[5];
  temps.local_14[2] = param_2[6];
  temps.local_14[3] = param_2[7];
  f9 = param_2[9];
  f10 = param_2[10];
  temps.local_4 = *(const int *)((const char *)param_2 + 44);
  FUN_00091d44(*(void **)(DAT_003e19f0 + 0x88), temps.local_20, temps.local_14, f9, f10, &temps.local_4, *(int *)(param_1 + 0x144));
  FUN_000cc2a8(*(void **)(DAT_003e19f0 + 0x90), *(int *)(param_1 + 0x148));
  if (*(int *)(DAT_003e19f0 + 0x3c) != 7) {
    enabled = !!*(unsigned char *)(DAT_003e1e84 + 0x5c);
    FUN_001228c0(*(int *)(DAT_003e19f0 + 0x9c), param_2, enabled ^ 1, 0);
  }
}
