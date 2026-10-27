/* HSTMATCH module=EBOOT.BIN start=0x002874c4 end=0x002875f8 symbol=FUN_002874c4 lang=c++ */
/* Clone of src/sharing_main/run_or_queue_cmd_00298bc0.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Runs command 0x24 at once when `delay` <= 0, otherwise appends {0x24, delay, a, b, c, d} to the owner's message list
   (FUN_00289544 is the out-of-line list insert: sret iterator in a0, list in a1, position iterator by reference in
   a2, element in a3; the position is end(), the list header node at +4). FUN_00288a84 returns the owner's player
   (the object 224 bytes below its base) when its kind is 2 or 3. c and d are int parameters passed on unchanged and
   tested unmasked; the record constructor takes them as unsigned char, which gives retail's `andi 0xff` before the
   two stores. The virtual at +160 is slot 38. */
struct Player {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual void v37();
  virtual void v38(int n);
};
struct Msg {
  int id;
  int delay;
  int a;
  int b;
  int c;
  int d;
  Msg(int id_, int delay_, int a_, int b_, unsigned char c_, unsigned char d_)
    : id(id_), delay(delay_), a(a_), b(b_), c(c_), d(d_) {}
};
struct Node { Node *next; Node *prev; };
struct Iter {
  Node *p;
  Iter() {}
  Iter(Node *n) : p(n) {}
};
struct MsgList {
  int size;
  Node header;
};
struct Obj {
  char pad[100];
  MsgList list;
};
extern "C" {
extern Player *FUN_00288a84(Obj *o);
extern void FUN_0012b2b0(Player *p, float f, int x, int y);
extern void FUN_0012ad54(Player *p, int a, int b, int c, int d, int e, float f);
extern void FUN_000937f0(Player *p, int a, float f);
extern void FUN_00093cc8(Player *p);
extern void FUN_00289544(Iter *ret, MsgList *l, Iter *pos, const Msg *x);
}
extern "C" void FUN_002874c4(Obj *self, int a, int b, int c, int d, int delay)
{
  if (delay <= 0) {
    Player *p = FUN_00288a84(self);
    if (p != 0) {
      if (a < 0) {
        FUN_0012b2b0(p, -1.0f, 1, 1);
      } else {
        FUN_0012ad54(p, a, b == 0, c, d, 1, -1.0f);
        if (b != 0)
          p->v38(b - 1);
        if (d == 0) {
          FUN_000937f0(p, -1, 0.0f);
          FUN_00093cc8(p);
        }
      }
    }
  } else {
    Msg m(0x24, delay, a, b, c, d);
    Iter ret;
    Iter pos(&self->list.header);
    FUN_00289544(&ret, &self->list, &pos, &m);
  }
}
