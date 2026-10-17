/* HSTMATCH module=EBOOT.BIN start=0x0005d4f0 end=0x0005d5cc symbol=FUN_0005d4f0 lang=c99 */
/* Clone of src/sharing_main/FUN_0005e30c_0005e30c.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
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
extern int FUN_0005d5cc(int owner, float parameter);

void FUN_0005d4f0(float parameter, Owner *owner)
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
          int i = FUN_0005d5cc((int)owner, parameter);
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
