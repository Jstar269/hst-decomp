/* HSTMATCH module=hstp_trans_main.prx start=0x0005e30c end=0x0005e3e8 symbol=FUN_0005e30c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short ushort;
typedef struct Counter Counter;
typedef struct CounterRef CounterRef;
typedef struct Child Child;
typedef struct Record Record;
typedef struct Owner Owner;
struct Counter { char pad[8]; ushort value; };
struct CounterRef { Counter *counter; };
struct Child { char pad[0x1c]; int value; };
struct Record { CounterRef *counter; Child *child; int value; };
struct Owner { char pad20[0x20]; int *mapping; Record *records; unsigned count; };
extern int FUN_0005e3e8(int owner, float parameter);

void FUN_0005e30c(float parameter, Owner *owner)
{
  unsigned index = 0;
  if (owner->count != 0) {
    unsigned offset = 0;
    do {
      Record *record = (Record *)((char *)owner->records + offset);
      if (record->value >= 0) {
        if (parameter < 0.0f) {
          record->child->value = record->value;
        } else {
          int i = FUN_0005e3e8((int)owner, parameter);
          int value = owner->mapping[i];
          if (value < 0) value = record->value;
          record->child->value = value;
        }
        record->counter->counter->value++;
      }
      index++;
      offset += 12;
    } while (index < owner->count);
  }
}
