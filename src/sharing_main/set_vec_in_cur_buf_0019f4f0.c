/* HSTMATCH module=hstp_trans_main.prx start=0x0019f4f0 end=0x0019f554 symbol=FUN_0019f4f0 lang=c99 */
/* Clone of src/eboot/set_vec_in_cur_buf_00192ce0.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec3 { float x, y, z; };
struct Entry { char pad[0x10]; struct Vec3 v; };
struct Obj { char pad[0x54]; int cur; int pad2[3]; struct Entry *bufs[2]; };

void FUN_0019f4f0(struct Obj *p, int n, struct Vec3 *v)
{
  p->bufs[p->cur][n].v.x = v->x;
  p->bufs[p->cur][n].v.y = v->y;
  p->bufs[p->cur][n].v.z = v->z;
}
