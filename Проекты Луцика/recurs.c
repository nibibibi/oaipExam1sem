// Ниже приведены примеры некоторых программ с использованием 
// рекурсивных функций
// (в рекурсивных функциях циклы не используются !!!!)

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// рекурсивная функция ввода информации в массив 
int Vvod(int *MS, int k)
{
	static int i = 0;
	int j;
	if (!MS) return 1;                 // проверка не нулевой ли указатель на массив 
	if (i >= k) return 0;              // массив введен полностью
	                                   // рекурсия окончена
    printf("MS[ %d ] = ", i);       
	fflush(stdin); //rewind(stdin);    // чистка входного буфера
	if (scanf("%d", MS + i)) i++;      // проверка введено ли число
	Vvod(MS,k);                        // рекурсия для ввода очередного элемента
	i--;
	return 0;
}

// рекурсивная функция вывода на экран информации из массива
void Print(int MS[], int k)       //  здесь MS[] и *MS  - эквивалентны  
{
	static int i;
	if (!MS) return;              // проверка не нулевой ли указатель на массив
	if (i >= k) return;
	printf("%4d", *(MS + i++));   // рекурсивный поэлементный вывод массива на экран 
	Print(MS,k);
	i--;
	if(!i) printf("\n");
	//i = 0;
	return;
}

// Рекурсивное вычисление чисел принадлежащих посл-сти Фибоначчи
// сформировать последовательность из 15 чисел:  1 1 2 3 5 8 13 .....
//int fibon(int);      // прототип рекурсивной функции
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int n, i;
//	printf("\nЧисла Фибоначчи =  ");
//	for (n = 0; n<15; n++) 
//	  printf("%4d",fibon(n));
//	puts("\n\n");
//	return 0;
//}
//
//int fibon(int n)  // рекурсивная функция 
//{
//	return ((n == 0 || n == 1)) ? 1 : fibon(n - 1) + fibon(n - 2);
//}

//====================================================================

// Ниже приведены 3 рекурсивные функции вычисление факториала числа  n!
//int fact1(int);    // прототип первой функции
//int fact2(int);    // прототип второй функции   
//int fact3(int);    // прототип третьей функции
//
//int main()
//{  setlocale(LC_ALL, "Russian");
//   int n,i;
//   char c;
//   do
//   {
//      fflush(stdin);
//	  puts("\nВводите число >=0 для вычисления его факт-ла :");
//      i=scanf("%d",&n);
//   } while(i<1 || n<0);
//   printf("\nФакториал числа %d (%d!) = %d   вариант 1",n,n,fact1(n));
//   printf("\nФакториал числа %d (%d!) = %d   вариант 2",n,n,fact2(n));
//   printf("\nФакториал числа %d (%d!) = %d   вариант 3",n,n,fact3(n));
//   printf("\n\n");
//}
//// рекурсивная функция вычисления факт-ла  (вариант 1 )
//int fact1(int n)
//{  
//   if (n==1 || n==0) return (1);    // выход из рекурсии
//   return fact1(n-1)*n;
//}
//
//// рекурсивная функция вычисления факт-ла  (вариант 2 )
//int fact2(int n)
//{
//   static long i;         // i-статическая переменная, чтобы сохранять своё 
//                          // последнее значение при каждом новом вызове функции
//   int factorial;
//   if(n <= 1)             // если число = 0 или 1
//   return 1;              // факториал равен 1
//   if (++i < n)           // используем прекремент, т.е. предварительное
//   {                         // увеличение i на единицу
//     factorial = i*fact2(n); // заново вызываем функцию факториала
//     i--;                    // декрементируем i
//     return factorial;
//   }
//   i--;
//   return n;
//}
//// рекурсивная функция вычисления факт-ла  (вариант 3 )
//
//int fact3(int n)
//{
//   return n ?n*fact3(n-1):1;
//}

//===================================================================

// рекурсивные функции перевода числа из десятичной с/с в новую (2 ... 16)
void fc(int);           // прототип рекурсивной ф-ции перевода целой части числа
void fd(double, int);   // прототип рекурсивной ф-ции перевода дробной части числа
                                      
int ss;                             // основание новой с/с
char znak='+';
int main()
{  setlocale(LC_ALL,"Russian" );
   int t;                       // точность дробной части
   double num;                  // исходное число (правильная дробь)
   printf("\nВведите исходное число : ");
   scanf("%lf",&num);
   num<0?znak='-',num*=-1:num;  // выделение знака числа
   printf("\nВведите основание новой с/с");
   scanf("%d",&ss);
   printf("\nВведите точность для дробной части числа с/с");
   scanf("%d",&t);
   printf("\nЧисло в с/с (%d) = ",ss);
   fc((int)num);                 // передача в функцию целой части числа
   putchar('.');
   fd(num-(int)num,t);           // передача в функцию дробной части числа          
   puts("\n");
   return 0;
}

