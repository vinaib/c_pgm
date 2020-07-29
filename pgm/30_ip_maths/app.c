#include<ip.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>

uint32_t check_ip( 	uint8_t *ip,
					uint8_t *id,
					uint32_t mask )
{
	uint32_t ret = -1;

	if(ip == NULL || id == NULL) {
		printf("IP/ID is NULL\n");
		goto end_fun;
	}

	if(mask <= 0) {
		printf("mask is <= 0\n");
		goto end_fun;
	}

	uint32_t len = strlen(ip);
	while(len-- != 0) {
		printf("%c", *ip++);
	}

	printf("\n");

	printf("input parameters verified ... \n");
end_fun:
	return ret;
}

uint32_t main(int argc, char *argv[])
{
	uint32_t val = 0;
	uint8_t ip[] = "192.168.10.12";
	uint8_t ip_in_diff_subnet[] = "10.10.10.2";
	uint8_t abcd_ip[16] = {0};
	uint8_t abcd_nw[16] = {0};
	uint8_t abcd_bcast[16] = {0};

#if 0
	check_ip("ABC", NULL, 1);
	check_ip(NULL, "DEF", 1);
	check_ip("ABC", "DEF", 0);
	check_ip("192.168.1.20", "DEF", 1);
#endif

	if(argc > 1) 
		val = get_ip_integral_equivalent(argv[1]);
	else
		val = get_ip_integral_equivalent(ip);

	printf("integral value %u(0x%0x)\n", val, val); 

	get_abcd_ip_format(val, abcd_ip);
	printf("a.b.c.d format %s\n", abcd_ip);

	if(argc > 1) 
		get_network_id(argv[1], MASK, abcd_nw);
	else
		get_network_id(ip, MASK, abcd_nw);

	printf("nwid  %s\n", abcd_nw);

	if(argc > 1) 
		get_broadcast_address(argv[1], MASK, abcd_bcast);
	else
		get_broadcast_address(ip, MASK, abcd_bcast);

	printf("bcast_addr %s\n", abcd_bcast);

	printf("Cardinality %u\n", get_subnet_cardinality(MASK));

	if(!check_ip_subnet_membership(abcd_nw, MASK, abcd_ip))
		printf("%s is valid in subnet %s\n", abcd_ip, abcd_nw);

	if(!check_ip_subnet_membership(abcd_nw, 
				MASK, 
				ip_in_diff_subnet)) 
		printf("%s is valid in subnet %s\n", 
				ip_in_diff_subnet, 
				abcd_nw);
	else
		printf("%s is not valid in subnet %s\n", 
				ip_in_diff_subnet, 
				abcd_nw);

	return 0;
}
