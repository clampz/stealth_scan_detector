/* pdefdev.c
 * written by: David Weinman
 * last update: 08/21/13
 * */

/* This file is licensed under The MIT License, see LICENSE for details. */

// prints the id for the current default network adapter

#include <stdio.h>
#include <pcap/pcap.h>
#include "malloc_dump.h"

int main(int, char **);

int main(int argc, char **argv) {

	char errbuf[PCAP_ERRBUF_SIZE];
        char *device;

        if (argc != 1) {printf("\nwrong # of args.\n\n"); exit(1);}

// find a device using packet capture lib
        device = pcap_lookupdev(errbuf);

// if no device is found, print an error
        if (device == NULL) {
                fatal(errbuf);
        }

// print the id
	printf("%s\n", device);

	return 0;

}

