#include <stdio.h>

void win() {
	printf("YOU WIN !\n");
}

int main(void) {
	char buf[8];
	printf("address : %p\n", &win);

	read(0, buf, 8);

	printf("buf : %x\n", buf);

	return 0;
} //