void fc(int num1)    // рекурсивная функция перевода (вывода на экран) в новую с/с
{                    // целой части исходного десятичного числа 
   int i;
   if(num1>=ss)
   {
	   i=num1%ss;      // получаем остаток от деления на основание
     num1/=ss;       // получаем целую часть от деления
     fc(num1);       // рекурсивный вызов функции fc
     printf("%c",i>9?i-10+'a':i+'0');
   }
   else printf("%c %c",znak,num1>9?num1-10+'A':num1+'0');
}

void fd(double num, int t)   // рекурсивная функция перевода (вывода на экран) в 
{                            // новую с/с дробной части исходного десятичного числа 
   static short int n;
   int i;
   if(num!=0 && n++<t)
   { 
     i=num*=ss;             // получаем произведение и выделяем целую частьk
     printf("%c",i>9?i-10+'a':i+'0');
     fd(num-(int)num,t);    // рекурсивный вызов fd
   }
  // else printf("%c",num>9?(int)num-10+'A':(int)num+'0');
}

//=====================================================================

// Рекурсивная функция нахождения НОД двух чисел
//int nod(int a,int b);
//int main()
//{  setlocale(LC_ALL,"Russian" );
//   int i,a,b;
//   do
//   { fflush(stdin);
//     printf("");
//     i=scanf("%d%d",&a,&b);
//   }while(i<2);
//   printf("\nНОД чисел %d и %d равен %d\n",a,b,nod(a,b));
//}
//
//int nod(int a,int b)  
//{  int c;
//   if (b>a) c=nod(b,a);
//   else if (b<=0) c=a;
//   else c=nod(b,a%b);
//   return c;
//}

//=====================================================================

// Рекурсивная функция сортировки методом Хоара
//void hoor(int *, int, int);
//void swap(int *, int, int);
//void FOR(int *, int, int, int, int &);
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int *ms, i, n;
//	do
//	{
//		fflush(stdin);
//		puts("\nВводите кол-во чисел");
//		i = scanf("%d", &n);
//	} while (i<1 || n<=0);
//	ms = (int*)malloc(n*sizeof(int));
//	puts("\nВводите элементы массива ");
//	Vvod(ms,n);
//	system("CLS");
//	printf("\nИсходный массив        :");
//	Print(ms,n);
//	hoor(ms, 0, n - 1);
//	printf("\n\nПреобразованный массив :");
//	Print(ms, n);
//}
//
//// рекурсивная функция сортировки методом Хоара
//void hoor(int *a, int l, int r)
//{
//	int i, las;
//	if (l >= r)  return;
//	swap(a, l, (l + r) / 2);  // делящий эл-т переносится в a[l] (a[l]<->a[(l+r)/2])
//	las = l;                  // позиция посл-го эл-та большего чем делящий
//	//for (i = l + 1; i <= r; i++) //деление [l,r] на [l,las-1] и [las+1,r]
//	//if (a[i]<a[l])         // ЦИКЛ УБРАТЬ !!!!!!!!!!!!!!!!!!!!
//	//	swap(a, ++las, i);
//	FOR(a, l, r, l+1, las);   // замена цикла for рекурсивной функцией FOR
//	swap(a, l, las);
//	hoor(a, l, las - 1);      // сортировка для [l,las-1]
//	hoor(a, las + 1, r);      // сортировка для [las+1,r]
//}
//  
//// функция ( не рекурсивная) замены i и j эл-тов в массиве a
//void swap(int *a, int i, int j)
//{
//	int tmp;           
//	tmp = a[i];
//	a[i] = a[j];
//	a[j] = tmp;
//}
//
//// рекурсивная функция заменяющая традиционный цикл for
//void FOR(int *a, int l, int r, int i, int &las)
//{ 
//	if (i > r) return;
//	if (a[i]<a[l])
//		swap(a, ++las, i);
//	FOR(a,l,r,++i,las);
//}



