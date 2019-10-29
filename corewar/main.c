//
//  main.c
//  corewar
//
//  Created by Frost atronach Snow bear on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"
#include "stdio.h"

int main(int argc, const char * argv[]) {
	
	int fd = open("42.cor", O_RDONLY);
	char buff[5];
	
	read(fd, &buff, sizeof(int));
	printf("%x", buff[0]);
	printf("%x", buff[1]);
	printf("%x", buff[2]);
	printf("%x\n", buff[3]);
}
