#include<ip.h>
#include<string.h>
#include<stdio.h>

void get_broadcast_address(	uint8_t *ip_addr, 
							uint8_t mask,
							uint8_t *output)
{
	if(ip_addr == NULL || output == NULL) 
		goto end_fun;

	if(mask <= 0)
		goto end_fun;

	uint32_t msk_val = ((1 << MASK) - 1) << CONTROL_BITS;
	
	uint32_t val = get_ip_integral_equivalent (ip_addr);

	get_abcd_ip_format(val, output);

	uint32_t nw_id = val & msk_val;
	uint32_t bcast_addr = nw_id | ((1 << CONTROL_BITS) - 1);

	get_abcd_ip_format(bcast_addr, output);

end_fun:	
	return;
}

uint32_t get_ip_integral_equivalent ( uint8_t *ip_addr )
{
	uint32_t ret = 0;
	uint32_t octet_no = 0;
	uint32_t f_octet = 0;
	uint32_t s_octet = 0;
	uint32_t t_octet = 0;
	uint32_t fo_octet = 0;

	if(ip_addr == NULL)
		goto end_fun;

	ret = strlen(ip_addr);
	if(ret == 0)
		goto end_fun;

	do {
		if(*ip_addr == '.') {
			++octet_no;
		}
		else if(*ip_addr >= '0' || *ip_addr <= '9') {
			switch(octet_no) {
				case 0: 
					fo_octet = (fo_octet * 10) + (*ip_addr - '0');
					break;
				case 1: 
					t_octet = (t_octet * 10) + (*ip_addr - '0');
					break;
				case 2:
					s_octet = (s_octet * 10) + (*ip_addr - '0');
					break;
				case 3: 
					f_octet = (f_octet * 10) + (*ip_addr - '0');
					break;
			}
		}

		++ip_addr;

	} while(--ret != 0);

	ret = 	fo_octet<<24 	| 
			t_octet << 16 	| 
		  	s_octet<<8 		| 
			f_octet;

end_fun:
	return ret;
}

void get_abcd_ip_format( uint32_t ip_addr,
						 uint8_t *output_buffer)
{
	if(ip_addr <= 0)
		goto end_fun;

	if(output_buffer == NULL)
		goto end_fun;

	uint8_t *pc = (uint8_t *)&ip_addr;

	sprintf(output_buffer, 
				"%d.%d.%d.%d", 
				pc[3], 
				pc[2],
				pc[1], 
				pc[0]);

	/* lengthy approach */	
#if 0	
	int32_t i = 3;
	uint32_t j = 0;
	uint8_t mod[16] = {0};
	uint8_t *pmod = mod;
	uint32_t temp;

	while(i >= 0) {
		temp = (uint32_t) pc[i];

		do {
			mod[j++] = (uint8_t)temp % 10 + '0';
			temp = temp/10;
		}while(temp != 0);

		if(i--) {
			mod[j++] = '.';
		}
	}

	uint32_t s = 0, e = 0;

	for(i=0;i<=j;i++) {
		if(mod[i] == '.') { 
			/*end of current octet*/
			e = i-1;
			temp = mod[s];
			mod[s] = mod[e];
			mod[e] = temp;
			/*start of next octet*/
			s = i+1;
		}
	}
	/* swap the last octet */
	i-=2;
	temp = mod[s];
	mod[s] = mod[i];
	mod[i] = temp;

	/*copy buffer to output parameter*/
	for(i=0;i<=j;i++) {
		*output_buffer++ = mod[i];
	}
#endif

end_fun:
	return;
}

void get_network_id(uint8_t *ip_addr,
					uint8_t mask,
					uint8_t* output_buffer)
{
	if(ip_addr == NULL || output_buffer == NULL)
		goto end_fun;

	if(mask <= 0)
		goto end_fun;

	/* since we are dealing with IPV4, 32bits are sufficient */
	uint32_t msk_val = ((1 << mask) - 1) << CONTROL_BITS;

	uint32_t val = 0;
	val = get_ip_integral_equivalent(ip_addr);

	uint32_t nw_id = val & msk_val;
	get_abcd_ip_format(nw_id, output_buffer);

end_fun:
	return;
}

uint32_t get_subnet_cardinality( uint32_t mask )
{
	uint32_t cardinality = 0;

	if(mask <= 0)
		goto end_fun;

	cardinality = (MASK + CONTROL_BITS) - mask;

	cardinality = ((1 << cardinality) - 2);

end_fun:
	return cardinality;
}


int32_t check_ip_subnet_membership ( uint8_t *network_id,
		 							 uint32_t mask,
									 uint8_t *check_ip)
{
	int32_t ret = 0;

	if(network_id == NULL || check_ip == NULL)
		goto end_fun;

	if(mask <= 0)
		goto end_fun;

	uint32_t nw_id = get_ip_integral_equivalent(network_id);

	uint32_t ip_addr = get_ip_integral_equivalent(check_ip);

	char out[20] = {0};

	get_network_id(check_ip, mask, out);

	uint32_t ip_addr_mask = get_ip_integral_equivalent(out);

	if(nw_id != ip_addr_mask) {
		ret = -1;
		goto end_fun;
	}

	uint32_t cardinality = get_subnet_cardinality(MASK);

	uint8_t *pc = (uint8_t*)&ip_addr;

	if(pc[3] <= 0 || pc[3] > cardinality) {
		ret = -1;
		goto end_fun;
	}

end_fun:	
	return ret;
}
