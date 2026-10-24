/* HSTMATCH module=EBOOT.BIN start=0x00299e08 end=0x00299e94 symbol=FUN_00299e08__FPviPv lang=c99 */
extern void FUN_00299af0(void *ctx, void *data, int len);
extern void FUN_00299c74(void *ctx, void *out);

typedef struct {
  unsigned int state[4];
  unsigned int unk16;
  unsigned short h20;
  unsigned short h22;
  unsigned int w24;
  unsigned int w28;
  unsigned char buf[64];
} Ctx;

int FUN_00299e08(void *param_1, int param_2, void *param_3)
{
  Ctx ctx;
  ctx.state[0] = 0x67452301;
  ctx.w24 = 0;
  ctx.w28 = 0;
  ctx.state[1] = 0xefcdab89;
  ctx.state[2] = 0x98badcfe;
  ctx.state[3] = 0x10325476;
  ctx.h20 = 0;
  ctx.h22 = 0;
  FUN_00299af0(&ctx, param_1, param_2);
  FUN_00299c74(&ctx, param_3);
  return 0;
}
// near miss: 33/35 words; frame size right (112) and all eight stores/constants right, but MWCC puts the
// 96-byte address-taken context at sp+16 (saved regs at 8/12) while retail has it at sp+0 with the saved
// regs at 96/100. Ruled out: byte array, typed struct, int[24], byte-indexed stores, aligned(16).
// near miss from lane ds4 (unreviewed)
// improved by lane fm10 (unreviewed): no comparable result -> 34 differing words
