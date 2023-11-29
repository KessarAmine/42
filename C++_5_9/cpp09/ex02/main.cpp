/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:46:44 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 15:39:03 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>
#include <iostream>
#include <deque>
#include <sys/time.h>

template <typename Container>
void ft_put_container(const Container& numbers)
{
	for (typename Container::const_iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

template<typename Container, typename PairContainer>
void init_pairs(const Container& numbers, PairContainer& pairs)
{
	typedef typename Container::const_iterator Iterator;
	for (Iterator iter = numbers.begin(); iter != numbers.end(); std::advance(iter, 2))
	{
		Iterator next = std::next(iter);
		std::pair<int, int> tmp;
		if (next != numbers.end())
		{
			tmp.first = std::max(*iter, *next);
			tmp.second = std::min(*iter, *next);
		}
		else
		{
			tmp.first = -1;
			tmp.second = *iter;
		}
		pairs.push_back(tmp);
	}
}

template<typename pair_container>
void merge(pair_container& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<typename pair_container::value_type> L(arr.begin() + p, arr.begin() + p + n1);
	std::vector<typename pair_container::value_type> M(arr.begin() + q + 1, arr.begin() + q + 1 + n2);
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
	{
		if ((L[i].first <= M[j].first && L[i].first != -1) || M[j].first == -1)
			arr[k++] = L[i++];
		else
			arr[k++] = M[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = M[j++];
}

template<typename pair_container>
void mergeSort(pair_container& arr, int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

template<typename container,typename pair_container>
void	fill(container& main_c,container& pend_c,pair_container&  pairs)
{
	for (typename pair_container::const_iterator iter = pairs.begin(); iter != pairs.end(); iter++)
	{
		if (iter->first != -1)
			main_c.push_back(iter->first);
		pend_c.push_back(iter->second);
	}
	
}

template<typename container>
void binary_search_insertion(container& main_c, int num)
{
	typename container::iterator low = main_c.begin();
	typename container::iterator high = main_c.end();
	while (low < high)
	{
		typename container::iterator mid = low + (std::distance(low, high) / 2);
		if (*mid < num)
			low = mid + 1;
		else
		{
			high = mid;
		}
	}
	main_c.insert(low, num);
}

template<typename container>
container	iterate(container main_c,container pend_c)
{
	container result(main_c);
	typename container::const_iterator iter = pend_c.begin();
	for (int i = 1, j = 1, counter = 0; counter < static_cast<int>(pend_c.size() - 1);)
	{
		for (size_t k = i; k > j; k--)
		{
			if (k < pend_c.size() + 1)
			{
				counter++;
				binary_search_insertion(result, iter[k - 1]);
			}
		}
		int tmp = i;
		i = i + 2 * j;
		j = tmp;
	}
	return (result);
}

template<typename container,typename pair_container>
container	ft_ford_johnsen(container& numbers,pair_container&  pairs)
{
	container main_c;
	container pend_c;

	init_pairs(numbers,pairs);
	pair_container sorted(pairs.size());
	mergeSort(pairs,0,pairs.size()-1);
	fill(main_c,pend_c,pairs);
	return(iterate(main_c,pend_c));
}

std::vector<int>	vector_f(std::vector<int>& numbers)
{
	std::vector<std::pair<int,int> > pairs(0);
	return(ft_ford_johnsen(numbers,pairs));
}

std::deque<int>	deque_f(std::deque<int>& numbers)
{
	std::deque<std::pair<int,int> > pairs(0);
	return(ft_ford_johnsen(numbers,pairs));
}

long long	get_timestamp(struct timeval *start, struct timeval *end)
{
	struct timeval tmp;

	tmp.tv_sec = end->tv_sec - start->tv_sec;
	tmp.tv_usec = end->tv_usec - start->tv_usec;
	while (tmp.tv_usec < 0)
	{
		tmp.tv_sec--;
		tmp.tv_usec += 1000000;
	}

	long long time = tmp.tv_usec + tmp.tv_sec * 1000000;
	return (time);
}

int main(int argc, char** argv)
{
	if (argc <= 2)
	{
		std::cout << "Error: args not matched" << std::endl;
		return(-1);
	}
	try
	{
		std::vector<int> vec;
		std::deque<int> deq;
		struct timeval time;
		struct timeval timeb;
		struct timeval vec_time;
		struct timeval deq_time;
		int o = 0;

		for (size_t i = 1; i < argc; i++)
		{
			int num = atoi(argv[i]);
			if (num == 0 && strcmp(argv[i], "0") != 0)
				throw(std::string("Error : isnotnumeric"));
			if (num < 0)
				throw(std::string("Error : number < 0"));
			vec.push_back(num);
			deq.push_back(num);
		}
		std::cout << "Before : ";
		ft_put_container(vec);
		gettimeofday(&time,NULL);
		vector_f(vec);
		gettimeofday(&vec_time,NULL);
		gettimeofday(&timeb,NULL);
		deque_f(deq);
		gettimeofday(&deq_time,NULL);
		std::vector<int> sorted_vec = vector_f(vec);
		std::deque<int> sorted_deq = deque_f(deq);

		std::cout << "After : ";
		ft_put_container(sorted_vec);		
		std::cout << "vec = " << get_timestamp(&time,&vec_time)  << std::endl;
		std::cout << "deq = " << get_timestamp(&timeb,&deq_time) << std::endl;
		for (size_t i = 0; i < sorted_vec.size()-1; i++)
		{
			if (sorted_vec[i] > sorted_vec[i + 1])
			{
				std::cout << "not sorted"<<std::endl;
				exit(0);
			}
			if (sorted_deq[i] > sorted_deq[i + 1])
			{
				std::cout << "not sorted"<<std::endl;
				exit(0);
			}
			o = i;
		}
		std::cout << "its sorted ="<< o <<std::endl;
	}
	catch(const std::string str)
	{
		std::cerr << str << '\n';
		exit(-1);
	}
	return(0);
}
