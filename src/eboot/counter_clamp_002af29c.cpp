/* HSTMATCH module=EBOOT.BIN start=0x002af29c end=0x002af314 symbol=FUN_002af29c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Owner of a counter (+0x4b74) followed by its record list (+0x4b78). */
struct RecordOwner {
  char pad0000[0x4b74];
  int count;              /* 0x4b74 */
  char records[0x44c0];   /* 0x4b78 */
};
extern "C" {
extern int DAT_00302ddc;  /* lower limit of the counter */
extern int DAT_00302de0;  /* upper limit of the counter */
extern void FUN_002af5b0(void *list);
}
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
/* Shift the record list and decrement the counter within its limits. */
extern "C" void FUN_002af29c(RecordOwner *self)
{
  FUN_002af5b0(self->records);
  self->count = Clamp(self->count - 1, DAT_00302ddc, DAT_00302de0);
}
