/* HSTMATCH module=EBOOT.BIN start=0x0012e924 end=0x0012ea0c symbol=FUN_0012e924 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the unused first parameter is an int (the generator's float-typed undefined4 moved the other parameter to a0); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Source: a 4x4 matrix (rows at 0x00..0x30) followed by the lens values. */
typedef struct CameraSrc {
  float row0[4];              /* 0x00 */
  float row1[4];              /* 0x10 */
  float row2[4];              /* 0x20 */
  float row3[4];              /* 0x30 */
  float fov;                  /* 0x40 field of view in degrees */
  float unk44;                /* 0x44 */
  float unk48;                /* 0x48 */
} CameraSrc;

/* Destination: the global camera, which keeps three matrix rows and the lens values. */
typedef struct CameraDst {
  char pad000[0x1d0];
  float row3[4];              /* 0x1d0 */
  float row2[4];              /* 0x1e0 */
  float row1[4];              /* 0x1f0 */
  float fov;                  /* 0x200 */
  float unk204;               /* 0x204 */
  float unk208;               /* 0x208 */
  char pad20c[8];
  float half_fov_value;       /* 0x214 function of half the field of view in radians */
} CameraDst;

extern CameraDst *DAT_003313c4;
extern float FUN_0000c000(float angle);

/* Copies rows 1..3 and the lens values of the matrix into the global camera. */
void FUN_0012e924(int unused,CameraSrc *src)
{
  CameraDst *cam;
  float fov;
  float half_fov_value;
  
  cam = DAT_003313c4;
  DAT_003313c4->row3[0] = src->row3[0];
  cam->row3[1] = src->row3[1];
  cam->row3[2] = src->row3[2];
  cam->row3[3] = src->row3[3];
  cam = DAT_003313c4;
  DAT_003313c4->row2[0] = src->row2[0];
  cam->row2[1] = src->row2[1];
  cam->row2[2] = src->row2[2];
  cam->row2[3] = src->row2[3];
  cam = DAT_003313c4;
  DAT_003313c4->row1[0] = src->row1[0];
  cam->row1[1] = src->row1[1];
  cam->row1[2] = src->row1[2];
  cam->row1[3] = src->row1[3];
  cam = DAT_003313c4;
  fov = src->fov;
  DAT_003313c4->fov = fov;
  half_fov_value = FUN_0000c000(fov * 0.008726646f);
  cam->half_fov_value = half_fov_value;
  DAT_003313c4->unk204 = src->unk44;
  DAT_003313c4->unk208 = src->unk48;
  return;
}
