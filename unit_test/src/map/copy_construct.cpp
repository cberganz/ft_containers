
#include <list>
#include "../../include/unit_test_map.hpp"

#define T1 int
#define T2 int
typedef NAMESPACE::pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	NAMESPACE::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	ft::printMap(mp);
	ft::printMap(mp_range);
	ft::printMap(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();
	ft::printMap(mp);
	ft::printMap(mp_range);
	ft::printMap(mp_copy);

	return (0);
}
