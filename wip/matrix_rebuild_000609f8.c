/* HSTMATCH module=EBOOT.BIN start=0x000609f8 end=0x00060bb8 symbol=FUN_000609f8 lang=c99 */
typedef struct { float x, y, z, w; } Vec4;

typedef struct {
    char pad[0x10];
    Vec4 rows[4];   /* 0x10 */
    float f50;      /* 0x50 */
    char pad2[0xc];
    Vec4 v60;       /* 0x60 */
    float f70;      /* 0x70 */
} Obj;

extern void FUN_00022434(Vec4 *, Vec4 *, Vec4 *);
extern void FUN_00060bb8(float, Vec4 *, Vec4 *);
extern void FUN_00022518(Vec4 *, Vec4 *);
extern void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
extern float FUN_000224d8(Vec4 *, Vec4 *);
extern float FUN_00022e44(float);

void FUN_000609f8(Obj *self)
{
    Vec4 v10, v20, v30, v40, v50, v60, v70, v80;

    FUN_00022434(&v80, &self->v60, &self->rows[3]);
    v20.x = v80.x;
    v20.y = v80.y;
    v20.z = v80.z;
    v20.w = 0.0f;
    FUN_00060bb8(self->f70, &v50, &v20);
    v30.x = v50.x;
    v30.y = v50.y;
    v30.z = v50.z;
    v30.w = 0.0f;
    FUN_00022518(&v20, &v20);
    FUN_000224f8(&v40, &v30, &v20);
    v40.w = 0.0f;
    FUN_00022518(&v40, &v40);
    FUN_000224f8(&v30, &v20, &v40);
    v10.x = self->rows[3].x;
    v10.y = self->rows[3].y;
    v10.z = self->rows[3].z;
    v10.w = 1.0f;
    self->rows[0] = v40;
    self->rows[1] = v30;
    self->rows[2] = v20;
    self->rows[3] = v10;
    FUN_00022434(&v70, &self->v60, &self->rows[3]);
    v60 = v70;
    self->f50 = FUN_00022e44(FUN_000224d8(&v60, &v60));
}
// 0x000609f8: 103/112 words, 77 differ. Structure: 8 Vec4 stack temps (declaration order is
// REVERSED vs stack address: last-declared v10 sits at sp+128, first-declared v80 at sp+16),
// cross(v60,row3) -> v20 with w=0, scale by f70 -> v30 (w=0), normalize v20, cross v30 x v20
// -> v40 (w=0), normalize v40, cross v20 x v40 -> v30, rebuild rows[0..3] = v40,v30,v20,
// (row3.xyz,1.0) then cross again and f50 = Length(v70). Helpers 0x22434 cross, 0x224f8 cross,
// 0x22518 normalize, 0x224d8 len, 0x22e44, 0x60bb8 scale(float,out,in) all take Vec4*.
// Remainder: retail has an extra self-copy of the 4th temp (sp+128 -> sp+128) and a different
// store schedule; ours keeps 4 FPRs live across the row stores. Arg-setup order (a0,a1,a2 then
// jal vs ours a0,a1,jal,a2) also differs.
// near miss from lane fm11 (unreviewed)
