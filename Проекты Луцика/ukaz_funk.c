#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <locale.h>

//------------------------------  Пример 1  --------------------------------
//double f(double);
//double pr(double(*)(double), double, double, double, int);
//double tr(double(*)(double), double, double, double, int);
//
//int main()
//{	setlocale(LC_ALL, "Russian");
//	double a, b, eps;
//	int n;
//	double(*ff)(double);
//	puts("Введите границы a и b и точность вычисления интеграла eps");
//	scanf("%lf%lf%lf", &a, &b, &eps);
//	puts("Введите максимальное число итераций n");
//	scanf("%d", &n);
//	ff = f;
//	printf("  интеграл = %6.4lf\n", pr(ff, a, b, eps, n));
//	printf("  интеграл = %6.4lf\n", tr(ff, a, b, eps, n));
//	return 0;
//}

// использование указателя на функцию на примере
// вычисления ИНТЕГРАЛА методом " ПРЯМОУГОЛЬНИКОВ "
//double pr(double(*fi)(double), double a, double b, double e, int n)
//{
//	double y2 = 0.0, y1, x, h = (b - a) ;
//	do
//	{
//		y1 = y2;                    // запоминаем текущее значение функции
//		y2 = 0.0;                   // обнуление для очередного нахождения значения функции
//		for (x = a; x<b; x += h)    // цикл перебора прямоугольников в интервале [a , b]
//			y2 += (*fi)(x)*h;       // вычисление функции
//		h /= 2;
//	} while (fabs(y1 - y2)>e);      // проверка на точность
//	return y2;
//}

// использование указателя на функцию на примере
// вычисления ИНТЕГРАЛА методом " ТРАПЕЦИЙ "
//double tr(double(*fi)(double), double a, double b, double e, int n)
//{
//	double y2 = 0, y1, x, h = (b - a);
//	do
//	{
//		y1 = y2;                                      // запоминаем текущее значение функции
//		y2 = 0.5*((*fi)(a)+(*fi)(b));                 // полусумма функций f(a) и f(b) 
//		for (x = a + h; x<b; x += h) y2 += (*fi)(x);  // цикл перебора трапеций в интервале [a , b]
//		y2 *= h;
//		h /= 2;
//	} while (fabs(y1 - y2)>e);                        // проверка на точность
//	return y2;
//}
//
//double f(double x)            
//{
//	return (x*x - 4.);       // вычисление значения ф-ции f(x)=x^2-4 в точке х
//}



//------------------------------  Пример 2  --------------------------------
// использование указателя на функцию на примере
// вычисления корня нелинейного уравнения методом " ПОЛОВИННОГО ДЕЛЕНИЯ "

//#include <stdio.h>
//#include <math.h>
//#include <conio.h>
//double f(double);
//double fun(double, double, double, double(*)(double));
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	double a, b, eps;
//	double(*ff)(double x);
//
//	puts("Введите границы a и b и точность вычисления корня");
//	scanf("%lf%lf%lf", &a, &b, &eps);
//	ff = f;
//	printf("a= %5.2lf  b=%5.2lf  корень = %6.4lf\n", a, b, fun(a, b, eps, ff));
//	getch();
//}
//double fun(double a, double b, double eps, double(*f1)(double))
//{
//	double fa, fb, c, fc;
//	do
//	{
//		fa = (*f1)(a);           // нахождение значений функции в концах
//		fb = (*f1)(b);           // выбранного интервала   [a,b]
//		c = (a + b) / 2.0;       // деление отрезка [a,b] пополам
//		fc = (*f1)(c);           // значение функции в середине отрезка
//		if (fa*fc>0) a = c;      //  выбор границ [c,b]
//		else if (fb*fc>0) b = c; //  выбор границ [a,c]
//		else
//		{
//			puts("точный корень"); return c;
//		}
//	} while (fabs(a - b)>eps);  // пока не достигнута точность  eps
//	return c;
//}
//
//double f(double x)
//{
//	return (x*x - 3.);       // вычисление значения ф-ции f(x)=x^2-3 в точке х
//}                        // [ нахождение квадратного кореня из 3 ]

//------------------------------  Пример 3  --------------------------------
// использование массива указателей на функции на примере
// организации диалогового меню
#include <stdio.h>
#include <string.h>
#include <conio.h>
void funk1();
void funk2();
void funk3();
void(*spisok[])() =                // объявление и инициализиализация 
    {funk1, funk2, funk3};         // массива указателей на функции
int menu();

int main()
{
	setlocale(LC_ALL, "Russian");
	void(**ptr_func)();            // объявление еще одного указателя на функции
	int i, n;
	printf("введите размерность массива указателей : ");
	scanf("%d",&n);
	ptr_func = (void (**)())malloc(n*sizeof(void *));
	if (!ptr_func) return 0;
	*(ptr_func + 0) = funk1;       // инициализация массива указателей
	*(ptr_func + 1) = funk2;
	*(ptr_func + 2) = funk3;
	
	do
	{
		i = menu();                // выбор номера из списка
		if (i<0 || i>2) break;
		// spisok[i]();            // вызов i-ой функции через указатель на нее
		// (*spisok[i])();         // верно
		// *spisok[i]();           // ошибка
		
		// (*(ptr_func + i))();
		ptr_func[i]();
	} while (i >= 0 && i<3);
	puts("окончание работы\n");
	return 0;
}
int menu()
{
	char c;
	int i;
	do
	{
		system("CLS");
		puts("1    funk1");
		puts("2    funk2");
		puts("3    funk3");
		puts("0    выход");
		c = (char)getch();   // можно без преобразования к char
	} while (!strchr("0123", c));
	return c - 49;           // возвращаем выбранный номер
}

void funk1()
{
	puts("выполняется функция   funk1");
	getch();
}
void funk2()
{
	puts("выполняется функция   funk2");
	getch();
}
void funk3()
{
	puts("выполняется функция   funk3");
	getch();
}