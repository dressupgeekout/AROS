/*
     (C) 1995-96 AROS - The Amiga Replacement OS
     $Id$
 
     Desc:
     Lang:
*/

	/* The following functions are guaranteed to preserve
	   all registers. But I do not want to write them completely
	   in assembly - C is generally more readable.
	   So I use those stubs to preserve the registers.
	*/

	#include "machine.i"

	.text
	.balign 16
	.globl	AROS_SLIB_ENTRY(_ObtainSemaphore,Exec)
	.type	AROS_SLIB_ENTRY(_ObtainSemaphore,Exec),@function
AROS_SLIB_ENTRY(_ObtainSemaphore,Exec):
	movem.l	d0-d1/a0-a1,-(sp)
	bsr	AROS_SLIB_ENTRY(ObtainSemaphore,Exec)
	movem.l	(sp)+,d0-d1/a0-a1
	rts

	.globl	AROS_SLIB_ENTRY(_ReleaseSemaphore,Exec)
	.type	AROS_SLIB_ENTRY(_ReleaseSemaphore,Exec),@function
AROS_SLIB_ENTRY(_ReleaseSemaphore,Exec):
	movem.l	d0-d1/a0-a1,-(sp)
	bsr	AROS_SLIB_ENTRY(ReleaseSemaphore,Exec)
	movem.l	(sp)+,d0-d1/a0-a1
	rts

	.globl	AROS_SLIB_ENTRY(_ObtainSemaphoreShared,Exec)
	.type	AROS_SLIB_ENTRY(_ObtainSemaphoreShared,Exec),@function
AROS_SLIB_ENTRY(_ObtainSemaphoreShared,Exec):
	movem.l	d0-d1/a0-a1,-(sp)
	bsr	AROS_SLIB_ENTRY(ObtainSemaphoreShared,Exec)
	movem.l	(sp)+,d0-d1/a0-a1
	rts

