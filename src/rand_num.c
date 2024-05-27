/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:47:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/25 17:12:47 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to generate the next random number
unsigned int lcg_rand(unsigned int *current)
{
    *current = (A * (*current) + C) % M;
    return *current;
}

// Function to generate a random number within a specific range [min, max]
unsigned int lcg_rand_range(unsigned int *current, unsigned int min, unsigned int max)
{
    unsigned int range = max - min + 1;
    return (lcg_rand(current) % range) + min;
}
