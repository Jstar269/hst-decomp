/* HSTMATCH module=EBOOT.BIN start=0x000612dc end=0x000613ec symbol=FUN_000612dc lang=c99 */
/* Clone of src/sharing_main/copy_float_state_00062160.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct { float x,y,z,w; } Vec4_000612dc;
typedef struct {
  char pad00[0x10];
  Vec4_000612dc f10;
  Vec4_000612dc f20;
  Vec4_000612dc f30;
  Vec4_000612dc f40;
  char pad50[0x30];
  Vec4_000612dc f80;
} Dest_000612dc;
typedef struct {
  char pad00[0x1d0];
  Vec4_000612dc f1d0;
  Vec4_000612dc f1e0;
  Vec4_000612dc f1f0;
  Vec4_000612dc f200;
} Src_000612dc;
extern Src_000612dc *DAT_003313c4;
extern void FUN_000224f8(Vec4_000612dc *,Vec4_000612dc *,Vec4_000612dc *);
extern void FUN_00022518(Vec4_000612dc *,Vec4_000612dc *);
void FUN_000612dc(Dest_000612dc *dst,Src_000612dc *src)
{
  if (src == 0) src = DAT_003313c4;
  dst->f40.x = src->f1d0.x;
  dst->f40.y = src->f1d0.y;
  dst->f40.z = src->f1d0.z;
  dst->f40.w = src->f1d0.w;
  dst->f30.x = src->f1e0.x;
  dst->f30.y = src->f1e0.y;
  dst->f30.z = src->f1e0.z;
  dst->f30.w = src->f1e0.w;
  dst->f20.x = src->f1f0.x;
  dst->f20.y = src->f1f0.y;
  dst->f20.z = src->f1f0.z;
  dst->f20.w = src->f1f0.w;
  FUN_00022518(&dst->f30,&dst->f30);
  ((uint *)&dst->f30)[3] = 0;
  FUN_000224f8(&dst->f10,&dst->f20,&dst->f30);
  FUN_00022518(&dst->f10,&dst->f10);
  ((uint *)&dst->f10)[3] = 0;
  FUN_000224f8(&dst->f20,&dst->f30,&dst->f10);
  dst->f40.x = dst->f40.x;
  dst->f40.y = dst->f40.y;
  dst->f40.z = dst->f40.z;
  dst->f40.w = dst->f40.w;
  dst->f80.x = src->f200.x;
  dst->f80.y = src->f200.y;
  dst->f80.z = src->f200.z;
}
