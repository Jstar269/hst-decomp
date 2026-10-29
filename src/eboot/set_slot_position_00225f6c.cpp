/* HSTMATCH module=EBOOT.BIN start=0x00225f6c end=0x00226030 symbol=FUN_00225f6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed Mgr/Node views as C++, the four float offsets are extern const (that is what hoists their loads above the member stores), and the tail is std::max-style const& max(count, idx + 1) (stack temp at sp+28); readability pass; exact match verified; names and types await human review. */
#include "hst/mode_parts.h"

extern const float DAT_002f11f8;
extern const float DAT_002f11fc;
extern const float DAT_002f1200;
extern const float DAT_002f1204;
extern "C" void FUN_00102c54(ModeNode *);

template <class T> inline const T &max(const T &a, const T &b) { return a < b ? b : a; }

/* Place node `idx` at (x, y) plus table offsets and grow the used-node count. */
extern "C" void FUN_00225f6c(float x, float y, ModeObj *self, int idx)
{
  ModePart24 *list = self->parts->part24;
  list->xs[idx] = x + DAT_002f11f8;
  list->ys[idx] = y + DAT_002f11fc;
  list->nodes[idx]->x = (x + DAT_002f1200) - 188.0f;
  list->nodes[idx]->y = (y + DAT_002f1204) - 120.0f;
  FUN_00102c54(list->nodes[idx]);
  int next = idx + 1;
  list->node_count = max(list->node_count, next);
}
