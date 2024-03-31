/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:49:29 by micabrer          #+#    #+#             */
/*   Updated: 2024/02/13 01:10:05 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*complex_sum(t_complex *left, t_complex *right)
{
	t_complex	*res;

	res = init_complex(left->re + right->re, left->im + right->im);
	return (res);
}

t_complex	*complex_multi(t_complex *left, t_complex *right)
{
	t_complex	*res;

	res = init_complex(left->re * right->re - left->im * right->im,
			left->re * right->im + left->im * right->re);
	return (res);
}

t_complex	*complex_power_2(t_complex	*number)
{
	t_complex	*res;

	res = complex_multi(number, number);
	return (res);
}

t_complex	*init_complex(double re, double im)
{
	t_complex	*number;

	number = (t_complex *)malloc(sizeof(t_complex));
	if (!number)
		return (NULL);
	number->re = re;
	number->im = im;
	number->value = sqrt(pow(re, 2) + pow(im, 2));
	return (number);
}
