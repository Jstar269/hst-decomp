/* HSTMATCH module=EBOOT.BIN start=0x00220238 end=0x00220338 symbol=FUN_00220238 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: typed nested float fields and used a const-reference clamp helper; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fade_pane.h"

extern "C" {
extern u32 DAT_002eff90;
extern float DAT_002f0b4c;
extern float DAT_002f0b7c;
extern float DAT_002f0b80;
extern u8 * DAT_003415a8;
extern float DAT_0034a200;
extern float DAT_0034a204;
extern void FUN_000ffb3c(u32 *, int);
extern void FUN_00103480(FadePane *);
extern void FUN_00220370(FadePane *);
extern u32 FUN_0026f4e4(u8 *);
}

static inline float Clamp_20220238(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

/* Starts the fade (unless the query on the global says otherwise): sets the timer to its start value,
   stores the flag, moves the node to its saved offsets, clamps the alpha and refreshes the colour. */
extern "C" void FUN_00220238(FadePane *self,u8 flag)
{
  u32 query;
  float alpha;
  
  query = FUN_0026f4e4(DAT_003415a8 + 0x80);
  if ((query & 0xff) == 0) {
    self->timer = DAT_002eff90;
    self->unk74 = flag;
    FUN_00220370(self);
    self->node->x = DAT_0034a200;
    self->node->y = DAT_0034a204;
    alpha = Clamp_20220238(DAT_002f0b4c, DAT_002f0b7c, DAT_002f0b80);
    self->node->alpha = alpha;
    FUN_00103480(self);
    FUN_000ffb3c(self->color,self->unk74 != 0 ^ 1);
  }
}
