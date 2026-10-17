/* HSTMATCH module=EBOOT.BIN start=0x0025afa0 end=0x0025b028 symbol=FUN_0025afa0 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0025afa0 {};
struct Tag_0025afa0 : InTag_0025afa0 {};
typedef void *Block_0025afa0;
struct It_0025afa0 {
    Block_0025afa0 *p_;
    Block_0025afa0 *first_;
    Block_0025afa0 *beg_;
    Block_0025afa0 *last_;
    It_0025afa0(const It_0025afa0 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0025afa0;
extern "C" void FUN_0025b1ec(Buf_0025afa0 *self, It_0025afa0 pos, It_0025afa0 first, It_0025afa0 last, Tag_0025afa0);
extern "C" void FUN_0025afa0(Buf_0025afa0 *self, It_0025afa0 pos, It_0025afa0 first, It_0025afa0 last)
{
    FUN_0025b1ec(self, pos, first, last, Tag_0025afa0());
}
