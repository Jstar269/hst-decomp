/* HSTMATCH module=EBOOT.BIN start=0x000c7894 end=0x000c7928 symbol=FUN_000c7894 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;

extern int DAT_003386cc;
extern undefined DAT_00338b04;
extern void FUN_0005c780(int, float *);
extern void FUN_0005c810(int, int, float *);

void FUN_000c7894(void)
{
  float local_10[4];
  float local_20[4];

  if (DAT_00338b04 != 0) {
    local_10[0] = 1.0f;
    local_10[3] = 1.0f;
    local_10[1] = 0.55f;
    local_10[2] = 0.75f;
    FUN_0005c780(DAT_003386cc, local_10);
    local_20[0] = 0.4f;
    local_20[1] = 0.2f;
    local_20[2] = 0.3f;
    local_20[3] = 1.0f;
    FUN_0005c810(DAT_003386cc, 0, local_20);
  }
}
