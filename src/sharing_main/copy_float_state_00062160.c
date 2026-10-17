/* HSTMATCH module=hstp_trans_main.prx start=0x00062160 end=0x00062270 symbol=FUN_00062160 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct { float x,y,z,w; } Vec4_00062160;
typedef struct {
  char pad00[0x10];
  Vec4_00062160 f10;
  Vec4_00062160 f20;
  Vec4_00062160 f30;
  Vec4_00062160 f40;
  char pad50[0x30];
  Vec4_00062160 f80;
} Dest_00062160;
typedef struct {
  char pad00[0x1d0];
  Vec4_00062160 f1d0;
  Vec4_00062160 f1e0;
  Vec4_00062160 f1f0;
  Vec4_00062160 f200;
} Src_00062160;
extern Src_00062160 *DAT_003da704;
extern void FUN_00022520(Vec4_00062160 *,Vec4_00062160 *,Vec4_00062160 *);
extern void FUN_00022540(Vec4_00062160 *,Vec4_00062160 *);
void FUN_00062160(Dest_00062160 *dst,Src_00062160 *src)
{
  if (src == 0) src = DAT_003da704;
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
  FUN_00022540(&dst->f30,&dst->f30);
  ((uint *)&dst->f30)[3] = 0;
  FUN_00022520(&dst->f10,&dst->f20,&dst->f30);
  FUN_00022540(&dst->f10,&dst->f10);
  ((uint *)&dst->f10)[3] = 0;
  FUN_00022520(&dst->f20,&dst->f30,&dst->f10);
  dst->f40.x = dst->f40.x;
  dst->f40.y = dst->f40.y;
  dst->f40.z = dst->f40.z;
  dst->f40.w = dst->f40.w;
  dst->f80.x = src->f200.x;
  dst->f80.y = src->f200.y;
  dst->f80.z = src->f200.z;
}
