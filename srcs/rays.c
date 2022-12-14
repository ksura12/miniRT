#include	"../header/minirt.h"

int	ray_create(t_data *data, t_ray *ray, int px, int py)
{
	t_coord	coord;
	t_vec	cam;
	t_vec	dir;

	cam = data->elements->camera->v_orient;
	coord = conversion(px, py);
	ray->tmax = RAY_T_MAX;
	ray->v_pos = data->elements->camera->v_pos;
	if(cam.y == 0 && cam.z == 0)
	{
		dir = vector_rot_z(cam, coord.y * data->elements->camera->angle_vert);
		dir = vector_rot_y(dir, coord.x * data->elements->camera->angle_horz);
		//rotate for pixel row around z and for colum araound y
	}
	if(cam.x == 0 && cam.z == 0)
	{
		dir = vector_rot_x(cam, coord.y * data->elements->camera->angle_vert);
		dir = vector_rot_z(dir, coord.x * data->elements->camera->angle_horz);
		//rotate for pixel row around x and for colum araound z
	}
	else
	{
		dir = vector_rot_x(cam, coord.y * data->elements->camera->angle_vert);
		dir = vector_rot_y(dir, coord.x * data->elements->camera->angle_horz);
		//rotate for pixel row around x and for colum araound y
	}
	ray->v_direct = dir;
	return (1);
}

/**
 * @brief returns 1 of it intersects with scene, 0 if not
 * 
 */
int	does_intersect_p(t_ray ray, t_data *data)
{	
	double raydotn;
	double t;

	raydotn = dot_prod(ray.v_direct, data->elements->objects[0]->v_orient);
	if (raydotn == 0)
		return(0);
	t = dot_prod(vector_dev(data->elements->objects[0]->v_pos, ray.v_pos), data->elements->objects[0]->v_orient) / raydotn;
	if (t <= RAY_T_MIN || t >= ray.tmax)
		return(0);
	return(1);
}

/**
 * @brief returns 1 of it intersects with scene, 0 if not
 * 
 */
int	intersect_p(t_ray ray, t_data *data)
{	
	double raydotn;
	double t;

	raydotn = dot_prod(ray.v_direct, data->elements->objects[0]->v_orient);
	if (raydotn == 0)
		return(0);
	t = dot_prod(vector_dev(data->elements->objects[0]->v_pos, ray.v_pos), data->elements->objects[0]->v_orient) / raydotn;
	if (t <= RAY_T_MIN || t >= ray.tmax)
		return(0);
	ray.tmax = t;
	return(1);
}

int does_intersect_s(t_ray ray, t_data *data)
{
	double a;
	double b;
	double c;
	double discriminant;
	double t[2];
	// Transform ray so we can consider origin-centred sphere
	ray.v_pos = vector_dev(ray.v_pos, data->elements->objects[0]->v_pos);
	

	// Calculate quadratic coefficients
	a = vector_lensqr(ray.v_direct);
	b = 2 * dot_prod(ray.v_direct, ray.v_pos);
	c = vector_lensqr(ray.v_pos) - sqr(data->elements->objects[0]->dia / 2);
	// float a = localRay.direction.length2();
	// float b = 2 * dot(localRay.direction, localRay.origin);
	// float c = localRay.origin.length2() - sqr(radius);

	// Check whether we intersect
	discriminant = sqr(b) - 4 * a* c;
	float discriminant = sqr(b) - 4 * a * c;

	if (discriminant < 0.0)
		return (0);

	// Find two points of intersection, t1 close and t2 far
	t[0] = (-b - sqrt(discriminant)) / (2 * a);
	if (t[0] > RAY_T_MIN && t[0] < ray.tmax)
		return (1);

	float t[1] = (-b + sqrt(discriminant)) / (2 * a);
	if (t[1] > RAY_T_MIN && t[1] < ray.tmax)
		return (1);

	return(0);
}
