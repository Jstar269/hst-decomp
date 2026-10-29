/* HSTMATCH module=hstp_trans_main.prx start=0x0022a5fc end=0x0022a73c symbol=FUN_0022a5fc lang=c++ */
/* Clone of src/eboot/FUN_0021b088.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Fresh reconstruction from the disassembly, byte-exact on the first install in the lane since pass 32.
   Two statements through the p->q pointer, each re-reading it, is what reproduces the double 100(s2) load
   and puts the zero store in the beqz delay; the float is assigned in the conditional and stored
   unconditionally before the call so it is not live across FUN_00108dac (a live float costs the frame).
   Names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern "C" {
extern undefined4 DAT_003983a0;
extern void FUN_00105470(undefined4,int);
extern void FUN_00108dac(int);
extern void FUN_00113a50(int);
extern undefined4 *FUN_0020d1e0(int,int,int);
extern void FUN_0022a73c(int);
}

extern "C" void FUN_0022a5fc(int param_1,int param_2,int param_3,int param_4)
{
  int *p = (int *)param_1;
  int *q;
  int v;
  int g;
  float f;
  unsigned int b0;
  unsigned int b1;

  b0 = 1;
  if (p[0x54 / 4] == param_2 - 1 && param_4 == 0) {
    b0 = 0;
  }
  b1 = 1;
  if (p[0x58 / 4] == param_3 - 1 && param_4 == 0) {
    b1 = 0;
  }
  p[0x54 / 4] = param_2 - 1;
  p[0x58 / 4] = param_3 - 1;
  FUN_0022a73c(param_1);
  g = DAT_003983a0;
  v = g + p[0x54 / 4];
  q = (int *)p[0x68 / 4];
  q[0x24 / 4] = v;
  q[0x28 / 4] = v;
  v = (int)FUN_0020d1e0(6,p[0x54 / 4] + 1,p[0x58 / 4] + 1);
  q = (int *)p[0x78 / 4];
  q[0xf8 / 4] = v;
  q[0x138 / 4] = 1;
  FUN_00113a50((int)q);
  b0 = (unsigned char)((b0 != 0) ^ 1);
  p[0x8c / 4] = 150;
  FUN_00105470(p[0x68 / 4],b0);
  FUN_00105470(p[0x70 / 4],b0);
  b1 = (unsigned char)((b1 != 0) ^ 1);
  FUN_00105470(p[0x6c / 4],b1);
  FUN_00105470(p[0x74 / 4],b1);
  ((int *)p[0x64 / 4])[0x60 / 4] = 0;
  f = 0.0f;
  if (b0 != 0) {
    f = -16.0f;
  }
  ((float *)p[0x64 / 4])[0x64 / 4] = f;
  FUN_00108dac(param_1);
  return;
}
