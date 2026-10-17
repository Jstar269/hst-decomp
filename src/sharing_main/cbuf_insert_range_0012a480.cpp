/* HSTMATCH module=hstp_trans_main.prx start=0x0012a480 end=0x0012a508 symbol=FUN_0012a480 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0012a480 {};
struct Tag_0012a480 : InTag_0012a480 {};
typedef void *Block_0012a480;
struct It_0012a480 {
    Block_0012a480 *p_;
    Block_0012a480 *first_;
    Block_0012a480 *beg_;
    Block_0012a480 *last_;
    It_0012a480(const It_0012a480 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0012a480;
extern "C" void FUN_0012b328(Buf_0012a480 *self, It_0012a480 pos, It_0012a480 first, It_0012a480 last, Tag_0012a480);
extern "C" void FUN_0012a480(Buf_0012a480 *self, It_0012a480 pos, It_0012a480 first, It_0012a480 last)
{
    FUN_0012b328(self, pos, first, last, Tag_0012a480());
}
