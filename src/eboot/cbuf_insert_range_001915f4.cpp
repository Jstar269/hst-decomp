/* HSTMATCH module=EBOOT.BIN start=0x001915f4 end=0x0019167c symbol=FUN_001915f4 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_001915f4 {};
struct Tag_001915f4 : InTag_001915f4 {};
typedef void *Block_001915f4;
struct It_001915f4 {
    Block_001915f4 *p_;
    Block_001915f4 *first_;
    Block_001915f4 *beg_;
    Block_001915f4 *last_;
    It_001915f4(const It_001915f4 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_001915f4;
extern "C" void FUN_001918f4(Buf_001915f4 *self, It_001915f4 pos, It_001915f4 first, It_001915f4 last, Tag_001915f4);
extern "C" void FUN_001915f4(Buf_001915f4 *self, It_001915f4 pos, It_001915f4 first, It_001915f4 last)
{
    FUN_001918f4(self, pos, first, last, Tag_001915f4());
}
