//#include "../for90std/for90std.h"

//double ss(const double & r, const foroptional<double> & h)
//{
//	double ss_result;
//	double temp_h;
//	if ((forpresent(h))) {
//		temp_h = h;
//	}
//	else {
//		temp_h = 1.0;
//	}
//	ss_result = 3.1415926 * power(r, 2) * temp_h;
//	return ss_result;
//}
//int main()
//{
//	printf(" %s%10.3f", "vol=", ss(2.5, 9));
//	return 0;
//}

///******************************************************************/
///* File:                                                          */
///* Author:                                                        */
///* Generated by CFortranTranslator                                */
///* CFortranTranslator is a open-source software under GPL license */
///* visit https://github.com/CalvinNeo/CFortranTranslator/ for more*/
///******************************************************************/
//#include "../for90std/for90std.h"
//int main()
//{
//
//	forarray<int> a(1, 10 + 1);
//
//	int i;
//	a(1) = 0;
//	a(2) = 1;
//	for (i = 3; i <= 10; i += 1) {
//		a(i) = a(i - 2) + a(i - 1);
//	}
//	printf(" %8d%8d%8d%8d%8d", a);
//	return 0;
//}


///******************************************************************/
///* File:                                                          */
///* Author:                                                        */
///* Generated by CFortranTranslator                                */
///* CFortranTranslator is a open-source software under GPL license */
///* visit https://github.com/CalvinNeo/CFortranTranslator/ for more*/
///******************************************************************/
//#include "../for90std/for90std.h"
//int sum(const int & x, const int & y)
//{
//	int sum_result;
//	sum_result = x + y;
//	return sum_result;
//}
//
//int minu(const int & x, const int & y)
//{
//	int minu_result;
//	minu_result = x - y;
//	return minu_result;
//}
//
//void proc(const int & a, const int & b, std::function<int(const int & x, const int & y)> fun)
//{
//	cout << fun(a, b) << endl;
//	return;
//}
//
//int main()
//{
//
//	int a, b;
//	cin >> a >> b;
//	proc(a, b, sum);
//	proc(a, b, minu);
//	return 0;
//}

/******************************************************************/
/* File:                                                          */
/* Author:                                                        */
/* Generated by CFortranTranslator                                */
/* CFortranTranslator is a open-source software under GPL license */
/* visit https://github.com/CalvinNeo/CFortranTranslator/ for more*/
/******************************************************************/
#include "../for90std/for90std.h"
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>

template<typename T>
void test1(T x, for1array_matcher<T>) {
	cout << "match" << endl;
}
template<typename T>
void test1(T x, ...) {
	cout << "no match" << endl;
}

int main()
{	
	//for1array<int>  a(5, 7 + 1);
	//for (int i = 5; i < 7; i++) {
	//	a(i) = to_int(i, 4) + 1;
	//};
	//for1array< for1array< for1array<int>  > > b(5, 6 + 1);
	//init_for1array(b, std::vector<int>{5, 6, 7}, std::vector<int>{2, 2, 2}, std::vector<int >{1, 2, 3, 4, 5, 6, 7, 8});

	//for1array< for1array<int>  > c(5, 7 + 1);
 
	//for1array<int>  d(5, 7 + 1);
	//d = a.slice(5, 7) + init_for1array_hiddendo(1, 4, [](int i) {return to_int(i) + 1; });

	//cout << a(6) << b(5)(6)(7) << endl;

	//for1array<int> e = for1array<int>(3, 6);
	//init_for1array(e, vector<int>{ 3 }, vector<int>{ 3 }, vector<int>{ 1, 2, 3 });
	//for (for1array<int>::iterator i = e.begin(); i != e.end(); i++)
	//{
	//	cout << *i << endl;
	//}

	for1array< for1array< for1array<int>  > > b(1, 3);
	init_for1array(b, std::vector<int>{1, 1, 1}, std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 3, 4, 5, 6});
	vector<for1array_size_type_t> size = for1array_getsize(b);

	int aa = 1;
	for1array<int> bb;
	for1array<for1array<int>> cc;
	test1<int>(aa, nullptr);
	test1<for1array<int>>(bb, nullptr);
	test1<for1array<for1array<int>>>(cc, nullptr);
	cout << is_for1array::test<int>(nullptr) << endl;
	cout << is_for1array::test<for1array<int>>(nullptr) << endl;
	cout << is_for1array::test<for1array<for1array<int>>>(nullptr) << endl;

	return 0;
}