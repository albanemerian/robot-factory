.name    "pdd"
.comment "pdd"

		sti	r1, %:live, %1
begin:	ld	76, r1
		ld	%40, r6
		ld	%1, r7
		fork %:begin#ldsslfj
		ld	15, r4
		ldi	%:live, %3, r5
                sti r1, 3, %1
                sti r1, 3, r3
		lld 12, r5
		sub	r4, r5, r3
		zjmp	%:attack
live:	live	%2
		lfork %:begin
		ld	%0, r4
		ldi	%8, %:begin, r5
		lld %:begin, r9
		zjmp	%:live
attack:	ld	%65, r8
		st	r8, 100
		add	r6, r7, r7
		fork %1
		sti	r7, r7, r1
		lld 6, r1
		ld	%15, r4
		lfork %8
                sti r1, :live, r1
                sti r1, %:live, r1
		ld	%:live, r5
		zjmp	%:live

