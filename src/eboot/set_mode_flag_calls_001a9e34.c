/* HSTMATCH module=EBOOT.BIN start=0x001a9e34 end=0x001a9f74 symbol=FUN_001a9e34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: Ghidra's goto structure rewritten as nested if/else (A != 0 && B == 0 outer, C == 0 && D != 0 inner, three call-pair copies), byte flags unsigned char; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int undefined4;

extern undefined4 DAT_00338ac4;
extern void FUN_000ffb3c();
extern void FUN_00103628();
extern void FUN_0010b6d4();
extern int FUN_0019d474();
extern void FUN_001a9f74();
extern void FUN_001aa1cc();
extern void FUN_001aa208();
extern void FUN_001aa244();
extern void FUN_001aa2a4();
extern void FUN_001aa450();
extern void FUN_001aa558();
extern void FUN_001aa770();

void FUN_001a9e34(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_0019d474();
  FUN_0010b6d4(param_1[0xff],0,2);
  FUN_00103628(*param_1,0);
  puVar4 = param_1 + 0x17;
  puVar3 = param_1 + 0x1c;
  if (*(uchar *)(FUN_0019d474() + 0x2a4) != 0 && *(uchar *)(FUN_0019d474() + 0x4d) == 0) {
    if (*(uchar *)(DAT_00338ac4 + 0x178) == 0 && *(uchar *)(FUN_0019d474() + 0x2b8) != 0) {
      FUN_000ffb3c(*puVar4,1);
      FUN_000ffb3c(*puVar3,1);
    }
    else {
      FUN_000ffb3c(*puVar4,0);
      FUN_000ffb3c(*puVar3,0);
    }
  }
  else {
    FUN_000ffb3c(*puVar4,1);
    FUN_000ffb3c(*puVar3,1);
  }
  FUN_001a9f74(param_1);
  FUN_001aa1cc(param_1);
  FUN_001aa208(param_1);
  FUN_001aa558(param_1);
  FUN_001aa244(param_1);
  FUN_001aa2a4(param_1);
  FUN_001aa450(param_1);
  FUN_001aa770(param_1);
  return;
}
