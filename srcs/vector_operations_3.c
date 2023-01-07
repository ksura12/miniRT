/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:23:38 by kaheinz           #+#    #+#             */
/*   Updated: 2023/01/07 05:23:39 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/minirt.h"

/**
 * @brief multiplies vector with 4x4matrix
 * 
 * @param vec vector to convert
 * @param mat (double) double pointer to matrix for convertion of vector
 * @return t_vec converted vector
 */
t_vec	mult_vec_mat(t_vec vec, double **mat)
{
	t_vec	ret;

	ret.x = vec.x * mat[0][0] + vec.y * mat[1][0] + vec.z
		* mat[2][0] + mat[3][0];
	ret.y = vec.x * mat[0][1] + vec.y * mat[1][1] + vec.z
		* mat[2][1] + mat[3][1];
	ret.z = vec.x * mat[0][2] + vec.y * mat[1][2] + vec.z
		* mat[2][2] + mat[3][2];
	ret.f = 1;
	return (ret);
}

/**
 * @brief converts degrees to radian
 * 
 * @param deg 
 * @return double rad
 */
double	degtorad(double deg)
{
	return (deg * M_PI / 180);
}

t_vec	make_opposite_vector(t_vec vec)
{
	t_vec	opp;

	opp.x = -vec.x;
	opp.y = -vec.y;
	opp.z = -vec.z;
	return (opp);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}
/**
 * @brief compares two vectors if they are the same, returns 0 if
 * they are different, 1 if they are similar
 * 
 * @param a first vector
 * @param b second vector
 * @return int: 0 for different, 1 for identical
 */
int	vec_comp(t_vec a, t_vec b)
{
	if (a.f != b.f)
		return (0);
	if (a.x != b.x)
		return (0);
	if (a.y != b.y)
		return (0);
	if (a.z != b.z)
		return (0);
	return (1);
}
