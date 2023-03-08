/*
 * main.h
 *
 *  Created on: May 22, 2020
 *      Author: GAYATHRI
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct {
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t current_state;
	void (*task_handler)(void);
}TCB_t;

void idle_task(void);
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);
void init_systick_timer(uint32_t tick_hz);
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack);
void init_tasks_stack(void);
void switch_stack_from_msp_to_psp(void);
void enable_processor_faults(void);
void save_psp_value(uint32_t current_psp_value);
uint32_t get_psp_value(void);
void task_delay(uint32_t tick_count);

/* stack memory calculation */
#define SIZE_TASK_STACK		1024U
#define SIZE_SCHED_STACK	1024U

#define SRAM_START			0x20000000U
#define SRAM_SIZE			((128) * (1024))
#define SRAM_END			((SRAM_START) + (SRAM_SIZE))

#define T1_STACK_START		SRAM_END
#define T2_STACK_START		((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T3_STACK_START		((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START		((SRAM_END) - (3 * SIZE_TASK_STACK))
#define IDLE_STACK_START	((SRAM_END) - (4 * SIZE_TASK_STACK))
#define SCHED_STACK_START	((SRAM_END) - (5 * SIZE_TASK_STACK))

/* Desired systick exception frequency */
#define TICK_HZ 		1000U
#define HSI_CLOCK 		16000000U
#define SYSTICK_TIM_CLK HSI_CLOCK

#define MAX_TASKS 5

#define DUMMY_XPSR 0x01000000U

#define TASK_READY_STATE 0x0
#define TASK_BLOCKED_STATE 0xFF

#define INTERRUPT_DISABLE()	do {__asm volatile("mov r0, #0x1"); __asm volatile("msr primask,r0");}while(0)
#define INTERRUPT_ENABLE() do {__asm volatile("mov r0, #0x0"); __asm volatile("msr primask,r0");}while(0)

#endif /* MAIN_H_ */
