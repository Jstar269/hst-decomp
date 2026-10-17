/* HSTMATCH module=hstp_trans_main.prx start=0x000dba70 end=0x000dbb20 symbol=FUN_000dba70 lang=c99 */
/* Clone of src/eboot/initialize_000d7d80.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: modeled signed -1 fields separately from the unsigned 0xffff fields; exact match verified; names and types await human review. */
typedef struct {
  short low[6];
  char pad0[20];
  unsigned short pair[2];
  char pad1[48];
  unsigned char text0[3];
  char pad2[17];
  unsigned char text1[3];
  char pad3[15];
  short high;
  char pad4[76];
} Data;
extern void *FUN_000114c0(void *, int, int);
extern void FUN_000dbb60(void *);
Data *FUN_000dba70(Data *p) {
  FUN_000114c0(p, 0, 0x9c);
  p->pair[1] = 0xffff;
  p->pair[0] = 0xffff;
  p->low[0] = -1;
  p->low[1] = -1;
  p->low[2] = -1;
  p->low[3] = -1;
  p->low[4] = -1;
  p->low[5] = -1;
  p->high = -1;
  p->text0[0] = 0x2d;
  p->text0[1] = 0x31;
  p->text0[2] = 0;
  p->text1[0] = 0x2d;
  p->text1[1] = 0x31;
  p->text1[2] = 0;
  FUN_000114c0(p, 0, 200);
  p->low[0] = -1;
  p->low[1] = -1;
  p->low[2] = -1;
  p->low[3] = -1;
  p->low[4] = -1;
  p->low[5] = -1;
  FUN_000dbb60(p);
  return p;
}
