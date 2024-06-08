#include "PmergeMe.hpp"

void showVector(std::vector<int> &vector)
{
    int flag = 8;
    std::vector<int>::iterator it = vector.begin();
	while (it != vector.end())
	{
		if(!flag)
		{
			std::cout << " [...]" << std::endl;
			return ;
		}
		std::cout << " " << *it;
        flag--;
        it++;
	}
    std::cout << std::endl;
}

void showDeque(std::deque<int> &deque)
{
    int flag = 8;
    std::deque<int>::iterator it = deque.begin();
    while (it != deque.end())
    {
        if(!flag)
        {
            std::cout << " [...]" << std::endl;
            return ;
        }
        std::cout << " " << *it;
        flag--;
        it++;
    }
    std::cout << std::endl;
}

void parser(char **av)
{
    int i = 0;
    while (av[++i])
    {
        if (av[i][0] == '-')
            throw "you cant sort negative numbers";
        for (int j = 0; av[i][j]; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                throw "you need to pass only numbers";
    }
}

void insertionSortVector(std::vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


void mergeVector(std::vector<int> &arr, int left_start, int left_end, int right_end)
{    
    std::vector<int> tmp;

    int i = left_start;
    int j = left_end + 1;

    while (i <= left_end && j <= right_end)
    {
        if (arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }
    while (i <= left_end)
        tmp.push_back(arr[i++]);
    while (j <= right_end)
        tmp.push_back(arr[j++]);
     for (int p = left_start; p <= right_end; p++)
        arr[p] = tmp[p - left_start];
}

void mergeSortVector(std::vector<int> &arr)
{
    const int INSERTION_THRESHOLD = 10; 

    int arr_size = arr.size();
    for (int split_size = 1; split_size < arr_size; split_size *= 2)
        for (int left_start = 0; left_start < arr_size - 1; left_start += 2 * split_size)
        {
            int left_end = std::min(left_start + split_size - 1, arr_size - 1);
            int right_end = std::min(left_start + 2 * split_size - 1, arr_size - 1);
            if (right_end - left_start <= INSERTION_THRESHOLD)
                insertionSortVector(arr, left_start, right_end);
            else
                mergeVector(arr, left_start, left_end, right_end);
        }
}

void insertionSortDeque(std::deque<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void mergeDeque(std::deque<int> &arr, int left, int left_end, int right_end)
{    
    std::deque<int> tmp;

    int i = left;
    int j = left_end + 1;

    while (i <= left_end && j <= right_end)
    {
        if (arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }
    while (i <= left_end)
        tmp.push_back(arr[i++]);
    while (j <= right_end)
        tmp.push_back(arr[j++]);
    for (int p = left; p <= right_end; p++)
        arr[p] = tmp[p - left];

}

void mergeSortDeque(std::deque<int> &arr)
{
    const int INSERTION_THRESHOLD = 10;

    int arr_size = arr.size();
    for (int split_size = 1; split_size < arr_size; split_size *= 2)
        for (int left_start = 0; left_start < arr_size - 1; left_start += 2 * split_size)
        {
            int left_end = std::min(left_start + split_size - 1, arr_size - 1);
            int right_end = std::min(left_start + 2 * split_size - 1, arr_size - 1);
            if (right_end - left_start <= INSERTION_THRESHOLD)
                insertionSortDeque(arr, left_start, right_end);
            else
                mergeDeque(arr, left_start, left_end, right_end);
        }
}

void ft_sort(char **av)
{
    std::vector<int> arr_vector;
	std::deque<int>	arr_deque;

    int n = 0;
    int i = 0;

    std::clock_t start;
    std::clock_t end;
	double vector_time;
    double deque_time;

    while (av[++i])
    {
        std::stringstream(av[i]) >> n;
        arr_vector.push_back(n);
        arr_deque.push_back(n);
    }
    std::cout << "Before: ";
    showVector(arr_vector);
    //showDeque(arr_deque);
    start = std::clock();
    mergeSortVector(arr_vector);
    end = std::clock();
    vector_time = (end - start) / (double)CLOCKS_PER_SEC * 1000;
    start = std::clock();
    mergeSortDeque(arr_deque);
    end = std::clock();
    deque_time = (end - start) / (double)CLOCKS_PER_SEC * 1000;
    std::cout << "After: ";
    showVector(arr_vector);
    //showDeque(arr_deque);
	std::cout << "Time to process a range of " << arr_vector.size() << " elements with std::vector : " << vector_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << arr_vector.size() << " elements with std::deque : " << deque_time << " ms" << std::endl;
}