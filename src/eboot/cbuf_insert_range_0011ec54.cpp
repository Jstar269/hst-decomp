/* HSTMATCH module=EBOOT.BIN start=0x0011ec54 end=0x0011ecdc symbol=FUN_0011ec54 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0011ec54 {};
struct Tag_0011ec54 : InTag_0011ec54 {};
typedef void *Block_0011ec54;
struct It_0011ec54 {
    Block_0011ec54 *p_;
    Block_0011ec54 *first_;
    Block_0011ec54 *beg_;
    Block_0011ec54 *last_;
    It_0011ec54(const It_0011ec54 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0011ec54;
extern "C" void FUN_0011f5e0(Buf_0011ec54 *self, It_0011ec54 pos, It_0011ec54 first, It_0011ec54 last, Tag_0011ec54);
extern "C" void FUN_0011ec54(Buf_0011ec54 *self, It_0011ec54 pos, It_0011ec54 first, It_0011ec54 last)
{
    FUN_0011f5e0(self, pos, first, last, Tag_0011ec54());
}
