.name    "pdd"
.comment "pdd"

live:   add r5, r8, r9
        sti r1, %:live, %1
        sti r1, :live, %1
        sti r1, :live, r1
        sti r1, %:live, r1
        sti r1, r3, r1
        sti r1, r3, %1
        sti r1, %3, r1
        sti r1, %3, %1
        sti r1, 3, %1
        sti r1, 3, r3
        sti r1, 3, %:live
        sti r1, %3, %:live
        sti r1, r3, %:live
        sti %4, 6, %4
        zjmp %0
