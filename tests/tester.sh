#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <asm1> <asm2> <input_file>"
    exit 1
fi

asm1="$1"
asm2="$2"
input_file="$3"

base_name="${input_file}"

./"$asm1" "$input_file"
./"$asm2" "$input_file"

if cmp -s ./*.co ./*.cor; then
    echo "Outputs are the same."
else
    echo "Outputs are different."
    echo "Hexdump of $asm1 output:"
    hexdump -C ./*.co
    echo "Hexdump of $asm2 output:"
    hexdump -C ./*.cor
fi

rm ./*.co
rm ./*.cor