//=====================================================================
// Рекурсивный переворот строки на месте
//# define kk 20
//void revers1(char *, int);
//void revers2(char *, int);
//
//// рекурсивный ввод строки и подсчет ее длины
//// get_str возвращает значение типа int
//// в указатель st копируется указатель на строку для ввода
//int get_str(char *st, int k)
//{
//	int c;
//	static int i, dl;
//    	 // ввод строки до заданного кол-ва символов k или до  
//	     // тех пор пока не нажата клавиша Enter (или Ctrl + Z)
//	if (--k > 0 && (c = getchar()) != EOF && c != '\n')
//	{
//		st[i++] = c;
//		get_str(st, k);
//		dl++;       // длина введенной строки
//	}
//	else st[i] = '\0';
//	if(i) i--;      // i уменьшается до 0
//	return dl;      // возврат длины строки
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int nn;
//	char st[kk];
//	system("CLS");
//	fflush(stdin);
//	puts("\nВводите символьную строку :");
//	nn = get_str(st, kk);    // nn - число реально введенных символов в строку (nn < kk)
//	system("CLS");
//	printf("\nСтрока до переворота    %s", st);
//	revers1(st, nn);
//	printf("\nПосле первой рекурсии   %s", st);
//	revers2(st, nn);
//	printf("\nПосле второй рекурсии   %s\n\n", st);
//	return 0;
//}
//
//// первая рекурсивная функция реверсивного переворота строки
//void revers1(char *st, int dl)
//{
//	static int i;
//	char c;
//	c = *(st + i++);        // сохраняем в стеке очередной считанный символ
//	if (c) revers1(st, dl); // рекурсивный вызов для считывания нового симв.
//	else return;    // пока не считан конец строки, иначе выход из рекурсии
//	*(st + dl - (--i)) = c; // обратный проход по функциям после окончания
//}                         // рекурсии
//
//// вторая рекурсивная функция реверсивного переворота строки
//void revers2(char *st, int dl)
//{
//	static int i;
//	char c;
//	c = *(st + i);                    // замена симметричных символов 
//	*(st + i) = *(st + dl - 1 - i);   // в строке до тех пор пока
//	*(st + dl - 1 - i++) = c;        
//	if (i < dl/2) revers2(st, dl);    // не достигнута середина строки
//	else return;
//}


//=====================================================================
// Рекурсивная функция удаления ВСЕХ совпавших символов в строке
// удаляются все (кроме первого в группе). Удаление и первого - самостоятельно

//#include <string.h>
//void del_first_simvol(char *, int);
//void del_simvol(char *, int, int);
//void poisk_simvol(char *);

// рекурсивный ввод строки и подсчет ее длины
// get_str возвращает значение типа int
// в указатель st копируется указатель на строку для ввода

//int get_str(char *st, int k)
//{
//	int c;
//	static int i, dl;
//    	 // ввод строки до заданного кол-ва символов k или до  
//	     // тех пор пока не нажата клавиша Enter (или Ctrl + Z)
//	if (--k > 0 && (c = getchar()) != EOF && c != '\n')
//	{
//		st[i++] = c;
//		get_str(st, k);
//		dl++;       // длина введенной строки
//	}
//	else st[i] = '\0';
//	if(i) i--;      // i уменьшается до 0
//	return dl;      // возврат длины строки
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int dl;
//	char *st;
//	system("CLS");
//	fflush(stdin);
//	puts("\nВводите размер символьной строки :");
//	scanf("%d", &dl);
//	puts("\nВводите символьную строку :");
//	st = (char *)calloc(dl, 1);
//    strcpy(st, "aca11 baaaaab12 3 aab ba");   // только для отладки программы
//	// get_str(st, dl);    // nn - число реально введенных символов в строку (nn < kk)
//	
//	system("CLS");
//	printf("\nСтрока до удаления    :  %s", st);
//	poisk_simvol(st);
//	printf("\nСтрока после удаления :  %s\n", st);
//	dl = 0;
//	while (*(st+ dl)) dl++;
//	st = (char*)realloc(st,dl+1);
//	printf("\nСтрока после удаления :  %s\n\n", st);
//	return 0;
//}
//
//// рекурсивная функция удаления совпавших символов
//void poisk_simvol(char *st)
//{
//	static int i1,i2=1;
//	if (!*(st + i2))                 // просмотр строки окончен
//	{
//		del_first_simvol(st, i1);    // удаление исходного символа для которого 
//                                     // выполнялось удаление всех совпавших с ним
//		i2 = ++i1 + 1;               // при достижении конца строки переход к выбору
//		                             // нового символа (i1++) i2 - исдекс следующего за i1 
//	}
//	if (!*(st + i1)) return;         // вся строка просмотрена
//	if (*(st+i1) == *(st+i2))        // найдено совпадение символов
//		del_simvol(st, i2, i2 + 1);  // рекурсивный вызов функции 
//		i2++;                        // новый символ i2 для сравнения с исходным i1
//		poisk_simvol(st);
//}                        
//
//void del_first_simvol(char *st,int i)   // функция удаления исходного символа для которого 
//{                                       // выполнялось удаление всех совпавших с ним
//	if ((*(st + i) = *(st + i + 1)) == '\0') return;
//	del_first_simvol(st,++i);           // рекурсия
//}
//
//void del_simvol(char *st, int i1, int i2)
//{    
//	static unsigned short int flag;
//	static char c;
//	if (!flag)              // "acbbab aab ba"
//	{
//	   c = st[i1];          // начало прохода по строке (запоминаем удаляемый символ)
//	   flag=1;              // flag=1 - запрет к повторному выбору для запоминания символа
//	}
//	if (c != *(st + i2))    // очередной символ не совпадает с символом в с
//	   *(st + i1++) = *(st + i2);  // сдвиг (перезапись) символа из i2 в i1
//	if(*(st+i2++)) del_simvol(st, i1, i2);
//	else flag = 0;         // сброс флажка для следующего символа
//}
//