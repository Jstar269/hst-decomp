/* HSTMATCH module=hstp_trans_main.prx start=0x0008ede8 end=0x0008ee64 symbol=FUN_0008ede8 lang=c99 */
/* Clone of src/eboot/init_defaults_0008d650.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_000114c0(void *, int, int);
typedef struct Header {
  char pad[0x20];
  unsigned short first;
  unsigned short second;
} Header;
void *FUN_0008ede8(void *param_1)
{
  Header *h = (Header *)param_1;
  short *p = (short *)param_1;
  FUN_000114c0(param_1, 0, 0x9c);
  h->second = 0xffff;
  h->first = 0xffff;
  p[0] = -1;
  p[1] = -1;
  p[2] = -1;
  p[3] = -1;
  p[4] = -1;
  p[5] = -1;
  p[0x3d] = -1;
  *(unsigned char *)((char *)param_1 + 0x54) = 45;
  *(unsigned char *)((char *)param_1 + 0x55) = 49;
  *(unsigned char *)((char *)param_1 + 0x56) = 0;
  *(unsigned char *)((char *)param_1 + 0x68) = 45;
  *(unsigned char *)((char *)param_1 + 0x69) = 49;
  *(unsigned char *)((char *)param_1 + 0x6a) = 0;
  return param_1;
}
