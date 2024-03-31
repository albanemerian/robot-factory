	.name "Bille"
	.comment "flsjfls"

	ld	%-345,r10
	add r2, r3, r1
	and %2, 2, r6
	ld 10, r4
	ld %2, r5
    and r3, %6, r4
    and r4, 4, r8
    and r3, r4, r5  
    and %2, %4, r5
    and %2, 3, r5
    and %1, r4, r5 
    and 3, %4, r4
    and 3, 7, r8
    and 3, r5, r8


ok: 	fork %:ok
		sti r5, r4, %0
		and	r6,%2147483648,r8
		add r5, r5, r4
		ld %0, r8
		aff r10
		sti r2 %:ok, %:ok
		add r4, r5, r4
		ld %0, r8
		aff r10
		zjmp %1

