
#include <vector>
#include <iterator>
#include <iostream>
#include <unordered_set>
#include <type_traits>

template<class In>
typename std::iterator_traits<In>::difference_type _distance(In first, In last, std::input_iterator_tag dummy)
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

template<class Ran>
typename std::iterator_traits<Ran>::difference_type _distance(Ran first, Ran last, std::random_access_iterator_tag dummy)
{
	std::cout << "random_access" << std::endl;
	return last - first;
}

template<class I> inline
typename std::iterator_traits<I>::difference_type distance2(I first, I last)
{
	typedef typename std::iterator_traits<I>::iterator_category cat;
	return _distance(first, last, cat());
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
