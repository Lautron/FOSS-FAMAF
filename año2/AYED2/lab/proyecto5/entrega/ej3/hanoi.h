/**
*  @file hanoi.h
*  @brief Hanoi util functions
*  @see https://en.wikipedia.org/wiki/Tower_of_Hanoi
*/
#ifndef __HANOI_H__
#define __HANOI_H__

typedef struct _hanoi *hanoi_t;

/**
* @brief Initializes the towers of Hanoi
* @param disks_count Amount of disks to insert in the source tower
* @returns Source tower: contains 'disks_count' well-ordered disks
*          Middle tower: empty
*          Target tower: empty
*/
hanoi_t hanoi_init(unsigned int disks_count);

/**
* @brief Moves all disks from the source tower to the target tower
* following the usual movement constraints (@see https://en.wikipedia.org/wiki/Tower_of_Hanoi)
* It also prints the three towers after each movement
* @note Solved using a recursive algorithm
*/
void hanoi_solve(hanoi_t hanoi);

/**
* @brief Prints the current state of the three towers
*/
void hanoi_print(hanoi_t hanoi);

/**
* @brief All memory resources are freed
*/
hanoi_t hanoi_destroy(hanoi_t hanoi);

#endif
