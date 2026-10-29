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

typedef struct EntryHolder {
  char pad00[0x830];
  Entry **entries;  /* 0x830 table of entry pointers */
} EntryHolder;

/* Copy src into the index-th entry of the table. */
void FUN_000f6850(EntryHolder *self,int index,Entry *src)
{
  Entry *e = self->entries[index];
  e->pos.x = src->pos.x;
  e->pos.y = src->pos.y;
  e->pos.z = src->pos.z;
  e->rot = src->rot;
  e->a = src->a;
  e->b = src->b;
  e->c = src->c;
}
