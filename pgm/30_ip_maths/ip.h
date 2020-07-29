#ifndef __IP_MATHS_H__
#define __IP_MATHS_H__

/* Tools:
 * http://www.silisoftware.com/tools/ipconverter.php
 * http://jodies.de/ipcalc
 */
#include<stdint.h>

#define MASK 			24
#define CONTROL_BITS 	8

/* 	Input: ip address(a.b.c.d), mask
 *	output: broadcast address
 *	ret: void
 */
void get_broadcast_address(	uint8_t *ip_addr, 
							uint8_t mask,
							uint8_t *output);

/* Input: ip_address: (a.b.c.d)
 * Output: none
 * ret: unsigned integer
 */
uint32_t get_ip_integral_equivalent ( uint8_t *ip_addr );


/* Input: ip_addr unsigned integer format
 * Output:ip_addr a.b.c.d
 * ret:
 */
void get_abcd_ip_format( uint32_t ip_addr,
						 uint8_t *output_buffer );

/* Input: ip_addr a.b.c.d, mask
 * Output: output_buffer a.b.c.d
 * ret:
 */
void get_network_id(uint8_t *ip_addr,
					uint8_t mask,
					uint8_t* output_buffer);

/* Input: mask
 * Output: None
 * ret: 
 * what is cardinality?
 * maximum number of assignable ip addressess
 */
 uint32_t get_subnet_cardinality( uint32_t mask );

/* Input: network_id, mask, check_ip
 * Output: None
 * ret: 0 for true, -1 for false
 */
 int32_t check_ip_subnet_membership ( uint8_t *network_id,
		 							  uint32_t mask,
									  uint8_t *check_ip);

#endif /* __IP_MATHS_H__*/
