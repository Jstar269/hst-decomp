/* HSTMATCH module=hstp_trans_main.prx start=0x0005ac18 end=0x0005acc0 symbol=FUN_0005ac18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Buffer {
  int *data;
  int size;
  char pad_8[8];
  int start;
};
struct EmptyTag {};

extern "C" void *FUN_00002f60(int, void *);
extern "C" void FUN_0005a484(void *, void *);

static inline void CopyElement(void *dst, void *src, EmptyTag)
{
  FUN_0005a484(dst, src);
}

extern "C" void FUN_0005ac18(Buffer *self, int count, void *source)
{
  void *src = source;
  char *cursor = (char *)self->data + self->start * 0x90 + self->size * 0x90;
  for (; count != 0; --count) {
    void *element = FUN_00002f60(0x90, cursor);
    if (element != 0) CopyElement(element, src, EmptyTag());
    self->size = self->size + 1;
    cursor += 0x90;
  }
}
