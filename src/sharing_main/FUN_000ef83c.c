/* HSTMATCH module=hstp_trans_main.prx start=0x000ef83c end=0x000ef9c8 symbol=FUN_000ef83c lang=c99 */
/* Clone of src/eboot/FUN_000ea62c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec.h"

#define HISTORY_LEN 0x28 /* records kept in the ring */

/* One record: seven 4-float vectors. */
typedef struct VecRecord {
  Float4 v[7];
} VecRecord;            /* size 0x70 */

/* Ring of the most recent records, written at index head. */
typedef struct VecRing {
  char pad00[0x50];
  VecRecord entries[HISTORY_LEN]; /* 0x50 */
  int head;                       /* 0x11d0 next slot to write */
} VecRing;

/* Store seven vectors into the current ring slot, then advance the head with wrap-around. */
void FUN_000ef83c(VecRing *ring,Float4 *v0,Float4 *v1,Float4 *v2,Float4 *v3, Float4 *v4,Float4 *v5,Float4 *v6)
{
  VecRecord *rec;

  rec = &ring->entries[ring->head];
  rec->v[0].x = v0->x;
  rec->v[0].y = v0->y;
  rec->v[0].z = v0->z;
  rec->v[0].w = v0->w;
  rec = &ring->entries[ring->head];
  rec->v[1].x = v1->x;
  rec->v[1].y = v1->y;
  rec->v[1].z = v1->z;
  rec->v[1].w = v1->w;
  rec = &ring->entries[ring->head];
  rec->v[2].x = v2->x;
  rec->v[2].y = v2->y;
  rec->v[2].z = v2->z;
  rec->v[2].w = v2->w;
  rec = &ring->entries[ring->head];
  rec->v[3].x = v3->x;
  rec->v[3].y = v3->y;
  rec->v[3].z = v3->z;
  rec->v[3].w = v3->w;
  rec = &ring->entries[ring->head];
  rec->v[4].x = v4->x;
  rec->v[4].y = v4->y;
  rec->v[4].z = v4->z;
  rec->v[4].w = v4->w;
  rec = &ring->entries[ring->head];
  rec->v[5].x = v5->x;
  rec->v[5].y = v5->y;
  rec->v[5].z = v5->z;
  rec->v[5].w = v5->w;
  rec = &ring->entries[ring->head];
  rec->v[6].x = v6->x;
  rec->v[6].y = v6->y;
  rec->v[6].z = v6->z;
  rec->v[6].w = v6->w;
  ring->head = ring->head + 1;
  ring->head = ring->head % HISTORY_LEN;
}
