/* HSTMATCH module=hstp_trans_main.prx start=0x0006de7c end=0x0006df1c symbol=FUN_0006de7c lang=c++ */
/* Clone of src/eboot/swap_node_payload_0006c894.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Exchanges the payload of two node records (the word at +0, the owner pointer at +4, the flag byte
   at +8 and the word at +0xc) and then re-points each owner back-reference at the node it now
   holds: the owner word at +8 keeps its low bit and gets the node address (node + 4), or, when the
   node has no owner, the node's own word at +0xc is set to node + 4.
   Matching idiom: the flag byte at +8 is a class with a user copy-assignment operator, which is what
   makes the compiler exchange the two bytes in the opposite registers to the word exchanges. */
typedef struct Owner Owner;

struct Flag {
  unsigned char v;
  Flag &operator=(const Flag &o)
  {
    v = o.v;
    return *this;
  }
};

typedef struct Node {
  int f0;
  Owner *f4;
  Flag f8;
  int fC;
} Node;

struct Owner {
  int pad[2];
  unsigned f8;
};

extern "C" void FUN_0006de7c(Node *a, Node *b)
{
  if (a != b) {
    int t = a->f0;
    a->f0 = b->f0;
    b->f0 = t;
    Owner *o = a->f4;
    a->f4 = b->f4;
    b->f4 = o;
    Flag c = a->f8;
    a->f8 = b->f8;
    b->f8 = c;
    t = a->fC;
    a->fC = b->fC;
    b->fC = t;
    o = a->f4;
    if (o != 0) {
      o->f8 = (unsigned)(int)((int *)a + 1) | (o->f8 & 1);
    } else {
      a->fC = (int)((int *)a + 1);
    }
    o = b->f4;
    if (o != 0) {
      o->f8 = (unsigned)(int)((int *)b + 1) | (o->f8 & 1);
    } else {
      b->fC = (int)((int *)b + 1);
    }
  }
}
