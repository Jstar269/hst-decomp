/* HSTMATCH module=EBOOT.BIN start=0x0015c4e0 end=0x0015c854 symbol=FUN_0015c4e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern "C" {
extern char DAT_002de480[];
extern char DAT_002de4a8[];
extern char DAT_002de4c4[];
extern char DAT_002de4dc[];
extern char DAT_002de4f8[];
extern int DAT_0030ebf4;
extern unsigned char DAT_0034179c;
extern int FUN_00000bcc(...);
extern int FUN_00014934(...);
extern void FUN_000143b0(...);
extern void FUN_000149a8(...);
extern void FUN_0001cad0(int *, int, const char *, ...);
extern void FUN_0001cb88(...);
extern undefined4 FUN_00050fc0(...);
extern void FUN_000511c4(...);
extern void FUN_00051398(float, ...);
extern void FUN_0015a62c(...);
extern void FUN_001b3378(...);
}
struct VC { virtual ~VC(); };

static inline void reload(char *param_1, int slot, int sub, int fields)
{
  undefined4 uVar2;

  if (*(int *)(param_1 + slot) != 0) {
    delete (VC *)*(int **)(param_1 + slot);
    *(int *)(param_1 + slot) = 0;
  }
  uVar2 = FUN_00000bcc(0x48);
  if (uVar2 != 0) {
    uVar2 = FUN_00050fc0(uVar2);
  }
  *(undefined4 *)(param_1 + slot) = uVar2;
  FUN_000511c4(uVar2, param_1 + 0x370, 0);
  FUN_00051398(3000.0f, *(undefined4 *)(param_1 + slot));
  FUN_000149a8(param_1 + sub, param_1 + 0x370);
  *(int *)(param_1 + fields) = 0;
  *(int *)(param_1 + fields + 4) = 0;
  *(int *)(param_1 + fields + 8) = 0;
  *(int *)(param_1 + fields + 0xc) = 0x3f800000;
}

extern "C" void FUN_0015c4e0(char *param_1, int param_2)
{
  FUN_000143b0(param_1 + 0x370, DAT_002de480, param_2);
  FUN_0001cad0(&DAT_0030ebf4, 1, param_1 + 0x370);
  if (param_2 == 0) {
    FUN_000143b0(param_1 + 0x370, DAT_002de4a8);
    if (*(int *)(param_1 + 0x34) == 0 || FUN_00014934(param_1 + 0x70, param_1 + 0x370) != 0) {
      reload(param_1, 0x34, 0x70, 0x40);
    }
    FUN_000143b0(param_1 + 0x370, DAT_002de4c4);
    if (*(int *)(param_1 + 0x38) == 0 || FUN_00014934(param_1 + 0x170, param_1 + 0x370) != 0) {
      reload(param_1, 0x38, 0x170, 0x50);
    }
  }
  else {
    FUN_000143b0(param_1 + 0x370, DAT_002de4dc);
    if (*(int *)(param_1 + 0x34) == 0 || FUN_00014934(param_1 + 0x70, param_1 + 0x370) != 0) {
      reload(param_1, 0x34, 0x70, 0x40);
    }
    FUN_000143b0(param_1 + 0x370, DAT_002de4f8);
    if (*(int *)(param_1 + 0x38) == 0 || FUN_00014934(param_1 + 0x170, param_1 + 0x370) != 0) {
      reload(param_1, 0x38, 0x170, 0x50);
    }
    FUN_0015a62c(param_1);
    FUN_001b3378(&DAT_0034179c, 0);
  }
  FUN_0001cb88(&DAT_0030ebf4);
}
