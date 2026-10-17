/* HSTMATCH module=EBOOT.BIN start=0x000f6850 end=0x000f68b4 symbol=FUN_000f6850 lang=c99 */
/* Hand-written reconstruction from the disassembly (entry copy: position by field, rotation as a struct); exact match verified; names and types await human review. */
typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
  Vec3 pos;
  int pad;
  Vec4 rot;
  int a;
  int b;
  unsigned char c;
} Entry;

void FUN_000f6850(int param_1,int param_2,Entry *param_3)
{
  Entry *e = (*(Entry ***)(param_1 + 0x830))[param_2];
  e->pos.x = param_3->pos.x;
  e->pos.y = param_3->pos.y;
  e->pos.z = param_3->pos.z;
  e->rot = param_3->rot;
  e->a = param_3->a;
  e->b = param_3->b;
  e->c = param_3->c;
}
