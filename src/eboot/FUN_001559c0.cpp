/* HSTMATCH module=EBOOT.BIN start=0x001559c0 end=0x00155a9c symbol=FUN_001559c0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: modeled the receiver as a virtual object, restored the float input and (float, int) method signature, and used the context pointer for +8 reads; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003402f0;
extern int DAT_0034a114;
extern char DAT_002dcb4c[];
extern unsigned char DAT_003083cc;
extern unsigned char DAT_003085bc;
void *FUN_00000bcc(int);
void FUN_0014d044(int);
void FUN_0014fd94(char *, int);
void FUN_001cc354(int, int);
}
struct Allocated {
  virtual ~Allocated();
  virtual int Run(float, int);
};

extern "C" int *FUN_001559c0(int *param_1, float param_3, int param_2)
{
  Allocated *p;
  int result;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dcb4c, param_1[2]);
  }
  FUN_001cc354(DAT_0034a114, param_1[2]);
  if ((p = (Allocated *)FUN_00000bcc(4)) != 0) {
    *(void **)p = &DAT_003083cc;
    *(void **)p = &DAT_003085bc;
  }
  result = p->Run(param_3, param_2);
  if (result != 0) {
    if (p != 0) {
      delete p;
    }
    return 0;
  }
  return (int *)p;}
