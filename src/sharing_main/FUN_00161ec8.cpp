/* HSTMATCH module=hstp_trans_main.prx start=0x00161ec8 end=0x00161fa4 symbol=FUN_00161ec8 lang=c++ data=0x00384034 */
/* Clone of src/eboot/FUN_001559c0.cpp (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00384034-0x00384045) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: modeled the receiver as a virtual object, restored the float input and (float, int) method signature, and used the context pointer for +8 reads; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003e9630;
extern int DAT_003f344c;
extern unsigned char DAT_003b1698;
extern unsigned char DAT_003b1888;
void *FUN_00000bcc(int);
void FUN_00158b2c(int);
void FUN_0015bb68(char *, int);
void FUN_001daa88(int, int);
}
struct Allocated {
  virtual ~Allocated();
  virtual int Run(float, int);
};

extern "C" int *FUN_00161ec8(int *param_1, float param_3, int param_2)
{
  Allocated *p;
  int result;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68("AppealText [%d]\n", param_1[2]);
  }
  FUN_001daa88(DAT_003f344c, param_1[2]);
  if ((p = (Allocated *)FUN_00000bcc(4)) != 0) {
    *(void **)p = &DAT_003b1698;
    *(void **)p = &DAT_003b1888;
  }
  result = p->Run(param_3, param_2);
  if (result != 0) {
    if (p != 0) {
      delete p;
    }
    return 0;
  }
  return (int *)p;}
