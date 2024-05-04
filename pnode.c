#include "types.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

void
insert_after(struct pnode *pnode, struct pnode *new)
{
  if(!pnode)
    panic("insert_after pnode null");

  if(new){
    new->next = pnode->next;
    new->prev = pnode;
  }
  if(pnode->next)
    pnode->next->prev = new;
  pnode->next = new;
}

void
insert_before(struct pnode *pnode, struct pnode *new)
{
  if(!pnode)
    panic("insert_before pnode null");

  if(new){
    new->next = pnode;
    new->prev = pnode->prev;
  }
  if(pnode->prev)
    pnode->prev->next = new;
  pnode->prev = new;
}

void
remove(struct pnode *pnode)
{
  if(!pnode)
    panic("remove pnode null");

  if(pnode->prev)
    pnode->prev->next = pnode->next;
  if(pnode->next)
    pnode->next->prev = pnode->prev;

  pnode->prev = 0;
  pnode->next = 0;
}
