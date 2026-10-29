/* HSTMATCH module=hstp_trans_main.prx start=0x00172c08 end=0x00172cb8 symbol=FUN_00172c08 lang=c99 */
/* Clone of src/eboot/FUN_00166a44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Reset the block: points at the origin (w = 1), everything else zero, the two flag bytes set. */
void FUN_00172c08(VecBlock *blk)
{
  blk->v00.x = 0;
  blk->v00.y = 0;
  blk->v00.z = 0;
  blk->v00.w = 1.0f;
  blk->v10.x = 0;
  blk->v10.y = 0;
  blk->v10.z = 0;
  blk->v10.w = 1.0f;
  blk->v20.x = 0;
  blk->v20.y = 0;
  blk->v20.z = 0;
  blk->v20.w = 1.0f;
  blk->unk30 = 0;
  blk->unk34 = 0;
  blk->unk38 = 0;
  blk->unk3c = 0;
  blk->unk40[0] = 0;
  blk->unk40[1] = 0;
  blk->unk40[2] = 0;
  blk->unk40[3] = 0;
  blk->unk50[0] = 0;
  blk->unk50[1] = 0;
  blk->unk50[2] = 0;
  blk->unk50[3] = 0;
  blk->unk60 = 0;
  blk->unk64 = 1;
  blk->unk65 = 1;
  blk->v70.x = 0;
  blk->v70.y = 0;
  blk->v70.z = 0;
  blk->v70.w = 1.0f;
  blk->v80.x = 0;
  blk->v80.y = 0;
  blk->v80.z = 0;
  blk->v80.w = 1.0f;
  blk->unk90[0] = 0;
  blk->unk90[1] = 0;
  blk->unk90[2] = 0;
  blk->unk90[3] = 0;
  blk->unk90[4] = 0;
  blk->unk90[5] = 0;
}
