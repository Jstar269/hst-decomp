/* HSTMATCH module=EBOOT.BIN start=0x0026ea04 end=0x0026ee0c symbol=FUN_0026ea04 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_001039d8(), FUN_001026b8(), FUN_000ffb3c(), FUN_0021dc84();
extern int FUN_001b1c44(), FUN_001b1f7c(), FUN_001b413c(), FUN_0026d5fc();
extern char DAT_002fe240[], DAT_002fe274[], DAT_002fe280[], DAT_002fe28c[];
extern char DAT_002fe298[], DAT_002fe2a4[], DAT_002fe24c[];
extern int DAT_0034b590; extern int DAT_0034179c;
#define K(s, v) FUN_000ffb3c(FUN_001026b8(FUN_001039d8(p + 0x3c, DAT_002fe240, 0), s), v)
void FUN_0026ea04(int p)
{
  int i4, i5, flag;
  char c;
  if (*(int *)(p + 0xa38) == 0) {
    K(DAT_002fe274, 1); K(DAT_002fe280, 1); K(DAT_002fe28c, 1);
    K(DAT_002fe298, 1); K(DAT_002fe2a4, 1); K(DAT_002fe24c, 1);
    (*(void (**)(int, int))(**(int **)(p + 0x474) + 0xc))(*(int *)(p + 0x474), 1);
    i5 = 0; i4 = p;
    do {
      FUN_000ffb3c(*(u32 *)(i4 + 0x4b8), 1);
      FUN_000ffb3c(*(u32 *)(i4 + 0x4bc), 1);
      i5++; i4 += 0x10;
    } while (i5 < 0xc);
  }
  i4 = FUN_0021dc84(*(u32 *)(p + 0xa3c));
  if (i4 == 0) {
    i4 = *(int *)(p + 0xa3c);
  } else {
    *(u8 *)(p + 0xa14) = 0;
    FUN_001b1c44(0x34179c, 3);
    K(DAT_002fe274, 0); K(DAT_002fe280, 1); K(DAT_002fe28c, 0);
    K(DAT_002fe298, 1); K(DAT_002fe2a4, 0); K(DAT_002fe24c, 0);
    (*(void (**)(int, int))(**(int **)(p + 0x474) + 0xc))(*(int *)(p + 0x474), 0);
    i4 = *(int *)(p + 0xa3c);
  }
  flag = 0;
  if (*(int *)(*(int *)(i4 + 0x16c) + 0x6c) != -1) flag = FUN_001b1f7c(0x34179c) != 0;
  if (flag && *(char *)(p + 0xa41) == 0) {
    FUN_001b413c(0x3e8c0000, 0x3dcccccd, 0x34179c);
    *(u8 *)(p + 0xa41) = 1;
  } else if (!flag && *(char *)(p + 0xa41) != 0) {
    FUN_001b413c(0x3f800000, 0x3e99999a, 0x34179c);
    *(u8 *)(p + 0xa41) = 0;
  }
  *(int *)(p + 0xa38) = *(int *)(p + 0xa38) + 1;
  if (*(char *)(p + 0xa14) == 0) {
    if (DAT_0034b590 == 0) {
      FUN_0026d5fc(p, *(u32 *)(p + 0x108));
      *(u8 *)(p + 0x8cc) = 1;
    } else {
      FUN_0026d5fc(p, *(u32 *)(p + 0x108));
      *(u8 *)(p + 0x8cc) = 1;
      FUN_0026d5fc(p, 6);
    }
  }
}
// near miss from lane fm11 (unreviewed)
