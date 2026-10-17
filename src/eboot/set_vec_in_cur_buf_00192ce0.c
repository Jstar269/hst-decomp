/* HSTMATCH module=EBOOT.BIN start=0x00192ce0 end=0x00192d44 symbol=FUN_00192ce0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec3 { float x, y, z; };
struct Entry { char pad[0x10]; struct Vec3 v; };
struct Obj { char pad[0x54]; int cur; int pad2[3]; struct Entry *bufs[2]; };

void FUN_00192ce0(struct Obj *p, int n, struct Vec3 *v)
{
  p->bufs[p->cur][n].v.x = v->x;
  p->bufs[p->cur][n].v.y = v->y;
  p->bufs[p->cur][n].v.z = v->z;
}
