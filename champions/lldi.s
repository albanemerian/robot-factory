.name    "pdd"
.comment "pdd"

live:   add r5, r8, r9
        lldi 1, %3, r3
        lldi %1, %3, r3
        lldi %1, r3, r3
        lldi r1, %3, r3
        lldi r1, r3, r3
        lldi 4, %:live, r4
        lldi %:live, r4, r5
        lldi :live, r6, r8
        lldi %4, %:live, r5
        lldi r4, %:live, r9
        lldi %:live, %5, r6
        lldi :live, %5, r5
