/* HSTMATCH module=hstp_trans_main.prx start=0x0026b450 end=0x0026b4d8 symbol=FUN_0026b450 lang=c++ */
/* Clone of src/eboot/cbuf_insert_range_0011ec54.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Circular-buffer (deque map) range insert forwarder: insert(pos, first, last) dispatches to the out-of-line
   insert(pos, first, last, forward_iterator_tag) 0x11f5e0. The 16-byte iterator {p, first, beg, last} has a
   member-wise copy constructor (by-value copies made by the caller, lw/sw); the tag is a DERIVED empty class
   (forward : input), whose by-value temporary gets a never-written frame slot read with lb. Names provisional. */
struct InTag_0026b450 {};
struct Tag_0026b450 : InTag_0026b450 {};
typedef void *Block_0026b450;
struct It_0026b450 {
    Block_0026b450 *p_;
    Block_0026b450 *first_;
    Block_0026b450 *beg_;
    Block_0026b450 *last_;
    It_0026b450(const It_0026b450 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
};
struct Buf_0026b450;
extern "C" void FUN_0026b69c(Buf_0026b450 *self, It_0026b450 pos, It_0026b450 first, It_0026b450 last, Tag_0026b450);
extern "C" void FUN_0026b450(Buf_0026b450 *self, It_0026b450 pos, It_0026b450 first, It_0026b450 last)
{
    FUN_0026b69c(self, pos, first, last, Tag_0026b450());
}
