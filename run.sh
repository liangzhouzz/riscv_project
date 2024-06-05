SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)

$SHELL_FOLDER/output/qemu/bin/qemu-system-riscv64 \
-M quard-star \
-m 1G \
-smp 8 \
-bios none \
-drive if=pflash,bus=0,unit=0,format=raw,file=$SHELL_FOLDER/output/lowlevelboot/fw.bin \
-monitor stdio \
#-nographic --parallel none