
#include <vector>
#include <iterator>
#include <iostream>
#include <unordered_set>
#include <type_traits>

template<bool B, typename T = void>
using EnableIf = typename std::enable_if<B, T>::type;

template<typename T>
EnableIf<std::iterator_traits<T>::iterator_category == std::random_access_iterator_tag>::type distance2(T first, T last)
{
   std::cout << "random_access" << std::endl;
	return last - first;
}

template<typename T>
EnableIf<std::iterator_traits<T>::iterator_category == std::input_iterator_tag>::type distance2(T first, T last)
{
   typename std::iterator_traits<In>::difference_type n = 0;
	std::cout << "input_iterator" << std::endl;
	while(first != last)
	{
		++first;
		++n;
	}

	return n;
}

int main()
{
	//Iterator
   auto v = std::vector<int>();
	std::cout << "Adding 4 elements to a vector.." << std::endl;
   v.push_back(2);
   v.push_back(2);
   v.push_back(2);
   v.push_back(2);

   auto dist = distance2(v.begin(), v.end());
   std::cout << "Distance = " << dist << std::endl;

	//Random access
	std::cout << "Inserting 4 elements into an unordered set.." << std::endl;
	auto s = std::unordered_set<int>();
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);

	auto dist_r = distance2(s.begin(), s.end());
	std::cout << "Distance = " << dist_r << std::endl;
   return 0;
}
