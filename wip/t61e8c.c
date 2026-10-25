/* HSTMATCH module=EBOOT.BIN start=0x00061e8c end=0x00062124 symbol=FUN_00061e8c lang=c99 */
typedef unsigned int u32;
extern char DAT_00331878; extern u32 DAT_0033187c; extern float DAT_00331880;
extern int DAT_002d1058, DAT_002d105c, DAT_002d1060, DAT_002d1064, DAT_002d1068;
extern int DAT_002d106c, DAT_002d1070, DAT_002d1074, DAT_002d1078;
extern int FUN_002b7c18(); extern int FUN_00062124(); extern int FUN_0000ef40();
extern int FUN_00070390(); extern int FUN_000703a0(); extern int FUN_000703b0();
extern int FUN_0006fd04(); extern int FUN_00078bf4(); extern int FUN_000790d0();
extern int FUN_000868ec(); extern int FUN_000869c0(); extern int FUN_00086a20();
extern int FUN_000104b0(); extern int FUN_000104e0();
extern char DAT_002d107c[], DAT_002d10a4[], DAT_002d10c8[], DAT_002d10f4[], DAT_002d1154[];
void FUN_00061e8c(void)
{
  int i, k;
  float *p;
  if (DAT_00331878 != 0) return;
  if (FUN_002b7c18(0x300) < 0) { FUN_00062124(DAT_002d107c); FUN_0000ef40(1); }
  if (FUN_002b7c18(0x301) < 0) { FUN_00062124(DAT_002d10a4); FUN_0000ef40(1); }
  if (FUN_002b7c18(0x302) < 0) { FUN_00062124(DAT_002d10c8); FUN_0000ef40(1); }
  FUN_00070390(FUN_000104b0);
  FUN_000703a0(FUN_000104e0);
  FUN_000703b0(&DAT_002d107c);
  if (FUN_0006fd04(DAT_002d10f4) == 0) { FUN_00062124(DAT_002d1154); FUN_0000ef40(1); }
  DAT_00331878 = 1;
  FUN_00078bf4(DAT_002d1058, DAT_002d1058);
  FUN_000790d0(3, DAT_002d105c, DAT_002d105c);
  FUN_000790d0(2, DAT_002d1060, DAT_002d1060);
  FUN_000790d0(4, DAT_002d1064, DAT_002d1064);
  FUN_000790d0(9, DAT_002d1068, DAT_002d1068);
  i = 0; p = &DAT_00331880;
  do {
    for (k = 0; k < 8; k++) {
      p[0] = 1.0f; p[1] = 1.0f; p[2] = 1.0f; p[3] = 1.0f; p[4] = 0.0f; p[5] = 0.0f;
      p += 6;
    }
    i += 8;
  } while (i < 0x20);
  FUN_000868ec(DAT_0033187c, DAT_002d106c);
  FUN_000869c0(DAT_0033187c, DAT_002d1070, DAT_002d1070);
  FUN_00086a20(DAT_0033187c, 0, DAT_002d1074);
  FUN_00086a20(DAT_0033187c, 1, DAT_002d1078);
}
// near miss from lane fm11 (unreviewed)
