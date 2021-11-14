#include "push_swap.h"

void   init_long(t_long *data, t_stack *a)
{
        data->size = list_size(a->front);
        data->min = get_min_data(a->front);
        data->max = get_max_data(a->front);
        data->med_1 = get_median_data(a, data->min, data->max, (data->size / 5));
        data->med_2 = get_median_data(a, data->min, data->max, (data->size / 5) * 2);
        data->med_3 = get_median_data(a, data->min, data->max, (data->size / 5) * 3);
        data->med_4 = get_median_data(a, data->min, data->max, (data->size / 5) * 4);
        data->front = 0;
        data->tail = 0;
}

void   collect_long(t_stack *a, t_stack *b, t_long data, int zone)
{
        int     way;
        int     step;

        way = 1;
        step = 0;
        while (way)
        {
			way = smart_way_long(a, data, zone, &step);
			if (way == 1 && step != 0)
			{
				while (--step)
					ra(a);
				pb(a, b);
				if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
						|| b->front->data == data.med_1 || b->front->data == data.med_2
						|| b->front->data == data.med_3 || b->front->data == data.med_4))
					rb(b);
			}
			else if (way == -1)
			{
				while (step--)
					rra(a);
				pb(a, b);
				if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
						|| b->front->data == data.med_1 || b->front->data == data.med_2
						|| b->front->data == data.med_3 || b->front->data == data.med_4))
					rb(b);
			}
        }
}

int    smart_way_long(t_stack *a, t_long data, int zone, int *step)
{
	smart_way_decision_long(a, &data, zone);
	if (data.front < data.tail)
	{
			*step = data.front;
			return (1);
	}
	else if (data.front > data.tail)
	{
			*step = data.tail;
			return (-1);
	}
	else if (data.front == 0 && data.front == 0)
	{
			*step = 0;
			return (0);
	}
	else
	{
			*step = data.front;
			return (1);
	}
}

void   smart_way_decision_long(t_stack *a, t_long *data, int zone)
{
        if (zone == 5)
        {
			data->front = get_by(a->front, data->min, data->med_1, 1);
			data->tail = get_by(a->tail, data->min, data->med_1, -1);
        }
        if (zone == 4)
        {
			data->front = get_by(a->front, data->med_1, data->med_2, 1);
			data->tail = get_by(a->tail, data->med_1, data->med_2, -1);
        }
        if (zone == 3)
        {
			data->front = get_by(a->front, data->med_2, data->med_3, 1);
			data->tail = get_by(a->tail, data->med_2, data->med_3, -1);
        }
        if (zone == 2)
        {
			data->front = get_by(a->front, data->med_3, data->med_4, 1);
			data->tail = get_by(a->tail, data->med_3, data->med_4, -1);
        }
        if (zone == 1)
        {
			data->front = get_by(a->front, data->med_4, data->max, 1);
			data->tail = get_by(a->tail, data->med_4, data->max, -1);
        }
}
