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
void test2(function<void(void)> f = nullptr, int a = 0, int b = 0) {
	f();
	printf("%d %d\n", a, b);
}
int main()
{
	forarray<int>  a(5, 7 + 1);
	for (int i = 5; i < 7; i++) {
		a(i) = to_int(i) + 1;
	};

	forarray< int > b(5, 7 + 1);

	forarray<int>  d(5, 7 + 1);
	d = a.slice(1, 2) + b.slice(3, 4);

	test2();
	test2([&]() {});

	return 0;
}