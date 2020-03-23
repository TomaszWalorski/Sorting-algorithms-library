#include <iostream>
#include <random>
#include <string>
#include <ctime>

// sorting tools

void swap(int* &arr, int positionONE, int positionTWO)
{
	int safe = arr[positionONE];
	arr[positionONE] = arr[positionTWO];
	arr[positionTWO] = safe;
}

int min(int* &arr, int size)
{
	int min_val = arr[0];
	int min_index = 0;
	for (int count = 1; count < size; count++)
	{
		if (min_val > arr[count]) 
		{
			min_val = arr[count];
			min_index = count;
		}
	}
	return min_index;
}

std::string check_if_sorted(int* arr,int size) 
{
	int i = 1;
	int is_sorted = 1;
	while ((i < size) && is_sorted) {
		if (arr[i - 1] > arr[i])
			is_sorted = 0;
		i++;
	}
	std::string answer = "Set is ";
	is_sorted == 1 ? answer += "sorted" : answer += "not sorted";
	return answer;
}

int* Generate_Set(int size)
{
	int *arr = new int [size];
	for (int count = 0; count < size; count++)
	{
		//while (true)
		//{
		//	int rand_val = std::_Random_device();
		//	if (rand_val > 0)
		//	{
		//		arr[count] = rand_val;
		//		break;
		//	}
		//}
		arr[count] = rand();
	}
	return arr;
}

bool ending()
{
	std::cout << "Do measurement again? (Y/N)" << std::endl;
	char answer;
	std::cin >> answer;
	return (answer = 'y' || 'Y');
}

void show_set(int* arr, int size)
{
	for (int i = 0; i < size; i++) std::cout << arr[i] << std::endl;
}

int* copy_part_of_array(int* arr, int lower_border, int upper_border)
{
	int* new_arr = new int[upper_border - lower_border];
	for (int counter = lower_border; counter < upper_border; counter++)
	{
		new_arr[counter - lower_border] = arr[counter];
	}
	return new_arr;
}

// Simple sorting algorithms

void Bubble_Sort(int* &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr, j - 1, j);
			}
		}
	}
}

void Selection_Sort(int* &arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int index_min = i;
		int value_min = arr[i];

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < value_min)
			{
				index_min = j;
				value_min = arr[j];
			}
		}
		swap(arr, i, index_min);
	}
}

void insertion_1_sort(int* &arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int value_min = arr[i];
		int j = i - 1;

		while (j >= 0 && value_min < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value_min;
	}
}

void insertion_2_sort(int* &arr, int size)
{
	int min_index = min(arr, size);
	swap(arr, 0, min_index);

	for (int i = 1; i < size; i++)
	{
		int value_min = arr[i];
		int j = i - 1;
		while (value_min < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value_min;
	}
}

// Fast sorting algorithms

void Shell_Sort_Core(int* &arr, int h, int size)
{
	for (int i = h; i < size; i++)
	{
		int x = arr[i];
		int j = i;
		while (j >= h)
		{
			if (x < arr[j - h])
			{
				arr[j] = arr[j - h];
				j = j - h;
			}
			else break;
		}
		arr[j] = x;
	}
}

void Shell_Sort_1(int* &arr, int size)
{
	int h = 1;
	while (h < (size / 9))
	{
		h = 3 * h + 1;
	}
	while (h > 0)
	{
		Shell_Sort_Core(arr, h, size);
		h = h / 3;
	}
	std::cout << "Shell sort 1" << std::endl;
}

void Shell_Sort_2(int* &arr, int size)
{
	for (int counter = 1;; counter++)
	{
		int h = 2 * (size / pow(2, counter)) + 1;

		Shell_Sort_Core(arr, h, size);		
		
		if (h == 1) break;
	} 
	std::cout << "Shell sort 2" << std::endl;
}

void Quick_Sort_1(int* &arr, int l_value, int r_value)
{
	int pivot, s_value;

	if (l_value < r_value)
	{
		pivot = arr[l_value];
		s_value = l_value;

		for (int counter = l_value + 1; counter < r_value/*+1 maybe*/; counter++)
		{
			if (arr[counter] < pivot)
			{
				s_value++;
				swap(arr, s_value, counter);
				
			}
		}
		swap(arr, s_value, l_value);
		Quick_Sort_1(arr, l_value, s_value);
		Quick_Sort_1(arr, s_value + 1, r_value);
	}
	//std::cout << "Quick sort 1" << std::endl;
}

void Quick_Sort_2(int* &arr, int l_value, int r_value)
{
	if (l_value < r_value)
	{
		int middle_point = (r_value + l_value)/2;
		int pivot = arr[middle_point];
		int s_value = l_value;

		swap(arr, middle_point, l_value);
		for (int counter = l_value + 1; counter < r_value/*+1 maybe*/; counter++)
		{
			if (arr[counter] < pivot)
			{
				s_value++;
				swap(arr, s_value, counter);

			}
		}
		swap(arr, s_value, l_value);
		Quick_Sort_2(arr, l_value, s_value);
		Quick_Sort_2(arr, s_value + 1, r_value);
	}
}

void Quick_Sort_3(int* &arr, int l_value, int r_value)
{
	if (l_value < r_value)
	{
		int middle_point = (std::rand() % (r_value - l_value)) + l_value;
		int pivot = arr[middle_point];
		int s_value = l_value;

		swap(arr, middle_point, l_value);
		for (int counter = l_value + 1; counter < r_value/*+1 maybe*/; counter++)
		{
			if (arr[counter] < pivot)
			{
				s_value++;
				swap(arr, s_value, counter);

			}
		}
		swap(arr, s_value, l_value);
		Quick_Sort_3(arr, l_value, s_value);
		Quick_Sort_3(arr, s_value + 1, r_value);
	}
}

void insertion_sort(int* &arr, int lower_border, int upper_border)
{
	for (int i = lower_border + 1; i < upper_border; i++)
	{
		int value_min = arr[i];
		int j = i - 1;

		while (j >= lower_border && value_min < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value_min;
	}
}

void Quick_Sort_plus_ins(int* &arr, int l_value, int r_value)
{
	if (l_value < r_value)
	{
		int middle_point = (std::rand() % (r_value - l_value)) + l_value;
		int pivot = arr[middle_point];
		int s_value = l_value;

		swap(arr, middle_point, l_value);
		for (int counter = l_value + 1; counter < r_value/*+1 maybe*/; counter++)
		{
			if (arr[counter] < pivot)
			{
				s_value++;
				swap(arr, s_value, counter);

			}
		}
		swap(arr, s_value, l_value);
		if (r_value - l_value > 170)
		{
			Quick_Sort_plus_ins(arr, l_value, s_value);
			Quick_Sort_plus_ins(arr, s_value + 1, r_value);
		}
		else
		{
			insertion_sort(arr, l_value, s_value);
			insertion_sort(arr, s_value + 1, r_value);
		}
	}
}

int main()
{
	int size = 128000;
	int *arr = Generate_Set(size);

	clock_t start = clock();
	Quick_Sort_plus_ins(arr, 0, size);
	clock_t stop = clock();

	std::cout << std::endl << check_if_sorted(arr, size) << std::endl << stop - start << "ms" << std::endl;
	
	//show_set(arr, size);
	getchar();
	return 0;
}